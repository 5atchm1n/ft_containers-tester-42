### MAKEFILE FOR CONTAINERS

## VARIABLES
# Makefile Rules

NAME = ft_containers

MAP_TEST = map_test

VEC_TEST = vector_test

TEST_VECTOR = test_vector

# Makefile recipe specific Rules

VEC_FT = ft_vector
VEC_STD = std_vector
OBJDIR = objs
MKDIR_P = mkdir -p
OUT_DIR = bin/log

# Compiler directives

CC = clang++
CPPSTD = -std=c++98
CFLAGS = -Wall -Wextra -Werror -MMD -MP

# Debug and Memory

MEM = -fsanitize=address -g3 
DEBUG = -fstandalone-debug

## SOURCE FILES
# Default
SRC = main3.cpp
# Map
_MAP_TEST = _containers_test/_test-map.cpp
# Vector
_VEC_TEST = _containers_test/_test-vector.cpp
# END

## INCLUDE FILES
# Global include
INC = -I./containers

## DEPENDECIES recipe
DEPS = ${OBJS:.o=.d}

## OBJS DIR recipe
OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})

# GLOBAL MAKE ALL

all : ${NAME}
# default recipe
${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

# object file recipe
${OBJDIR}/%.o:%.cpp
	@${MKDIR_P} ${@D}
	${CC} ${CFLAGS} ${_TEST} ${INC} $(DEBUG) ${MEM} ${CPPSTD} -c $< -o $@

# END GLOBAL ALL

# TEST MAP
# generate map exectutable

${MAP_TEST} : fclean ${_MAP_TEST_OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

# VECTOR
# create make calls for ft and std

${VEC_FT} : ${VEC_TEST}

${VEC_STD} : _TEST=-D _NAMESPACE=std

${VEC_STD} : ${VEC_TEST}

# VECTOR
# generate vector exectutable

${VEC_TEST} : ${_VEC_TEST_OBJS}
	@${MKDIR_P} ${OUT_DIR} 
	${CC} ${CFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

# Run test against stl and generate diff

${TEST_VECTOR} : tclean
	make -s ${VEC_STD} && mv ${VEC_TEST} ./bin/${VEC_STD} && make clean
	make -s ${VEC_FT} && mv ${VEC_TEST} ./bin/${VEC_FT}
	-./bin/${VEC_STD} > ${OUT_DIR}/std.out
	-./bin/${VEC_FT} > ${OUT_DIR}/ft.out
	-diff -u ${OUT_DIR}/std.out ${OUT_DIR}/ft.out > ${OUT_DIR}/diff.log

# VECTOR END

# COMMON RULES
re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME}

tclean : fclean
	rm -rf bin

.PHONY : all clean fclean tclean

# ADD DEPENDECIES
-include ${DEPS}