### MAKEFILE FOR CONTAINERS

## VARIABLES
# Makefile Rules

NAME = ft_containers

VEC_FT = ft_vector

VEC_STD = std_vector

MAP_FT = ft_map

MAP_STD = std_map

SET_FT = ft_set

SET_STD = std_set

STACK_FT = ft_stack

STACK_STD = std_stack
# Makefile recipe specific Rules

STACK_TEST = stack_test
MAP_TEST = map_test
VEC_TEST = vector_test
SET_TEST = set_test
OBJDIR = objs
MKDIR_P = mkdir -p
LOG_DIR = log
BIN_DIR = bin

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

# Debug and Memory

#DEBUG = -fstandalone-debug -g3
#MEM = -fsanitize=address 

ifeq ($(NO_MEM),1)
MEM = 
endif

# Map
_MAP_TEST = _containers_test/_test-map.cpp
# Vector
_VEC_TEST = _containers_test/_test-vector.cpp
# Set 
_SET_TEST = _containers_test/_test-set.cpp
# Stack
_STACK_TEST = _containers_test/_test-stack.cpp
# END

## INCLUDE FILES
# Global include
INC = -I./containers

## DEPENDECIES recipe
VEC_DEPS = ${_VEC_TEST_OBJS:.o=.d}
MAP_DEPS = ${_MAP_TEST_OBJS:.o=.d}
SET_DEPS = ${_SET_TEST_OBJS:.o=.d}


## OBJS DIR recipe
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})
_SET_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_SET_TEST:.cpp=.o})
_STACK_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_STACK_TEST:.cpp=.o})

# GLOBAL MAKE ALL

all : test_vector test_map test_stack test_set

# default recipe

# object file recipe
${OBJDIR}/%.o:%.cpp
	@${MKDIR_P} ${@D}
	${CC} ${CXXFLAGS} ${_TEST} ${MEM} ${INC} $(DEBUG) $(_INC_RBT_TEST)  ${CPPSTD} -c $< -o $@

# END GLOBAL ALL

# SET

${SET_FT} : ${SET_TEST}
	mv ${SET_TEST} ${SET_FT}

${SET_STD}: _TEST=-D_NAMESPACE=std

${SET_STD}: ${SET_TEST}
	mv ${SET_TEST} ${SET_STD}

# TEST MAP
# generate map exectutable

${SET_TEST} : clean ${_SET_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_SET_TEST_OBJS} -o $@

TEST_SET = test_set

