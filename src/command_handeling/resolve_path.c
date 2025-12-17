#include "pipex.h"
#include "libft.h"
#include <stdio.h>

static char *get_current_command(const t_data *data);
static char *get_path_to_executable(const t_data *data);

void resolve_path(t_data *data)
{
	int i;
	char *path_to_executable;

	i = 0;
	while (data->path[i] != NULL)
	{
		path_to_executable = get_path_to_executable(data);
		if (access(path_to_executable, X_OK) == IS_CORRECT_PATH)
		{
			data->path_to_executable = path_to_executable;
			return ;
		}
		free(path_to_executable);
		i++;
	}
}

static char *get_path_to_executable(const t_data *data)
{
	char *current_command;
	char *path_to_executable;

	current_command = get_current_command(data);
	path_to_executable = ft_strjoin(data->path[i], "/"); // check for not freed mem
	path_to_executable = ft_strjoin(path_to_executable, current_command); // als here
}

static char *get_current_command(const t_data *data)
{
	char *current_command;
	char **current_command_with_flags;


	current_command_with_flags = ft_split(
			data->commands[data->num_of_current_command], ' ');
	//check for fail
	current_command = ft_strdup(current_command_with_flags[0]);
	//free doubble char array
	//check for fail
	return (current_command);
}
