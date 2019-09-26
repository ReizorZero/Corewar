#include "asm.h"

int		check_name_cmnd_tag(char *s, int i)
{
	int cmnd_len;
	
	cmnd_len = 5;
	if (s[i] != '.' ||
	s[i + 1] != 'n' ||
	s[i + 2] != 'a' ||
	s[i + 3] != 'm' ||
	s[i + 4] != 'e')
		ERROR(SYMBOLS_CMND_NAME);
	return (i + cmnd_len);
}

int		anything_after_dot_name(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
			i++;
	i = check_name_cmnd_tag(s, i);
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_text_comment(char **s)
{
	char **arr;

	//NOTE THAT YOU HAVE A LEAK HERE, BECAUSE YOU CHANGE A POINTER TO NEW WITHOUT 
	//DELETING THE PREVIOUS ONE
	if (ft_strchr(*s, COMMENT_CHAR))
	{
		arr = ft_strsplit(*s, COMMENT_CHAR);
		*s = arr[0];
		free(arr[1]);
		free(arr[2]);
		free(arr);
	}
	//PROBABLY, YOU ALSO FORGOT TO FREE SOMEWHERE A POINTER FROM GET_NEXT_LINE
	else if (ft_strchr(*s, ALT_COMMENT_CHAR))
	{
		arr = ft_strsplit(*s, ALT_COMMENT_CHAR);
		*s = arr[0];
		free(arr[1]);
		free(arr[2]);
		free(arr);
	}
}

void	check_symbols_at_end_name(char *s)
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != ' ')
			ERROR(SYMBOLS_CHAMP_NAME);
		i++;
	}
}

void	check_name(t_asm *the_asm, char *s)
{
	int		kavichki;
	char	**arr;

	check_text_comment(&s);
	kavichki = count_kavicki(s);
	if (kavichki != 2 && kavichki != 0)
		ERROR(KAVICHKI_NUMBER);
	arr = ft_strsplit(s, '\"');
	if (!arr[1])
		ERROR(NO_CHAMP_NAME);
	if (arr[2])
		check_symbols_at_end_name(arr[2]);
	if (anything_after_dot_name(arr[0]))
		ERROR(SYMBOLS_CMND_NAME);
	the_asm->champion_name = ft_strdup(arr[1]);
	free(arr[0]);//NORMALNO SDELAY TO AVOID SEGV
	free(arr[1]);
	free(arr);
}