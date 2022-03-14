#include "_test_tools.hpp"

#ifndef _STACK_TEST_HPP
#define _STACK_TEST_HPP

namespace _test
{
    template <typename _stack>
    void test_constructors(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        switch (std::rand() % 4)
        {
            case (0):
                _NAMESPACE::stack<std::string, std::deque<std::string> > Z;
                Z.push(rdm_val <std::string>);
                std::cout << Z.top() << std::endl;
                break;
            case (1):
                _NAMESPACE::stack<std::string, std::vector<std::string> > Z;
                Z.push(rdm_val <std::string>);
                std::cout << Z.top() << std::endl;
                break;
            case (2):
                _NAMESPACE::stack<std::string, std::list<std::string> > Z;
                Z.push(rdm_val <std::string>);
                std::cout << Z.top() << std::endl;
                break;
            case (3):
                _NAMESPACE::stack<std::string, _test::vect_proxy> Z;
                break;
        }
        }
    }
    
    void test_relational_op(_stack &X, _stack &Y)
    {
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

    void test_push(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - PUSH" << std::endl;
        test_fill<_stack>(X);
        test_fill<_stack>(Y);
        test_print<_stack>(X);
        test_print<_stack>(Y);
    }

    template <typename _stack>
    void test_pop(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - POP" << std::endl;
        test_fill<_stack>(X);
        test_fill<_stack>(Y);
        X.pop();
        Y.pop();
        test_print<_stack>(X);
        test_print<_stack>(Y);

    }
}


#endif 