${TEST_SET} : clean
	@echo ${BLUE} "\n\t RUN SET TESTS" ${RESET}
	@echo ${CYAN} "Make std_set :\t" ${RESET}
	@make -s ${SET_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${SET_STD} > ${LOG_DIR}/${SET_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_set:\t" ${RESET}
	@make -s ${SET_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${SET_FT} > ${LOG_DIR}/${SET_FT}.out 2> ${LOG_DIR}/${SET_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${SET_STD}.out ${LOG_DIR}/${SET_FT}.out > ${LOG_DIR}/set.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# SET END

# MAP

${MAP_FT} : ${MAP_TEST}
	mv ${MAP_TEST} ${MAP_FT}

${MAP_STD}: _TEST=-D_NAMESPACE=std

${MAP_STD}: ${MAP_TEST}
	mv ${MAP_TEST} ${MAP_STD}

# TEST MAP
# generate map exectutable

${MAP_TEST} : clean ${_MAP_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

TEST_MAP = test_map

${TEST_MAP} : clean
	@echo ${BLUE} "\n\t RUN MAP TESTS" ${RESET}
	@echo ${CYAN} "Make std_map :\t" ${RESET}
	@make -s ${MAP_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${MAP_STD} > ${LOG_DIR}/${MAP_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_map:\t" ${RESET}
	@make -s ${MAP_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${MAP_FT} > ${LOG_DIR}/${MAP_FT}.out 2> ${LOG_DIR}/${MAP_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${MAP_STD}.out ${LOG_DIR}/${MAP_FT}.out > ${LOG_DIR}/map.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# MAP END

# VECTOR
# create make calls for ft and std

${VEC_FT} : ${VEC_TEST}
	mv ${VEC_TEST} ${VEC_FT}

${VEC_STD} : _TEST=-D_NAMESPACE=std

${VEC_STD} : ${VEC_TEST}
	mv ${VEC_TEST} ${VEC_STD}

# VECTOR
# generate vector exectutable

${VEC_TEST} : clean ${_VEC_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

TEST_VECTOR = test_vector

${TEST_VECTOR} : clean
	@echo ${BLUE} "\n\t RUN VECTOR TESTS" ${RESET}
	@echo ${CYAN} "Make std_vector :\t" ${RESET}
	@make -s ${VEC_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${VEC_STD} > ${LOG_DIR}/${VEC_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_vector :\t" ${RESET}
	@make -s ${VEC_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${VEC_FT} > ${LOG_DIR}/${VEC_FT}.out 2> ${LOG_DIR}/${VEC_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${VEC_STD}.out ${LOG_DIR}/${VEC_FT}.out > ${LOG_DIR}/vector.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}

# VECTOR END

# STACK
# create make calls for ft and std

${STACK_FT} : ${STACK_TEST}
	mv ${STACK_TEST} ${STACK_FT}

${STACK_STD} : _TEST=-D_NAMESPACE=std

${STACK_STD} : ${STACK_TEST}
	mv ${STACK_TEST} ${STACK_STD}

# STACK
# generate vector exectutable

${STACK_TEST} : clean ${_STACK_TEST_OBJS}
	${CC} ${CXXFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_STACK_TEST_OBJS} -o $@

# TEST STACK
TEST_STACK = test_stack

${TEST_STACK} : clean
	@echo ${BLUE} "\n\t RUN VECTOR TESTS" ${RESET}
	@echo ${CYAN} "Make std_stack :\t" ${RESET}
	@make -s ${STACK_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@${MKDIR_P} ${LOG_DIR} 
	@echo -n ${YELLOW} " RUN TEST - STD\t" ${RESET}
	@-./${STACK_STD} > ${LOG_DIR}/${STACK_STD}.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo ${CYAN} "Make ft_stack :\t" ${RESET}
	@make -s ${STACK_FT}
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@echo -n ${YELLOW} " RUN TEST - FT\t\t" ${RESET}
	@-./${STACK_FT} > ${LOG_DIR}/${STACK_FT}.out 2> ${LOG_DIR}/${STACK_FT}.mem.out
	@echo ${GREEN} "[ DONE ]" ${RESET}
	@-diff -u ${LOG_DIR}/${STACK_STD}.out ${LOG_DIR}/${STACK_FT}.out > ${LOG_DIR}/stack.diff.log
	@echo ${BLUE} "\n\tcheck log dir for output" ${RESET}



# TEST TIMING
time :
	@echo -n ${YELLOW} "std::vector = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${VEC_STD} > /dev/null
	@echo -n ${BLUE} "ft::vector = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${VEC_FT} > /dev/null
	@echo -n ${YELLOW} "std::map = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${MAP_STD} > /dev/null
	@echo -n ${BLUE} "ft::map = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${MAP_FT} > /dev/null
	@echo -n ${YELLOW} "std::set = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${SET_STD} > /dev/null
	@echo -n ${BLUE} "std::set = " ${RESET}
	@/usr/bin/time -f "real : %E -- user : %U -- sys : %S" ./${SET_FT} > /dev/null


# COMMON RULES
re : fclean all

clean :
	@echo -n ${BLUE} "clean objs :\t\t" ${RESET}
	@rm -rf ${OBJDIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

fclean : clean tclean
	@echo -n ${BLUE} "clean binaries:\t" ${RESET}
	@rm -f ${VEC_FT} ${VEC_STD} ${MAP_STD} ${MAP_FT} ${SET_FT} ${SET_STD} ${STACK_FT} ${STACK_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}

tclean : clean
	@echo -n ${BLUE} "clean test logs :\t" ${RESET}
	@rm -rf ${LOG_DIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

.PHONY : all clean fclean tclean

# ADD DEPENDECIES
-include ${DEPS}
