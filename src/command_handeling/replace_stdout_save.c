/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stdout_save.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:39:10 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/17 10:39:11 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void replace_stdout_save(int file_fd_to_replace_with)
{
	int return_of_dup2;

	return_of_dup2 = dup2(file_fd_to_replace_with, STDOUT_FILENO); // check if input_file_fd really gets closed
	if(return_of_dup2 == -1)
		//throw Error
		return;
}

