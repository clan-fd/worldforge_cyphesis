#include <stdio.h>
#include <unistd.h>

#include <Python.h>

#include "Python_API.h"

#include <modules/Location.h>
/*
 * Beginning of Object methods section.
 */

static PyObject* Object_get_name(AtlasObject * self, PyObject * args)
{
    if (self->m_obj == NULL) {
        PyErr_SetString(PyExc_TypeError,"invalid atlas object");
        return NULL;
    }
    if (!PyArg_ParseTuple(args, "")) {
        PyErr_SetString(PyExc_TypeError,"too many args");
        return NULL;
    }
    return PyString_FromString("obj");
}

/*
 * Object methods structure.
 */

PyMethodDef Object_methods[] = {
	{"get_name",    (PyCFunction)Object_get_name,  1},
	{NULL,          NULL}           /* sentinel */
};

/*
 * Beginning of Object standard methods section.
 */

static void Object_dealloc(AtlasObject *self)
{
    if (self->m_obj != NULL) {
        delete self->m_obj;
    }
    Py_XDECREF(self->Object_attr);
    PyMem_DEL(self);
}

static PyObject * Object_getattr(AtlasObject *self, char *name)
{
    if (self->m_obj == NULL) {
        PyErr_SetString(PyExc_TypeError,"invalid object");
        return NULL;
    }
    if (self->m_obj->IsMap()) {
        Object::MapType & omap = self->m_obj->AsMap();
        if (omap.find(name) != omap.end()) {
            printf("Getting attribute %s from Atlas Map Object\n", name);
            return Object_asPyObject(omap[name]);
        }
    }
    if (self->Object_attr != NULL) {
        PyObject *v = PyDict_GetItemString(self->Object_attr, name);
        if (v != NULL) {
            Py_INCREF(v);
            return v;
        }
    }
    return Py_FindMethod(Object_methods, (PyObject *)self, name);
}

static int Object_setattr( AtlasObject *self, char *name, PyObject *v)
{
    if (self->m_obj == NULL) {
        PyErr_SetString(PyExc_TypeError,"invalid object");
        return -1;
    }
    if (self->m_obj->IsMap()) {
        Object::MapType & omap = self->m_obj->AsMap();
        Object v_obj = PyObject_asObject(v);
        if ((v_obj.GetType() != Object::TYPE_NONE) &&
            (v_obj.GetType() != Object::TYPE_MAP) &&
            (v_obj.GetType() != Object::TYPE_LIST)) {
            printf("Setting attribute %s in Atlas Map Object\n", name);
            omap[name] = v_obj;
            return 0;
        }
    }
    if (self->Object_attr == NULL) {
        self->Object_attr = PyDict_New();
        if (self->Object_attr == NULL) {
            return -1;
        }
    }
    return PyDict_SetItemString(self->Object_attr, name, v);
}

PyTypeObject Object_Type = {
	PyObject_HEAD_INIT(&PyType_Type)
	0,				/*ob_size*/
	"AtlasObject",			/*tp_name*/
	sizeof(AtlasObject),		/*tp_basicsize*/
	0,				/*tp_itemsize*/
	/* methods */
	(destructor)Object_dealloc,	/*tp_dealloc*/
	0,				/*tp_print*/
	(getattrfunc)Object_getattr,	/*tp_getattr*/
	(setattrfunc)Object_setattr,	/*tp_setattr*/
	0,				/*tp_compare*/
	0,				/*tp_repr*/
	0,				/*tp_as_number*/
	0,				/*tp_as_sequence*/
	0,				/*tp_as_mapping*/
	0,				/*tp_hash*/
};

/*
 * Beginning of Object creation functions section.
 */

AtlasObject * newAtlasObject(PyObject *arg)
{
	AtlasObject * self;
	self = PyObject_NEW(AtlasObject, &Object_Type);
	if (self == NULL) {
		return NULL;
	}
	self->Object_attr = NULL;
	return self;
}

/*
 * Utility functions to munge between Object related types and python types
 */

PyObject * MapType_asPyObject(Object::MapType & map)
{
    PyObject * args_pydict = PyDict_New();
    Object::MapType::iterator I;
    AtlasObject * item;
    for(I=map.begin();I!=map.end();I++) {
        const string & key = I->first;
        item = newAtlasObject(NULL);
        if (item == NULL) {
            PyErr_SetString(PyExc_TypeError,"error creating map");
            return NULL;
        }
        item->m_obj = new Object(I->second);
        PyDict_SetItemString(args_pydict,(char *)key.c_str(),(PyObject *)item);
    }
    return(args_pydict);
}

