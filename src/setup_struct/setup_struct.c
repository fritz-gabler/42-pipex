/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/09 12:55:59 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include "libft.h"

static int get_infile_fd(char *infile_str);
static int get_pos_of_path_env(char **envp);
static char **get_all_paths_from_env(char **envp);

void setup_struct(t_data *data, int argument_count, char **arguemt_vector,
                  char **enviroment_ptr)
{
	data->arguemt_vector = arguemt_vector;
	data->arguemtn_count = argument_count;
	data->enviroment_ptr = enviroment_ptr;
	data->input_file_fd = get_infile_fd(arguemt_vector[1]);
	data->path = get_all_paths_from_env(enviroment_ptr);
}

static int get_infile_fd(char *infile_str)
{
	int infile_fd;

	infile_fd = open(infile_str, O_RDONLY);
	if (infile_fd == -1)
		exit(0);
	return (infile_fd);
}

static char **get_all_paths_from_env(char **envp)
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
