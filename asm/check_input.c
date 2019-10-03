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
	int i;

	if (!ft_strchr(filename, '.'))
	{
		printf("File extension is missing.\n");
		exit (0);
	}
	if (filename[0] == '.' || filename[0] == '\0')
	{
		printf("File name is missing.\n");
		exit (0);
	}
	i = 0;
	while (filename[i] != '\0' && filename[i] != '.')
		i++;
	the_asm->dot_s_name = ft_strsub(filename, 0, i);//MAKE SURE IT DOESN'T GIVE US LEAKS
	i++;
	if (filename[i] == '\0')
	{
		printf("File extension is missing.\n");
		exit (0);
	}
	if (filename[i] != 's' || filename[i + 1] != '\0')
	{
		printf("File extension is wrong.\n");
		exit (0);
	}
	the_asm->dot_s_file_name = ft_strdup(filename);//MAKE SURE IT DOESN'T GIVE US LEAKS
}

void	check_input(int argc, char **argv, t_asm *the_asm)
{
	check_arguments_n(argc);
	check_file_name(argv[1]);
	check_file_extension(argv[1], the_asm);
}