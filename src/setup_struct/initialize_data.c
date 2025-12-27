/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:31:54 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/26 18:31:55 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	initialize_child(t_child *child);

void	initialize_data(t_data *data)
{
	data->pipe_fds[0] = -1;
	data->pipe_fds[1] = -1;
	data->child_pids[0] = -1;
	data->child_pids[1] = -1;
	initialize_child(&data->first_child);
	initialize_child(&data->second_child);
}

static void	initialize_child(t_child *child)
{
	child->input_file_fd = -1;
	child->output_file_fd = -1;
	child->execve_argv = NULL;
	child->path = NULL;
}
