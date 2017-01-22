##
## Makefile for gkrellm in /home/debout_l/Pool/Rush/cpp_gkrellm
## 
## Made by Lucas Debouté
## Login   <debout_l@epitech.net>
## 
## Started on  Sat Jan 21 11:22:35 2017 Lucas Debouté
## Last update Sun Jan 22 08:46:47 2017 Nicolas Chevalier
##

CC	= g++
RM	= rm -f

CFLAGS	= -Wall -Wextra -std=c++03 -I ./includes -g

NAME	= gkrellm

SRCS	= srcs/main.cpp 		\
	  srcs/modules/System.cpp 	\
	  srcs/modules/Cpu.cpp 		\
	  srcs/modules/Battery.cpp 	\
	  srcs/modules/Date.cpp 	\
	  srcs/modules/NetworkLoad.cpp 	\
	  srcs/modules/User.cpp 	\
	  srcs/modules/Ram.cpp		\
	  srcs/display/ncurses/DisplayRam.cpp \
	  srcs/display/ncurses/Ncurses.cpp \
	  srcs/display/ncurses/DisplayBatterie.cpp \
	  srcs/display/ncurses/DisplayNetwork.cpp \
	  srcs/display/ncurses/DisplayUser.cpp \
	  srcs/display/ncurses/DisplayDate.cpp \

OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) -lncurses

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
