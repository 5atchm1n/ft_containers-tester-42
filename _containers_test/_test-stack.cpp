#include "stack_test/_test_header.hpp"

template <class _stack>
void test_stack(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_list[])(_stack &, _stack &) =
        {
            &_test::test_relational_op,
            &_test::test_push,
            &_test::test_pop
        };
    
    _stack X;
    _stack Y;

    for (int i = 0; i < _NTESTS; i++)
    {
        switch (std::rand() % _TEST_NB)
        {
        case (_REL_OP) :
            if (std::rand() % 2)
                _test_list[_REL_OP](X, Y);
            else
                _test_list[_REL_OP](Y, X);
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
        case (_DEFAULT_CONSTRUCTOR):
            _test::test_constructors();
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
        test_stack<_NAMESPACE::stack<std::string> >(seed++);
    return 0;
}