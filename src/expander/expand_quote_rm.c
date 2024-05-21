#include "minishell.h"

/* Returns a *char expanded and the quote removed */
char	*expand_quote_rm(char *str, t_env *envlist)
{
	char	*result;
	size_t	len;

	result = NULL;
	len = new_tok_len(str, envlist);//calcula el len del nuevo token, sin comillas y expandido
//	printf("new_tok_len:%zu\n", len);
	result = (char *)p_malloc(sizeof(char) * (len + 1));//reserva la memoria para el token
	result = new_tok_builder(str, envlist, result);//crea y rellena un nuevo token y borra y libera el antiguo
	return (result);
}