#include "lua_manager.hpp"
#include <stdexcept>
#include <iostream>

int lua_test(lua_State* lvm)
{
	std::cout << "Hello" << std::endl;
	return 0;
}

luanda::lua_manager::lua_manager(const char* script_name)
{
	if ((lvm = luaL_newstate()) == NULL) throw std::runtime_error("lua: failed to create new lua state");
	luaL_openlibs(lvm);
	if (luaL_dofile(lvm, script_name) != LUA_OK) throw std::runtime_error("lua: failed to execute lua_script");

	lua_register(lvm, "_test", lua_test);

	lua_getglobal(lvm, "init");
	if (lua_isfunction(lvm, -1))
	{
		lua_pushlightuserdata(lvm, this);
		if (lua_pcall(lvm, 1, 0, 0) != LUA_OK) throw std::runtime_error("lua: failed to call init function");
	}
}

luanda::lua_manager::~lua_manager()
{
	lua_close(lvm);
}
