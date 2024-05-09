#include "minishell.h"

//Initialize all variables from 't_exe exe' to zero
void	init_exe(t_exe *exe, t_cmd *cmd)
{
	exe->paths = NULL;
	exe->index = 0;
	exe->cmd_fullpath = NULL;
	exe->new_array = NULL;
	exe->num_cmds = 0;
	exe->pid = p_malloc(sizeof(pid_t) * exe->num_cmds);
	exe->fd_input = 0;//fd del teclado. REVISAR CON CARLOS
	exe->fd_output = 0;//fd del teclado. REVISAR CON CARLOS
	exe->fd[0] = -1;
	exe->fd[1] = -1;
	exe->dup_stdin = 0;//REVISAR CON CARLOS
	exe->dup_stdout = 0;//REVISAR CON CARLOS
	exe->path = NULL;
	exe->exit_stat = 0;
}
