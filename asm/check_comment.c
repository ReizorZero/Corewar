#include "asm.h"

int		count_kavicki(char *s)
{//DO THE STUFF NORMALLYY 
	int i;
	int kavichki;
	int	met_hash;

	i = 0;
	met_hash = 0;
	kavichki = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			met_hash++;
		if (s[i] == '\"' &&
		(met_hash == 1 && kavichki <= 1))// && kavichki <= 2)
			kavichki++;
		i++;
	}
	printf("KAVICHKI = %i\n", kavichki);
	return (kavichki);
}

// int		check_comment_cmnd_tag(char *s, int i)
// {
// 	int cmnd_len;
	
// 	cmnd_len = 8;
// 	if (s[i] != '.' ||
// 	s[i + 1] != 'c' ||
// 	s[i + 2] != 'o' ||
// 	s[i + 3] != 'm' ||
// 	s[i + 4] != 'm' ||
// 	s[i + 5] != 'e' ||
// 	s[i + 6] != 'n' ||
// 	s[i + 7] != 't')
// 		ERROR(SYMBOLS_CMND_COMMENT);
// 	return (i + cmnd_len);
// }

// int		anything_after_dot_comment(char *s)
// {
// 	int i;

// 	i = 0;
// 	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
// 			i++;
// 	i = check_comment_cmnd_tag(s, i);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != '\t' && s[i] != ' ')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	check_symbols_at_end_comment(char *s)
// {
// 	int i;
	
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] != '\t' && s[i] != ' ')
// 			ERROR(SYMBOLS_COMMENT);
// 		i++;
// 	}
// }

void	check_comment(t_asm *the_asm, t_line **line)
{
	//BE CAREFUL AND NOTE THAT YOU ARE POTENTIALLY ABOUT TO LOOSE POINTERS HERE!

	printf("[%s]\n", (*line)->str);
	//*line = (*line)->next;
	//printf("\t{%s}\n", (*line)->str);
	//del this line later
	the_asm->exec_code_size = 0;
}