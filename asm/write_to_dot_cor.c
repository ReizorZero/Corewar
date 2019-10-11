#include "asm.h"

static void		out_in_file(int32_t nbr, int size, t_asm *the_asm)
{
	unsigned int	tmp;
	int				i;
	char			*res;

	if (size == 0)
		return ;
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

int			convert_bit_to_int(char *bit)
{
	int		sum;
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

char		*get_arg_types_code(int *arg_code)
{
	int		i;
	int		j;
	char	*rez;

	if (!(rez = ft_memalloc(sizeof(char) * 9)))
		exit(0);
	i = -1;
	j = 0;
	while (++i != 3)
	{
		if (arg_code[i] == 1)
		{
			rez[j] = '0';
			rez[j + 1] = '1';
		}
		if (arg_code[i] == 2)
		{
			rez[j] = '1';
			rez[j + 1] = '0';
		}
		if (arg_code[i] == 3)
		{
			rez[j] = '1';
			rez[j + 1] = '1';
		}
		j += 2;
	}
	rez[j] = '0';
	rez[j + 1] = '0';
	rez[j + 2] = '\0';
	return (rez);
}

void		write_cmnd_code(t_asm *the_asm)
{
	int					i;
	t_exec_code_line	*tmp;
	char				*arg_types_code;

	tmp = the_asm->e_c_l_top;
	while (tmp)
	{
		// printf("%d\n", tmp->cmnd_code);
		if (tmp->cmnd_code != 0)
		{
			out_in_file(tmp->cmnd_code, 1, the_asm);
			if (tmp->has_arg_types_code > 0)
			{
				arg_types_code = get_arg_types_code(tmp->arg_code);
				out_in_file(convert_bit_to_int(arg_types_code), 1, the_asm); // "01101000" will be arg_types_code_size
			}
			i = -1;
			printf("\n%s\n", "cmnd--");
			while (++i < 3)
			{
				printf("%d\n", tmp->arg_value[i]);
				if (tmp->arg_size[i] != 0)
				{
					out_in_file(tmp->arg_value[i], tmp->arg_size[i], the_asm);
				}
					// out_in_file(convert_hex_to_int("01"), 1, the_asm); //convert_bit_to_int("01") : 01 will be tmp->arg_code[i], change 1 to tmp->arg_size[i]
			}
		}
		tmp = tmp->next;
	}
	free(arg_types_code);
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
	write_null_in_file(the_asm, 128 - j);
	write_null_in_file(the_asm, 4);
	printf("\n%d\n", the_asm->exec_code_size);
	out_in_file(22, 4, the_asm);
	j = -1;
	while (the_asm->champion_comment[++j] != '\0')
		out_in_file(the_asm->champion_comment[j], 1, the_asm);
	write_null_in_file(the_asm, 2048 - j);
	write_null_in_file(the_asm, 4);
	write_cmnd_code(the_asm);
}