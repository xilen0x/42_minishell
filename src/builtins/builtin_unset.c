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
				printf("NO existe la variable!\n");//cambiar luego por printf("\n")
			//update_env(env, env->key, env->val);
			else
			{
				printf("variable elimninada!\n");
				env_delone(&env, env, &free);
			}
			
			return (0);
		}
	}
	return (0);
}
