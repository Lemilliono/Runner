NAME	=	CORTEIZ

SRC		=	source/main.c\
			source/draw.c\
			source/init.c\
			source/input.c

OBJ     =   $(SRC:.c=.o)

CFLAGS  +=  -I./include
CFLAGS  +=  -W -Werror -Wall -Wextra

LIBS    +=  -lSDL2 -lSDL2_image 

all:        $(NAME)

$(NAME):    $(OBJ)
    $(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
    rm -f $(OBJ)

fclean:        clean
    rm -f $(NAME)