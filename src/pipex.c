#include "pipex.h"

int main(int argument_count, char **arguemt_vector, char **enviroment_ptr)
{
	(void) arguemt_vector;
	(void) enviroment_ptr;

	if (is_input_valid(argument_count) == false)
	{
		write(STDERR_FILENO,
		"Invalid input, correct usage: ./pipex file1 cmd1 cmd2 file2\n", 30);
		return (1);
	}
	return (0);
}
