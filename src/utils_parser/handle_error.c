#include "minishell.h"

/*------FREES t_lst AND PRINTS AN ERROR MESSAGE-----*/

void	handle_error(char *str, t_tok **tokens)//aqui sera t_global
{
    write(2, ">>>>minishell: ", 11);
	write(2, str, ft_strlen(str));
	if (tokens != NULL)
		tok_free(tokens);
}
//Hacer una funcion para:
//free t_cmd cmd y free de sus elementos internos y ponerlos a 0.
//free t_lst tokens "  "       "   "
//free t_redir "                    "