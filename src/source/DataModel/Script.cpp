#include "DataModel/Script.h"
#include <iostream>
#include <lua.hpp>
Script::Script()
{

}
Script::~Script()
{
	
}
void Script::run()
{
	//std::cout << Source;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dostring(L,Source.c_str());
	//lua_call(L,0,0);
}