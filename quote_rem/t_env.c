#include "quote_rem.h"

/* Función para imprimir solo las claves (keys) */
void	ft_print_keys(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->key);
		env_struct = env_struct->next;
	}
}

/* Función para imprimir solo los valores (values) */
void	ft_print_values(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->val);
		env_struct = env_struct->next;
	}
}

/*funcion que imprime la lista completa*/
void	ft_printstack(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s=%s\n", env_struct->key, env_struct->val);
		env_struct = env_struct->next;
	}
}

void	ft_free_split(char **array_strings)
{
	size_t	i;

	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			i++;
		}
		free(array_strings);
	}
}

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

/*funcion que inicializa la lista creando un nodo(newnode) y 
agregandolo a la lista(ft_stack_add_back)*/
void	init_list(char **envp, t_env **envlist)
{
	int		i;
	char	**tokens;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		// Dividir la cadena en clave y valor
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