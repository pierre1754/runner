##
## EPITECH PROJECT, 2020
## Base
## File description:
## Main Makefile
##

SRC =	flags.c									\
		src/start_engine.c						\
		src/draw_element.c						\
		src/draw_background.c					\
		src/get_element.c						\
		src/init_element.c						\
		src/set_element.c						\
		src/pause_game.c						\
		src/move_planes.c						\
		src/destroy_plane.c						\
		src/set_explosion.c						\
		src/set_element/set_asset.c				\
		src/set_element/set_poland.c			\
		src/set_element/set_engine.c			\
		src/set_element/set_environement.c		\
		src/set_element/set_object.c			\
		src/set_element/set_explosion.c			\
		src/set_element/set_window.c			\
		src/set_element/destroy_engine.c		\
		src/set_element/destroy_object.c		\

SRC_MAIN =	main.c								\

SRC_TEST =

OBJ =	$(SRC:.c=.o)

OBJ_MAIN =	$(SRC_MAIN)

OBJ_TEST =	$(SRC_TEST:.c=.o)

CFLAGS	=	-L lib/my -lmy -I include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

CFLAGS_TEST	=	--coverage -lcriterion

CFLAGS_DEBUG =	-Wall -Wextra -W -g

NAME =	my_hunter

NAME_TEST =	unit_tests

$(NAME): $(OBJ) $(OBJ_MAIN)
	@make -C lib/my
	@(gcc $(OBJ) $(OBJ_MAIN) -o $(NAME) $(CFLAGS)) > /dev/null

all:	$(NAME)

clean:
	@make clean -C lib/my
	@(rm -f $(OBJ)) > /dev/null
	@find . -name "*.gcno" -delete
	@find . -name "*.gcda" -delete
	@find . -name "*.o" -delete

fclean:	clean
	@make fclean -C lib/my
	@rm -f $(NAME)
	@(rm -f $(NAME) $(NAME_TEST)) > /dev/null
	@(rm -rf tests/coverage) > /dev/null
	@$(ECHO) $(CLEAR)

re:	fclean all

debug:
	@make -C lib/my
	gcc $(SRC) $(SRC_MAIN) -o $(NAME) $(CFLAGS) $(CFLAGS_DEBUG)

unit_tests: $(OBJ_TEST)
	@make -C lib/my
	@(gcc -o $(NAME_TEST) $(OBJ_TEST) $(SRC) $(CFLAGS_TEST) $(CFLAGS)) > /dev/null
	./$(NAME_TEST)

tests_run:	re unit_tests

gcovr: tests_run
	@gcovr --exclude tests
	@gcovr --exclude tests --branch

gen_html: unit_tests
	@(mkdir -p tests/coverage) > /dev/null
	@(lcov -c -d . --output-file tests/coverage/lcov) > /dev/null
	@(genhtml tests/coverage/lcov --output-directory tests/coverage) > /dev/null

html_run: gen_html
	@(firefox tests/coverage/index.html) > /dev/null
