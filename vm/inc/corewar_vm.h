/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:23:56 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/21 12:23:59 by mshvets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H

# define COREWAR_VM_H

#include "../../libft/inc/libft.h"
#include "../../op.h"

typedef struct	s_carriage
{
	int					position;
	uint8_t				carry;
	uint8_t				player;
	unsigned int		reg[16];
	uint8_t				live;
	uint8_t				command;
	int					cycles;
	struct s_carriage	*next;
}						t_carriage;

int						ft_add_end_carriage(t_carriage **lst_carriage, int player);
int						ft_add_carriage(t_carriage **lst_carriage, int player);
#endif
