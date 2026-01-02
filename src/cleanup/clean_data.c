/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:58:36 by fgabler           #+#    #+#             */
/*   Updated: 2026/01/02 14:56:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static void	close_pipes(t_data *data);
static void	close_in_and_outfile(t_child *child);
static void	clean_child(t_child *child);

void	clean_data(t_data *data)
{
	close_pipes(data);
	clean_child(&data->first_child);
	clean_child(&data->second_child);
}

static void	close_pipes(t_data *data)
{
	if (data->pipe_fds[0] != -1)
		close(data->pipe_fds[0]);
	if (data->pipe_fds[1] != -1)
		close(data->pipe_fds[1]);
}

static void	clean_child(t_child *child)
{
	close_in_and_outfile(child);
	if (child->execve_argv != NULL)
		free_dubble_array(child->execve_argv);
	if (child->path != NULL)
		ft_free_string_save(&child->path);
}

static void	close_in_and_outfile(t_child *child)
{
	if (child->input_file_fd != -1)
		close(child->input_file_fd);
	if (child->output_file_fd != -1)
		close(child->output_file_fd);
}
