/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:32:36 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:41:55 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

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
	the_asm->e_c_l->arg_code[arg_index] = REG_CODE;
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[1]);
	the_asm->e_c_l->arg_size[arg_index] = 1;
	check_cmnd_correspondance(the_asm, arg_index);
	return (1);
}

int		check_label_arg(t_asm *the_asm, int arg_index, char *s, int arg_code)
{
	int i;

	i = (arg_code == DIR_CODE) ? 1 : 0;
	the_asm->e_c_l->has_label_arg = 1;
	the_asm->e_c_l->label_arg_index[arg_index] = 1;
	the_asm->e_c_l->label_arg_value[arg_index] = ft_strdup(&s[i + 1]);
	the_asm->e_c_l->arg_code[arg_index] = arg_code;
	the_asm->e_c_l->arg_size[arg_index] = (arg_code == DIR_CODE) ?
	g_commands[the_asm->e_c_l->cmnd_code - 1].t_dir_size : 2;
	check_cmnd_correspondance(the_asm, arg_index);
	return (check_label(the_asm, &s[i + 1]));
}

int		check_t_dir(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 1;
	if (s[i] == LABEL_CHAR)
		check_label_arg(the_asm, arg_index, s, DIR_CODE);
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
	the_asm->e_c_l->arg_code[arg_index] = DIR_CODE;
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[1]);
	the_asm->e_c_l->arg_size[arg_index] =
	g_commands[the_asm->e_c_l->cmnd_code - 1].t_dir_size;
	check_cmnd_correspondance(the_asm, arg_index);
	return (1);
}

int		check_t_ind(t_asm *the_asm, char *s, int arg_index)
{
	int i;

	i = 0;
	if (s[i] == LABEL_CHAR)
		check_label_arg(the_asm, arg_index, s, IND_CODE);
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
	the_asm->e_c_l->arg_code[arg_index] = IND_CODE;
	the_asm->e_c_l->arg_value[arg_index] = ft_atoi(&s[0]);
	the_asm->e_c_l->arg_size[arg_index] = 2;
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
