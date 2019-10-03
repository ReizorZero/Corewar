#include "asm.h"

void	check_command_line(t_asm *the_asm, t_line **line)
{
	char	*s;
	int		i;
	int		start;
	int		len;
	char	*word;
	int		met_sep;

	s = (*line)->str;
	i = 0;
	printf("[%s]\n", s);

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
	// if (len == 0)
	// 	printf("len = 0");
	word = ft_strsub(s, start, len);
	printf("\tWORD 1: [%s]\n", word);
	//WE GOT FIRST WORD, WE SHOULD CHECK IF IT IS A LABEL OR A COMMAND
	//ALSO WE SHOULD CHECK IF THE LABEL IS CORRECT
	//ALSO WE SHOULD CHECK IF THE COMMAND IS CORRECT
	//ALSO WE SHOULD CHECK ON CASES SUCH AS label:: and so one
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
		i++;
	met_sep = 0;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//SECOND WORD: COMMAND OR ARG_1
	{
		len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		//len++;
		met_sep = 1;//WE MET A SEPARATOR
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		printf("error! ,,\n");
	}
	// if (len == 0 && met_sep == 1)
	// {
	// 	printf("MISSED ARG");
	// }
	word = ft_strsub(s, start, len);
	printf("\tWORD 2: [%s]\n", word);
	//================
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
		//len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		printf("error! ,,\n");
	}
	if (len == 0 && met_sep == 1)
	{
		//printf("MISSED ARG");
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
			i++;
		//printf("[%s]", &s[i]);
		start = i;
		len = 0;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//FOURTH WORD: ARG_2 OR ARG_3
		{
			len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			met_sep = 1;
			//len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			printf("error! ,,\n");
		}
	}
	word = ft_strsub(s, start, len);
	printf("\tWORD 3: [%s]\n", word);
	//
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
		i++;
	met_sep = 0;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//FOURTH WORD: ARG_2 OR ARG_3
	{
		len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		met_sep = 1;
		//len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		printf("error! ,,\n");
	}
	if (len == 0 && met_sep == 1)
	{
		//printf("MISSED ARG");
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
			i++;
		//printf("[%s]", &s[i]);
		start = i;
		len = 0;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//FOURTH WORD: ARG_2 OR ARG_3
		{
			len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			met_sep = 1;
			//len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			printf("error! ,,\n");
		}
	}
	word = ft_strsub(s, start, len);
	printf("\tWORD 4: [%s]\n", word);
	//
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
		i++;
	met_sep = 0;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//FIFTH WORD: ARG_3
	{
		len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		met_sep = 1;
		//len++;
		i++;
	}
	if (s[i] == SEPARATOR_CHAR)
	{
		printf("error! ,,\n");
	}
	if (len == 0 && met_sep == 1)
	{
		//printf("MISSED ARG");
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))//SKIP BLANKS
			i++;
		//printf("[%s]", &s[i]);
		start = i;
		len = 0;
		while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)//FOURTH WORD: ARG_2 OR ARG_3
		{
			len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			met_sep = 1;
			//len++;
			i++;
		}
		if (s[i] == SEPARATOR_CHAR)
		{
			printf("error! ,,\n");
		}
	}
	// if (len == 0)
	// 	printf("len = 0");
	word = ft_strsub(s, start, len);
	printf("\tWORD 5: [%s]\n", word);
	//CHECK IF SOMETHING LEFT AT END AFTER THE COMMENTS
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	if (s[i] != '\0')
		printf("some junk shit at the end of the string\n");
	the_asm->exec_code_size = 0;
}