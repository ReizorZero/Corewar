#include "asm.h"

int		main(int argc, char **argv)
{
	t_asm *the_asm;

	the_asm = new_asm();
	check_asm_input(argc, argv, the_asm);
	if (read_from_dot_s(the_asm))
        //write_to_dot_cor(the_asm);
		printf("Writing output to .cor\n");
	//system("leaks -q asm");
	// t_label *ek = the_asm->labels_top;
	// while (ek)
	// {
	// 	printf("label: %s\n", ek->name);
	// 	ek = ek->next;
	// }
	t_exec_code_line *ecl;
	ecl = the_asm->e_c_l_top;
	printf("INDICES OF CMND_LINES:\n");
	while (ecl)
	{
		printf("%i\t", ecl->id);
		ecl = ecl->next;
	}
	printf("\nINDICES OF LABELS:\n");
	t_label *ek = the_asm->labels_top;
	while (ek)
	{
		printf("%s, %i\t", ek->name, ek->cmnd_id_at);
		ek = ek->next;
	}
	return (0);
}