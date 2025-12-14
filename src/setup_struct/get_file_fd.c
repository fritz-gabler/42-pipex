/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:57:04 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/10 16:05:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int get_file_fd(char *infile_str, int flags)
{
	int file_fd;

	file_fd = open(infile_str, flags);
	if (file_fd == -1)
		exit(0);
	return (file_fd);
}
