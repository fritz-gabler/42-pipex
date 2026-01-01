/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:18 by fritzgabler       #+#    #+#             */
/*   Updated: 2026/01/01 16:42:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_data data;

	input_validation(argc);
	setup_struct(&data, argc, argv, envp);
	printf("infile: %d\n", data.first_child.input_file_fd);
	printf("outfile: %d\n", data.second_child.output_file_fd);

	fork_save(&data, FIRST_CHILD);
	if (data.child_pids[FIRST_CHILD])
		first_child(&data);
	fork_save(&data, SECOND_CHILD);
	if (data.child_pids[SECOND_CHILD])
		second_child(&data);

//	close(data.pipe_fds[WRITE]);
//	close(data.pipe_fds[READ]);
//	close(data.first_child.input_file_fd);
//	close(data.second_child.output_file_fd);
	waitpid(data.child_pids[FIRST_CHILD], NULL, 0);
	waitpid(data.child_pids[SECOND_CHILD], NULL, 0);
	clean_data(&data);
	return (0);
}
