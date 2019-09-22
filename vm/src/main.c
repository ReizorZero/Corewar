/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:11:46 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/21 14:11:48 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/corewar_vm.h"
#include "../inc/operation.h"

int main(void)
{

	t_general	data;

	ft_memset(&data, 0, sizeof(data));
//	if (op_tab[0].id == 1)
//		ft_printf("Norm - %s;\n", op_tab[5].description);
	ft_mem_clean(&data);
	return(0);
}
