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
	// the_asm->header = NULL;
	// the_asm->champion_name = NULL;
	// the_asm->exec_code_size = 0;
	// the_asm->champion_comment = NULL;
	// the_asm->exec_code = NULL;
	// the_asm->dot_s_name = NULL;
	// the_asm->dot_s_file_name = NULL;
	return (the_asm);
}