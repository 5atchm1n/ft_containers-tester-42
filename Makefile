### MAKEFILE FOR CONTAINERS

## VARIABLES
# Makefile Rules

## RUN COMPARE TESTS
TEST_MAP = test_map
TEST_VECTOR = test_vector
TEST_SET = test_set
TEST_STACK = test_stack
TEST = test
TEST_BONUS = test_bonus
TEST_ALL = test_all
TEST_ALL_BONUS = test_all_bonus
## RULES
FT = ft
STD = std
# VECTOR
VEC_FT = ft_vector
VEC_STD = std_vector
# MAP
MAP_FT = ft_map
MAP_STD = std_map
# SET
SET_FT = ft_set
SET_STD = std_set
# STACK
STACK_FT = ft_stack
STACK_STD = std_stack

# Makefile recipe specific variables
OBJDIR = objs
MKDIR_P = mkdir -p
LOG_DIR = log
BIN_DIR = bin
CONST_TEST = -D_TCONST=1

# Makefile colours
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
GREY="\033[0;37m"
RESET="\033[m"

# Compiler directives

CC = clang++
CPPSTD = -std=c++98
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP

## DEPENDECIES recipe
DEPS = ${OBJS:.o=.d}

# Debug and Memory

#ifeq ($(TMEM),1)
MEM = -fsanitize=address 
#endif

#ifeq ($(TDEBUG),1)
DEBUG = -fstandalone-debug -g3
#endif

ifeq ($(TCONST),0)
CONST_TEST =
endif

# Main
_TEST_MAIN = srcs/_test-main.cpp

## INCLUDE FILES
# Global include
INC = -I./containers

## OBJS DIR recipe
OBJS = $(addprefix ${OBJDIR}/, ${_TEST_MAIN:.cpp=.o})

# object file recipe
${OBJDIR}/%.o:%.cpp
	@echo -n ${CYAN} "Create objects : \t"
	@${MKDIR_P} ${@D}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${MEM} ${DEBUG} ${INC} $(DEBUG) ${CPPSTD} -c $< -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

##
# GLOBAL
##
all : ${FT} ${STD}

bonus : _TEST+=-D_TSET=1

bonus : ${FT} ${STD}

# make ft

${FT} : _TEST+= -D_TVECTOR=1 -D_TMAP=1 -D_TSTACK=1

${FT} : ${OBJS}
	@echo -n ${CYAN} "Make ft : \t\t"
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# make std

${STD} : _TEST+= -D_NAMESPACE=std -D_TVECTOR=1 -D_TMAP=1 -D_TSTACK=1

${STD} : ${OBJS}
	@echo -n ${CYAN} "Make std : \t\t"
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# make test

