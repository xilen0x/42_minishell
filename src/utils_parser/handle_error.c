#include "minishell.h"

/*------FREES MEMORY AND PRINTS AN ERROR MESSAGE-----*/

void	handle_error(char *str, t_cmd *cmd)//aqui sera t_global
{
    write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
//	if (tokens != NULL)
//		free_token(global->tokens);//crear esta funcion
    if (cmd != NULL)
		free_cmd(cmd->cmd);//liberar listas, nodos, *char, **char
//    if (global != NULL)
//		free_array_2d(global);
    
}