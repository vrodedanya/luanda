#ifndef LUA_MANAGER_HPP
#define LUA_MANAGER_HPP

#include "lua.hpp"

namespace luanda
{
	class lua_manager
	{
	private:
		lua_State* lvm = nullptr;
	public:
		lua_manager(const char* script_name);
		~lua_manager();
	};
}

#endif
