/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fritzgabler <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:40:29 by fritzgabler       #+#    #+#             */
/*   Updated: 2026/01/02 16:38:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static bool	is_num_of_args_correct(int argument_count);

void	input_validation(int argument_count)
{
	if (is_num_of_args_correct(argument_count) == true)
		return ;
	write(STDERR_FILENO,
		"Invalid input, correct usage: ./pipex file1 cmd1 cmd2 file2\n", 61);
	exit(1);
}

static bool	is_num_of_args_correct(int argument_count)
{
	if (argument_count == 5)
		return (true);
	return (false);
}
