/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:06:46 by fgabler           #+#    #+#             */
/*   Updated: 2025/12/15 11:59:24 by fgabler          ###   ########.fr       */
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////STRUCTS/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

typedef struct s_data
{
	int		pipe_fds[2];
	int		arguemtn_count;
	char	**arguemt_vector;
	char	**enviroment_ptr;
	int		input_file_fd;
	int		output_file_fd;
	char	**path;
	int		number_of_commands;
	int		num_of_current_command;
	char	**commands;
	char	*path_to_executable;
	int		child_pid;
}	t_data;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////FUNCTION DECLATATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Input check
bool	is_input_valid(int argument_count, char **argument_vector);

//STRUCT SETUP
void	setup_struct(t_data *data, int argument_count, char **arguemt_vector,
			char **enviroment_ptr);
char	**get_all_paths(char **envp);
int	get_file_fd(char *infile_str, int flags);
void	set_pipe_fds(t_data *data);
char **get_commands(int number_of_commands, char **arguemt_vector);

//COMMAND HANDELING
void resolve_path(t_data *data);
void create_child(t_data *data);
void replace_stdin_of_child(t_data *data);
void replace_stdout_of_child(t_data *data);
void replace_stdin_save(int file_fd_to_replace_with);
void replace_stdout_save(int file_fd_to_replace_with);
void execute_command(t_data *data);

//ERROR HANDELING
void exit_clean(t_data *data, char *error);


#endif // PIPEX_H
