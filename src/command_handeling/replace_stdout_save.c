#include "pipex.h"

void replace_stdout_save(int file_fd_to_replace_with)
{
	int return_of_dup2;

	return_of_dup2 = dup2(file_fd_to_replace_with, STDOUT_FILENO); // check if input_file_fd really gets closed
	if(return_of_dup2 == -1)
		//throw Error
		return;
}

