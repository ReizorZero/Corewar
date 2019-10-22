/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:31:59 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:32:01 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "../libft/inc/libft.h"
# include <fcntl.h>

# define _ERROR(X, Y, Z) {ft_printf(X, Y, Z);exit(1);}
# define ERROR(X, Y) {ft_printf(X, Y);exit(1);}
# define ERROR_(X) {ft_printf(X);exit(1);}
# define USAGE(X, Y) {ft_printf(X);ft_printf(Y);exit(1);}

# define USAGE_INFO_1 "Usage: ./asm <sourcefile.s>\n"
# define USAGE_INFO_2 "\t(Note that only one file should be passed to input).\n"

# define ALLOCATE_MEM_ERR "Error. Failed to allocate memory: struct %s.\n"

# define TOO_MANY_FILES "Too many files. Enter only one file at a time.\n"
# define NO_FILE_NAME "File name is missing.\n"
# define NO_FILE_EXTENSION "File extension is missing.\n"
# define WRONG_FILE_EXTENSION "File extension is wrong.\n"

# define ERROR_OPEN_FILE "Error. Unable to open file %s\n"
# define ERROR_CLOSE_FILE "Error. Unable to close file %s\n"

# define NO_NAME_AT_ALL "No champion name.\n"
# define NO_COMMENT_AT_ALL "No champion comment.\n"
# define NO_EXEC_CODE "No executable code.\n"
# define TOO_BIG_EXEC_CODE "Executable code size is too big.\n"
# define TOO_BIG_NAME_COMMENT "Champion name/comment is too big.\n"

# define KAVICHKI_NUMBER "Wrong number of \" symbols. (Line %i)\n"

# define NO_CHAMP_NAME "No champion name after .name (Line %i)\n"
# define EMPTY_CHAMP_NAME "Empty champion name. (Line %i)\n"
# define NAME_NOT_A_S ".name not at the beginning of file. (Line %i)\n"
# define NAME_TWICE ".name is duplicated. (Line %i)\n"
# define SMBLS_CHAMP_NAME "Wrong symbols after champion name. (Line %i)\n"
# define SYMBOLS_CMND_NAME "Wrong symbols before/after .name (Line %i)\n"
# define CLSNG_QT_CHAMP_NAME "No closing quote for champion name. (Line %i)\n"

# define NO_COMMENT "No comment after .comment (Line %i)\n"
# define EMPTY_COMMENT "Empty champion comment. (Line %i)\n"
# define COMMENT_NOT_A_S ".comment not at the beginning of file. (Line %i)\n"
# define COMMENT_TWICE ".comment is duplicated. (Line %i)\n"
# define SYMBOLS_COMMENT "Should't be any symbols after comment. (Line %i)\n"
# define SYMBOLS_CMND_COMMENT "Wrong symbols before/after .comment (Line %i)\n"
# define NO_CLSNG_QT_COMMENT "No closing quote for comment. (Line %i)\n"

# define LABEL_WRONG_CHAR "Label contains wrong char. (Line %i)\n"
# define EMPTY_LABEL "Label name missing. (Line %i)\n"
# define NO_SUCH_LABEL "Label \'%s\' doesn't exist. (Line %i)\n"

# define MANY_SEPARATORS "Found 2 or more separator char in a row. (Line %i)\n"
# define WRONG_N_SEPARATORS "Wrong number of separator chars. (Line %i)\n"
# define SEPARATOR_AFTER_LABEL "Separator char after label. (Line %i)\n"
# define SEPARATOR_AFTER_CMND "Separator char after command. (Line %i)\n"

# define WRONG_SMBLS_AT_END "Wrong symbols at the end of the line. (Line %i)\n"

# define WRONG_COMMAND "Wrong command. (Line %i)\n"
# define NO_ARGS "No arguments after command. (Line %i)\n"
# define TOO_MANY_ARGS "Too many arguments after command. (Line %i)\n"
# define WRONG_ARGS_N "Wrong number of arguments. (Line %i)\n"
# define WRONG_ARG_SNTX "Wrong argument syntax. (Line %i)\n"
# define WRONG_ARG_TYPE "Wrong argument %i type. (Line %i)\n"
# define INCORRECT_REG "Registry number is incorrect. (Line %i)\n"

# define MAX_WORDS_N 5
# define COMMANDS_N 16

typedef struct		s_commands_info
{
	int		id;
	char	*name;
	int		t_dir_size;
	int		has_arg_types_code;
	int		arg_n;
	int		arg_types[3][3];
}					t_commands_info;

