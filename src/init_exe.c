#include "minishell.h"

//Sets to 0 or NULL all variables from a 't_exe' struct
void	init_exe(t_exe *exe, t_cmd *cmd)
{
//	exe->paths = NULL;
//	exe->index = 0;
//	exe->cmd_fullpath = NULL;
//	exe->new_array = NULL;
	exe->num_cmds = cmd_size(cmd);
	exe->pid = p_malloc(sizeof(pid_t) * exe->num_cmds);
//	exe->fd_input = 0;
//	exe->fd_output = 0;
	exe->fd[0] = -1;
	exe->fd[1] = -1;
//	exe->dup_stdin = 0;
//	exe->dup_stdout = 0;
//	exe->path = NULL;
//	exe->exit_stat = 0;
}