PyObject * ListType_asPyObject(Object::ListType & list)
{
    PyObject * args_pylist = PyList_New(list.size());
    Object::ListType::iterator I;
    int j=0;
    AtlasObject * item;
    for(I=list.begin();I!=list.end();I++,j++) {
        item = newAtlasObject(NULL);
        if (item == NULL) {
            PyErr_SetString(PyExc_TypeError,"error creating list");
            return NULL;
        }
        item->m_obj = new Object(*I);
        PyList_SetItem(args_pylist, j, (PyObject *)item);
    }
    return(args_pylist);
}

PyObject * Object_asPyObject(Object & obj)
{
    PyObject * ret = NULL;
    switch (obj.GetType()) {
        case Object::TYPE_INT:
            ret = PyInt_FromLong(obj.AsInt());
            break;
        case Object::TYPE_FLOAT:
            ret = PyFloat_FromDouble(obj.AsFloat());
            break;
        case Object::TYPE_STRING:
            ret = PyString_FromString(obj.AsString().c_str());
            break;
        case Object::TYPE_MAP:
            ret = MapType_asPyObject(obj.AsMap());
            break;
        case Object::TYPE_LIST:
            ret = ListType_asPyObject(obj.AsList());
            break;
        default:
            break;
    }
    return(ret);
}

Object::ListType PyListObject_asListType(PyObject * list)
{
    Object::ListType argslist;
    AtlasObject * item;
    for(int i = 0; i < PyList_Size(list); i++) {
        item = (AtlasObject *)PyList_GetItem(list, i);
        if ((PyTypeObject*)PyObject_Type((PyObject *)item) != &Object_Type) {
            PyErr_SetString(PyExc_TypeError,"list contains non Atlas Object");
            return Object::ListType();
        }
        argslist.push_back(*(item->m_obj));
    }
    return(argslist);
}

Object::MapType PyDictObject_asMapType(PyObject * dict)
{
    Object::MapType argsmap;
    AtlasObject * item;
    PyObject * list = PyDict_Keys(dict);
    PyObject * key;
    for(int i = 0; i < PyDict_Size(list); i++) {
        key = PyList_GetItem(list, i);
        item = (AtlasObject *)PyDict_GetItem(dict, key);
        if ((PyTypeObject*)PyObject_Type((PyObject *)item) != &Object_Type) {
            PyErr_SetString(PyExc_TypeError,"dict contains non Atlas Object");
            return Object::MapType();
        }
        argsmap[PyString_AsString(key)] = *(item->m_obj);
    }
    return(argsmap);
}

Object PyObject_asObject(PyObject * o)
{
    if (PyInt_Check(o)) {
        return(Object((int)PyInt_AsLong(o)));
    }
    if (PyFloat_Check(o)) {
        return(Object(PyFloat_AsDouble(o)));
    }
    if (PyString_Check(o)) {
        return(Object(PyString_AsString(o)));
    }
    if (PyList_Check(o)) {
        return(Object(PyListObject_asListType(o)));
    }
    if (PyDict_Check(o)) {
        return(Object(PyDictObject_asMapType(o)));
    }
    if (PyTuple_Check(o)) {
        Object::ListType list;
        int i, size = PyTuple_Size(o);
        for(i = 0; i < size; i++) {
            Object item = PyObject_asObject(PyTuple_GetItem(o, i));
            if (item.GetType() != Object::TYPE_NONE) {
                list.push_back(item);
            }
        }
        return Object(list);
    }
    if ((PyTypeObject*)PyObject_Type(o) == &Object_Type) {
        AtlasObject * obj = (AtlasObject *)o;
        return *(obj->m_obj);
    }
    if ((PyTypeObject*)PyObject_Type(o) == &RootOperation_Type) {
        RootOperationObject * op = (RootOperationObject *)o;
        return op->operation->AsObject();
    }
    if ((PyTypeObject*)PyObject_Type(o) == &Oplist_Type) {
        OplistObject * opl = (OplistObject *)o;
        Object::ListType _list;
        Object msg(_list);
        Object::ListType & entlist = msg.AsList();
        oplist & ops = *opl->ops;
        oplist::const_iterator I;
        for(I = ops.begin(); I != ops.end(); I++) {
            entlist.push_back((*I)->AsObject());
        }
        return msg;
    }
    if ((PyTypeObject*)PyObject_Type(o) == &Location_Type) {
        LocationObject * loc = (LocationObject *)o;
        Object::MapType _map;
        Object ent(_map);
        loc->location->addObject(&ent);
        return ent;
    }
    printf("PyObject cannot be cast into Object\n");
    return Object();
}
