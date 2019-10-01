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

void	check_command_line(t_asm *the_asm, t_line **line)
{
	char	**words;
	int		words_n;
	int 	i;
	//BE CAREFUL AND NOTE THAT YOU ARE POTENTIALLY ABOUT TO LOOSE POINTERS HERE!

	printf("[%s]\n", (*line)->str);
	words = tabs_split((*line)->str);
	words_n = 0;
	i = 0;
	while (words[words_n])
	{
		printf("\t{%s}\n", words[words_n]);
		words_n++;
	}
	printf("\tn = %i\n", words_n);
	if (words_n > 0)//HANDLE THIS IN A BETTER WAY
	{
		if (ft_strchr(words[i], LABEL_CHAR) && words_n == 1)
			check_label(the_asm, words[i]);
		else
		{
			while (i < words_n)
			{
				if (ft_strchr(words[i], LABEL_CHAR) && check_label(the_asm, words[i]))
				{
					i++;
					check_command(the_asm, words[i]);
				}
				else
					check_command(the_asm, words[i]);
				i++;
			}
		}
	}
	the_asm->exec_code_size = 0;//del this line later
}
