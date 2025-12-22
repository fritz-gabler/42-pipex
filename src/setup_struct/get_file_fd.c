/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:57:04 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/22 07:59:54 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_infile_fd(char *infile_str)
{
	int file_fd;

	file_fd = open(infile_str, O_RDONLY);
	if (file_fd == -1)
		exit(0);
	return (file_fd);
}

int get_outfile_fd(char *infile_str)
{
	int file_fd;

	file_fd = open(infile_str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file_fd == -1)
		exit(0);
	return (file_fd);
}
