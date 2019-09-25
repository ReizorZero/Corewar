#include "../asm.h"
#include <fcntl.h>

void	int32_to_bytecode(char *data, int32_t pos, int32_t value, size_t size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		data[pos + size - 1] = (uint8_t)((value >> i) & 0xFF);
		i += 8;
		size--;
	}
}

int		main(void)
{
	printf("SOSI PISOS\n");
	//
	int fd = open("yeeee.cor", O_RDWR);
	//
	char *bcode;
	int32_t	len;

	len = 4 + 6 + 1;
	bcode = ft_strnew((size_t)len);
	int32_to_bytecode(bcode, 0, COREWAR_EXEC_MAGIC, 4);

	char c;
	c = 'B';
	int32_to_bytecode(bcode, 4, c, 1);
	c = 'a';
	int32_to_bytecode(bcode, 5, c, 1);
	c = 't';
	int32_to_bytecode(bcode, 6, c, 1);
	c = 'm';
	int32_to_bytecode(bcode, 7, c, 1);
	c = 'a';
	int32_to_bytecode(bcode, 8, c, 1);
	c = 'n';
	int32_to_bytecode(bcode, 9, c, 1);

	int32_to_bytecode(bcode, 10, 10, 1);
	//
	write(fd, bcode, (size_t)len);
	close(fd);
	return (0);
}//gcc -Wall -Wextra -Werror kekeke.c ../libft/libft.a