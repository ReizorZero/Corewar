//#include "asm.h"
//
//void	check_command_line(t_asm *the_asm, t_line **line)
//{
//	char	*s;
//	int		i;
//	int		len;
//	int		start;
//	int		t_i;
//
//	s = (*line)->str;
//	i = 0;
//	printf("[%s]\n", s);
//	t_i = 0;
//
//	while (t_i < MAX_TOKENS_N)
//	{
//		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
//			i++;
//		start = i;
//		len = 0;
//		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
//		{
//			i++;
//			len++;
//		}
//		the_asm->line_tokens[t_i] = ft_strsub(s, start, len);
//		printf("\tWORD %i: [%s]\n", t_i + 1, the_asm->line_tokens[t_i]);
//		if (ft_strchr(the_asm->line_tokens[t_i], SEPARATOR_CHAR)
//		&& ft_strlen(the_asm->line_tokens[t_i]) > 1)
//		{
//			printf("\tgot separator, must be fixed\n");
//			// int k = 0;
//			// while (the_asm->line_tokens[t_i][k] != '\0' && the_asm->line_tokens[t_i][k] != SEPARATOR_CHAR)
//			// 	k++;
//			// k++;
//			// start = k;
//			// len = 0;
//			// while (the_asm->line_tokens[t_i][k] != '\0')
//			// {
//			// 	k++;
//			// 	len++;
//			// }
//			// //printf("\t{%s}\n", &the_asm->line_tokens[t_i][k]);
//			// the_asm->line_tokens[t_i + 1] = ft_strsub(the_asm->line_tokens[t_i], start, len);
//			// printf("\tWORD %i: [%s]\n", t_i + 1 + 1, the_asm->line_tokens[t_i + 1]);
//			// t_i++;//SEGV MAY OCCUR HERE, IF WE HAPPEN TO GO TO 8 T_I
//			// //
//		}
//		t_i++;
//	}
//	//DO NOT FUCKING FORGET TO CHECK IF THERE IS 8TH WORD
//	//IF THERE IS, THEN IT IS A FUCKING ERROR!
//	// if (s[i] != '\0')
//	// {
//	// 	printf("smthng wrng @ [%s]\n", &s[i]);
//	// 	exit(0);
//	// }
//}