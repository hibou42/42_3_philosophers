#***** Name *****#

NAME			=		philosophers

#***** Makeflags *****#

MAKEFLAGS += --no-print-directory

#***** Sources / Objs *****#

SRC				=		philosophers.c \
						src/check.c \
						src/init.c \
						src/free_and_exit.c \
						src/str_to_int.c \
						src/routine.c \
						src/time.c \
						src/print.c \

OBJS			=		$(SRC:.c=.o)

#***** Couleurs *****#

GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#***** Textes *****#

START_TXT		=		echo "$(GREEN)Compilation of $(NAME) just started$(ENDCOLOR)"
TEST_TXT		=		echo "$(GREY)Running some test$(ENDCOLOR)\n"
LEAKS_TXT		=		echo "$(RED)Leaks mode activated$(ENDCOLOR)\n"
END_COMP_TXT	=		echo "$(GREEN)Compilation is done$(ENDCOLOR)"
CLEAN_TXT		=		echo "$(RED)Deleting objects$(ENDCOLOR)"
FCLEAN_TXT		=		echo "$(RED)Deleting program$(ENDCOLOR)"
CHARG_LINE_TXT	=		echo "$(BG_GREEN)    $(ENDCOLOR)\c"
BS_N_TXT		=		echo "\n"

#***** Flags *****#

CC				=		gcc
CFLAGS			=		-Wall -Wextra -Werror -pthread -fsanitize=thread -g3
L				=		$(CFLAGS)
RM				=		rm -f

# -fsanitize=thread -g3

#***** Compilation *****#

all : logo start $(NAME)

logo :
			@tput setaf 2; cat ascii_art/hibou; tput setaf default
			@$(BS_N_TXT)

start:
			@tput setaf 2; cat ascii_art/philosophers; tput setaf default
			@$(START_TXT)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@
			@$(CHARG_LINE_TXT)

$(NAME) :	${OBJS}
			@$(BS_N_TXT)
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
			@$(END_COMP_TXT)
			@tput setaf 2; cat ascii_art/small_hibou1; tput setaf default

leaks :		${OBJS}
			@$(BS_N_TXT)
			@${CC} ${L} -o ${NAME} ${OBJS}
			@$(END_COMP_TXT)
			@$(LEAKS_TXT)
			@./${NAME} 2 310 200 100 1
			@make fclean

test: 		all
			@$(TEST_TXT)
			@./$(NAME) 2 310 200 100 1
			@make fclean

#***** Clean *****#

clean:
			@$(CLEAN_TXT)
			@${RM} ${OBJS}
			@tput setaf 1; cat ascii_art/trash; tput setaf default

fclean:		clean
			@$(FCLEAN_TXT)	
			@${RM} ${NAME}
			@echo "$(GREEN)Cleaning succes$(ENDCOLOR)"

re:			fclean all

.PHONY:		all clean fclean 
