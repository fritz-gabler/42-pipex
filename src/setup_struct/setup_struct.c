/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/25 11:19:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

void	setup_struct(t_data *data, int argc, char **argv, char **envp)
{
	(void) argc;
	data->envp = envp;
	initialize_data(data);
	set_pipe_fds(data);
	setup_first_child(data, argv);
	setup_second_child(data, argv);
}
