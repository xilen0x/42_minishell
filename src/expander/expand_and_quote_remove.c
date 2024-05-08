#include <minishell.h>
/* Retorna un *str con el argumento expandido y/o sin comillas*/
char	*expand_and_quote_remove(char *str, t_env *envlist, unsigned int *exit_status)
{
	char	*result;
	size_t	len;

//	printf("%p\n", &str);
	result = NULL;
	len = new_tok_len(str, envlist, exit_status);//calcula el len del nuevo token, sin comillas y expandido
	result = (char *)p_malloc(sizeof(char) * (len + 1));//reserva la memoria para el token
	result = new_tok_builder(str, envlist, result, exit_status);//crea y rellena un nuevo token y borra y libera el antiguo
	return (result);
}