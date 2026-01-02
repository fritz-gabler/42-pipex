/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 16:40:17 by fgabler           #+#    #+#             */
/*   Updated: 2026/01/02 16:40:18 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_save(t_data *data, int child)
{
	data->child_pids[child] = fork();
	if (data->child_pids[child] == -1)
		exit_clean(data, __FILE__, __LINE__);
}
