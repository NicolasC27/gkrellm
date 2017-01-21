##
## Makefile for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm
## 
## Made by Lucas Debouté
## Login   <debout_l@epitech.net>
## 
## Started on  Sat Jan 21 11:22:35 2017 Lucas Debouté
## Last update Sat Jan 21 19:00:18 2017 Lucas Debouté
##

CC	= g++
RM	= rm -f

CFLAGS	= -Wall -Wextra -std=c++03 -I ./includes

NAME	= gkrellm

SRCS	= srcs/main.cpp 		\
	  srcs/modules/System.cpp 	\
	  srcs/modules/Date.cpp 	\
	  srcs/modules/User.cpp 	\
	  srcs/modules/Ram.cpp		\
	  srcs/modules/Battery.cpp	\
	  srcs/modules/NetworkLoad.cpp

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
