#include "minishell.h"

/*------FREES t_tok list AND PRINTS AN ERROR MESSAGE-----*/

void	handle_error(char *str, t_tok **tok)
{
	write(2, str, ft_strlen(str));
	get_signal = 2;//el 2 corresponderia a un error de sintaxis
	if (tok != NULL)
		tok_free(tok); // segfault
}