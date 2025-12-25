#include "pipex.h"

void	fork_save(t_data *data, int child)
{
	data->child_pids[child] = fork();
	if (data->child_pids[child] == -1)
		exit_clean(data, __FILE__, __LINE__);
}
