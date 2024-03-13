
#include "minishell.h"

/*------RETORNA UN NUEVO NODO CREADO CON LOS ARGUMENTOS---------*/
t_lst	*lstnew_tok(char *value, int keyword)
{
	t_lst	*token;

	token = (t_lst *)malloc(sizeof(t_lst));
	if (!token)
		return (NULL);
	token->value = *value;
	token->keyword = keyword;
    token->next = NULL;
	return (token);
}