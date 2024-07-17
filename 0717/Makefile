# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yilin <yilin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 12:11:58 by yilin             #+#    #+#              #
#    Updated: 2024/07/17 16:38:29 by yilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              COLOR SETTING                                   #
# **************************************************************************** #

COLOR_RESET = \033[0m
PINKB = \033[1;95m
REDB = \033[1;91m
ROSEB = \033[1;38;5;225m
BLUEB = \033[1;34m
GREENB = \033[1;38;5;85m
PURPLEB = \033[1;38;5;55m

# **************************************************************************** #
#                                 MAIN                                         #
# **************************************************************************** #

NAME = push_swap
HEADER = includes/push_swap.h

# **************************************************************************** #
#                               DIRECTORIES                                    #
# **************************************************************************** #

LIBFT = libft
LIBFT_INCLUDES = $(LIBFT)/includes
SRCS_DIR = srcs/
OBJS_DEPS_DIR = objs_deps/

# **************************************************************************** #
#                         SRCS, OBJS, DEPENTDENCIES                            #
# **************************************************************************** #

PUSH_SWAP_SRCS = commands/cmd_push\
		 		 commands/cmd_rotate\
				 commands/cmd_rrotate\
				 commands/cmd_swap\
				 stack_operations/avs_to_stack_a\
				 stack_operations/check_error\
				 stack_operations/cleanup_function\
			 	 stack_operations/get_cheapest_a2b\
				 stack_operations/get_cheapest_b2a\
				 stack_operations/push_swap\
				 stack_operations/stack_helper\
				 sort/sort_helper\
				 sort/sort_stack_small\
				 sort/sort_stack_big\

PUSH_SWAP_FILES = $(addsuffix .c, $(PUSH_SWAP_SRCS))
SRCS = $(addprefix $(SRCS_DIR), $(PUSH_SWAP_FILES))
OBJS = $(addprefix $(OBJS_DEPS_DIR), $(PUSH_SWAP_FILES:.c=.o))
DEPS = $(addprefix $(OBJS_DEPS_DIR), $(PUSH_SWAP_FILES:.c=.d))
OBJS_FLAGS = .cache_exists

# **************************************************************************** #
#                            COMPILER & FLAGS                                  #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_INCLUDES) -Iincludes -g3
AR = ar rcs
RM = rm -rf
LIB_FLAGS = -L$(LIBFT) -lft
LIBFT_A = $(LIBFT)/libft.a

# **************************************************************************** #
#                             BUILD COMMANDS                                   #
# **************************************************************************** #

all: $(NAME)
	@echo "$(ROSEB)🦄COMPILATION DONE! [$(NAME)] CREATED🦄$(COLOR_RESET)"

$(OBJS_DEPS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER) #| $(OBJS_DEPS_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREENB)---COMPILING $< TO $@---$(COLOR_RESET)"

$(NAME): $(OBJS) $(LIBFT_A)
	@make -sC ./$(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREENB)---LINKING---$(NAME)$(COLOR_RESET)"

$(LIBFT_A):
	@make -C $(LIBFT)

# **************************************************************************** #
#                             CLEAN COMMANDS                                   #
# **************************************************************************** #

clean:
	@$(RM) $(OBJS_DEPS_DIR)
	@make clean -C $(LIBFT)
	@echo "$(GREENB)🫧CLEAN DONE! OBJS & DEPS of [$(NAME)] REMOVED🫧$(COLOR_RESET)"

fclean: clean
	@$(RM) $(NAME)
	@rm -f $(LIBFT_A)
	@echo "$(GREENB)🫧🫧FCLEAN DONE! [$(LIBFT_A)] REMOVED🫧🫧$(COLOR_RESET)"
	@echo "$(GREENB)🫧🫧FCLEAN DONE! [$(NAME)] REMOVED🫧🫧$(COLOR_RESET)"

re: fclean all
	@echo "$(REDB)RE DONE$(COLOR_RESET)"

-include $(DEPS)

.PHONY: all clean fclean re
