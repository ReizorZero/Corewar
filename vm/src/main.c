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

int main(void)
{
	t_carriage *lst_carriage;

	lst_carriage = NULL;
	ft_add_end_carriage(&lst_carriage, 2);
	ft_add_carriage(&lst_carriage, 1);
	ft_add_end_carriage(&lst_carriage, 3);
	ft_add_carriage(&lst_carriage, 4);
	ft_add_end_carriage(&lst_carriage, 5);

	return(0);
}
