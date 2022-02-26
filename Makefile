
NAME = ft_containers

MAP_TEST = map_test

VEC_FT = ft_vector
VEC_STD = std_vector

SRC = _containers_test/main3.cpp

_MAP_TEST = _containers_test/_test-map.cpp
_VEC_TEST = _containers_test/_test-vector.cpp

CC = clang++
CPPSTD = -std=c++98
CFLAGS = -Wall -Wextra -Werror -MMD -MP

MEM = -fsanitize=address -g3 
#DEBUG = -fstandalone-debug

INC = -I./containers

OBJDIR = objs

DEPS = ${OBJS:.o=.d}

OBJS = $(addprefix ${OBJDIR}/, ${SRC:.cpp=.o})
_VEC_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_VEC_TEST:.cpp=.o})
_MAP_TEST_OBJS = $(addprefix ${OBJDIR}/, ${_MAP_TEST:.cpp=.o})

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${CPPSTD} ${OBJS} -o $@

${OBJDIR}/%.o:%.cpp
	@mkdir -p ${@D}
	${CC} ${CFLAGS} ${_TEST} ${INC} $(DEBUG) ${MEM} ${CPPSTD} -c $< -o $@

${MAP_TEST} : fclean ${_MAP_TEST_OBJS}
	${CC} ${CFLAGS} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_MAP_TEST_OBJS} -o $@

${VEC_STD} : _TEST= -D _NAMESPACE=std

${VEC_STD} : ${VEC_FT}

${VEC_FT} : tclean ${_VEC_TEST_OBJS}
	${CC} ${CFLAGS} ${_TEST} ${INC} ${MEM} ${DEBUG} ${CPPSTD} ${_VEC_TEST_OBJS} -o $@

vector_test : 
	mkdir -p bin/logs
	-make -s ${VEC_STD} && mv ft_vector bin/std_vector
	-make -s ${VEC_FT} && mv ft_vector bin/ft_vector
	-./bin/${VEC_STD} > bin/logs/std.out
	-./bin/${VEC_FT} > bin/logs/ft.out
	-diff -u bin/logs/std.out bin/logs/ft.out > bin/logs/diff.log	

re : fclean all

clean :
	rm -rf ${OBJDIR}

fclean : clean
	rm -f ${NAME} ${VEC_FT} ${VEC_STD}

tclean : fclean
	rm -rf bin

.PHONY : all clean fclean test_vector

-include ${DEPS}