#include "asm.h"
#include "commands.h"

void	write_words(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		start;
	int		len;
	int		met_sep;

	s = (*line)->str;
	i = 0;
	printf("[%s]\n", s);

	int w_i;
	w_i = 0;
	while (w_i < MAX_WORDS_N)
	{
		if (w_i == 0)
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)// && s[i] != DIRECT_CHAR)//SKIP BLANKS
				i++;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != LABEL_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)// && s[i] != DIRECT_CHAR)//FIRST WORD: LABEL OR COMMAND
			{
				len++;
				i++;
			}
			if (s[i] == LABEL_CHAR)
			{
				len++;
				i++;
			}
		}
		else
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)// && s[i] != DIRECT_CHAR)//SKIP BLANKS
				i++;
			met_sep = 0;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)// && s[i] != DIRECT_CHAR)//THIRD WORD: ARG_1 OR ARG_2
			{
				len++;
				i++;
			}
			if (s[i] == SEPARATOR_CHAR)
			{
				met_sep = 1;
				i++;
			}
			if (s[i] == SEPARATOR_CHAR)
				ERROR(MANY_SEPARATORS, 0);
			if (len == 0 && met_sep == 1)
			{
				while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t') && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)//SKIP BLANKS
					i++;
				start = i;
				len = 0;
				while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)//THE WORD ITSELF
				{
					len++;
					i++;
				}
				if (s[i] == SEPARATOR_CHAR)
					i++;
				if (s[i] == SEPARATOR_CHAR)
					ERROR(MANY_SEPARATORS, 0);
			}
		}
		the_asm->line_words[w_i] = ft_strsub(s, start, len);
		w_i++;
	}
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		ERROR(WRONG_SMBLS_AT_END, 0);
	//OUTPUT OF RECEIVED 5 WORDS -- DELETE LATER
	int k = 0;
	while (k < MAX_WORDS_N)
	{
		printf("\tWORD %i: [%s]\n", k + 1, the_asm->line_words[k]);
		k++;
	}
}

int		check_label(char *s)
{
	int i;
	int j;
	int is_match;

	i = 0;
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
			ERROR(LABEL_WRONG_CHAR, 0);
		i++;
	}
	// if (s[0] == LABEL_CHAR)
	// 	ERROR(LABEL_CHAR_POSITON);
	return (1);
	//the_asm->exec_code_size = 0;//del this line later
}

int		check_if_words_correct(t_asm *the_asm)
{
	int	words;
	int first_is_label;
	int i;
	int found_command;
	//int arg_type;

	words = 0;
	i = 0;
	while (i < MAX_WORDS_N)
	{
		if (the_asm->line_words[i][0] != '\0')
			words++;
		i++;
	}
	//printf("words: %i\n", words);
	first_is_label = 0;
	if (ft_strchr(the_asm->line_words[0], LABEL_CHAR))
	{
		//printf("\tFIRST WORD IS A LABEL\n");
		check_label(the_asm->line_words[0]);
		first_is_label = 1;
	}
	else
	{
		i = 0;
		found_command = 0;
		while (i < COMMANDS_N)
		{
			if (!ft_strcmp(the_asm->line_words[0], commands[i].name))
			{
				printf("\t%s\n", commands[i].name);
				found_command = 1;
			}
			i++;
		}
		if (!found_command)
			ERROR(WRONG_COMMAND, 0);
	}
	if (first_is_label)
	{
		if (words == 1)
			return (1);
		i = 0;
		found_command = 0;
		while (i < COMMANDS_N)
		{
			if (!ft_strcmp(the_asm->line_words[1], commands[i].name))
			{
				printf("\t%s\n", commands[i].name);
				found_command = 1;
			}
			i++;
		}
		if (!found_command)
			ERROR(WRONG_COMMAND, 0);
		i = 0;
		while (i < words - 2)
		{
			//printf("\targ[%i] ", i + 1);
			//CHECK ARGS AND DEFINE ARGS TYPE
			if (the_asm->line_words[i + 2][0] == 'r')
				printf("\targ[%i] - T_REG\n", i + 1);
			else if (the_asm->line_words[i + 2][0] == DIRECT_CHAR)
				printf("\targ[%i] - T_DIR\n", i + 1);
			else if (the_asm->line_words[i + 2][0] == '-' || ft_isdigit(the_asm->line_words[i + 2][0]) ||
			the_asm->line_words[i + 2][0] == LABEL_CHAR)
				printf("\targ[%i] - T_IND\n", i + 1);
			else
				ERROR(WRONG_ARG_SNTX, 0);
				//printf("che za @ %s\n", the_asm->line_words[i + 2]);
			i++;
		}
		//printf("\n");
	}
	else
	{
		if (words == 1)
			ERROR(NO_ARGS, 0);
		if (words == 5)
			ERROR(TOO_MANY_ARGS, 0);
		i = 0;
		while (i < words - 1)
		{
			//printf("\targ[%i] ", i + 1);
			//CHECK ARGS AND DEFINE ARGS TYPE
			if (the_asm->line_words[i + 1][0] == 'r')
				printf("\targ[%i] - T_REG\n", i + 1);
			else if (the_asm->line_words[i + 1][0] == DIRECT_CHAR)
				printf("\targ[%i] - T_DIR\n", i + 1);
			else if (the_asm->line_words[i + 1][0] == '-' || ft_isdigit(the_asm->line_words[i + 1][0]) ||
			the_asm->line_words[i + 1][0] == LABEL_CHAR)
				printf("\targ[%i] - T_IND\n", i + 1);
			else
				ERROR(WRONG_ARG_SNTX, 0);
				//printf("che za @ %s\n", the_asm->line_words[i + 2]);
			i++;
		}
		
	}
	return (1);
}

int		is_empty_or_comment(t_line **line)
{
	int		i;
	char	*s;

	i = 0;
	s = (*line)->str;
	if (s[0] == '\0')
		return (1);
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	check_command_line(t_asm *the_asm, t_line **line)
{
	if (!is_empty_or_comment(line))
	{
		write_words(the_asm, line);
		check_if_words_correct(the_asm);//REPEAT WITH OTHER WORDS AS WELL
	//ALSO DEFINE ARGS TYPE AND CHECK IF THEY ARE VALID
	}
}