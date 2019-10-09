#include "asm.h"

static void		out_in_file(int32_t nbr, int size, t_asm *the_asm)
{
	unsigned int	tmp;
	int				i;
	char			*res;

	if (nbr < 0)
	{
		tmp = -nbr;
		tmp = ~tmp + 1;
	}
	else
		tmp = nbr;
	res = ft_memalloc(sizeof(char) * size);
	i = size;
	while (--i >= 0)
	{
		res[i] = tmp % 256;
		tmp /= 256;
	}
	write(the_asm->fd, res, size);
	free(res);
}

uint32_t	convert_hex_to_int(char *hex)
{
	uint32_t	val;
	uint8_t		byte; 

	val = 0;
	while (*hex) {
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else
			if (byte >= 'a' && byte <='f')
				byte = byte - 'a' + 10;
		else
			if (byte >= 'A' && byte <='F')
				byte = byte - 'A' + 10;    
		val = (val << 4) | (byte & 0xF);
	}
	return val;
}

void		write_null_in_file(t_asm *the_asm, int i)
{
	int	j;

	j = -1;
	if (i < 0)
	{
		printf("Too much inf in comm or name.\n");
		exit(0);
	}
	while (++j != i)
		out_in_file(0, 1, the_asm);
}

void		write_to_dot_cor(t_asm *the_asm)
{
	char	*s;
	int		j;

	s = ft_strchr(the_asm->dot_s_file_name, '.');
	s[0] = '\0';
	the_asm->fd = open(ft_strjoin(the_asm->dot_s_file_name, ".cor"), O_WRONLY | O_CREAT | O_TRUNC, 0777);
	out_in_file(convert_hex_to_int("ea83f3"), 4, the_asm);
	j = -1;
	while (the_asm->champion_name[++j] != '\0')
		out_in_file(the_asm->champion_name[j], 1, the_asm);
	write_null_in_file(the_asm, 128 - j);
	write_null_in_file(the_asm, 4);
	the_asm->exec_code_size = 22; // random number
	out_in_file(the_asm->exec_code_size, 4, the_asm);
	j = -1;
	while (the_asm->champion_comment[++j] != '\0')
		out_in_file(the_asm->champion_comment[j], 1, the_asm);
	write_null_in_file(the_asm, 2048 - j);
	write_null_in_file(the_asm, 4);
	out_in_file(-19, 2, the_asm); // manualy get number
	// champ_code_size(the_asm);
}