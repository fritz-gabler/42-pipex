#include "libft.h"
#include "pipex.h"

static void set_stdin_of_first_child(t_data *data);
//static void set_stdout_of_first_child(t_data *data);

void first_child(t_data *data)
{
	t_child *first_child;

	first_child = &data->first_child;
	set_stdin_of_first_child(data);
	//set_stdout_of_first_child(data);
	execve(first_child->path, first_child->execve_argv, data->envp);
}

static void set_stdin_of_first_child(t_data *data)
{
	if (dup2(data->first_child.input_file_fd, STDIN_FILENO) == -1)
		exit_clean(data, __FILE__, __LINE__);
	close(data->first_child.input_file_fd);
}

/*
static void set_stdout_of_first_child(t_data *data)
{
	if (dup2(data->pipe_fds[WRITE], STDOUT_FILENO) == -1)
		exit_clean(data, __FILE__, __LINE__);
	close(data->pipe_fds[WRITE]);
	close(data->pipe_fds[READ]);
}
*/
