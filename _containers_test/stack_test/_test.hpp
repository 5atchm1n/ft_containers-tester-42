#include "_test_tools.hpp"

#ifndef _STACK_TEST_HPP
#define _STACK_TEST_HPP

namespace _test
{
    void test_constructors()
    {
        std::cout << "TEST - CONSTRUCTORS" << std::endl;
        switch (std::rand() % 4)
        {
            case (0):
            {
                _NAMESPACE::stack<std::string, std::deque<std::string> > Z;
                Z.push("test test test test");
                std::cout << Z.top() << std::endl;
                break;
            }
            case (1):
            {
                _NAMESPACE::stack<std::string, std::vector<std::string> > K;
                K.push("test test test test");
                std::cout << K.top() << std::endl;
                break;
            }
            case (2):
            {
                _NAMESPACE::stack<std::string, std::list<std::string> > L;
                L.push("test test test test");
                std::cout << L.top() << std::endl;
                break;
            }
            case (3):
            {    
                _NAMESPACE::stack<std::string, _test::vect_proxy> U;
                break;
            }
        }
    }
    
    template <typename _stack>
    void test_relational_op(_stack &X, _stack &Y)
    {
        std::cout << "TEST - RELATIONAL OPERATOR" << std::endl;
        _NAMESPACE::stack<std::string, std::deque<std::string> > Z;
        test_fill<_NAMESPACE::stack<std::string, std::deque<std::string> > >(Z);
        _NAMESPACE::stack<std::string, std::deque<std::string> > K;
        test_fill<_NAMESPACE::stack<std::string, std::deque<std::string> > >(K);
        test_fill<_stack>(X);
        test_fill<_stack>(Y);
        std::cout << (Z == K) << std::endl;
        std::cout << (Z != K) << std::endl;
        std::cout << (Z > K) << std::endl;
        std::cout << (Z >= K) << std::endl;
        std::cout << (X < Y) << std::endl;
        std::cout << (X <= Y) << std::endl;
        test_print(Z);
        test_print(K);
    }

    template <typename _stack>
    void test_push(_stack &X, _stack &Y)
    {
        std::cout << "TEST - PUSH" << std::endl;
        test_fill<_stack>(X);
        test_fill<_stack>(Y);
        test_print<_stack>(X);
        test_print<_stack>(Y);
    }

    template <typename _stack>
    void test_pop(_stack &X, _stack &Y)
    {
        std::cout << "TEST - POP" << std::endl;
        test_fill<_stack>(X);
        test_fill<_stack>(Y);
        X.pop();
        Y.pop();
        test_print<_stack>(X);
        test_print<_stack>(Y);

    }
}


#endif 