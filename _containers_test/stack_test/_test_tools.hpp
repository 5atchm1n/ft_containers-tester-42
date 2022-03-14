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
            v.push(rdm_val <std::string>);
    }

    template <typename _stack>
    void test_print(_stack &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v.top() << std::endl;
            v.pop();
        }
    }

    class vect_proxy : std::vector<std::string>
    {
        vect_proxy() {std::cout << "test ok" << std::endl;}
    }

    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }
    
    template <>
    std::string rdm_val<std::string>()
    {
        std::string default_val[18] =
            {
                "This is a test",
                "there are many tests",
                "all tests should pass",
                "Lorem ipsum dolor sit amet",
                "consectetur adipiscing elit.",
                "Phasellus ut rutrum ante.",
                "Sed vehicula tellus eu erat",
                "congue dictum. Fusce a ultrices",
                "",
                "magna. Morbi fringilla ullamcorper",
                "nisi id scelerisque.",
                "Curabitur elementum enim",
                "a mi vestibulum eleifend.",
                "Pellentesque eget risus efficitur",
                "euismod mi ut, tristique lorem.",
                "Praesent ullamcorper venenatis augue,",
                "\t",
                "eget pretium velit vehicula et."};
        return (std::string(default_val[std::rand() % 18]));
    }

    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }
}

#endif