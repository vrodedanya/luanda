#include <iostream>
#include "lua_manager.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) 
	{
		std::cerr << "./lua <script_name>" << std::endl;
		return EXIT_FAILURE;
	}
	luanda::lua_manager manager(argv[1]);
	
	return EXIT_SUCCESS;
}
