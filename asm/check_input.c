#include "asm.h"

void	check_arguments_n(int argc)
{
	if (argc < 2)
	{
		printf("Usage: ./asm <sourcefile.s>\n");
		printf("\t(Note that only one file should be passed to input).\n");
		exit(0);
	}
	else if (argc > 2)
	{
		printf("Too many files. You should enter only one file at a time.\n");
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

void	check_file_extension(char *filename, t_asm *the_asm)
{
	char **arr;

	arr = ft_strsplit(filename, '.');
	if (!arr[1])
	{
		printf("File name extension is missing.\n");
		exit (0);
	}
	if (arr[2] ||
	ft_strstr(filename, ".s.") ||
	ft_strcmp(arr[1], "s"))
	{
		printf("File extension is wrong.\n");
		exit (0);
	}
	the_asm->dot_s_name = ft_strdup(arr[0]);//MAKE SURE IT DOESN'T GIVE US LEAKS
	free(arr[0]);//REWRITE THIS STUFF AND MAKE SURE IT NEVER GIVES SEGV
	free(arr[1]);
	free(arr);
}

void	check_input(int argc, char **argv, t_asm *the_asm)
{
	check_arguments_n(argc);
	check_file_name(argv[1]);
	check_file_extension(argv[1], the_asm);
	the_asm->dot_s_file_name = ft_strdup(argv[1]);
}