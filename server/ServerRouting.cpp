// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Alistair Riddoch

#include <Atlas/Message/Object.h>
#include <Atlas/Objects/Root.h>
#include <Atlas/Objects/Operation/Login.h>

#include "ServerRouting.h"

#include <common/persistance.h>


ServerRouting::ServerRouting(CommServer * server, char * name) :
        comm_server(server), svr_name(name)
{
    fullid = name;
    id_dict[fullid] = this;
    world=new WorldRouter(this); //game world;
    BaseEntity * obj=add_object((BaseEntity*)Persistance::load_admin_account());
    //obj->server=this;
    obj->world=world;
}
