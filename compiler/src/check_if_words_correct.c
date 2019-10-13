/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_words_correct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:42:46 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 17:50:23 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"
#include "../../inc/commands.h"

void	define_cmnd_type(t_asm *the_asm, int w_i)
{
	int i;
	int found_command;

	i = 0;
	found_command = 0;
	while (i < COMMANDS_N)
	{
		if (!ft_strcmp(the_asm->line_words[w_i], g_commands[i].name))
		{
			found_command = 1;
			break ;
		}
		i++;
	}
	the_asm->e_c_l->cmnd_code = g_commands[i].id;
	if (!found_command)
		ERROR(WRONG_COMMAND, the_asm->curr_line_n);
}

void	count_words_cmnd_line(t_asm *the_asm)
{
	int words;
	int i;

	words = 0;
	i = 0;
	while (i < MAX_WORDS_N)
	{
		if (the_asm->line_words[i][0] != '\0')
			words++;
		i++;
	}
	the_asm->e_c_l->words = words;
}

int		check_if_first_is_label(t_asm *the_asm, int words)
{
	if (the_asm->e_c_l->first_is_label)
	{
		check_label(the_asm, the_asm->line_words[0]);
		add_label(the_asm);
		the_asm->labels->cmnd_id_at = the_asm->e_c_l->id;
	}
	if (the_asm->e_c_l->first_is_label && words == 1)
	{
		the_asm->e_c_l->is_label_only = 1;
		the_asm->e_c_l->id = -the_asm->e_c_l->id;
		the_asm->labels->cmnd_id_at = -the_asm->e_c_l->id;
		the_asm->last_cmnd_id--;
		return (1);
	}
	return (0);
}

void	fill_exec_code_line_info(t_asm *the_asm, t_line **line)
{
	check_separators(the_asm, line);
	the_asm->e_c_l->has_arg_types_code =
	g_commands[the_asm->e_c_l->cmnd_code - 1].has_arg_types_code;
	the_asm->e_c_l->cmnd_line_size = 1 +
	the_asm->e_c_l->has_arg_types_code +
	the_asm->e_c_l->arg_size[0] +
	the_asm->e_c_l->arg_size[1] +
	the_asm->e_c_l->arg_size[2];
}

int		check_if_words_correct(t_asm *the_asm, t_line **line)
{
	int	words;
	int args_n;
	int shift;

	count_words_cmnd_line(the_asm);
	words = the_asm->e_c_l->words;
	if (check_if_first_is_label(the_asm, words))
		return (1);
	if ((the_asm->e_c_l->first_is_label && words == 2) ||
	(!the_asm->e_c_l->first_is_label && words == 1))
		ERROR(NO_ARGS, the_asm->curr_line_n);
	if (!the_asm->e_c_l->first_is_label && words == 5)
		ERROR(TOO_MANY_ARGS, the_asm->curr_line_n);
	define_cmnd_type(the_asm, the_asm->e_c_l->first_is_label);
	shift = (the_asm->e_c_l->first_is_label) ? 2 : 1;
	args_n = 0;
	while (args_n < words - shift)
	{
		check_args(the_asm, args_n, shift);
		args_n++;
	}
	if (args_n != g_commands[the_asm->e_c_l->cmnd_code - 1].arg_n)
		ERROR(WRONG_ARGS_N, the_asm->curr_line_n);
	fill_exec_code_line_info(the_asm, line);
	return (1);
}
