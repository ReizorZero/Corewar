/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuhuk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:55:55 by vkuhuk            #+#    #+#             */
/*   Updated: 2019/10/08 09:55:57 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/corewar_vm.h"

void	err_read_less(t_general *data, char *file)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(" is too small to be a champion", 2);
	ft_mem_clean(data);
	exit(1);
}

void	err_cant_read(t_general *data, char *file)
{
	ft_putstr_fd("Can't read source file ", 2);
	ft_putendl_fd(file, 2);
	ft_mem_clean(data);
	exit(1);
}

void	err_diff_size(t_general *data, char *file)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(" has a code size that differ from what its header says", 2);
	ft_mem_clean(data);
	exit(1);
}

void	err_too_large(t_general *data, int size, char *file)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(" has too large a code (", 2);
	ft_putnbr_fd(size, 2);
	ft_putendl_fd(" > 682 bytes)", 2);
	ft_mem_clean(data);
	exit(1);
}

void	err_magic_header(t_general *data, char *file)
{
	ft_putstr_fd("Error: File ", 2);
	ft_putstr_fd(file, 2);
	ft_putendl_fd(" has an invalid header", 2);
	ft_mem_clean(data);
	exit(1);
}