typedef struct		s_exec_code_line
{
	int							id;
	int							cmnd_code;
	int							arg_code[3];
	int							arg_value[3];
	int							arg_size[3];
	int							cmnd_line_size;
	int							first_is_label;
	int							is_label_only;
	int							has_label_arg;
	int							label_arg_index[3];
	char						**label_arg_value;
	int							words;
	int							has_arg_types_code;
	struct s_exec_code_line		*next;
}					t_exec_code_line;

typedef struct		s_label
{
	char			*name;
	int				cmnd_id_at;
	struct s_label	*next;
}					t_label;

typedef struct		s_line
{
	struct s_line	*next;
	char			*str;
}					t_line;

typedef struct		s_garbage
{
	void				*ptr;
	struct s_garbage	*next;
}					t_garbage;

typedef struct		s_asm
{
	int					fd;
	char				*dot_s_name;
	char				*dot_s_file_name;
	char				*champion_name;
	char				*champion_comment;
	int					exec_code_size;
	t_exec_code_line	*e_c_l;
	t_exec_code_line	*e_c_l_top;
	t_line				*lines;
	t_line				*lines_top;
	char				**line_words;
	t_label				*labels;
	t_label				*labels_top;
	int					curr_line_n;
	int					curr_w_i;
	int					curr_start;
	int					curr_len;
	int					last_cmnd_id;
	t_garbage			*g;
	t_garbage			*top_g;
}					t_asm;

t_commands_info		g_commands[16];

void				check_asm_input(int argc, char **argv, t_asm *the_asm);

int					read_from_dot_s(t_asm *the_asm);
void				close_file(int fd, char *filename);
void				parse_lines(t_asm *the_asm);
void				check_name(t_asm *the_asm, t_line **line);
int					check_name_cmnd_tag(t_asm *the_asm, char *s, int i);
int					anything_after_dot_name(t_asm *the_asm, char *s);
void				check_text_comment(char **s);
int					found_closing_quote_name(t_asm *the_asm);
int					count_kavichki(char *s);
void				check_comment(t_asm *the_asm, t_line **line);
int					check_comment_cmnd_tag(t_asm *the_asm, char *s, int i);
int					anything_after_dot_comment(t_asm *the_asm, char *s);
void				check_symbols_at_end_comment(t_asm *the_asm, char *s);
void				check_comment_char_case(t_asm *the_asm, char *s);
void				check_text_comment(char **s);
void				check_command_line(t_asm *the_asm, t_line **line);

void				write_cmnd_line_words(t_asm *the_asm, t_line **line);
int					manage_separators(t_asm *a, char *s, int i, int j);
void				check_symbols_at_end(t_asm *the_asm, char *s, int i);
int					operate_first_word(t_asm *the_asm, char *s, int i);
int					manage_separators_again(t_asm *the_asm, char *s, int i);
int					manage_separators_last(t_asm *a, char *s, int i, int j);
int					operate_label_char(t_asm *a, char *s, int i, int *j);
int					check_if_words_correct(t_asm *the_asm, t_line **line);
int					go_past_label(char *s, int i);
int					go_past_command(t_asm *the_asm, char *s, int i);
int					go_past_arg_1(t_asm *the_asm, char *s, int i, int words);
int					go_past_arg_2(t_asm *the_asm, char *s, int i, int words);
int					go_past_arg_3(t_asm *the_asm, char *s, int i, int words);
void				check_separators(t_asm *the_asm, t_line **line);
int					check_label(t_asm *the_asm, char *s);
void				check_args(t_asm *the_asm, int i, int shift);
void				check_cmnd_correspondance(t_asm *the_asm, int arg_index);

void				write_to_dot_cor(t_asm *the_asm);
void				arg_cases(int *arg_code, char *rez, int j, int i);
int					convert_bit_to_int(char *bit);
void				write_null_in_file(t_asm *the_asm, int i);
void				out_in_file(int nbr, int size, t_asm *the_asm);

void				write_line_to_list(t_asm *the_asm, char *s);
void				add_cmnd_line(t_asm *the_asm);
void				add_label(t_asm *the_asm);
int					get_label_arg_value(t_asm *the_asm, char *label_name);
void				fill_labels_args(t_asm *the_asm);

void				add_garbage(t_asm *the_asm, void *ptr);

t_asm				*new_asm(void);
t_line				*new_line(char *str);
t_exec_code_line	*new_exec_code_line(int id);
t_label				*new_label(char *name);
t_garbage			*new_garbage(void *ptr);

#endif
