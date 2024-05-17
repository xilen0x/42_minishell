# include "minishell.h"

/*Funcion que cambia al directorio anterior y actualiza la variable OLDPWD*/
int	set_old_pwd(t_cmd *cmd, t_env *env)
{
	char	*previous_directory;
	char	*current_wd;

	current_wd = getcwd(NULL, 0);//obtiene el directorio actual
	previous_directory = getenv("OLDPWD");//obtiene el directorio anterior
	if (previous_directory == NULL)
	{
		ft_msgs(4, cmd);
		return (1);
	}
	// Cambiar al directorio anterior
	else if (chdir(previous_directory) != 0)//cambia al directorio anterior
	{
		perror("chdir");
		return (1);
	}
	update_env(env, "OLDPWD", current_wd);//actualiza la variable OLDPWD en el env
	return (0);
}

// /*cambia al directorio anterior(si existe) */
int	get_old_pwd(t_cmd *cmd, t_env *env)
{
	// (void)cmd;
	if (!(variable_exists_op3(env, "OLDPWD")))//si no existe la variable
	{
		write(2, "cd: OLDPWD not set", 18);
		write(2, "\n", 1);
		return (1);
	}
	else if (variable_exists_op3(env, "OLDPWD"))//si existe la variable
	{
		set_old_pwd(cmd, env);
		// if (chdir("OLDPWD") != 0)
		// {
		// 	// ft_msgs(4, cmd);
		// 	// set_exit_status(1);
		// 	return (1);
		// }
	}
	else
	{
		printf("algo extrano\n");
		return (1);
	}
	return (0);
}

/*Funcion que retorna el path anterior(OLDPWD). Utiliza para ello la funcion getcwd*/
// int	old_pwd(t_shell *shell)
// {
// 	char	*old_wd;

// 	old_wd = "/";
// 	if (variable_exists(shell->link_env, shell->link_cmd->commands[1]))
// 	{
// 		printf("variable oldpwd existe\n");
// 	}
// 	// 	old_wd = getenv("OLDPWD");
// 	// 	if (chdir(old_wd) != 0)
// 	// 	{
// 	// 		perror("cd: OLDPWD not set");
// 	// 		set_exit_status(1);
// 	// 		return (1);
// 	// 	}
// 	// }
// 	else
// 	{
// 		printf("no existe oldpwd aun\n");
// 		return (1);
// 	}
// 	//*shell->link_env = *update_env(shell->link_env, "OLDPWD", old_wd);
// 	set_exit_status(0);
// 	///free(old_wd);
// 	return (0);
// }