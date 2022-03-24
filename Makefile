# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/08 17:36:51 by felcaue-          #+#    #+#              #
#    Updated: 2022/03/23 19:00:40 by felcaue-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	/bin/rm -rf
LIB			=	ar -rcs

LIBFT			=	libraries/Libft/libft.a
LIBFT_PATH		=	libraries/Libft

DIRECTORY	=	Objs_Push-Swap

INCLUDE		=	Source_Code/push_swap.h

SOURCE		=	check_args.c \
				error_clean.c \
				index_manager.c \
				main.c \
				sequence_content_info.c \
				sort_operation_p_.c \
				sort_operation_s_.c \
				sort_operation_r_.c \
				sort_operation_rr_.c \
				start_sorting.c \
				utils__sort_01.c \
				utils__sort_02.c \
				utils__sort_03.c \
				utils_01.c \
				utils_lists_01.c \
				utils_lists_02.c \
				

ADD_ARG_S	=	$(addprefix Source_Code/,$(SOURCE))

OBJS		=	$(addprefix $(DIRECTORY)/,$(SOURCE:.c=.o))

all:		$(NAME)

$(DIRECTORY)/%.o:	Source_Code/%.c
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(DIRECTORY) $(OBJS) $(INCLUDE)   $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@
			@echo "\033[1;32m\nCOMPILED SUCCESFULY!\033[0m\n\n"


$(DIRECTORY):
				mkdir -p $(DIRECTORY)

$(LIBFT):	
			make -C $(LIBFT_PATH)


clean:
			$(RM) $(DIRECTORY)
			make -C $(LIBFT_PATH) clean

fclean:		clean
			$(RM) $(NAME) 
			make -C $(LIBFT_PATH) fclean

myclean:	clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean
			clear

re:			fclean all

.PHONY:		all clean fclean re