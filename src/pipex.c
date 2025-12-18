/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:18 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/18 14:07:19 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argument_count, char **arguemt_vector, char **enviroment_ptr)
{
	t_data data;

	if (is_input_valid(argument_count, arguemt_vector) == false)
	{
		write(STDERR_FILENO,
			"Invalid input, correct usage: ./pipex file1 cmd1 cmd2 file2\n", 61);
		return (1);
	}

	setup_struct(&data, argument_count, arguemt_vector, enviroment_ptr);
	while (data.num_of_current_command < data.number_of_commands)
	{
		resolve_path(&data);
		create_child(&data);
		replace_stdin_of_child(&data);
		replace_stdout_of_child(&data);
		execute_command(&data);
		data.num_of_current_command++;
	}
	//wait for children
	//clear_data
	return (0);
}
