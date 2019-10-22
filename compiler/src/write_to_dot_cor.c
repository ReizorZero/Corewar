/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_dot_cor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:46 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:44:48 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

void			out_in_file(int nbr, int size, t_asm *the_asm)
{
	uint32_t		tmp;
	int				i;
	char			*res;

	if (size == 0)
		return ;
	tmp = (uint32_t)nbr;
	if (!(res = ft_memalloc(sizeof(char) * size)))
		exit(0);
	i = size;
	while (--i >= 0)
	{
		res[i] = tmp % 256;
		tmp /= 256;
	}
	write(the_asm->fd, res, size);
	add_garbage(the_asm, res);
}

char			*get_arg_types_code(t_asm *the_asm, int *arg_code)
{
	int		i;
	int		j;
	char	*rez;

	if (!(rez = ft_memalloc(sizeof(char) * 9)))
		exit(0);
	i = -1;
	j = 0;
	while (++i != 3)
	{
		arg_cases(arg_code, rez, j, i);
		j += 2;
	}
	rez[j] = '0';
	rez[j + 1] = '0';
	rez[j + 2] = '\0';
	add_garbage(the_asm, rez);
	return (rez);
}

void			write_cmnd_code(t_asm *the_asm)
{
	int					i;
	t_exec_code_line	*tmp;
	char				*arg_types_code;

	tmp = the_asm->e_c_l_top;
	while (tmp)
	{
		if (tmp->cmnd_code != 0)
		{
			out_in_file(tmp->cmnd_code, 1, the_asm);
			if (tmp->has_arg_types_code > 0)
			{
				arg_types_code = get_arg_types_code(the_asm, tmp->arg_code);
				out_in_file(convert_bit_to_int(arg_types_code), 1, the_asm);
			}
			i = -1;
			while (++i < 3)
				if (tmp->arg_size[i] != 0)
					out_in_file(tmp->arg_value[i], tmp->arg_size[i], the_asm);
		}
		tmp = tmp->next;
	}
	add_garbage(the_asm, arg_types_code);
}

int				get_dot_cor_fd(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ERROR(ERROR_OPEN_FILE, filename);
	return (fd);
}

void			write_to_dot_cor(t_asm *the_asm)
{
	int		j;
	char	*filename;

	filename = ft_strjoin(the_asm->dot_s_name, ".cor");
	add_garbage(the_asm, filename);
	the_asm->fd = get_dot_cor_fd(filename);
	out_in_file(COREWAR_EXEC_MAGIC, 4, the_asm);
	j = -1;
	while (the_asm->champion_name[++j] != '\0')
		out_in_file(the_asm->champion_name[j], sizeof(char), the_asm);
	write_null_in_file(the_asm, PROG_NAME_LENGTH - j);
	write_null_in_file(the_asm, 4);
	out_in_file(the_asm->exec_code_size, sizeof(int), the_asm);
	j = -1;
	while (the_asm->champion_comment[++j] != '\0')
		out_in_file(the_asm->champion_comment[j], sizeof(char), the_asm);
	write_null_in_file(the_asm, COMMENT_LENGTH - j);
	write_null_in_file(the_asm, 4);
	write_cmnd_code(the_asm);
	close_file(the_asm->fd, filename);
}
