# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 12:40:04 by gbreana           #+#    #+#              #
#    Updated: 2022/03/06 13:42:40 by gbreana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME		=	server
CNAME		=	client

LIB			=	-L ./libft -lft
LIBFT		=	libft.a

SSRC		=	server.c
CSRC		=	client.c

SOBJS		=	$(patsubst %.c,%.o,$(SSRC))
COBJS		=	$(patsubst %.c,%.o,$(CSRC))

SDEPS		=	$(patsubst %.c,%.d,$(SSRC))
CDEPS		=	$(patsubst %.c,%.d,$(CSRC))

CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra -MD
RM			=	rm -rf

override		OBJS_ALL ?= $(SOBJS) $(COBJS)
override		DEP_ALL ?= $(SDEPS) $(CDEPS)

%.o:			%.c Makefile libft/libft.a
				$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}


all:			$(LIBFT) $(SNAME) $(CNAME)

$(LIBFT):
				@make -C libft


$(SNAME):		$(LIBFT) $(SOBJS)
				@$(CC) $(SOBJS) $(LIB) -o $@

$(CNAME):		$(LIBFT) $(COBJS)
				@$(CC) $(COBJS) $(LIB) -o $@

$(NAME):		$(LIBFT) $(CNAME) $(SNAME)

clean:
				@make clean -C libft
				$(RM) $(SOBJS) $(COBJS) $(SDEPS) $(CDEPS)

fclean:			clean
				@make fclean -C libft
				$(RM) $(SNAME) $(CNAME)

re:				fclean all

.PHONY:		all clean fclean re