
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
		@echo "-----------------------------------"
		@echo "Compiling libft"
		@$(MAKE) -C ./libft
		@$(MAKE) clean -C ./libft
		@echo "-----------------------------------"
		@echo "Compiling Filler bot"
		@gcc $(FLAGS) -c $(SRC)
		@gcc $(FLAGS) -o $(NAME) $(SRC) $(LIBFT)
		@echo "-----------------------------------"
		@echo "arepnovs_filler is ready to fight"
		@make bonus

bonus: 	
		@echo "-----------------------------------"
		@echo "Compiling bonus"
		@gcc $(FLAGS) -o colorme colorme.c $(LIBFT)
		@echo "-----------------------------------"
		@echo "Let the colors be!"
		@echo "-----------------------------------"
clean:
	@rm -f *.o
	@echo "-----------------------------------"
	@echo "Objects successfully removed"
fclean:	
	@make clean
	@rm -f $(NAME)
	@rm -f colorme
	@$(MAKE) fclean -C ./libft
	@echo "-----------------------------------"
	@echo "Bot is successfully destroyed"

re: 
	@make fclean
	@make all
