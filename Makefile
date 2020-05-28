##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compile
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\e[0m"
BOLD_T		=	"\e[1m"
DIM_T		=	"\e[2m"
UNDLN_T		=	"\e[4m"
BLACK_C		=	"\e[30m"
RED_C		=	"\e[31m"
GREEN_C		=	"\e[32m"
YELLO_C		=	"\e[33m"
BLUE_C		=	"\e[34m"
MAGEN_C		=	"\e[35m"
CYAN_C		=	"\e[36m"
WHITE_C		=	"\e[97m"
DEFAULT_C	=	"\e[39m"
LIGHT_GREY	=	"\e[37m"
DARK_GREY	=	"\e[90m"
LIGHT_RED	=	"\e[91m"
LIGHT_GREEN	=	"\e[92m"
LIGHT_YELLO	=	"\e[93m"
LIGHT_BLUE	=	"\e[94m"
LIGHT_MAGEN	=	"\e[95m"
LIGHT_CYAN	=	"\e[96m"
LINE_RETURN	=	$(ECHO) ""

NAME		=	groundhog
COLOR_THEME	=	$(WHITE_C)

ROOT_PATH	=	./
SRC_NAME	=	src
INCL_NAME	=	include
INCL_PATH	=	$(ROOT_PATH)$(INCL_NAME)
SRC_PATH	=	$(ROOT_PATH)$(SRC_NAME)

SRC			=	groundhog.cpp

SRCS		=	$(SRC:%=$(SRC_PATH)/%)
OBJ			=	$(SRCS:.cpp=.o)

SRC_MAIN	= src/main.cpp
OBJ_MAIN	= $(SRC_MAIN:.cpp=.o)

SRC_TEST	= 	tests/error.cpp \
				tests/functions.cpp
OBJ_TEST	= $(SRC_TEST:.cpp=.o)

CC			= g++
CFLAGS		= -ldl -I $(INCL_PATH)\

DEBUG_FLAGS	=	-g3 -gdwarf-4
MAKE_RULE	=	all
CLEAN_RULE	=	clean

all:	message $(NAME)

message:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)" ____        _ _     _"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| __ ) _   _(_) | __| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|  _ \| | | | | |/ _\` |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"| |_) | |_| | | | (_| |"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"|____/ \__,_|_|_|\__,_|"$(DEFAULT)
	@$(LINE_RETURN)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) && \
		$(ECHO) $(BOLD_T)$(GREEN_C)"\n[✔] COMPILED:" $(DEFAULT)$(LIGHT_GREEN) "$(NAME)\n"$(DEFAULT) || \
		$(ECHO) $(RED_C)$(BOLD_T)"[✘] "$(UNDLN_T)"BUILD FAILED:" $(LIGHT_RED) "$(NAME)\n"$(DEFAULT)

clean:
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_MAIN)
	@$(RM) $(OBJ_TEST)
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"$(NAME)'s object files"$(DEFAULT)
	@$(RM) vgcore.*
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Valgrind files"$(DEFAULT)
	@$(RM) tests/*.gcno
	@$(RM) tests/*.gcda
	@$(RM) src/*.gcno
	@$(RM) src/*.gcda
	@$(ECHO) $(RED_C)$(DIM_T)"[clean]  "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Tests files"$(DEFAULT)

fclean: CLEAN_RULE=fclean
fclean:	clean
	@$(RM) $(NAME)
	@$(RM) unit_tests
	@$(ECHO) $(RED_C)$(DIM_T)"[fclean] "$(DEFAULT) \
		$(RED_C)$(BOLD_T)"DELETED: "$(DEFAULT) \
		$(LIGHT_RED)"Binary $(NAME)"$(DEFAULT)

re:		fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: COLOR_THEME = $(CYAN_C)
debug: MAKE_RULE = debug
debug: re
	@$(ECHO) $(BOLD_T)$(COLOR_THEME)"⚠ DEBUG MODE ACTIVATED ⚠\n"$(DEFAULT)

message_tests:
	@$(LINE_RETURN)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)"  _______        _       "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)" |__   __|      | |      "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)"    | | ___  ___| |_ ___ "$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)"    | |/ _ \/ __| __/ __|"$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)"    | |  __/\__ \ |_\__ \""$(DEFAULT)
	@$(ECHO) $(BOLD_T)$(LIGHT_MAGEN)"    |_|\___||___/\__|___/"$(DEFAULT)
	@$(LINE_RETURN)

tests_run: clean message_tests
		@g++ -c -o tests/error.o tests/error.cpp $(CFLAGS) -lcriterion --coverage
		@g++ -c -o tests/functions.o tests/functions.cpp $(CFLAGS) -lcriterion --coverage
		@g++ -c -o src/groundhog.o src/groundhog.cpp $(CFLAGS) -lcriterion --coverage
		@$(CC) -o unit_tests $(OBJ) $(OBJ_TEST) -lcriterion --coverage
		@./unit_tests
		gcovr --exclude tests/

%.o: %.cpp
	@$(CC) -c $(CFLAGS) -o $@ $< && \
		$(ECHO) $(DIM_T) "cc $(CFLAGS) -c "$<$(COLOR_THEME)$(BOLD_T)" -o "$@ $(DEFAULT) || \
		$(ECHO) "\n"$(MAGEN_C) $(UNDLN_T)$(BOLD_T)"cc $(CFLAGS) -c "$<" -o "$@$(DEFAULT)"\n"

.PHONY: all message clean fclean re debug

.cpp.o:
	g++ -c -o $@ $< $(CFLAGS) -lcriterion --coverage


# SRC_DIR	=	src/
# INC_DIR	=	include/

# NAME	=	groundhog

# CFLAGS	=	-g3 -Wall -Wextra -Werror -I $(INC_DIR)

# SRC	=	$(SRC_DIR)groundhog.cpp

# OBJ	=	$(SRC:.cpp=.o)

# SRC_MAIN =	$(SRC_DIR)main.cpp
# OBJ_MAIN =	$(SRC_MAIN:.cpp=.o)

# RM	=	rm -f

# all:	$(NAME)

# $(NAME): $(OBJ) $(OBJ_MAIN)
# 	g++ -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)

# clean:
# 	$(RM) $(OBJ)
# 	$(RM) $(OBJ_MAIN)

# fclean: clean
# 	$(RM) $(NAME)

# re:	fclean all