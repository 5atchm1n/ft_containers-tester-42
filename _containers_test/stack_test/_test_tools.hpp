#include <string>
#include <climits>
#include <fstream>
#include <iostream>

#ifndef _STACK_TEST_TOOLS_HPP
#define _STACK_TEST_TOOLS_HPP

namespace _test
{
    template <typename _stack>
    void test_fill(_stack &v)
    {
        for (int i = 0; i < _MAX_TEST_SIZE; i++)
            v.push("test test test");
    }

    template <typename _stack>
    void test_print(_stack &v)
    {
        for (unsigned int i = 0; i < v.size(); i++)
        {
            std::cout << v.top() << std::endl;
            v.pop();
        }
    }

    class vect_proxy : public std::vector<std::string>
    {
    public:
        vect_proxy() {std::cout << "test ok" << std::endl;}
    };
}
#endif