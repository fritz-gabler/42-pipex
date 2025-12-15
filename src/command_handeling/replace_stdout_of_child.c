#include "pipex.h"

static bool is_last_child(const t_data *data);

void replace_stdout_of_child(t_data *data)
{
	if (data->child_pid != 0)
		return ;
	if (is_last_child(data) == true)
		replace_stdout_save(data->output_file_fd);
	else
		replace_stdout_save(data->pipe_fds[WRITE]);
}

static bool is_last_child(const t_data *data)
{
	if (data->num_of_current_command == data->number_of_commands)
		return (true);
	return (false);
}
