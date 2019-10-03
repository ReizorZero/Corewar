#include "asm.h"
#include "commands.h"

int		check_label(t_asm *the_asm, char *s)
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
	if (s[0] == LABEL_CHAR)
		ERROR(LABEL_CHAR_POSITON);
	return (1);
	the_asm->exec_code_size = 0;//del this line later
}

int		check_command(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(s, commands[i].name))
			return (commands[i].id);
		i++;
	}
	printf("***%s\n", s);
	ERROR(WRONG_COMMAND);
	the_asm->exec_code_size = 0;//del this line later
}

void	write_all_tokens(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		len;
	int		start;
	int		t_i;
	
	s = (*line)->str;
	i = 0;
	printf("[%s]\n", s);
	t_i = 0;

	while (t_i < MAX_TOKENS_N)
	{
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
			i++;
		start = i;
		len = 0;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
		{
			i++;
			len++;
		}
		the_asm->line_tokens[t_i] = ft_strsub(s, start, len);
		//printf("\tWORD %i: [%s]\n", t_i + 1, the_asm->line_tokens[t_i]);
		t_i++;
	}
}

int		separate_2_0(t_asm *the_asm, int t_i)
{
	the_asm->exec_code_size = 0;
	printf("case [r1,r2,r3]\n");
	return (t_i + 1);
}

int		separate_2_1(t_asm *the_asm, int t_i)
{
	the_asm->exec_code_size = 0;
	printf("case [r1,r2,]\n");
	return (t_i + 1);
}

int		separate_1_0(t_asm *the_asm, int t_i)
{
	the_asm->exec_code_size = 0;
	printf("case [r1,r2]\n");
	return (t_i + 1);
}

int		separate_1_1(t_asm *the_asm, int t_i)
{
	the_asm->line_tokens[t_i] = ft_strsub(the_asm->line_tokens[t_i], 0,
	ft_strlen(the_asm->line_tokens[t_i]) - 1);
	the_asm->line_tokens[t_i + 2] = ft_strdup(the_asm->line_tokens[t_i + 1]);
	the_asm->line_tokens[t_i + 1] = ft_strdup(",");
	//printf("case [r1,]\n");
	return (t_i + 1);
}

int		separate_tokens(t_asm *the_asm, int t_i)//, t_line **line)
{
	int i;
	int seps;
	int seps_at_end;

	i = 0;
	seps = 0;
	seps_at_end = 0;
	while (the_asm->line_tokens[t_i][i] != '\0')
	{
		if (the_asm->line_tokens[t_i][i] == SEPARATOR_CHAR)
			seps++;
		i++;
	}
	//CHECK FUCKED UP CASES LIKE r1,, AND SO ONE
	if (the_asm->line_tokens[t_i][i - 1] == SEPARATOR_CHAR)
		seps_at_end = 1;
	if (seps == 2 && !seps_at_end)
		return (separate_2_0(the_asm, t_i));
	else if (seps == 2 && seps_at_end)
		return (separate_2_1(the_asm, t_i));
	else if (seps == 1 && !seps_at_end)
		return (separate_1_0(the_asm, t_i));
	else if (seps == 1 && seps_at_end)
		return (separate_1_1(the_asm, t_i));
	return(t_i);
}

void	check_command_line(t_asm *the_asm, t_line **line)
{
	int t_i;

	write_all_tokens(the_asm, line);
	//separate_tokens(the_asm);//, line);
	t_i = 0;
	while (t_i < MAX_TOKENS_N)
	{
		printf("\tWORD %i: [%s]\n", t_i + 1, the_asm->line_tokens[t_i]);
		if (ft_strchr(the_asm->line_tokens[t_i], SEPARATOR_CHAR) &&
		ft_strlen(the_asm->line_tokens[t_i]) > 1)
		{
			printf("\tgot separator here, must be fixed\n");
			t_i = separate_tokens(the_asm, t_i);
		}
		else
			t_i++;
	}
	printf("AFTER WE FIXED:\n");
	t_i = 0;
	while (t_i < MAX_TOKENS_N)
	{
		printf("\tWORD %i: [%s]\n", t_i + 1, the_asm->line_tokens[t_i]);
		t_i++;
	}
	//printf("AND NEXT STR\n");
}
