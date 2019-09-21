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

typedef struct			s_carriage
{
	int					position;
	uint8_t				carry;
	uint8_t				player;
	unsigned int		reg[REG_NUMBER];
	uint8_t				live;
	uint8_t				command;
	int					cycles;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_player
{
	uint8_t				id;
	header_t			inf;
//				or
//	char				*name;
//	char 				*comment;
//	int 				size;
	char 				*code;
	struct s_player		*next;
}						t_player;

typedef struct 			s_general
{
	t_player			*head_p;
//					or
//	t_player			head_p[MAX_PLAYERS];
	t_carriage			*head_c;
	char 				mem[MEM_SIZE + 1];
}						t_general;


int						ft_add_end_carriage(t_carriage **lst_carriage, int player);
int						ft_add_carriage(t_carriage **lst_carriage, int player);
void					ft_add_player(t_player **lst_player, t_player *new);
void					ft_add_end_player(t_player **lst_player, t_player *new);
void					ft_del_player(t_player **lst_player);
void					ft_del_carriage(t_carriage **lst_carriage);
void					ft_mem_clean(t_general *data);
#endif
