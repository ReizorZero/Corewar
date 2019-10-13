/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:43:22 by rzero             #+#    #+#             */
/*   Updated: 2019/10/13 13:43:27 by rzero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H

# define COMMANDS_H

# include "asm.h"

struct s_commands_info	g_commands[16] =
{
	{1, "live", 4, 0, 1,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		}
	},
	{2, "ld", 4, 1, 2,
		{
			{0, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0},
			{0, 0, 0}
		}
	},
	{3, "st", 4, 1, 2,
		{
			{REG_CODE	, 0, 0},
			{REG_CODE, 0, IND_CODE},
			{0, 0, 0}
		}
	},
	{4, "add", 4, 1, 3,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0}
		}
	},
	{5, "sub", 4, 1, 3,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0},
			{REG_CODE, 0, 0}
		}
	},
	{6, "and", 4, 1, 3,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		}
	},
	{7, "or", 4, 1, 3,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		}
	},
	{8, "xor", 4, 1, 3,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0}
		}
	},
	{9, "zjmp", 2, 0, 1,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		}
	},
	{10, "ldi", 2, 1, 3,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0},
			{REG_CODE, 0, 0}
		}
	},
	{11, "sti", 2, 1, 3,
		{
			{REG_CODE, 0, 0},
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0}
		}
	},
	{12, "fork", 2, 0, 1,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		}
	},
	{13, "lld", 4, 1, 2,
		{
			{0, DIR_CODE, IND_CODE},
			{REG_CODE, 0, 0},
			{0, 0, 0}
		}
	},
	{14, "lldi", 2, 1, 3,
		{
			{REG_CODE, DIR_CODE, IND_CODE},
			{REG_CODE, DIR_CODE, 0},
			{REG_CODE, 0, 0}
		}
	},
	{15, "lfork", 2, 0, 1,
		{
			{0, DIR_CODE, 0},
			{0, 0, 0},
			{0, 0, 0}
		}
	},
	{16, "aff", 4, 1, 1,
		{
			{REG_CODE, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
		}
	}
};

#endif
