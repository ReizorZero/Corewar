/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:31:41 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:31:43 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void	write_line_to_list(t_asm *the_asm, char *s)
{
	if (!the_asm->lines)
		the_asm->lines = new_line(s);
	else
	{
		the_asm->lines->next = new_line(s);
		the_asm->lines = the_asm->lines->next;
	}
	if (!the_asm->lines_top)
		the_asm->lines_top = the_asm->lines;
}

void	add_cmnd_line(t_asm *the_asm)
{
	if (!the_asm->e_c_l)
		the_asm->e_c_l = new_exec_code_line(the_asm->last_cmnd_id);
	else
	{
		the_asm->e_c_l->next = new_exec_code_line(the_asm->last_cmnd_id);
		the_asm->e_c_l = the_asm->e_c_l->next;
	}
	if (!the_asm->e_c_l_top)
		the_asm->e_c_l_top = the_asm->e_c_l;
	the_asm->last_cmnd_id++;
}

void	add_label(t_asm *the_asm)
{
	if (!the_asm->labels)
		the_asm->labels = new_label(the_asm->line_words[0]);
	else
	{
		the_asm->labels->next = new_label(the_asm->line_words[0]);
		the_asm->labels = the_asm->labels->next;
	}
	if (!the_asm->labels_top)
		the_asm->labels_top = the_asm->labels;
}

void	add_garbage(t_asm *the_asm, void *ptr)
{
	if (!the_asm->g)
		the_asm->g = new_garbage(ptr);
	else
	{
		the_asm->g->next = new_garbage(ptr);
		the_asm->g = the_asm->g->next;
	}
	if (!the_asm->top_g)
		the_asm->top_g = the_asm->g;
}
