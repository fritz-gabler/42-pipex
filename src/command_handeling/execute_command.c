#include "pipex.h"
#include "libft.h"
#include <stdio.h>

void execute_command(t_data *data)
{
	int	execve_return;
	char **commands;

	if (data->child_pid != 0)
		return;

	commands = ft_split(data->commands[data->num_of_current_command], ' ');
	int i = 0;
	while (commands[i] != NULL)
	{
		printf("COMMANDS VAL: %s\n", commands[i]);
		i++;
	}
	printf("path to ex: %s,\n", data->path_to_executable);
	

	execve_return = execve(data->path_to_executable, commands, data->enviroment_ptr);
	if (execve_return == -1)
		exit_clean(data, __FILE__, (__LINE__ - 2));
}
