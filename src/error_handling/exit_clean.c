#include "pipex.h"
#include <errno.h>
#include <stdio.h>
#include <libft.h>

void exit_clean(t_data *data, char *error, int line)
{
	(void) data;
	ft_printf("Line: %d ", line);
	perror(error);
	//close all fds
	//free all memory
	exit(1);
}

