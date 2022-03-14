
## INCLUDE FILES

INC = -I ..

## VARIABLES
# Makefile Rules

MAP_TEST = map_test

VEC_TEST = vector_test

STACK_TEST = stack_test

VEC_FT = ft_vector

VEC_STD = std_vector

MAP_FT = ft_map

MAP_STD = std_map

STACK_FT = ft_stack

STACK_STD = std_stack

# Compiler directives

CC = clang++
CPPSTD = -std=c++98
CFLAGS = -Wall -Wextra -Werror


# Makefile recipe specific Rules

OBJDIR = objs
MKDIR_P = mkdir -p

# Makefile colours

RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
BLUE="\033[1;34m"
PURPLE="\033[1;35m"
CYAN="\033[1;36m"
GREY="\033[0;37m"
RESET="\033[m"


## SOURCE FILES
# Map
_MAP_TEST = _containers_test/_test-map.cpp
# Vector
_VEC_TEST = _containers_test/_test-vector.cpp
# Stack
_STACK_TEST = _containers_test/_test-stack.cpp
# END

## OBJS DIR recipe
OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})
_STACK_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_STACK_TEST:.cpp=.o}) 

# GLOBAL MAKE ALL

all : ${NAME}
# default recipe
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${CPPSTD} ${OBJS} -o $@

# object file recipe
${OBJDIR}/%.o:%.cpp
	@${MKDIR_P} ${@D}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${CPPSTD} -c $< -o $@

# END GLOBAL ALL

# MAP

${MAP_FT} : ${MAP_TEST}
	mv ${MAP_TEST} ${MAP_FT}

${MAP_STD}: _TEST=-D_NAMESPACE=std

${MAP_STD}: ${MAP_TEST}
	mv ${MAP_TEST} ${MAP_STD}


# TEST MAP
# generate map exectutable

${MAP_TEST} : fclean ${_MAP_TEST_OBJS}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@


# VECTOR
# create make calls for ft and std

${VEC_FT} : ${VEC_TEST}
	mv ${VEC_TEST} ${VEC_FT}

${VEC_STD} : _TEST=-D_NAMESPACE=std

${VEC_STD} : ${VEC_TEST}
	mv ${VEC_TEST} ${VEC_STD}

# TEST VECTOR
# generate vector exectutable

${VEC_TEST} : fclean ${_VEC_TEST_OBJS}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

# STACK

${STACK_FT} : ${STACK_TEST}

${STACK_STD}: _TEST=-D_NAMESPACE=std

${STACK_STD}: ${STACK_TEST}


# TEST STACK
# generate stack exectutable

${STACK_TEST} : fclean ${_STACK_TEST_OBJS}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${CPPSTD} ${_STACK_TEST_OBJS} -o $@


# COMMON RULES
re : fclean all


# COMMON RULES
re : fclean all

clean :
	@echo -n ${BLUE} "clean objs :\t\t" ${RESET}
	@rm -rf ${OBJDIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

fclean : clean tclean lclean
	@echo -n ${BLUE} "clean binaries:\t" ${RESET}
	@rm -f  ${NAME} ${TEST_VECTOR} ${VEC_FT} ${VEC_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}

tclean : clean
	@echo -n ${BLUE} "clean tests:\t\t" ${RESET}
	@rm -rf ${VEC_TEST} ${VEC_FT} ${VEC_STD}
	@echo ${GREEN} "[ DONE ]" ${RESET}

lclean :
	@echo -n ${BLUE} "clean logs:\t\t" ${RESET}
	@rm -rf ${LOG_DIR}
	@echo ${GREEN} "[ DONE ]" ${RESET}

.PHONY : all clean fclean tclean

# ADD DEPENDECIES
-include ${DEPS}
