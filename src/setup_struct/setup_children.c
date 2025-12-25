#include "pipex.h"
#include "libft.h"

static void fail_check(t_data *data, t_child *child);

void setup_first_child(t_data *data, char **argv, char **envp)
{
	t_child *first_child;

	first_child = &data->first_child;
	first_child->execve_argv = ft_split(argv[2], ' ');
	first_child->path = get_resolved_path(first_child->execve_argv[0], envp);
	first_child->input_file_fd = open(argv[1], O_RDONLY);
	fail_check(data, &data->first_child);
}

void setup_second_child(t_data *data, char **argv, char **envp)
{
	t_child *second_child;

	second_child = &data->second_child;
	second_child->execve_argv = ft_split(argv[3], ' ');
	second_child->path = get_resolved_path(second_child->execve_argv[0], envp);
	second_child->input_file_fd = open(argv[4],
									O_CREAT | O_WRONLY | O_TRUNC, 0644);
	fail_check(data, &data->second_child);
}

static void fail_check(t_data *data, t_child *child)
{
	if (data->pipe_fds[0] == -1 || data->pipe_fds[1] == -1)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->output_file_fd == -1 && child->input_file_fd == -1)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->execve_argv == NULL)
		exit_clean(data, __FILE__, __LINE__);
	else if (child->path == NULL)
		exit_clean(data, __FILE__, __LINE__);
}
