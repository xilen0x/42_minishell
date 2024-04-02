#include "minishell.h"

/*------FREES t_tok list AND PRINTS AN ERROR MESSAGE-----*/

void	handle_error(char *str, t_tok **tok)//aqui sera t_global para poder manejar todos los errores
{
    write(2, ">>>>minishell: ", 11);
	write(2, str, ft_strlen(str));
	if (tok != NULL)
		tok_free(tok);
}