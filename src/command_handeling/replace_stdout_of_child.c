/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stdout_of_child.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:13:01 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/18 14:00:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

static bool is_last_child(const t_data *data);

void replace_stdout_of_child(t_data *data)
{
	if (data->child_pid != 0)
		return ;
	if (is_last_child(data) == true)
	{
		replace_stdout_save(data->output_file_fd);
	}
	else
		replace_stdout_save(data->pipe_fds[WRITE]);
}

static bool is_last_child(const t_data *data)
{
	if (data->num_of_current_command == data->number_of_commands - 1)
		return (true);
	return (false);
}
