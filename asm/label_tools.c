#include "asm.h"

int		check_label(t_asm *the_asm, char *s)
{
	int i;
	int j;
	int is_match;

	i = 0;
	if (s[i] == LABEL_CHAR)
		ERROR(EMPTY_LABEL, the_asm->curr_line_n);
	while (s[i] != '\0' && s[i] != LABEL_CHAR)
	{
		j = 0;
		is_match = 0;
		while (LABEL_CHARS[j] != '\0')
		{
			if (s[i] == LABEL_CHARS[j])
				is_match = 1;
			j++;
		}
		if (is_match == 0)
			ERROR(LABEL_WRONG_CHAR, the_asm->curr_line_n);
		i++;
	}
	return (1);
}

int		count_label_byte_at(t_asm *the_asm)
{
	int i;
	int id;
	int byte_at;
	t_exec_code_line *cmnd_line;

	i = 0;
	id = the_asm->last_cmnd_id;
	byte_at = 0;
	cmnd_line = the_asm->e_c_l_top;
	while (i < id && cmnd_line)
	{
		byte_at += cmnd_line->cmnd_size;
		cmnd_line = cmnd_line->next;//AVOID SEGV HERE
		i++;
	}
	return (byte_at);
}