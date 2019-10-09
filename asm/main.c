#include "asm.h"

int		main(int argc, char **argv)
{
	t_asm *the_asm;

	the_asm = new_asm();
	check_asm_input(argc, argv, the_asm);
	if (read_from_dot_s(the_asm))
		write_to_dot_cor(the_asm);
	//system("leaks -q asm");
	return (0);
}