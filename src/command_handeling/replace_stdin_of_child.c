#include "pipex.h"
#include <stdio.h>

static bool is_first_child(const t_data *data);

void replace_stdin_of_child(t_data *data)
{
	if (data->child_pid != 0)
		return ;
	if (is_first_child(data) == true)
		replace_stdin_save(data->input_file_fd);
	else 
		replace_stdin_save(data->pipe_fds[READ]);
}

static bool is_first_child(const t_data *data)
{
	if (data->num_of_current_command == 0)
		return (true);
	return (false);
}
