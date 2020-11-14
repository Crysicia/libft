# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpassera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/15 11:22:32 by lpassera          #+#    #+#              #
#    Updated: 2020/07/15 19:06:00 by lpassera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS			:=	$(shell uname -s)

AR 			= ar rc
CC			= gcc
CFLAGS 		= -Wall -Wextra -Werror
NORMINETTE  = ~/.norminette/norminette.rb
RM 			= rm -f
NAME 		= $(STATIC_NAME)
STATIC_NAME = libft.a
DYNAMIC_NAME = libft.so

ifeq ($(OS), Linux)
	CFLAGS += -fPIC
endif

SRCS 		= ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memccpy.c \
			  ft_memmove.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strlen.c \
			  ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_isspace.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \

BONUS_SRCS	= ft_lstnew.c \
			  ft_lstadd_front.c \
 			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c \

OBJS 		= $(SRCS:.c=.o)
BONUS_OBJS 	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

ifeq ($(OS), Linux)
so: $(OBJS)
	$(CC) $(OBJS) -shared -o $(DYNAMIC_NAME)

bonus: $(NAME) $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
	$(CC) $(OBJS) $(BONUS_OBJS) -shared -o $(DYNAMIC_NAME)
else
bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)
endif

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(DYNAMIC_NAME)

norme:
	$(NORMINETTE) $(SRCS) $(BONUS_SRCS)

re: fclean all

.PHONY: all bonus bonus_so clean fclean norme so
