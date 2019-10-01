/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshvets <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:23:56 by mshvets           #+#    #+#             */
/*   Updated: 2019/09/29 14:25:07 by vkuhuk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H

# define COREWAR_VM_H

# include "../../libft/inc/libft.h"
# include "../../op.h"
# include <stdbool.h>

typedef struct 			s_mem
{
	uint8_t				type;
	void				*mem;
	void 				*current;
	size_t 				total_s;
}						t_mem;

typedef struct			s_carriage
{
	bool				carry;
	bool				live;
	uint8_t				op_id;
//	uint8_t				player;
	int					op_cycles;
	struct s_carriage	*next;
	size_t				position;
	size_t				lst_live_cycle;
	uint32_t			reg[REG_NUMBER];
	t_mem				arg[3];
}						t_carriage;

typedef struct			s_player
{
	uint8_t				id;
	char				*name;
	unsigned int		size;
	char				*comment;
	uint8_t				*code;
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
	size_t				cycles;
	uint8_t 			mem_f[MEM_SIZE + 1];
//	t_operation			op_tab[17];
	uint8_t				lst_live_plr;
	size_t 				cnt_live;
	size_t 				cycles_to_die;
	size_t				num_checks;
	size_t				dump_cycle; //-dump option
    size_t				pl_nbr; //number of player's
    uint8_t				verb_nbr; //verbosity option
}						t_general;


t_operation				op_tab[17];
void					ft_fight(t_general *data);
void					(*op_func[16])(t_general*, t_carriage*);
int						ft_add_end_carriage(t_carriage **lst_carriage, int player);
int						ft_add_carriage(t_carriage **lst_carriage, int player);
void					ft_add_player(t_player **lst_player, t_player *new);
void					ft_add_end_player(t_player **lst_player, t_player *new);
void					ft_del_player(t_player **lst_player);
void					ft_del_lst_carriage(t_carriage **lst_carriage);
void					ft_mem_clean(t_general *data);
bool					arg_read(t_general *data, t_carriage *carriage);
void					op_live(t_general *data, t_carriage *carriage);
void 					op_ld(t_general *data, t_carriage *carriage);
#endif
