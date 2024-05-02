#include <minishell.h>
/* Retorna un *str con el argumento expandido y/o sin comillas*/
char	*expand_and_quote_remove(char *str, t_env *envlist)
{
	char	*result;
	size_t	len;

	result = NULL;
	len = new_tok_len(str, envlist);//calcula el len del nuevo token, sin comillas y expandido
	result = (char *)malloc(sizeof(char) * (len + 1));//reserva la memoria para el token
//	if (!result)
//	{
//		printf("fallo la creacion del malloc");
//	}
	malloc_s_pointer_protect(result);
	result = new_tok_builder(str, envlist, result);//rellena el nuevo token
	return (result);
}