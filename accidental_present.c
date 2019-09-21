# include "libft/inc/libft.h"
# include <stdio.h> //DELETE THEN

void	check_arguments_n(int argc)
{
	if (argc < 2)
	{//update usage info later
		printf("Usage: ./corewar <champion1.cor> <...>\n");
		printf("\t(Note that you can only pass from 1 to 4 files).\n");
		exit(0);
	}
	if (argc > 5)
	{
		printf("You can't submit more than 4 champion files.\n");
		exit(0);
	}
}

void	check_file_name(char *filename)
{
	if (filename[0] == '\0')
	{
		printf("File name is missing.\n");
		exit (0);
	}
}

void	check_file_extension(char *filename)
{
	char **arr;

	arr = ft_strsplit(filename, '.');
	if (!arr[1])
	{
		printf("File extension is missing.\n");
		exit (0);
	}
	if (arr[2] ||
	ft_strstr(filename, ".cor.") ||
	ft_strcmp(arr[1], "cor"))
	{
		printf("File extension is wrong.\n");
		exit (0);
	}
	free(arr[0]);
	free(arr[1]);
	free(arr);
}

/*
**	Checks if input is correct: from 1 to 4 files, all with .cor extension.
*/

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	check_arguments_n(argc);
	while (i < argc)
	{
		check_file_name(argv[i]);
		check_file_extension(argv[i]);
		i++;
	}
	return (0);
}//gcc -Wall -Wextra -Werror accidental_present.c libft/libft.a