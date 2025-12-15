#include "pipex.h"

void create_child(t_data *data)
{
	int	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		//error
		return;
	data->child_pid = child_pid;
}
