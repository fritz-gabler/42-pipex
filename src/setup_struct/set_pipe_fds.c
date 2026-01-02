/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pipe_fds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:32:16 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/26 18:32:35 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_pipe_fds(t_data *data)
{
	int	pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return ;
	data->pipe_fds[WRITE] = pipe_fds[WRITE];
	data->pipe_fds[READ] = pipe_fds[READ];
}
