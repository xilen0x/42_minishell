/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tok_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:08:28 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/02 16:39:28 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Returns the token length once expanded and the quote removed if it applies*/
size_t	new_tok_len(char *str, t_env *envlist)
{
	t_iter	*iter;//contiene el iterador del str y el len resultante
	t_qts	*quotes;//si es molesta amb el quotes del builder posar quotes1 y quotes2

	init_iter(iter);
	init_quotes(quotes);
	while (str && str[iter->i])
	{
		if (str[iter->i] == '"' || str[iter->i] == '\'')//gestiona las comillas
			handle_quote_1(str[iter->i], iter, quotes);
		else if (str[iter->i] == '$' && quotes->s_quote == 0 \
			&& str[iter->i + 1])//gestiona '$'
		{
			iter->i++;//salta el '$'
			handle_dollar(str, iter, quotes, envlist);
			iter->i++;
		}
		else//gestiona los demas caracteres
		{
			iter->len++;
			iter->i++;
		}
	}
	return (iter->len);
}

//>>>>>>>>>>>>>>>>>>>>FUNCIO MEVA ORIGINAL BONA PERO MASSA LLARGA>>>>>>>>>>>>>
/*
int	new_tok_len(char *str, t_env *envlist)
{
	size_t	i;
	size_t	len;
	t_qts	quotes;
	char	*env_key;
	char	*env_val;

	i = 0;
	len = 0;
	quotes.s_quote = 0;
	quotes.d_quote = 0;
	env_key = NULL;
	env_val = NULL;
	while (str && str[i])//le he añadido 'str' para hacerlo mas robusto
	{
		if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
			quotes.d_quote = 1;
		else if (str[i] == '"' && quotes.d_quote == 1)
			quotes.d_quote = 0;
		else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
			quotes.s_quote = 1;
		else if (str[i] == '\'' && quotes.s_quote == 1)
			quotes.s_quote = 0;
		else if (str[i] == '$' && quotes.s_quote == 0 && str[i + 1])//si es un '$' y despues hay algo
		{
			i++;//salto el '$'
//			SI NOMBRE NO VALIDO SINTACTICAMENTE (si despues del $ NO es '?', alfabetico o '_')
			if (str[i] != '?' && !ft_isalpha(str[i]) && str[i] != '_')//ESTO NO SE EXPANDIRA, SINO QUE SE AÑADIRA TAL CUAL
			{
				if (str[i] == '\'' || str[i] == '"')//ULTIMO ADDED PARA SOLVENTAR $'h'
				{
					if (str[i] == '"' && quotes.d_quote == 0 && quotes.s_quote == 0)
						quotes.d_quote = 1;
					else if (str[i] == '"' && quotes.d_quote == 1)
						quotes.d_quote = 0;
					else if (str[i] == '\'' && quotes.s_quote == 0 && quotes.d_quote == 0)
						quotes.s_quote = 1;
					else if (str[i] == '\'' && quotes.s_quote == 1)
						quotes.s_quote = 0;
					len++;//cuento el simbolo '$' saltado arriba
				}
				else
					len += 2;//cuento el '$' saltado hace dos lineas y el char actual no valido, porque los deberé añadir
			}
//			SI ES EL CASO ESPECIAL '$?'
			else if (str[i] == '?')//VERIFICA SI ES EL CASO ESPECIAL '$?'
				len += get_exit_status_len();
			else//SI EL NOMBRE ES VALIDO SINTACTICAMENTE, BUSCARA SI CORRESPONDE CON UNA VARIABLE DE ENTORNO Y CONTARA SU LEN
			{
				env_key = get_env_key(str + i);//retorna un puntero mallocado al nombre despues del '$'
				env_val = get_env_val(env_key, envlist);//busco su valor en el env y retorna un mallocado o un NULL si no lo hay
				if (env_val != NULL)
					len += get_len_and_free(env_val);//calcula su len, lo libera y lo pone a NULL
				i += get_len_and_free(env_key);
				continue;//salto el ciclo para que no se incremente 'i' de nuevo
			}
		}
		else
			len++; 
		i++;
	}
	return (len);
}*/
//#include "minishell.h"
//>>>>>>>>>>>>>>>>>>>>>PROPOSTA DE LA IA>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
/*Maneja y guarda el estado actual de las comillas: abiertas o cerradas*/
/*static void	handle_quotes(char c, t_qts *quotes)
{
	if (c == '"' && quotes->d_quote == 0 && quotes->s_quote == 0)
		quotes->d_quote = 1;
	else if (c == '"' && quotes->d_quote == 1)
		quotes->d_quote = 0;
	else if (c == '\'' && quotes->s_quote == 0 && quotes->d_quote == 0)
		quotes->s_quote = 1;
	else if (c == '\'' && quotes->s_quote == 1)
		quotes->s_quote = 0;
}*/
/*Retorna el length de la variable sintacticamente NO valida  */
/*static size_t	handle_invalid_env_var(char *str, t_len *len, t_qts *quotes)
{
	if (str[len->i] == '\'' || str[len->i] == '"')
	{
		handle_quotes(str[len->i], quotes);
		(len->len)++;
	}
	else
		len->len += 2;//cuento el '$' y el char actual no valido, porque los deberé añadir al nuevo token
	return (len->i);
}*/
/*
static size_t	handle_valid_env_var(char *str, t_len *len, t_env *envlist)
{
	char	*env_key;
	char	*env_val;

	env_key = get_env_key(str + len->i);
	env_val = get_env_val(env_key, envlist);
	if (env_val != NULL)
		len->len += get_len_and_free(env_val);//ENTREGA EL LEN DEL VALOR DE LA VARIABLE
	len->i += get_len_and_free(env_key);//ENTREGA EL LEN DEL NOMBRE DE LA VARIABLE
	return (len->i);
}*/
/*Gestiona lo que encuentra despues de '$', segun sea expansionable, invalid syntax o '$?'*/
/*static size_t	handle_dollar(char *str, t_len *len, t_env *envlist, t_qts *quotes)
{
	len->i++;
	if (str[len->i] != '?' && !ft_isalpha(str[len->i]) && str[len->i] != '_')//SI ES UNA VAR CON INVALID SYNTAX
		len->i = handle_invalid_env_var(str, len, quotes);
	else if (str[len->i] == '?')//SI ES UN $?
		len->len += get_exit_status_len();
	else//SI ES UNA VAR CON VALID SYNTAX
	{
		len->i = handle_valid_env_var(str, len, envlist);
		len->i--;
	}
	return (len->i);
}
*/
/*Recorre el token y retorna el lenght final que tendrá la expansion una vez
 quitadas comillas y expandida si procede*/
/*
int	new_tok_len(char *str, t_env *envlist)
{
//	size_t	i;
//	size_t	len;
	t_len	len;
	t_qts	quotes;

	len.i = 0;
	len.len = 0;
	quotes.d_quote = 0;
	quotes.s_quote = 0;
	while (str && str[len.i])
	{
		if (str[len.i] == '"' || str[len.i] == '\'')//SI COMILLAS
			handle_quotes(str[len.i], &quotes, &len);
		else if (str[len.i] == '$' && quotes.s_quote == 0 && str[len.i + 1])//SI $
			len.i = handle_dollar(str, &len, envlist, &quotes);
		else//SI CUALQUIER OTRO CARACTER
			len.len++;
		len.i++;
	}
	return (len.len);
}*/