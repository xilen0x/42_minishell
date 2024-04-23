#include "minishell.h"

void	init_main_struct(t_shell *shell)
{
	shell->exit_status = 0;
	//shell->link_cmd = NULL;
	shell->link_env = NULL;
	//shell->link_redir = NULL;
	//shell->link_redir_t = NULL;
	//shell->link_tok = NULL;
	shell->link_exe = NULL;
}

/* Función para imprimir solo las claves (keys) del environment*/
void	ft_print_keys(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->key);
		env_struct = env_struct->next;
	}
}

/* Función para imprimir solo los valores (val) del environment*/
void	ft_print_values(t_env *env_struct)
{
	while (env_struct != NULL)
	{
		printf("%s\n", env_struct->val);
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

/*Devuelve el último nodo de la lista.*/
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

/*Añade el nodo ’new’ al final de la lista ’lst’.*/
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

/*Crea un nuevo nodo.*/
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

/*funcion que inicialista la lista creando un nodo(newnode) y agregandolo a la lista(ft_stack_add_back)*/
int	*init_list(char **envp, t_shell *shell)
{
	int		i;
	char	**tokens;
	char	*key;
	char	*value;

	i = 0;
	while (envp[i])
	{
		tokens = ft_split(envp[i], '=');// Dividir: clave y valor
		if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
		{
			key = tokens[0];
			value = tokens[1];
			lstadd_back(&shell->link_env, lstnew(key, value));
		}
		ft_free_split(tokens);
		i++;
	}
	return (0);
}

/*Funcion que elimina una variable del entorno*/
void	env_delone(t_env **env, char *node_to_del, void (*del)(void*))
{
	t_env	*current;
	t_env	*prev;

	current = *env;
	prev = NULL;
	while (current)
	{
		if (ca_strcmp(current->key, node_to_del) == 0)
		{
			// Ajustar los enlaces de los nodos
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			del(current->key);
			del(current->val);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}
