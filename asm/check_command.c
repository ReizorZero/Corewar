#include "asm.h"

struct s_commands_info	commands[16] =
{
	{1, "live", 1,
		{0, DIR_CODE, 0},
		{0, 0, 0},
		{0, 0, 0} },
	{2, "ld", 2,
		{0, DIR_CODE, IND_CODE},
		{REG_CODE, 0, 0},
		{0, 0, 0} },
	{3, "st", 2,
		{REG_CODE, 0, 0},
		{REG_CODE, 0, IND_CODE},
		{0, 0, 0} },
	{4, "add", 3,
		{REG_CODE, 0, 0},
		{REG_CODE, 0, 0},
		{REG_CODE, 0, 0} },
	{5, "sub", 3,
		{REG_CODE, 0, 0},
		{REG_CODE, 0, 0},
		{REG_CODE, 0, 0} },
	{6, "and", 3,
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, 0, 0} },
	{7, "or", 3,
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, 0, 0} },
	{8, "xor", 3,
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, 0, 0} },
	{9, "zjmp", 1,
		{0, DIR_CODE, 0},
		{0, 0, 0},
		{0, 0, 0} },
	{10, "ldi", 3,
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, 0},
		{REG_CODE, 0, 0} },
	{11, "sti", 3,
		{REG_CODE, 0, 0},
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, 0} },
	{12, "fork", 1,
		{0, DIR_CODE, 0},
		{0, 0, 0},
		{0, 0, 0} },
	{13, "lld", 2,
		{0, DIR_CODE, IND_CODE},
		{REG_CODE, 0, 0},
		{0, 0, 0} },
	{14, "lldi", 3,
		{REG_CODE, DIR_CODE, IND_CODE},
		{REG_CODE, DIR_CODE, 0},
		{REG_CODE, 0, 0} },
	{15, "lfork", 1,
		{0, DIR_CODE, 0},
		{0, 0, 0},
		{0, 0, 0} },
	{16, "aff", 1,
		{REG_CODE, 0, 0},
		{0, 0, 0},
		{0, 0, 0} }
};

void			check_command(t_asm *the_asm, char *s)
{
	int i;
	int start;
	int len;
	
	the_asm->exec_code_size = 0;
	printf("[%s]\n", s);

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
	{
		i++;
		len++;
	}
	char *command;
	command = ft_strsub(s, start, len);
	printf("\tFIRST WORD: [%s]\n", command);
	int t;
	t = 0;
	while (t < 16)
	{
		if (!ft_strcmp(commands[i].name, command))
			printf("\tFOUND COMMAND: %s\n", commands[i].name);
		t++;
	}

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'))
		i++;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
	{
		i++;
		len++;
	}
	command = ft_strsub(s, start, len);
	printf("\tSECOND WORD: [%s]\n", command);

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == SEPARATOR_CHAR))
		i++;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t' && s[i] != SEPARATOR_CHAR)
	{
		i++;
		len++;
	}
	command = ft_strsub(s, start, len);
	printf("\tTHIRD WORD: [%s]\n", command);

	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t'|| s[i] == SEPARATOR_CHAR))
		i++;
	start = i;
	len = 0;
	while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
	{
		i++;
		len++;
	}
	command = ft_strsub(s, start, len);
	printf("\tFOURTH WORD: [%s]\n", command);
}
