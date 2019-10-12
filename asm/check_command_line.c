#include "asm.h"

int		is_empty_or_comment(t_line **line)
{
	int		i;
	char	*s;

	i = 0;
	s = (*line)->str;
	if (s[0] == '\0')
		return (1);
	while (s[i] != '\0' && s[i] != COMMENT_CHAR && s[i] != ALT_COMMENT_CHAR)
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

void	check_command_line(t_asm *the_asm, t_line **line)
{
	if (!is_empty_or_comment(line))
	{
		add_cmnd_line(the_asm);
		write_cmnd_line_words(the_asm, line);
		check_if_words_correct(the_asm, line);
	}
}