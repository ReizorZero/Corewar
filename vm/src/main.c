/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:11:46 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/30 15:13:13 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/corewar_vm.h"
//#include "../inc/operation.h"

void print_mem(t_general *data)
{
    int i;
    int j;

    i = 0;
    while (i < MEM_SIZE)
    {
        ft_printf("%.4p : ", i);
        j = 0;
        while (j < 64)//32!
        {
            ft_printf("%.2x ", data->mem_f[i + j]);
            j++;
        }
        ft_printf("\n");
        i += 64;//32!
    }
}

int main(int argc, char **argv)
{
	t_general	data;

	ft_memset(&data, 0, sizeof(data));
	if (argc > 1)
	{
		data.dump_cycle = -1;
		args_checking(&data, argc, argv);
	}
	else
		usage_msg();
	//{
	//	int fd = open("/Users/mshvets/Desktop/Corewar/maptest", O_RDONLY);
	//	int j = 0, ret = read(fd, &data.mem_f, 4096);
	//	while ( j !=  ret)
	//	{
	//		ft_printf("%02.2x", data.mem_f[j++]);
	//		j % 2 ? 0 : ft_printf(" ");
	//	}
	//}

//	ft_add_carriage(&data.head_c, 5);
//	data.head_c->live = 1;
	//ft_add_carriage(&data.head_c, 1);
//	ft_add_carriage(&data.head_c, 2);
//	data.head_c->live = 1;
//	ft_add_carriage(&data.head_c, 3);
	//ft_add_carriage(&data.head_c, 4);
//	data.head_c->live = 1;
//	ft_check_live_carriage(&data);
//	data.head_c->op_id = data.mem_f[0];
	ft_fight(&data);
//	arg_read(&data, data.head_c);
//	ft_mem_clean(&data);
	return(0);
}
