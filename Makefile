NAME = push_swap
BONUS_NAME = checker //보너스 헤더 따로 만들기
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = //작성 필요한 부분.
SRCS_BONUS = //작성 필요한 부분. /libft/get_next_line.c /libft/get_next_line_utils.c
INC = ./push_swap.h
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
RM = rm
RMFLAGS = -f

ifdef BONUS
$(NAME): $(OBJS_BONUS)
	 $(CC) $(CFLAGS) -o $@ $^
else
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
endif

all: $(NAME)

bonus :
	make BONUS=1

clean:
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean: 
	make clean
	$(RM) $(RMFLAGS) $(NAME)

re: 
	make fclean
	make all

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: all clean fclean re bonus