#include "pipex.h"

void execute_command(t_data *data)
{
	int	execve_return;
	char *command;

	if (data->child_pid != 0)
	return;

	// NULL got to be replaced with the flags of the command
	command = data->commands[data->num_of_current_command];
	execve_return = execve("/bin/", &command, data->enviroment_ptr);
	if (execve_return == -1)
		//throw error
		exit(1);
}
