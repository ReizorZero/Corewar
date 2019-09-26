#include "asm.h"

int		count_kavicki(char *s)
{
	int i;
	int kavichki;

	i = 0;
	kavichki = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\"')
			kavichki++;
		i++;
	}
	return (kavichki);
}

int		check_comment_cmnd_tag(char *s, int i)
{
	int cmnd_len;
	
	cmnd_len = 8;
	if (s[i] != '.' ||
	s[i + 1] != 'c' ||
	s[i + 2] != 'o' ||
	s[i + 3] != 'm' ||
	s[i + 4] != 'm' ||
	s[i + 5] != 'e' ||
	s[i + 6] != 'n' ||
	s[i + 7] != 't')
		ERROR(SYMBOLS_CMND_COMMENT);
	return (i + cmnd_len);
}

int		anything_after_dot_comment(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
			i++;
	i = check_comment_cmnd_tag(s, i);
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_symbols_at_end_comment(char *s)
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\t' && s[i] != ' ')
			ERROR(SYMBOLS_COMMENT);
		i++;
	}
}

void	check_comment(t_asm *the_asm, char *s)
{
	int		kavichki;
	char	**arr;

	check_text_comment(&s);
    kavichki = count_kavicki(s);
	if (kavichki != 2 && kavichki != 0)
		ERROR(KAVICHKI_NUMBER);
	arr = ft_strsplit(s, '\"');
	if (!arr[1])
		ERROR(NO_COMMENT);
	if (arr[2])
		check_symbols_at_end_comment(arr[2]);
	if (anything_after_dot_comment(arr[0]))
		ERROR(SYMBOLS_CMND_COMMENT);
	the_asm->champion_comment = ft_strdup(arr[1]);
	free(arr[0]);//NORMALNO SDELAY TO AVOID SEGV
	free(arr[1]);
	free(arr);
}