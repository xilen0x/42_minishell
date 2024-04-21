# include "minishell.h"

int	builtin_unset(t_cmd *cmd, t_env *env)
{
	/* char	**tokens;
	char	**tokens2;
	char	*key;
	char	*value; */
	int		chk_exp;
	(void)env;
	//---------------UNSET SIN ARGUMENTOS
	if (size_arr2d(cmd->command_and_arg) == 1)
		return (0);
	//---------------UNSET VARIABLE
	else
	{
		chk_exp = check_export(cmd->command_and_arg[1]);
		if (chk_exp == 1 || chk_exp == 2) 
			return (0);
		else
		{
			if (!(variable_exists_op3(env, cmd->command_and_arg[1])))
 			{
				printf("+= NO existe la variable!\n");
				/* tokens = ft_split(cmd->command_and_arg[1], '+');
				tokens2 = ft_split(tokens[1], '=');
				if (tokens != NULL && tokens[0] != NULL && tokens[1] != NULL)
				{
					key = tokens[0];
					value = tokens2[0];
					lstadd_back(&env, lstnew(key, value));
				}
				ft_free_split(tokens); */
			} 
			update_env(env, env->key, env->val);
			return (0);
		}
	}
	return (0);
}
