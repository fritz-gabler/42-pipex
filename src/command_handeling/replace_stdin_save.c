#include "pipex.h"

void replace_stdin_save(int file_fd_to_replace_with)
{
	int return_of_dup2;

	return_of_dup2 = dup2(STDIN_FILENO, file_fd_to_replace_with);
	if(return_of_dup2 == -1)
		//throw Error
		return;
}

