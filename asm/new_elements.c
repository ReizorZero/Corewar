#include "asm.h"

t_asm	*new_asm(void)
{
	t_asm *the_asm;

	the_asm = (t_asm*)malloc(sizeof(t_asm));
	if (!the_asm)
	{
		printf("Error. Failed to allocate memory: struct t_asm.\n");
		exit(0);
	}
	ft_bzero(the_asm, sizeof(t_asm));
	// the_asm->header = NULL;
	// the_asm->champion_name = NULL;
	// the_asm->exec_code_size = 0;
	// the_asm->champion_comment = NULL;
	// the_asm->exec_code = NULL;
	// the_asm->dot_s_name = NULL;
	// the_asm->dot_s_file_name = NULL;
	the_asm->line_words = (char**)malloc(sizeof(char*) * MAX_WORDS_N);
	return (the_asm);
}

t_line	*new_line(char *str)
{
	t_line *the_line;

	the_line = (t_line*)malloc(sizeof(t_line));
	if (!the_line)
	{
		printf("Error. Failed to allocate memory: struct t_line.\n");
		exit(0);
	}
	the_line->next = NULL;
	the_line->str = ft_strdup(str);
	return (the_line);
}