#include "asm.h"

// int		check_name_cmnd_tag(char *s, int i)
// {
// 	int cmnd_len;
	
// 	cmnd_len = 5;
// 	if (s[i] != '.' ||
// 	s[i + 1] != 'n' ||
// 	s[i + 2] != 'a' ||
// 	s[i + 3] != 'm' ||
// 	s[i + 4] != 'e')
// 		ERROR(SYMBOLS_CMND_NAME);
// 	return (i + cmnd_len);
// }

// int		anything_after_dot_name(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
// 			i++;
// 	i = check_name_cmnd_tag(s, i);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != '\t' && s[i] != ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void	check_text_comment(char **s)//ABSOLUTELY FUCKING SURE IT LEAKS SOMEWHERE HERE
{
	int i;

	i = 0;
	if (s[0][0] == COMMENT_CHAR || s[0][0] == ALT_COMMENT_CHAR)
		*s = ft_strdup("");
	else if (ft_strchr(*s, COMMENT_CHAR) || (ft_strchr(*s, ALT_COMMENT_CHAR)))
	{
		while (s[0][i] != '\0' && s[0][i] != COMMENT_CHAR && s[0][i] != ALT_COMMENT_CHAR)
			i++;
		*s = ft_strsub(*s, 0, (size_t)i);
	}
}

// void	check_symbols_at_end_name(char *s)
// {
// 	int i;
	
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != '\t' && s[i] != ' ')
// 			ERROR(SYMBOLS_CHAMP_NAME);
// 		i++;
// 	}
// }

void	check_name(t_asm *the_asm, t_line **line)
{//BE CAREFUL AND NOTE THAT YOU ARE POTENTIALLY ABOUT TO LOOSE POINTERS HERE!
	int kavichki;

	printf("[%s]\n", (*line)->str);
	kavichki = count_kavicki((*line)->str);
	if (kavichki > 2)
		ERROR(KAVICHKI_NUMBER);
	//*line = (*line)->next;
	//printf("\t{%s}\n", (*line)->str);
	//del this line later
	the_asm->exec_code_size = 0;
}