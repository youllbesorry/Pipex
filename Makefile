# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 10:53:15 by bfaure            #+#    #+#              #
#    Updated: 2023/04/14 12:50:10 by bfaure           ###   ########lyon.fr    #
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

LIBFT_A = $(DIR_LIBFT)$(LIBFT)

# ---- Files ---- #

SRCS			=	main.c\
					parsing.c\
					utils.c\
					exec.c\
					init_data.c\

OBJS = ${SRCS:%.c=${DIR_OBJS}%.o}

DEPS = ${SRCS:%.c=${DIR_OBJS}%.d}

# ---- Compilation ---- #

CC		=	cc

DEPS_FLAGS = -MMD -MP

CFLAGS	=	${DEPS_FLAGS} -Wall -Wextra -Werror

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p

# ********* RULES ******** #

	
all		:	$(NAME)

$(LIBFT_A):	force
	@ ${MAKE} ${LIBFT} -C ${DIR_LIBFT} -j4

.PHONY:	all clean fclean re fclean_lib fclean_all force

# ---- Variables Rules ---- #

${NAME}	:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L${DIR_LIBFT} -lft

# ---- Compiled Rules ---- #

-include ${DEPS}

${DIR_OBJS}%.o	:	${DIR_SRCS}%.c $(LIBFT_A)
					@${MKDIR} ${DIR_OBJS}
					${CC} ${CFLAGS} -I $(DIR_LIBFT) -I. -c $< -o $@		

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
