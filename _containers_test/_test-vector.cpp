#include "vector_test/_test_header.hpp"

template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_list[])(_vector &, _vector &) =
        {
            &_test::test_constructors,
            &_test::test_copy,
            &_test::test_assign_op,
            &_test::test_relational_op,
            &_test::test_insert,
            &_test::test_assign,
            &_test::test_push,
            &_test::test_pop,
            &_test::test_erase,
            &_test::test_resize,
            &_test::test_swap,
            &_test::test_clear,
            &_test::test_reserve
        };
    
    _vector X;
    _vector Y;

    for (int i = 0; i < _NTESTS; i++)
    {
        switch (std::rand() % _TEST_NB)
        {
        case (_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_list[_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_list[_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (_COPY_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_list[_COPY_CONSTRUCTOR](X, Y);
            else
                _test_list[_COPY_CONSTRUCTOR](Y, X);
            break;
        case (_ASSIGNMENT_OP):
            if (std::rand() % 2)
                _test_list[_ASSIGNMENT_OP](X, Y);
            else
                _test_list[_ASSIGNMENT_OP](Y, X);
            break;
        case (_REL_OP) :
            if (std::rand() % 2)
                _test_list[_REL_OP](X, Y);
            else
                _test_list[_REL_OP](Y, X);
            break;
        case (_INSERT):
            if (std::rand() % 2)
                _test_list[_INSERT](X, Y);
            else
                _test_list[_INSERT](Y, X);
            break;
        case (_ASSIGN):
            if (std::rand() % 2)
                _test_list[_ASSIGN](X, Y);
            else
                _test_list[_ASSIGN](Y, X);
            break;
        case (_PUSH):
            if (std::rand() % 2)
                _test_list[_PUSH](X, Y);
            else
                _test_list[_PUSH](Y, X);
            break;
        case (_POP):
            if (std::rand() % 2)
                _test_list[_POP](X, Y);
            else
                _test_list[_POP](Y, X);
            break;
        case (_ERASE):
            if (std::rand() % 2)
                _test_list[_ERASE](X, Y);
            else
                _test_list[_ERASE](Y, X);
            break;
        case (_RESIZE):
            if (std::rand() % 2)
                _test_list[_RESIZE](X, Y);
            else
                _test_list[_RESIZE](Y, X);
            break;
        case (_SWAP):
            _test_list[_SWAP](X, Y);
            break;
        case (_CLEAR) :
            _test_list[_CLEAR](X, Y);
            break;
        case (_RESERVE) :
            _test_list[_RESERVE](X, Y);
            break;
        }
        _test::test_print(X);
        _test::test_print(Y);
    }
}

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
        test_vector<_NAMESPACE::vector<std::string> >(seed++);
    return 0;
}