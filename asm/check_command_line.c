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
	while (w_i < MAX_WORDS_N)//CHANGE THIS WONDERFUL MAGIC NUMBER TO DEFINE FROM ASM.H DEFINE
	{
		if (w_i == 0)
		{
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
				i++;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != LABEL_CHAR)//FIRST WORD: LABEL OR COMMAND
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
			while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
				i++;
			met_sep = 0;
			start = i;
			len = 0;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//THIRD WORD: ARG_1 OR ARG_2
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
				ERROR(TOO_MANY_SEPARATORS);
			if (len == 0 && met_sep == 1)
			{
				while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
					i++;
				start = i;
				len = 0;
				while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//THE WORD ITSELF
				{
					len++;
					i++;
				}
				if (s[i] == SEPARATOR_CHAR)
					i++;
				if (s[i] == SEPARATOR_CHAR)
					ERROR(TOO_MANY_SEPARATORS);
			}
		}
		the_asm->line_words[w_i] = ft_strsub(s, start, len);
		w_i++;
	}
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
		ERROR(WRONG_SMBLS_AT_END);
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
			ERROR(LABEL_WRONG_CHAR);
		i++;
	}
	// if (s[0] == LABEL_CHAR)
	// 	ERROR(LABEL_CHAR_POSITON);
	return (1);
	//the_asm->exec_code_size = 0;//del this line later
}

void	check_if_words_correct(t_asm *the_asm)
{
	if (ft_strchr(the_asm->line_words[0], LABEL_CHAR))
	{
		//printf("\tFIRST WORD IS A LABEL\n");
		check_label(the_asm->line_words[0]);
	}
	else
	{
		int i = 0;
		int found_command = 0;
		while (i < 16)
		{
			if (!ft_strcmp(the_asm->line_words[0], commands[i].name))
			{
				printf("\t%s\n", commands[i].name);
				found_command = 1;
			}
			i++;
		}
		if (!found_command)
			ERROR(WRONG_COMMAND);
		//exit(0);
		//printf("\tFIRST WORD IS A COMMAND\n");
	}
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