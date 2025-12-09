/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/09 13:06:53 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

static int get_infile_fd(char *infile_str);

void setup_struct(t_data *data, int argument_count, char **arguemt_vector,
                  char **enviroment_ptr)
{
	data->arguemt_vector = arguemt_vector;
	data->arguemtn_count = argument_count;
	data->enviroment_ptr = enviroment_ptr;
	data->input_file_fd = get_infile_fd(arguemt_vector[1]);
	data->path = get_all_paths(enviroment_ptr);
}

static int get_infile_fd(char *infile_str)
{
	int infile_fd;

	infile_fd = open(infile_str, O_RDONLY);
	if (infile_fd == -1)
		exit(0);
	return (infile_fd);
}
