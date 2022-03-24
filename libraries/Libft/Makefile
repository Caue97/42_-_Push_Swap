NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIB			= ar -rcs
LIB1		= ranlib
RM			= /bin/rm -f

INCLUDE		=	libft.h
SRCS		=	ft_bzero.c ft_calloc.c ft_strdup.c \
				ft_atoi.c ft_itoa.c ft_memcmp.c ft_strnstr.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memcpy.c ft_memset.c ft_memmove.c ft_memchr.c ft_striteri.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_split.c \

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB) $(NAME) $(OBJS)
			$(LIB1) $(NAME)

git:
			git add .
			git commit -m "updating norminette v3"
			git push

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re