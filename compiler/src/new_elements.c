/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:03 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:44:05 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

t_asm				*new_asm(void)
{
	t_asm *the_asm;

	the_asm = (t_asm*)malloc(sizeof(t_asm));
	if (!the_asm)
		ERROR(ALLOCATE_MEM_ERR, "t_asm");
	ft_bzero(the_asm, sizeof(t_asm));
	the_asm->curr_line_n = 1;
	the_asm->last_cmnd_id = 1;
	the_asm->line_words = (char**)malloc(sizeof(char*) * MAX_WORDS_N);
	return (the_asm);
}

t_line				*new_line(char *str)
{
	t_line *the_line;

	the_line = (t_line*)malloc(sizeof(t_line));
	if (!the_line)
		ERROR(ALLOCATE_MEM_ERR, "t_line");
	the_line->next = NULL;
	the_line->str = ft_strdup(str);
	return (the_line);
}

t_exec_code_line	*new_exec_code_line(int id)
{
	t_exec_code_line *exec_code_line;

	exec_code_line = (t_exec_code_line*)malloc(sizeof(t_exec_code_line));
	if (!exec_code_line)
		ERROR(ALLOCATE_MEM_ERR, "t_exec_code_line");
	ft_bzero(exec_code_line, sizeof(t_exec_code_line));
	exec_code_line->id = id;
	exec_code_line->label_arg_value = (char**)malloc(sizeof(char*) * 3);
	return (exec_code_line);
}

t_label				*new_label(char *name)
{
	t_label *label;

	label = (t_label*)malloc(sizeof(t_label));
	if (!label)
		ERROR(ALLOCATE_MEM_ERR, "t_label");
	label->name = ft_strsub(name, 0, ft_strlen(name) - 1);
	label->cmnd_id_at = 0;
	label->next = NULL;
	return (label);
}

t_garbage			*new_garbage(void *ptr)
{
	t_garbage *garbage;

	garbage = (t_garbage*)malloc(sizeof(garbage));
	if (!garbage)
		ERROR(ALLOCATE_MEM_ERR, "t_garbage");
	garbage->ptr = ptr;
	garbage->next = NULL;
	return (garbage);
}
