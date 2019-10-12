#include "asm.h"

uint32_t		convert_hex_to_int(char *hex)
{
	uint32_t	val;
	uint8_t		byte;

	val = 0;
	while (*hex)
	{
		byte = *hex++;
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else
		{
			if (byte >= 'a' && byte <= 'f')
				byte = byte - 'a' + 10;
			else
			{
				if (byte >= 'A' && byte <= 'F')
					byte = byte - 'A' + 10;
			}
		}
		val = (val << 4) | (byte & 0xF);
	}
	return (val);
}

int				convert_bit_to_int(char *bit)
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

void			write_null_in_file(t_asm *the_asm, int i)
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
