
NAME = ft_containers

MAP_TEST = map_test
VEC_TEST = vector_test
VEC_STD = vector_std

SRC = main3.cpp \

_MAP_TEST = _containers_test/_test-map.cpp
_VEC_TEST = _containers_test/_test-vector.cpp

CC = clang++
CPPSTD = -std=c++98
CFLAGS = -Wall -Wextra -Werror -MMD -MP

MEM = -fsanitize=address -g3 
DEBUG = -fstandalone-debug

INC = -I./containers

OBJDIR = objs

DEPS = ${OBJS:.o=.d}

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})

all : ${NAME}

${MAP_TEST} : fclean ${_MAP_TEST_OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

${VEC_STD} : _TEST= -D _NAMESPACE=std

${VEC_STD} : ${VEC_TEST}

${VEC_TEST} : fclean ${_VEC_TEST_OBJS}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

vector_diff : 
	-make -s ${VEC_STD} && ./vector_test > std.out
	-make -s ${VEC_TEST} && ./vector_test > ft.out
	-diff -u std.out ft.out > diff.log

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${_TEST} ${INC} $(DEBUG) ${MEM} ${CPPSTD} -c $< -o $@

re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME} ${RBT_TEST} ${MAP_TEST}

.PHONY : all clean fclean vector_diff

-include ${DEPS}
