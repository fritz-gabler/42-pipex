#include "pipex.h"
#include "libft.h"

void execute_command(t_data *data)
{
	int	execve_return;
	char **commands;

	if (data->child_pid != 0)
		return;

	// NULL got to be replaced with the flags of the command
	commands = ft_split(data->commands[data->num_of_current_command], ' ');

	execve_return = execve(data->path_to_executable, commands, data->enviroment_ptr);
	if (execve_return == -1)
		exit_clean(data, data->commands[data->num_of_current_command]);
}
