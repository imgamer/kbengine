/*
This source file is part of KBEngine
For the latest info, see http://www.kbengine.org/

Copyright (c) 2008-2020 KBEngine.

KBEngine is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

KBEngine is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with KBEngine.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "entitydef/entitycall_cross_server.h"
#include "entitydef/entity_call.h"
#include "pyscript/scriptobject.h"

namespace KBEngine
{

class EntityCallCrossServer : public EntityCall
{
	/** 子类化 将一些py操作填充进派生类 */
	INSTANCE_SCRIPT_HREADER(EntityCallCrossServer, EntityCall)

public:
	EntityCallCrossServer(COMPONENT_ORDER centerID, EntityCall *entitycall, const Network::Address *addr);

	virtual ~EntityCallCrossServer();

	PyObject* onScriptGetAttribute(PyObject* attr);

	virtual void c_str(char* s, size_t size);

	virtual void newCall(Network::Bundle& bundle);

protected:
	ENTITYCALL_TYPE prototype_;	// 原 EntityCall 类型

	COMPONENT_ORDER centerID_;	// centermgr分配的EntityCall所在服务器的全局id
};

}	// end namespace KBengine

