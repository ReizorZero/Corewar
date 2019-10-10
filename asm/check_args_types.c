#include "asm.h"

void	check_cmnd_correspondance(t_asm *the_asm, int arg_index)
{
	int i;
	int found_type;
	i = 0;
	found_type = 0;

	while (i < 3)
	{
		if (the_asm->e_c_l->arg_code[arg_index] ==
		commands[the_asm->e_c_l->cmnd_code - 1].arg_types[arg_index][i])
		{
			found_type = 1;
			break ;
		}
		i++;
	}
	if (!found_type)
	{
		printf("Wrong arg_%i type.\n", arg_index + 1);
		exit (0);
	}
}

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
	printf("ARG NUMBER %i;\t", arg_index + 1);
	the_asm->e_c_l->arg_code[arg_index] = REG_CODE;
	printf("ARG TYPE: T_REG;\t");
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[1]);
	printf("ARG VALUE: %i;\t", the_asm->e_c_l->arg_value[arg_index]);
	the_asm->e_c_l->arg_size[arg_index] = 1;
	printf("ARG SIZE: %i\n", the_asm->e_c_l->arg_size[arg_index]);
	check_cmnd_correspondance(the_asm, arg_index);
	return (1);
}

int		check_t_dir(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 1;
	if (s[i] == LABEL_CHAR)
	{
		printf("ARG NUMBER: %i;\t", arg_index + 1);
		the_asm->e_c_l->arg_code[arg_index] = DIR_CODE;
		printf("ARG TYPE: T_DIR;\t");
		printf("ARG VALUE: %s\t", &s[i]);//the_asm->e_c_l->arg_value[arg_index]);
		//the_asm->e_c_l->arg_size[arg_index] = commands[the_asm->e_c_l->cmnd_code - 1].t_dir_size;
		//printf("ARG SIZE: %i\n", the_asm->e_c_l->arg_size[arg_index]);
		check_cmnd_correspondance(the_asm, arg_index);
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
	printf("ARG NUMBER: %i;\t", arg_index + 1);
	the_asm->e_c_l->arg_code[arg_index] = DIR_CODE;
	printf("ARG TYPE: T_DIR;\t");
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[1]);
	printf("ARG VALUE: %i\t", the_asm->e_c_l->arg_value[arg_index]);
	the_asm->e_c_l->arg_size[arg_index] = 2;
	printf("ARG SIZE: %i\n", the_asm->e_c_l->arg_size[arg_index]);
	check_cmnd_correspondance(the_asm, arg_index);
	return (1);
}

int		check_t_ind(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 0;
	if (s[i] == LABEL_CHAR)
	{
		printf("ARG NUMBER %i;\t", arg_index + 1);
		the_asm->e_c_l->arg_code[arg_index] = IND_CODE;
		printf("ARG TYPE: T_IND;\t");
		//SIZE
		//MANAGE LABEL VALUE
		printf("ARG VALUE: %s\t", &s[i]);//the_asm->e_c_l->arg_value[arg_index]);
		//printf("ARG VALUE %i\n", the_asm->e_c_l->arg_value[arg_index]);
		check_cmnd_correspondance(the_asm, arg_index);
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
	printf("ARG NUMBER %i;\t", arg_index + 1);
	the_asm->e_c_l->arg_code[arg_index] = IND_CODE;
	printf("ARG TYPE: T_IND;\t");
	//SIZE
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[0]);
	printf("ARG VALUE %i\n", the_asm->e_c_l->arg_value[arg_index]);
	check_cmnd_correspondance(the_asm, arg_index);
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