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
	//ADD LABEL TO LIST
	//COUNT ITS BYTE_AT
	return (1);
}

int		get_label_byte_at(t_asm *the_asm, char *label_name, int cmnd_id)
{
	int byte_at;
	int label_id;
	t_exec_code_line *ecl;

	byte_at = 0;
	label_id = get_label_arg_value(the_asm, label_name);
	//printf("FOUND LABEL CORRESPONDING COMMAND ID = %i\n", label_id);
	printf("LABEL NAME IS... [%s]\n", label_name);
	printf("(label_id) LABEL POINTS AT CMND_LINE WITH ID = %i\n", label_id);
	printf("(cmnd_id) CMND_LINE WHERE WE GOT LABEL_ARG ID = %i\n", cmnd_id);
	ecl = the_asm->e_c_l_top;
	//>= case - ?
	if (label_id >= cmnd_id)
	{
		printf("\t\t\t\tCASE LABEL_ID >= CMND_ID\n");
		// while (ecl && ecl->id < label_id)
		// 	ecl = ecl->next;
		//while (ecl && ecl->id <= cmnd_id)
		while (ecl && ecl->id < cmnd_id)
			ecl = ecl->next;
		while (ecl && ecl->id < label_id)
		{
			printf("\t\tcurr size @ %i\n", ecl->cmnd_line_size);
			byte_at += ecl->cmnd_line_size;
			ecl = ecl->next;
		}
	}
	else
	{
		printf("\t\t\t\tCASE LABEL_ID < CMND_ID\n");
		while (ecl && ecl->id < label_id)
			ecl = ecl->next;
		while (ecl && ecl->id < cmnd_id)
		{
			//printf("\t\tcurr size @ %i\n", ecl->cmnd_line_size);
			byte_at += ecl->cmnd_line_size;
			ecl = ecl->next;
		}
		byte_at = -byte_at;
	}
	printf("\tBYTE_AT IS FOUND AND IS EQUAL TO... %i\n", byte_at);
	//printf("MEANWHILE, LABEL ID IS EQUAL TO... %i\n", label_id);
	return (byte_at);
}

int		get_label_arg_value(t_asm *the_asm, char *label_name)
{
	t_label *labels;
	int label_id;

	label_id = 0;
	labels = the_asm->labels_top;
	while (labels)
	{
		if (!ft_strcmp(label_name, labels->name))
		{
			label_id = labels->cmnd_id_at;
			break ;
		}
		labels = labels->next;
	}
	if (!label_id)
	{
		printf("Error. Label \'%s\' doesn't exist.\n", label_name);
		exit(0);
	}
	return (label_id);
}

void	fill_labels_args(t_asm *the_asm)
{
	t_exec_code_line *ecl;
	int i;

	printf("\n===============================================================================================\n");
	ecl = the_asm->e_c_l_top;
	while (ecl)
	{
		if (ecl->has_label_arg)
		{
			i = 0;
			while (i < 3)
			{
				if (ecl->label_arg_index[i] == 1)
				{
					//printf("\t\t\t\t\t\t\t\t\t\t===> we got label arg\n");
					ecl->arg_value[i] =
					get_label_byte_at(the_asm, ecl->label_arg_value[i], ecl->id);
				}
				i++;
			}
		}
		ecl = ecl->next;
	}
}