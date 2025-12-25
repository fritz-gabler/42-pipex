/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:29:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/25 09:58:25 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static void setup_first_child(t_data *data, char **argv, char **envp);
static void fail_check(t_data *data, t_child *child);

void setup_struct(t_data *data, int argc, char **argv, char **envp)
{
	(void) argc;
	initialize_data(data);
	set_pipe_fds(data);
	setup_first_child(data, argv, envp);
}

static void setup_first_child(t_data *data, char **argv, char **envp)
{
	t_child *first_child;

	first_child = &data->first_child;
	first_child->execve_argv = ft_split(argv[2], ' ');
	first_child->path = get_resolved_path(first_child->execve_argv[0], envp);
	first_child->input_file_fd = open(argv[1], O_RDONLY);
	fail_check(data, &data->first_child);
}

static void fail_check(t_data *data, t_child *child)
{
	if (data->pipe_fds[0] == -1 || data->pipe_fds[1] == -1)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->output_file_fd == -1 && child->input_file_fd == -1)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->execve_argv == NULL)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->path == NULL)
		exit_clean(data, __FILE__, __LINE__);
}
