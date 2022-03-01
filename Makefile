NAME        =   push_swap
CHECKER     =   checker
SRC         =   big_sort.c komand.c libft_functions.c sort_3and5.c validator.c komand2.c komand3.c \
				list_and_index.c atoi_strncmp.c push_swap.c\
		
SRC_CHECKER =   checker.c
SRC_PUSH    =   intmain.c
HEADER      =   push_swap.h

OBJ         =   $(SRC_PUSH:%.c=%.o)     $(SRC:%.c=%.o)
OBJ_CHECKER =   $(SRC_CHECKER:%.c=%.o)  $(SRC:%.c=%.o)
OBJS        =   $(SRCS:%.c=%.o)
CC          =   gcc
CFLAGS      =   -Wall -Wextra -Werror -I$(HEADER)

.PHONY      :   all clean fclean re checker

all         :   $(NAME)
checker     :   $(CHECKER)
$(NAME)     :   $(OBJ) $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ) $(OBJS) -o $(NAME)

$(CHECKER)  :   $(OBJ_CHECKER) $(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJ_CHECKER) $(OBJS) -o $(CHECKER)
%.o         :   %.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@
clean       :
				@rm -f $(OBJ) $(OBJ_CHECKER) $(OBJS)
fclean      :   clean
				@$(RM) $(NAME) $(CHECKER)
re          :   fclean all