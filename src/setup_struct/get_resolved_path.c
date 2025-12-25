#include "libft.h"
#include "pipex.h"
#include <stdio.h>

static t_path_sizes get_path_to_executable_len(char *command, char *path);
static char *get_path_to_executable(char *command, char *path);

char *get_resolved_path(char *command, char **envp)
{
	int i;
	char **all_paths;
	char *path_to_executable;


	i = 0;
	all_paths = get_all_paths(envp);
	while (all_paths[i] != NULL)
	{
		path_to_executable = get_path_to_executable(command, all_paths[i]);
		if (access(path_to_executable, X_OK) == IS_CORRECT_PATH)
		{
			// FREE all pathes
			return (path_to_executable);
		}
		free(path_to_executable);
		i++;
	}
	//free all path
	//Fail check
	return (NULL);
}

static char *get_path_to_executable(char *command, char *path)
{
	char *path_to_executable;
	t_path_sizes	sizes;

	sizes = get_path_to_executable_len(command, path);
	path_to_executable = ft_calloc(sizeof(char), sizes.path_to_executable_len);
	ft_memcpy(path_to_executable, path, sizes.path);
	path_to_executable[sizes.path] = '/';
	ft_memcpy(path_to_executable + sizes.path + 1, command, sizes.command_len);
	path_to_executable[sizes.path_to_executable_len] = '\0'; 
	return (path_to_executable);
}

static t_path_sizes get_path_to_executable_len(char *command, char *path)
{
	t_path_sizes	sizes;
	
	sizes.command_len = ft_strlen(command);
	sizes.path = ft_strlen(path);
	sizes.path_to_executable_len = sizes.command_len + sizes.path + 2;
	return (sizes);
}
