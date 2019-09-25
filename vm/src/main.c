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

#include <fcntl.h>
#include "../inc/corewar_vm.h"
//#include "../inc/operation.h"

int main(void)
{
	t_general	data;
//	unsigned int i;
//	uint32_t 	l;
//	int32_t 	k;
//
//	i = -1;
//	l = -2;
//	k = -1;
//	k = l;


	ft_memset(&data, 0, sizeof(data));

	{
		int fd = open("/Users/mshvets/Desktop/Corewar/maptest", O_RDONLY);
		int j = 0, ret = read(fd, &data.mem_f, 4096);
		while ( j !=  ret)
		{
			ft_printf("%02.2X", data.mem_f[j++]);
			j % 2 ? 0 : ft_printf(" ");
		}
	}

//	ft_add_carriage(&data.head_c, 5);
//	data.head_c->live = 1;
//	ft_add_carriage(&data.head_c, 1);
//	ft_add_carriage(&data.head_c, 2);
//	data.head_c->live = 1;
//	ft_add_carriage(&data.head_c, 3);
//	ft_add_carriage(&data.head_c, 4);
//	data.head_c->live = 1;
//	ft_check_live_carriage(&data);
//	data.head_c->op_id = data.mem_f[0];
//	ft_fight(&data);
//	arg_read(&data, data.head_c);
	ft_mem_clean(&data);
	return(0);
}
