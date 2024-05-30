#include "minishell.h"

// /*Calcula el len que tendra el token(str) una vez haya eliminado comillas 
// y expandido las variables que procedan*/
// int	new_tok_len(char *str, t_env *envlist)
// {
// 	size_t	i;
// 	size_t	len;
// 	t_qts	quotes;
// 	char	*env_key;
// 	char	*env_val;

// 	i = 0;
// 	len = 0;
// 	quotes.s_quote = 0;
// 	quotes.d_quote = 0;
// 	env_key = NULL;
// 	env_val = NULL;
// //	while (str[i])
// 	while (str && str[i])//le he añadido 'str' para hacerlo mas robusto
// 	{
// 		if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
// 			quotes.d_quote = 1;
// 		else if (str[i] == '"' && quotes.d_quote == 1)
// 			quotes.d_quote = 0;
// 		else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
// 			quotes.s_quote = 1;
// 		else if (str[i] == '\'' && quotes.s_quote == 1)
// 			quotes.s_quote = 0;
// 		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es un '$' y despues hay algo
// 		{
// 			i++;//salto el '$'
// //			FILTRA NOMBRES SINTACTICAMENTE NO VALIDOS (si despues del $ NO es '?', alfabetico o '_')
// 			if (str[i] != '?' && !ft_isalpha(str[i]) && str[i] != '_')//ESTO NO SE EXPANDIRA, SINO QUE SE AÑADIRA TAL CUAL
// 			{
// 				if (str[i] == '\'' || str[i] == '"')//ULTIMO ADDED PARA SOLVENTAR $'h'
// 				{
// 					if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
// 						quotes.d_quote = 1;
// 					else if (str[i] == '"' && quotes.d_quote == 1)
// 						quotes.d_quote = 0;
// 					else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
// 						quotes.s_quote = 1;
// 					else if (str[i] == '\'' && quotes.s_quote == 1)
// 						quotes.s_quote = 0;
// //					i++;
// 					len++;//cuento el simbolo '$' saltado arriba
// 				}
// 				else
// 					len += 2;//cuento el '$' saltado hace dos lineas y el char actual no valido, porque los deberé añadir
// 			}
// 			else if (str[i] == '?')//VERIFICA SI ES EL CASO ESPECIAL '$?'
// 				len += get_exit_status_len();
// 			else//SI EL NOMBRE ES VALIDO SINTACTICAMENTE, BUSCARA SI CORRESPONDE CON UNA VARIABLE DE ENTORNO Y CONTARA SU LEN
// 			{
// 				env_key = get_env_key(str + i);//retorna un puntero mallocado al nombre despues del '$'
// 				env_val = get_env_val(env_key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
// 				if (env_val != NULL)
// //				{
// //					len += ft_strlen(env_val);//incremento el tamaño del nuevo token con el de la expansion
// //					free(env_val);
// //					env_val = NULL;
// //				}
// 					len += get_len_and_free(env_val);//calcula su len, lo libera y lo pone a NULL
// //				i += ft_strlen(env_key);//incremento/salto el len del nombre de la var en el recorrido del token
// //				free(env_key);
// //				env_key = NULL;
// 				i += get_len_and_free(env_key);
// 				continue;//salto el ciclo para que no se incremente 'i' de nuevo
// 			}
// 		}
// 		else
// 			len++; 
// 		i++;
// 	}
// 	return (len);
// }

#include "minishell.h"

void handle_quotes(char c, t_qts *quotes) {
	if (c == '"' && quotes->d_quote == 0 && quotes->s_quote == 0)
		quotes->d_quote = 1;
	else if (c == '"' && quotes->d_quote == 1)
		quotes->d_quote = 0;
	else if (c == '\'' && quotes->s_quote == 0 && quotes->d_quote == 0)
		quotes->s_quote = 1;
	else if (c == '\'' && quotes->s_quote == 1)
		quotes->s_quote = 0;
}

size_t handle_invalid_env_var(char *str, size_t i, size_t *len, t_qts *quotes) {
	if (str[i] == '\'' || str[i] == '"') {
		handle_quotes(str[i], quotes);
		(*len)++;
	} else {
		*len += 2;
	}
	return i;
}

size_t handle_valid_env_var(char *str, size_t i, size_t *len, t_env *envlist) {
	char *env_key = get_env_key(str + i);
	char *env_val = get_env_val(env_key, envlist);
	if (env_val != NULL)
		*len += get_len_and_free(env_val);
	i += get_len_and_free(env_key);
	return i;
}

size_t handle_dollar_sign(char *str, size_t i, size_t *len, t_env *envlist, t_qts *quotes) {
	i++;
	if (str[i] != '?' && !ft_isalpha(str[i]) && str[i] != '_') {
		i = handle_invalid_env_var(str, i, len, quotes);
	} else if (str[i] == '?') {
		*len += get_exit_status_len();
	} else {
		i = handle_valid_env_var(str, i, len, envlist);
		i--;
	}
	return i;
}

int new_tok_len(char *str, t_env *envlist) {
	size_t i = 0;
	size_t len = 0;
	t_qts quotes = {0, 0};

	while (str && str[i]) {
		if (str[i] == '"' || str[i] == '\'') {
			handle_quotes(str[i], &quotes);
		} else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1]) {
			i = handle_dollar_sign(str, i, &len, envlist, &quotes);
		} else {
			len++;
		}
		i++;
	}
	return len;
}

