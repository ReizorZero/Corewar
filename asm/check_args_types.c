#include "asm.h"

int		check_t_reg(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 1;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
		i++;
	}
	if (ft_atoi(&s[1]) > REG_NUMBER || ft_atoi(&s[1]) == 0)
		ERROR(INCORRECT_REG, the_asm->curr_line_n);
	printf("ARG NUMBER %i\n", arg_index + 1);
	the_asm->e_c_l->arg_code[i] = REG_CODE;
	printf("ARG TYPE: T_REG\n");
	the_asm->e_c_l->arg_value[i] = ft_atoi(&s[1]);
	printf("ARG VALUE %i\n", the_asm->e_c_l->arg_value[i]);
	//SIZE
	return (1);
}

int		check_t_dir(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 1;
	if (s[i] == LABEL_CHAR)
	{
		printf("ARG NUMBER %i\n", arg_index + 1);
		the_asm->e_c_l->arg_code[i] = DIR_CODE;
		printf("ARG TYPE: T_DIR\n");
		//SIZE
		return (check_label(the_asm, &s[i + 1]));
	}
	else 
	{
		if (s[i] == '-')
			i++;
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]))
				ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
			i++;
		}
	}
	printf("ARG NUMBER %i\n", arg_index + 1);
	the_asm->e_c_l->arg_code[i] = DIR_CODE;
	printf("ARG TYPE: T_DIR\n");
	//SIZE
	return (1);
}

int		check_t_ind(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 0;
	if (s[i] == LABEL_CHAR)
	{
		printf("ARG NUMBER %i\n", arg_index + 1);
		the_asm->e_c_l->arg_code[i] = IND_CODE;
		printf("ARG TYPE: T_IND\n");
		//SIZE
		return (check_label(the_asm, &s[i + 1]));
	}
	else 
	{
		if (s[i] == '-')
			i++;
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]))
				ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
			i++;
		}
	}
	printf("ARG NUMBER %i\n", arg_index + 1);
	the_asm->e_c_l->arg_code[i] = IND_CODE;
	printf("ARG TYPE: T_IND\n");
	//SIZE
	return (1);
}

void	check_args(t_asm *the_asm, int i, int shift)
{
	if (the_asm->line_words[i + shift][0] == 'r')
		check_t_reg(the_asm, the_asm->line_words[i + shift], i);
	else if (the_asm->line_words[i + shift][0] == DIRECT_CHAR)
		check_t_dir(the_asm, the_asm->line_words[i + shift], i);
	else if (the_asm->line_words[i + shift][0] == '-' ||
	ft_isdigit(the_asm->line_words[i + shift][0]) ||
	the_asm->line_words[i + shift][0] == LABEL_CHAR)
		check_t_ind(the_asm, the_asm->line_words[i + shift], i);
	else
		ERROR(WRONG_ARG_SNTX, the_asm->curr_line_n);
	i++;
}