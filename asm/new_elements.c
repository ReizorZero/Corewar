#include "asm.h"

t_asm	*new_asm(void)
{
	t_asm *the_asm;

	the_asm = (t_asm*)malloc(sizeof(the_asm));
	if (!the_asm)
	{
		printf("Error. Failed to allocate memory: struct t_asm.\n");
		exit(0);
	}
	ft_bzero(the_asm, sizeof(the_asm));
	return (the_asm);
}