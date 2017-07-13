NAME = fillit

HEADER = fillit.h

OBJ = list.o main.o termits.o valid.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAGS) -o $(NAME) -I $(HEADER) $(OBJ)

list.o: list.c
	@gcc -c $(FLAGS) list.c

main.o: main.c
	@gcc -c $(FLAGS) main.c

termits.o: termits.c
	@gcc -c $(FLAGS) termits.c

valid.o: valid.c
	@gcc -c $(FLAGS) valid.c

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

