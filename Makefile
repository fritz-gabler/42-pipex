###############################################################################
###############################################################################

NAME			=			pipex

###############################################################################
###############################################################################

CC				=			cc
CFLAGS			=			-Wall -Werror -Wextra  -g #-fsanitize=address -g
HEADERS			=			-I./include -I./libs/include
LIBS			=			./libs
LIBS_NAME		=			./libs/libs.a

###############################################################################
###############################################################################

VPATH					=	src src/input_check src/setup_struct			\
							src/command_handeling src/error_handling		\
							src/child_handeling

SRC_MAIN				:=	pipex.c
SRC_INPUT_CHECK			:=	input_validation.c
SRC_SETUP_STRUCT		:=	setup_struct.c get_all_paths.c get_file_fd.c	\
							get_resolved_path.c initialize_data.c			\
							set_pipe_fds.c setup_children.c
SRC_ERROR_HANDLING		:=	exit_clean.c
SRC_CHILD_HANDELING		:=	first_child.c second_child.c fork_save.c

SOURCE					:=	$(SRC_MAIN) $(SRC_INPUT_CHECK)					\
							$(SRC_SETUP_STRUCT) $(SRC_ERROR_HANDLING)		\
							$(SRC_CHILD_HANDELING)

###############################################################################
###############################################################################

OBJ_DIR			:=	./_obj
OBJ				:=	$(addprefix $(OBJ_DIR)/, $(SOURCE:%.c=%.o))

###############################################################################
###############################################################################

all : $(NAME)

$(NAME): $(LIBS_NAME) $(OBJ)
	@echo $(YELLOW)Compiling [$(NAME)]...$(RESET)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) $(HEADERS) $(OBJ) $(LIBS_NAME) $(MLX_LIB) $(MLX) -o $(NAME)
	@echo $(GREEN)Finished"  "[$(NAME)]...$(RESET)

$(OBJ_DIR)/%.o: %.c
	@echo $(YELLOW)Compiling [$@]...$(RESET)
	@if [ ! -d "${OBJ_DIR}" ]; then											\
		mkdir -p _obj;														\
	fi
	@$(CC) $(CFLAGS) -c $< $(HEADERS) -o $@
	@printf $(UP)$(CUT)

$(LIBS_NAME):
	@git submodule update --remote --init -q
	@$(MAKE) -C $(LIBS) -B

###############################################################################
###############################################################################

clean:
	@if [ -d "${OBJ_DIR}" ]; then							\
			$(MAKE) -C ./libs clean;						\
			echo $(RED)Cleaning"  "[$(OBJ_DIR)]...$(RESET);	\
			rm -rf ${OBJ_DIR};								\
			echo $(GREEN)Cleaned!$(RESET);					\
	fi

###############################################################################
###############################################################################

fclean: clean
		@if [ -f "$(NAME)" ]; then								\
				$(MAKE) -C ./libs fclean;						\
				echo $(RED)Cleaning"  "[$(NAME)]...$(RESET);	\
				rm -f $(NAME);									\
				echo $(GREEN)Cleaned!$(RESET);					\
		fi

re: fclean all

###############################################################################
###############################################################################

.PHONY : clean fclean all re

###############################################################################
###############################################################################
YELLOW := "\033[33m"
RED := "\033[31m"
GREEN := "\033[32m"
RESET := "\033[0m"
UP := "\033[A"
CUT := "\033[K"
