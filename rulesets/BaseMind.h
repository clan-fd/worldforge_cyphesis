// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Alistair Riddoch

#ifndef BASE_MIND_H
#define BASE_MIND_H

#include "Thing.h"

class BaseMind : public Thing {
  protected:
    virtual int script_Operation(const string &, const RootOperation &, oplist &, RootOperation * sub_op=NULL);

    MemMap map;
  public:
    BaseMind(string &, string &);
    virtual ~BaseMind() { }

    virtual int set_object(PyObject * obj) {
        map.set_object(obj);
        script_object = obj;
        return(obj == NULL ? -1 : 0);
    }

    virtual MemMap * getMap() { return &map; }

    virtual oplist Sight_Operation(const Sight & op, Login & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Chop & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Create & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Cut & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Delete & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Eat & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Fire & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Move & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Set & sub_op);
    virtual oplist Sight_Operation(const Sight & op, Touch & sub_op);
    virtual oplist Sight_Operation(const Sight & op, RootOperation & sub_op);

    virtual oplist Sound_Operation(const Sound & op, Talk & sub_op);
    virtual oplist Sound_Operation(const Sound & op, RootOperation & sub_op);

    oplist call_sight_operation(const Sight & op, RootOperation & sub_op);
    oplist call_sound_operation(const Sound & op, RootOperation & sub_op);
    virtual oplist Operation(const Sight & op);
    virtual oplist Operation(const Sound & op);
    //RootOperation * get_op_name_and_sub(RootOperation & op, string & name);
    //virtual int call_triggers(RootOperation & op);
    //virtual oplist message(const RootOperation & op);
    virtual oplist operation(const RootOperation & op);

};

#endif /* BASE_MIND_H */
