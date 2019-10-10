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
	if (!(res = ft_memalloc(sizeof(char) * size)))
		exit(0);
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

uint32_t		convert_bit_to_int(char *bit)
{
	int32_t	sum;
	int		i;
	int		n;

	n = 8;
	i = n - 1;
	sum = 0;

	while (i != -1)
	{
		if (bit[i] == '1')
			sum += ft_pow(2, n - (i + 1));
		i--;
	}
	return (sum);
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

void		write_cmnd_code(t_asm *the_asm)
{
	int					i;
	t_exec_code_line	*tmp;

	tmp = the_asm->e_c_l_top;
	while (tmp)
	{
		printf("%d\n", tmp->cmnd_code);
		if (tmp->cmnd_code != 0)
		{
			out_in_file(tmp->cmnd_code, 1, the_asm); // change 1 with tmp->cmnd_size
			out_in_file(convert_bit_to_int("01101000"), 1, the_asm); //change 1 with tmp->(t_comands_info(struct type))->has_arg_types_code
			i = -1;
			while (++i < 3)
				out_in_file(convert_bit_to_int("01"), 1, the_asm); //convert_bit_to_int("01") : 01 will be arg_code, change 1 to arg_size
		}
		tmp = tmp->next;
	}
}

void		write_to_dot_cor(t_asm *the_asm)
{
	char	*s;
	int		j;

	s = ft_strchr(the_asm->dot_s_file_name, '.');
	s[0] = '\0';
	the_asm->fd = open(ft_strjoin(the_asm->dot_s_file_name, ".cor")
		, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	out_in_file(convert_hex_to_int("ea83f3"), 4, the_asm);
	j = -1;
	while (the_asm->champion_name[++j] != '\0')
		out_in_file(the_asm->champion_name[j], 1, the_asm);
	// write_null_in_file(the_asm, 128 - j);
	out_in_file(0, PROG_NAME_LENGTH - j, the_asm);
	write_null_in_file(the_asm, 4);
	printf("\n%d\n", the_asm->exec_code_size);
	out_in_file(the_asm->exec_code_size, 4, the_asm);
	j = -1;
	while (the_asm->champion_comment[++j] != '\0')
		out_in_file(the_asm->champion_comment[j], 1, the_asm);
	// write_null_in_file(the_asm, 2048 - j);
	out_in_file(0, COMMENT_LENGTH - j, the_asm);
	write_null_in_file(the_asm, 4);
	write_cmnd_code(the_asm);
}