/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:06:46 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/27 09:03:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////INCLUDES////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////DEFINES/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

# define READ 0
# define WRITE 1
# define CHILD 0
# define IS_CORRECT_PATH 0
# define FIRST_CHILD 0
# define SECOND_CHILD 1

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////STRUCTS/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


typedef struct s_child
{
	char	**execve_argv;
	char	*path;
	int		input_file_fd;
	int		output_file_fd;
}	t_child;

typedef struct s_data
{
	t_child	first_child;
	t_child	second_child;
	int		pipe_fds[2];
	int		child_pids[2];
	char	**envp;
}	t_data;

typedef struct s_path_sizes
{
	size_t	command_len;
	size_t	path;
	size_t	path_to_executable_len;
}	t_path_sizes;



///////////////////////////////////////////////////////////////////////////////
//////////////////////////////FUNCTION DECLATATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Input check
void	input_validation(int argument_count);

//STRUCT SETUP
void	setup_struct(t_data *data, int argc, char **argv, char **envp);

char	*get_resolved_path(char *command, char **envp);
void	initialize_data(t_data *data);
void	setup_first_child(t_data *data, char **argv);
void	setup_second_child(t_data *data, char **argv);


char	**get_all_paths(char **envp);
int get_outfile_fd(char *infile_str);
int get_infile_fd(char *infile_str);
void	set_pipe_fds(t_data *data);
char **get_commands(int number_of_commands, char **arguemt_vector);

//CHILD HANDELING
void	first_child(t_data *data);
void	second_child(t_data *data);
void	fork_save(t_data *data, int child);



//COMMAND HANDELING
void resolve_path(t_data *data);
void create_child(t_data *data);
void replace_stdin_of_child(t_data *data);
void replace_stdout_of_child(t_data *data);
void replace_stdin_save(int file_fd_to_replace_with);
void replace_stdout_save(int file_fd_to_replace_with);
void execute_command(t_data *data);

//ERROR HANDELING

void exit_clean(t_data *data, char *error, int error_code);


#endif // PIPEX_H
