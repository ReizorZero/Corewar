#include "asm.h"

//I DON'T EVEN USE THIS FILE ANYWHERE, IT'S A SAMPLE OF ALL COMMANDS INFO AND STUFF

t_commands_info		commands[16] =
{
	{1, "live", 1, {0, DIR_CODE, 0}, {0, 0, 0}, {0, 0, 0} },
	{2, "ld", 2, {0, DIR_CODE, IND_CODE}, {REG_CODE, 0, 0}, {0, 0, 0} },
	{3, "st", 2, {REG_CODE, 0, 0}, {REG_CODE, 0, IND_CODE}, {0, 0, 0} },
	{4, "add", 3, {REG_CODE, 0, 0}, {REG_CODE, 0, 0}, {REG_CODE, 0, 0} },
	{5, "sub", 3, {REG_CODE, 0, 0}, {REG_CODE, 0, 0}, {REG_CODE, 0, 0} },
	{6, "and", 3, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, 0, 0} },
	{7, "or", 3, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, 0, 0} },
	{8, "xor", 3, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, 0, 0} },
	{9, "zjmp", 1, {0, DIR_CODE, 0}, {0, 0, 0}, {0, 0, 0} },
	{10, "ldi", 3, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, 0}, {REG_CODE, 0, 0} },
	{11, "sti", 3, {REG_CODE, 0, 0}, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, 0} },
	{12, "fork", 1, {0, DIR_CODE, 0}, {0, 0, 0}, {0, 0, 0} },
	{13, "lld", 2, {0, DIR_CODE, IND_CODE}, {REG_CODE, 0, 0}, {0, 0, 0} },
	{14, "lldi", 3, {REG_CODE, DIR_CODE, IND_CODE}, {REG_CODE, DIR_CODE, 0}, {REG_CODE, 0, 0} },
	{15, "lfork", 1, {0, DIR_CODE, 0}, {0, 0, 0}, {0, 0, 0} },
	{16, "aff", 1, {REG_CODE, 0, 0}, {0, 0, 0}, {0, 0, 0} }
};
