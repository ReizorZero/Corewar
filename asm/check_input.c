#include "asm.h"

void	check_arguments_n(int argc)
{
	if (argc != 2)
	{
		printf("Usage: ./asm <sourcefile.s>\n");
		printf("\t(Note that only one file should be passed to input).\n");
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
	free(arr[0]);
	free(arr[1]);
	free(arr);
}

void	check_input(int argc, char **argv)
{
	check_arguments_n(argc);
	check_file_name(argv[1]);
	check_file_extension(argv[1]);
}