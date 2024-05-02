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
/*-------ESTA FUNCION ESTA MAL, ELIMINARLA-------
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
}*/
/*-----TAMPOCO FUNCIONA, NO ENCUENTRA LA DIRECCION DE MEMORIA
void lstadd_back(t_env **lst, t_env *new) 
{
	t_env	*last;

    if (*lst == NULL) 
	{
        *lst = new;  // Si la lista está vacía, el nuevo nodo se convierte en el primer nodo
        return;
    }
    // Recorre la lista hasta llegar al último nodo
    last = (*lst);
    while (last->next != NULL) 
	{
        last = last->next;
    }
    // Inserta el nuevo nodo al final de la lista
    last->next = new;
}*/

/*--Adds a node to the end of a t_env list---*/
void	lstadd_back(t_env **lst, t_env *new)
{
	t_env	*aux;

	if (*lst)
	{
		aux = lstlast(*lst);
		aux->next = new;
	}
	else
		*lst = new;
}
/*OJO: lstnew deberia tener un protector de malloc por si falla???*/
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
void	init_envlist(char **envp, t_env **envlist)
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
		free_arr2d(tokens);//libera malloc que entrega el split a tokens
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