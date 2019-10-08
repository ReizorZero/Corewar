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
# include "op.h"
# include <stdbool.h>
# include <fcntl.h>


typedef struct 			s_mem
{
	uint8_t				type;
	void				*mem;
	void 				*current;
	size_t 				size;
	int16_t				IND_pntr;
	void				*mem_end;
}						t_mem;

typedef struct			s_carriage
{
	bool				carry;
	bool				live;
	uint8_t				op_id;
//	uint8_t				player;
	int					op_cycles;
	size_t				nbr;
	size_t				position;
	size_t				position_tmp;
	size_t				lst_live_cycle;
	uint32_t			reg[REG_NUMBER];
	t_mem				arg[3];
	struct s_carriage	*next;
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
//	char 				name[6];
	char 				*name;
	uint8_t				n_arg;
	uint8_t				arg[3];
	uint8_t				id;
	int 				cycles;
//	char 				descr[50];
	char 				*descr;
	bool				octal;
	bool				label;
}						t_operation;

typedef struct 			s_general
{
	t_player			*head_p;
//					or
//	t_player			head_p[MAX_PLAYERS];
	t_carriage			*head_c;
	uint8_t 			mem_f[MEM_SIZE + 1];
	uint8_t				lst_live_plr;
	int					cycles_total;
	int					cycles_tmp;
	int 				cycles_to_die;
	size_t 				cnt_live;
	size_t				num_checks;
	size_t				num_carriage;
	int					dump_cycle; //-dump option
    int					pl_nbr; //number of player's
    uint8_t				verb_nbr; //verbosity option
}						t_general;


t_operation				op_tab[17];
void					ft_fight(t_general *data);
void					(*op_func[16])(t_general*, t_carriage*);
int 					ft_add_end_carriage(t_carriage **lst_carriage, int player, size_t nbr);
int 					ft_add_carriage(t_carriage **lst_carriage, int player, size_t nbr);
t_carriage				*ft_new_carriage(int player, size_t nbr);
void					ft_add_player(t_player **lst_player, t_player *new);
void					ft_add_end_player(t_player **lst_player, t_player *new);
void					ft_del_player(t_player **lst_player);
void					ft_del_lst_carriage(t_carriage **lst_carriage);
void					ft_mem_clean(t_general *data);
bool					arg_read(t_general *data, t_carriage *carriage, size_t arg_cod);
void					read_dir(t_general *data, t_mem *arg, size_t position, size_t size);
void					memory_cpy(t_mem *dest, t_mem src);
void					op_live(t_general *data, t_carriage *carriage);
void 					op_ld(t_general *data, t_carriage *carriage);
void 					op_and(t_general *data, t_carriage *carriage);
void 					op_or(t_general *data, t_carriage *carriage);
void 					op_xor(t_general *data, t_carriage *carriage);
void 					op_st(t_general *data, t_carriage *carriage);
void 					op_add(t_general *data, t_carriage *carriage);
void 					op_sub(t_general *data, t_carriage *carriage);
void 					op_zjmp(t_general *data, t_carriage *carriage);
void 					op_ldi(t_general *data, t_carriage *carriage);
void 					op_sti(t_general *data, t_carriage *carriage);
void 					op_fork(t_general *data, t_carriage *carriage);
void 					op_lld(t_general *data, t_carriage *carriage);
void 					op_lldi(t_general *data, t_carriage *carriage);
void 					op_lfork(t_general *data, t_carriage *carriage);
void 					op_aff(t_general *data, t_carriage *carriage);
t_player				*get_by_id(t_general *data, uint8_t id);
void					print_mem(t_general *data);
uint32_t				reverse_32bits(uint32_t pInt);
uint16_t				reverse_16bits(uint16_t pInt);
uint32_t				get_val32bit(t_mem src);
uint16_t				get_val16bit(t_mem src);
void					args_checking(t_general *data, int argc, char **argv);
char					*check_comment(int fd, int len, char *file);
uint8_t					*check_players_code(int fd, int len, char *file);
void					before_start(t_general *data);
t_player				*player(t_general *data, char **argv, int *i, int id);
int						is_free_id(t_general *data, uint8_t id);
void					check_n_id(t_general *data);
void					check_id(t_general *data);
void					usage_msg(void);
void					error_msg(char *msg);
void					introducing(t_general *data);
int						get_num_reg(t_carriage *carriage, int n);
void					show_pc_movement(t_general data, t_carriage carriage);
void					print_winner(t_general *data);
void					ft_check_live_carriage(t_general *data);
void					start_new_op(t_general *data, t_carriage *crg);
void					set_new_cycle(t_general *data);
void					err_read_less(char *file);
void					err_cant_read(char *file);
void					err_diff_size(char *file);
void					err_too_large(char *file, int size);
void					err_magic_header(char *file);

#endif
