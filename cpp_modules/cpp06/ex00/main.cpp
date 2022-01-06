#include <iostream>
#include "Convert.hpp"

int	main(int ac, char **av)
{
	Convert	convert;

	if (ac != 2)
	{
		std::cerr << "wrong number of arguments" << std::endl;
		return 1;
	}

	try
	{
		convert = Convert(av[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	convert.print();

	return 0;
}