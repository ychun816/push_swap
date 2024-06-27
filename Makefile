# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yilin <yilin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:20:33 by yilin             #+#    #+#              #
#    Updated: 2024/06/27 19:09:43 by yilin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_RESET = \033[0m
COLOR_PINKB = \033[1;95m
COLOR_REDB = \033[1;91m

NAME = push_swap


OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
RM = rm rf
### for libft###
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)
	@echo "$(COLOR_PINKB)🦄ALL DONE🦄$(COLOR_RESET)"

## compile libft
libft:
	$(MAKE) -C $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 
	@echo "$(COLOR_PINKB)✨COMPILATION DONE✨$(COLOR_RESET)"

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	@echo "$(COLOR_PINKB)🫧CLEAN DONE🫧$(COLOR_RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	@echo "$(COLOR_PINKB)🫧🫧FCLEAN DONE🫧🫧$(COLOR_RESET)"

re: fclean all

.PHONY: all clean fclean re