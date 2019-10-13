/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:43:53 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:43:55 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		main(int argc, char **argv)
{
	t_asm *the_asm;

	the_asm = new_asm();
	check_asm_input(argc, argv, the_asm);
	if (read_from_dot_s(the_asm))
		write_to_dot_cor(the_asm);
	ft_printf("Writing output program to %s.cor\n", the_asm->dot_s_name);
	return (0);
}
