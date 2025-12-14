#include "pipex.h"
#include "libft.h"
#include <stdio.h>

void resolve_path(t_data *data)
{
	int i;
	char *current_command;
	char *path_to_executable;

	i = 0;
	current_command = data->commands[data->num_of_current_command];
	while (data->path[i] != NULL)
	{
		path_to_executable = ft_strjoin(data->path[i], "/");
		path_to_executable = ft_strjoin(path_to_executable, current_command);
		if (access(path_to_executable, X_OK) == IS_CORRECT_PATH)
		{
			data->path_to_executable = path_to_executable;
			return ;
		}
		free(path_to_executable);
		i++;
	}
}
