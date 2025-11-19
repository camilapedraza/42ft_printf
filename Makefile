# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 16:52:21 by mpedraza          #+#    #+#              #
#    Updated: 2025/11/19 18:24:35 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I libft
# LDFLAGS := -L .
# LDLIBS := -l:$(NAME)

FTS := ft_printf
SRCS := $(FTS:%=%.c)
OBJS := $(SRCS:%.c=%.o)

LIBFT := $(LIBFT_DIR)/$(LIBFT_NAME)
LIBFT_NAME := libft.a
LIBFT_DIR := libft

#TEST_SRCS := $(SRCS:%=test_%)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rcs $@ $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)


# test: $(NAME) $(TEST_SRCS)
#	override undefine CPPFLAGS
#	$(CC) $(CFLAGS) $(TEST_SRCS) $(TESTLDFLAGS) $(TESTLDLIBS)

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBFT_DIR)/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_DIR)/$(LIBFT_NAME)

re: fclean all

.PHONY: all clean fclean re test



