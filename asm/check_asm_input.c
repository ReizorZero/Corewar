/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_asm_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:32:47 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:32:49 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
//REWORK @ file.3.s
void	check_arguments_n(int argc)
{
	if (argc < 2)
		USAGE(USAGE_INFO_1, USAGE_INFO_2);
	if (argc > 2)
		ERROR_(TOO_MANY_FILES);
}

void	check_file_name(char *filename)
{
	if (filename[0] == '\0')
		ERROR_(NO_FILE_NAME);
}

void	check_file_extension(char *filename, t_asm *the_asm)
{
	int i;

	if (!ft_strchr(filename, '.'))
		ERROR_(NO_FILE_EXTENSION);
	if (filename[0] == '.' || filename[0] == '\0')
		ERROR_(NO_FILE_NAME);
	i = 0;
	while (filename[i] != '\0' && filename[i] != '.')
		i++;
	the_asm->dot_s_name = ft_strsub(filename, 0, i);
	i++;
	if (filename[i] == '\0')
		ERROR_(NO_FILE_EXTENSION);
	if (filename[i] != 's' || filename[i + 1] != '\0')
		ERROR_(WRONG_FILE_EXTENSION);
	the_asm->dot_s_file_name = ft_strdup(filename);
}

void	check_asm_input(int argc, char **argv, t_asm *the_asm)
{
	check_arguments_n(argc);
	check_file_name(argv[1]);
	check_file_extension(argv[1], the_asm);
}
