/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/14 10:01:59 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <string.h>

void setup_struct(t_data *data, int argument_count, char **arguemt_vector,
                  char **enviroment_ptr)
{
	char *out_file_str;

	out_file_str = arguemt_vector[argument_count - 1];
	data->arguemt_vector = arguemt_vector;
	data->arguemtn_count = argument_count;
	data->enviroment_ptr = enviroment_ptr;
	data->input_file_fd = get_file_fd(arguemt_vector[1], O_RDONLY);
	data->output_file_fd = get_file_fd(out_file_str, O_WRONLY | O_CREAT);
	data->path = get_all_paths(enviroment_ptr);
	data->number_of_commands = argument_count - 3;
	data->num_of_current_command = 0;
	data->commands = get_commands(data->number_of_commands, arguemt_vector);
	set_pipe_fds(data);
}
