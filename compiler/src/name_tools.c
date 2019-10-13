/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:02:26 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 18:02:32 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

int		check_name_cmnd_tag(t_asm *the_asm, char *s, int i)
{
	int cmnd_len;

	cmnd_len = 5;
	if (s[i] != '.' ||
	s[i + 1] != 'n' ||
	s[i + 2] != 'a' ||
	s[i + 3] != 'm' ||
	s[i + 4] != 'e')
		ERROR(SYMBOLS_CMND_NAME, the_asm->curr_line_n);
	return (i + cmnd_len);
}

int		anything_after_dot_name(t_asm *the_asm, char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == ' '))
		i++;
	i = check_name_cmnd_tag(the_asm, s, i);
	while (s[i] != '\0' && s[i] != '\"' &&
	s[i] != ALT_COMMENT_CHAR &&
	s[i] != COMMENT_CHAR)
	{
		if (s[i] != '\t' && s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_text_comment(char **s)
{
	int i;

	i = 0;
	if (s[0][0] == COMMENT_CHAR || s[0][0] == ALT_COMMENT_CHAR)
		*s = ft_strdup("");
	else if (ft_strchr(*s, COMMENT_CHAR) || (ft_strchr(*s, ALT_COMMENT_CHAR)))
	{
		while (s[0][i] != '\0' && s[0][i] != COMMENT_CHAR &&
		s[0][i] != ALT_COMMENT_CHAR)
			i++;
		*s = ft_strsub(*s, 0, (size_t)i);
	}
}

int		found_closing_quote_name(t_asm *the_asm)
{
	int i;

	i = 0;
	while (the_asm->champion_name[i] != '\0' &&
	the_asm->champion_name[i] != '\"')
		i++;
	the_asm->champion_name = ft_strsub(the_asm->champion_name, 0, i);
	return (1);
}
