/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:58:35 by fgabler           #+#    #+#             */
/*   Updated: 2026/01/02 16:38:19 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	exit_clean(t_data *data, char *error, int error_code)
{
	perror(error);
	clean_data(data);
	exit(error_code);
}
