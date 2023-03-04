# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:53:15 by bfaure            #+#    #+#              #
#    Updated: 2023/03/04 11:27:20 by bfaure           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	pipex

LIBFT		=	libft.a

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	=	src/

DIR_LIBFT	=	Libft/

# ---- Files ---- #

HEAD			=	header/pipex.h\

SRCS			=	main.c\
					parsing.c\
					utils.c\
					exec.c\

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

all		:	
	@ ${MAKE} libs -j4
	@ ${MAKE} ${NAME} -j4

libs	:
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT}

.PHONY:	all clean fclean re fclean_lib fclean_all

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

${addprefix ${DIR_LIBFT}, ${LIBFT}}	:
	@ $(MAKE) ${LIBFT} -C ${DIR_LIBFT}

# ---- Compiled Rules ---- #

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c ${HEAD} ./Libft/headers/ft_printf.h ./Libft/headers/get_next_line.h ./Libft/headers/libft.h | ${DIR_OBJS}
					${CC} ${CFLAGS} -I ${addprefix ${DIR_LIBFT}, headers/} -I. -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

fclean_lib		:
					make fclean -C ${DIR_LIBFT}

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

fclean_all		:	fclean fclean_lib

re				:	fclean_all
					$(MAKE)
