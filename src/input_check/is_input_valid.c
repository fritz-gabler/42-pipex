/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:29 by fritzgabler       #+#    #+#             */
/*   Updated: 2025/12/09 10:02:17 by fritzgabler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	is_num_of_args_correct(int argument_count);
static bool	does_input_file_exists(char *file_name);

bool	is_input_valid(int argument_count, char **argument_vector)
{
	if (is_num_of_args_correct(argument_count) == false)
		return (false);
	if (does_input_file_exists(argument_vector[1]) == false)
		return (false);
	return (true);
}

static bool	is_num_of_args_correct(int argument_count)
{
	if (argument_count == 5)
		return (true);
	return (false);
}

static bool	does_input_file_exists(char *file_name)
{
	int	file_fd;

	file_fd = open(file_name, O_RDONLY);
	if (file_fd == -1)
		return (false);
	close(file_fd);
	return (true);
}
