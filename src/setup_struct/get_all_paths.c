#include <stdio.h>
#include "libft.h"

static int get_pos_of_path_env(char **envp);

char **get_all_paths(char **envp)
{
	int	pos_of_path;
	char **all_paths;

	pos_of_path = get_pos_of_path_env(envp);
	all_paths = ft_split(envp[pos_of_path], ':');
	printf("%s\n", all_paths[1]);
	return (all_paths);
}

static int get_pos_of_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (i);
		i++;
	}
	return (0);
}

