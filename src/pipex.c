/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:18 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/28 19:16:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	input_validation(argc);
	setup_struct(&data, argc, argv, envp);

	fork_save(&data, FIRST_CHILD);
	if (data.child_pids[FIRST_CHILD])
		first_child(&data);
	fork_save(&data, SECOND_CHILD);
	if (data.child_pids[SECOND_CHILD])
		second_child(&data);

	close(data.pipe_fds[WRITE]);
	close(data.pipe_fds[READ]);
	waitpid(data.child_pids[FIRST_CHILD], NULL, 0);
	waitpid(data.child_pids[SECOND_CHILD], NULL, 0);

	return (0);
}
