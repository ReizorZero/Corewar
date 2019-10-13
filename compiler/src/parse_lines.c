/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:13 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:44:16 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	count_exec_size(t_asm *the_asm)
{
	t_exec_code_line *ecl;

	ecl = the_asm->e_c_l_top;
	while (ecl)
	{
		the_asm->exec_code_size += ecl->cmnd_line_size;
		ecl = ecl->next;
	}
	if (the_asm->exec_code_size == 0)
		ERROR_(NO_EXEC_CODE);
	if (the_asm->exec_code_size > CHAMP_MAX_SIZE)
		ERROR_(TOO_BIG_EXEC_CODE);
}

void	operate_name(t_asm *the_asm, t_line *lines)
{
	if (the_asm->e_c_l_top)
		ERROR(NAME_NOT_A_S, the_asm->curr_line_n);
	if (!the_asm->champion_name)
		check_name(the_asm, &lines);
	else
		ERROR(NAME_TWICE, the_asm->curr_line_n);
}

void	operate_comment(t_asm *the_asm, t_line *lines)
{
	if (the_asm->e_c_l_top)
		ERROR(COMMENT_NOT_A_S, the_asm->curr_line_n);
	if (!the_asm->champion_comment)
		check_comment(the_asm, &lines);
	else
		ERROR(COMMENT_TWICE, the_asm->curr_line_n);
}

void	parse_lines(t_asm *the_asm)
{
	t_line *lines;

	lines = the_asm->lines_top;
	while (lines)
	{
		if (ft_strstr(lines->str, NAME_CMD_STRIN))
			operate_name(the_asm, lines);
		else if (ft_strstr(lines->str, COMMENT_CMD_STRING))
			operate_comment(the_asm, lines);
		else
			check_command_line(the_asm, &lines);
		the_asm->curr_line_n++;
		lines = lines->next;
	}
	if (!the_asm->champion_name)
		ERROR_(NO_NAME_AT_ALL);
	if (!the_asm->champion_comment)
		ERROR_(NO_COMMENT_AT_ALL);
	if (!the_asm->e_c_l_top)
		ERROR_(NO_EXEC_CODE);
	fill_labels_args(the_asm);
	count_exec_size(the_asm);
}
