#include <minishell.h>
/* Retorna un *str con el argumento expandido y/o sin comillas*/
char	*expand_and_quote_remove(char *str, t_env *envlist)
{
	char	*result;
	size_t	len;

	result = NULL;
	
	len = new_tok_len(str, envlist);//CALCULA EL len DEL TOKEN FINAL (SIN COMILLAS Y EXPANDIDO)
	printf("token final len: %zu\n", len);
	result = (char *)malloc(sizeof(char) * (len + 1));//reservamos mem con el len del token final
	if (!result)
		printf("fallo la creacion del malloc");
	result = new_tok_builder(str, envlist, result);
//	printf("::%s\n", result);
	return (result);
}