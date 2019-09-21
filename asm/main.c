#include "asm.h"

int		main(int argc, char **argv)
{
	check_input(argc, argv);
	system("leaks -q asm");
	return (0);
}