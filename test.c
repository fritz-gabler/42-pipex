#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "libft.h"

int main(void)
{
	char *str = "ls -l";
	char **test = ft_split(str, ' ');
	int i = 0;

	while (test[i] != NULL)
	{
		printf("%s\n", test[i]);
		i++;
	}
	int fd = open("test", O_WRONLY);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execve("/bin/ls", test, NULL);
	return (0);
}
