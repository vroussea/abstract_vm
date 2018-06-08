# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/11/23 17:14:11 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

# comp
CC =		clang++
CFLAGS =	-Wall -Wextra -Werror
CPPVERSION =-std=c++11

# binaries
EXE = abstract_vm
LIB_A =

# dir
SRC_DIR =	srcs
TESTS_DIR = tests
OBJ_DIR =	objs
INC_DIR =	includes

# sources
MAIN_NAME = main.cpp
SRC_NAME =	Commands.cpp Lexer.cpp
TESTS_NAME =testCommands.cpp testLexer.cpp

# objects
OBJ_NAME =		$(SRC_NAME:.cpp=.o)
OBJ_MAIN_NAME =		$(MAIN_NAME:.cpp=.o)

#paths
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_NAME))
MAIN =		$(addprefix $(SRC_DIR)/, $(MAIN_NAME))
TESTS =		$(addprefix $(TESTS_DIR)/, $(TESTS_NAME))
OBJ =		$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
OBJ_MAIN =	$(addprefix $(OBJ_DIR)/, $(OBJ_MAIN_NAME))
INC =		$(addprefix -I, $(INC_DIR))

all :		$(EXE)
$(EXE) :	$(SRC) $(OBJ) $(OBJ_MAIN)
		@$(CC) $(OBJ) $(OBJ_MAIN) -o $@
		@echo "$(CLEAR)$(LIG)$(BLUE)  Compiling "$()"$(CLEAR)$(LIG)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
		@mkdir -p $(OBJ_DIR) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(CPPVERSION) $(INC) -o $@ -c $<

tests :
		$(CC) $(CFLAGS) $(CPPVERSION) $(INC) $(TESTS) $(SRC) -o test
		./test ; rm test

meteo :
		@curl http://wttr.in/Paris

clean :
		@echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
		@$(RM) $(OBJ) $(OBJ_MAIN)
		@rmdir $(OBJ_DIR) 2> /dev/null || true

fclean :	clean
		@echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
		@$(RM) $(EXE)

re :		fclean all

.PHONY :	all, clean, fclean, re, tests
.SILENT :