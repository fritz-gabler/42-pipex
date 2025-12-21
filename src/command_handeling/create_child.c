/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:38:46 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/17 10:38:47 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void create_child(t_data *data)
{
	int	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		//error
		return;
	data->child_pid = child_pid;
}
