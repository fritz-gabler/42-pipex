/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/09 13:19:43 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

static int get_file_fd(char *infile_str, int flags);

void setup_struct(t_data *data, int argument_count, char **arguemt_vector,
                  char **enviroment_ptr)
{
	char *out_file_str;

	data->arguemt_vector = arguemt_vector;
	data->arguemtn_count = argument_count;
	data->enviroment_ptr = enviroment_ptr;
	data->input_file_fd = get_file_fd(arguemt_vector[1], O_RDONLY);
	out_file_str = arguemt_vector[argument_count - 1];
	data->output_file_fd = get_file_fd(out_file_str, O_WRONLY | O_CREAT);
	data->path = get_all_paths(enviroment_ptr);
}

static int get_file_fd(char *infile_str, int flags)
{
	int file_fd;

	file_fd = open(infile_str, flags);
	if (file_fd == -1)
		exit(0);
	return (file_fd);
}
