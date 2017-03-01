
NAME = arepnovs_filler

FLAGS =	-Wall -Wextra -Werror 

SRC =	arepnovs_filler.c\
		read.c\
		player1.c\
		player2.c\
		tools.c\
		aggressive_strategy.c\

LIBFT	= libft/libft.a

SRO  =  $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		@echo "Compiling Filler bot"
		@gcc $(FLAGS) -c $(SRC)
		@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
		@echo "arepnovs_filler is ready to fight"
		@make bonus

bonus: 	
		@echo "Compiling bonus"
		@gcc $(FLAGS) -o colorme colorme.c $(LIBFT)
		@echo "Let the colors be!"
clean:
	@rm -f *.o
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME)
	@rm -f colorme
	@echo "Bot is successfully destroyed"

re: 
	@make fclean
	@make all
