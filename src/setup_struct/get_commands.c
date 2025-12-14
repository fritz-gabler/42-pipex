#include "pipex.h"
#include "libft.h"
#include <stdio.h>

char **get_commands(int number_of_commands, char **arguemt_vector)
{
	char	**commands;
	int		i;

	i = 0;
	commands = (char**) malloc(sizeof(char *) * (number_of_commands + 1));
	if (commands == NULL)
		return (NULL);
		//handle errro
	while(number_of_commands != i)
	{
		commands[i] = ft_strdup(arguemt_vector[i + 2]);
		//Error check
		i++;
	}
	commands[i] = NULL;
	return (commands);
}
