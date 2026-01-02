#include "pipex.h"

static void set_stdin_of_second_child(t_data *data);
static void set_stdout_of_second_child(t_data *data);

void	second_child(t_data *data)
{
	t_child *second_child;

	second_child = &data->second_child;
	set_stdin_of_second_child(data);
	set_stdout_of_second_child(data);
	execve(second_child->path, second_child->execve_argv, data->envp);
	exit_clean(data, __FILE__, __LINE__);
}

static void	set_stdin_of_second_child(t_data *data)
{
	if (dup2(data->pipe_fds[READ], STDIN_FILENO) == -1)
		exit_clean(data, __FILE__, __LINE__);
	close(data->pipe_fds[READ]);
}


static void	set_stdout_of_second_child(t_data *data)
{
	if (dup2(data->second_child.output_file_fd, STDOUT_FILENO) == -1)
		exit_clean(data, __FILE__, __LINE__);
	close(data->pipe_fds[WRITE]);
	close(data->second_child.output_file_fd);
}
