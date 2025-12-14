#include "pipex.h"

void	set_pipe_fds(t_data *data)
{
	int pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		exit(0); // CLOSE AND FREE EVERYTHING
	data->pipe_fds[WRITE] = pipe_fds[WRITE];
	data->pipe_fds[READ] = pipe_fds[READ];
}
