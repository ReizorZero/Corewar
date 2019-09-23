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

# include "../../libft/inc/libft.h"
# include "../../op.h"
# include <stdbool.h>

typedef struct			s_carriage
{
	size_t				position;
	bool				carry;
	uint8_t				player;
	uint32_t			reg[REG_NUMBER];
	bool				live;
	uint8_t				operation_id;
	int					cycles;
	struct s_carriage	*next;
}						t_carriage;

typedef struct			s_player
{
	uint8_t				id;
	t_header			inf;
	char 				*code;
	struct s_player		*next;
}						t_player;

typedef struct			s_operation
{
	char 				name[6];
	uint8_t				n_arg;
	uint8_t				arg[3];
	uint8_t				id;
	int 				cycles;
	char 				descr[50];
	bool				octal;
	bool				label;
}						t_operation;

typedef struct 			s_general
{
	t_player			*head_p;
//					or
//	t_player			head_p[MAX_PLAYERS];
	t_carriage			*head_c;
	t_operation			op_tab[17];
	char 				mem[MEM_SIZE + 1];
	size_t				cycles;
}						t_general;

typedef struct 			s_mem
{
	void				*mem;
	size_t 				total_s;
	size_t 				current;
}						t_mem;

t_operation				op_tab[17];
void					(*op_func[16])(t_carriage*, t_mem*, t_mem*, t_mem*);
int						ft_add_end_carriage(t_carriage **lst_carriage, int player);
int						ft_add_carriage(t_carriage **lst_carriage, int player);
void					ft_add_player(t_player **lst_player, t_player *new);
void					ft_add_end_player(t_player **lst_player, t_player *new);
void					ft_del_player(t_player **lst_player);
void					ft_del_carriage(t_carriage **lst_carriage);
void					ft_mem_clean(t_general *data);
void					op_live(t_general *data);
#endif