${TEST} :
	@make -sB ${FT}
	@make -sB ${STD}
	@echo ${BLUE} "\n\t RUN CONTAINERS TESTS" ${RESET}
	@${MKDIR_P} ${LOG_DIR}
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${STD} > ${LOG_DIR}/${STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${FT} > ${LOG_DIR}/${FT}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${STD}.out ${LOG_DIR}/${FT}.out > ${LOG_DIR}/diff.log
	@echo ${BLUE} "\tcheck log dir for output" ${RESET}

# make test_bonus
${TEST_BONUS} : bonus ${TEST}

#make test_all

${TEST_ALL} : ${TEST_VECTOR} ${TEST_MAP} ${TEST_STACK}
	@${MKDIR_P} ${BIN_DIR}
	@mv -t ${BIN_DIR} ${VEC_STD} ${MAP_STD} \
			${STACK_STD} ${VEC_FT} ${MAP_FT} \
			${STACK_FT}

${TEST_ALL_BONUS} : ${TEST_VECTOR} ${TEST_MAP} ${TEST_STACK} ${TEST_SET}
	@${MKDIR_P} ${BIN_DIR}
	@mv -t ${BIN_DIR} ${VEC_STD} ${MAP_STD} \
			${STACK_STD} ${VEC_FT} ${MAP_FT} \
			${STACK_FT} ${SET_FT} ${SET_STD}

# make test_bonus
# END GLOBAL

##
# MAP
##

# Make ft_map
${MAP_FT} : _TEST+=-D_TMAP=1

${MAP_FT} : clean ${OBJS}
	@echo -n ${CYAN} "Make ft_map:\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# Make std_map
${MAP_STD}: _TEST+=-D_NAMESPACE=std -D_TMAP=1

${MAP_STD}: clean ${OBJS}
	@echo -n ${CYAN} "Make std_map :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}


${TEST_MAP} :
	@make -sB ${MAP_STD}
	@make -sB ${MAP_FT}
	@echo ${BLUE} "\n\t RUN MAP TESTS" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${MAP_STD} > ${LOG_DIR}/${MAP_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${MAP_FT} > ${LOG_DIR}/${MAP_FT}.out 2> ${LOG_DIR}/${MAP_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${MAP_STD}.out ${LOG_DIR}/${MAP_FT}.out > ${LOG_DIR}/map.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# MAP END

##
# VECTOR
##
# Make recipes to generate Map binaries

# Make ft_vector
${VEC_FT} : _TEST+=-D_TVECTOR=1

${VEC_FT} : ${OBJS}
	@echo -n ${CYAN} "Make ft_vector :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# Make std_vector
${VEC_STD} : _TEST+=-D_NAMESPACE=std -D_TVECTOR=1

${VEC_STD} : ${OBJS}
	@echo -n ${CYAN} "Make std_vector :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# VECTOR TEST


${TEST_VECTOR} :
	@make -sB ${VEC_STD}
	@make -sB ${VEC_FT}
	@echo ${BLUE} "\n\t RUN VECTOR TESTS" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${VEC_STD} > ${LOG_DIR}/${VEC_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${VEC_FT} > ${LOG_DIR}/${VEC_FT}.out 2> ${LOG_DIR}/${VEC_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${VEC_STD}.out ${LOG_DIR}/${VEC_FT}.out > ${LOG_DIR}/vector.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# VECTOR END

##
# STACK
##
# Make recipes to generate binaries

# make ft_stack
${STACK_FT} : _TEST+=-D_TSTACK=1

${STACK_FT} : ${OBJS} 
	@echo -n ${CYAN} "Make ft_stack :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

#make std_stack
${STACK_STD} : _TEST+=-D_NAMESPACE=std -D_TSTACK=1 

${STACK_STD} : ${OBJS} 
	@echo -n ${CYAN} "Make std_stack :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# TEST STACK

${TEST_STACK} :
	@make -sB ${STACK_STD}
	@make -sB ${STACK_FT}
	@echo ${BLUE} "\n\t RUN STACK TESTS" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${STACK_STD} > ${LOG_DIR}/${STACK_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${STACK_FT} > ${LOG_DIR}/${STACK_FT}.out 2> ${LOG_DIR}/${STACK_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${STACK_STD}.out ${LOG_DIR}/${STACK_FT}.out > ${LOG_DIR}/stack.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# END STACK

##
# SET
##
# Make recipes to generate binaries

# make ft_set
${SET_FT} : _TEST+=-D_TSET=1

${SET_FT} : ${OBJS}
	@echo -n ${CYAN} "Make ft_set:\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# make std_set
${SET_STD}: _TEST+=-D_NAMESPACE=std -D_TSET=1

${SET_STD}: ${OBJS}
	@echo -n ${CYAN} "Make std_set :\t" ${RESET}
	@${CC} ${CXXFLAGS} ${_TEST} ${CONST_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${OBJS} -o $@
	@echo ${GREEN} "[ DONE ]" ${RESET}

# TEST SET

${TEST_SET} :
	@make -sB ${SET_STD}
	@make -sB ${SET_FT}
	@echo ${BLUE} "\n\t RUN SET TESTS" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${SET_STD} > ${LOG_DIR}/${SET_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${SET_FT} > ${LOG_DIR}/${SET_FT}.out 2> ${LOG_DIR}/${SET_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${SET_STD}.out ${LOG_DIR}/${SET_FT}.out > ${LOG_DIR}/set.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# SET END

# TEST TIMING
time :
	@echo -n ${YELLOW} "std::vector = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${VEC_STD} > /dev/null
	@echo -n ${BLUE} "ft::vector = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${VEC_FT} > /dev/null
	@echo -n ${YELLOW} "std::map = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${MAP_STD} > /dev/null
	@echo -n ${BLUE} "ft::map = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${MAP_FT} > /dev/null
	@echo -n ${YELLOW} "std::stack = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${STACK_STD} > /dev/null
	@echo -n ${BLUE} "ft::stack = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${STACK_FT} > /dev/null

time_bonus:
	@echo -n ${YELLOW} "std::set = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${SET_STD} > /dev/null
	@echo -n ${BLUE} "ft::set = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${BIN_DIR}/${SET_FT} > /dev/null

# COMMON RULES
re : fclean all

clean :
	@echo -n ${BLUE} "clean objs :\t\t" ${RESET}
	@rm -rf ${OBJDIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

fclean : clean tclean
	@echo -n ${BLUE} "clean binaries:\t" ${RESET}
	@rm -f ${VEC_FT} ${VEC_STD} ${MAP_STD} ${MAP_FT} ${SET_FT} ${SET_STD} ${STACK_FT} ${STACK_STD} ${FT} ${STD}
	@rm -rf ${BIN_DIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

tclean : clean
	@echo -n ${BLUE} "clean test logs :\t" ${RESET}
	@rm -rf ${LOG_DIR} ${BIN_DIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

.PHONY : all bonus re fclean tclean

# ADD DEPENDECIES
-include ${DEPS}