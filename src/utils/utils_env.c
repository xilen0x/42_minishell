#include "minishell.h"

t_env	*lstlast(t_env *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*lastnode;

	if (lst != 0)
	{
		lastnode = lstlast(*lst);
		if (!lastnode)
			*lst = new;
		else
			lastnode->next = new;
	}
}

t_env	*lstnew(char *key, char *value)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (new_node)
	{
		new_node->key = ft_strdup(key);
		new_node->val = ft_strdup(value);
		new_node->next = NULL;
	}
	else
		return (NULL);
	return (new_node);
}

/* Inicializa la lista t_env creando un nodo(newnode) y agregandoselo*/
void	init_list(char **envp, t_env **envlist)
{
	int		i;
	char	**tokens;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		// Dividir la cadena en 'key' y 'val'
		tokens = ft_split(envp[i], '=');
		if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
		{
			key = tokens[0];
			value = tokens[1];
			lstadd_back(envlist, lstnew(key, value));
		}
		ft_free_split(tokens);
		i++;
	}
	return ;
}
/* Borra una lista t_env y libera todos sus nodos */
void	cleaner(t_env **lst)
{
	t_env	*aux;

	aux = (*lst);
	while (aux)
	{
		free(aux->key);
		aux->key = NULL;
		free(aux->val);
		aux->val = NULL;
		(*lst) = aux->next;
		free(aux);
		aux = (*lst);
	}
	(*lst) = NULL;
}