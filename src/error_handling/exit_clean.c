#include "pipex.h"
#include <errno.h>
#include <stdio.h>

void exit_clean(t_data *data, char *error)
{
	(void) data;
	perror(error);
	//close all fds
	//free all memory
	exit(1);
}

