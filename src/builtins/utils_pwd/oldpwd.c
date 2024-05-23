# include "minishell.h"

/*Funcion que cambia al directorio anterior y actualiza la variable OLDPWD*/
int	set_old_pwd(t_cmd *cmd, t_env *env)
{
	char	*previous_directory;
(void)env;
(void)cmd;
	previous_directory = getenv("OLDPWD");
	if (chdir(previous_directory) != 0)//cambia al directorio anterior
		return (1);
	return (0);
}

/*actualiza la variable OLDPWD del entorno*/
int	update_oldpwd(t_env *env, char *current_wd)
{
	char	*previous_directory;

	previous_directory = current_wd;
	if (!previous_directory)
	{
		perror("getenv");
		free(previous_directory);
		return (1);
	}
	env = update_env(env, "OLDPWD", previous_directory);
	return (0);
}

// /*consulta el directorio anterior(si existe) */
int	get_old_pwd(char *current_wd, t_env *env)
{
	if (!(variable_exists_op3(env, "OLDPWD")))//si no existe la variable envia error
	{
		write(2, "cd: OLDPWD not set", 18);
		write(2, "\n", 1);
		return (1);
	}
	else if (variable_exists_op3(env, "OLDPWD"))//si existe la variable envia el directorio anterior
		update_oldpwd(env, current_wd);
	return (0);
}

