#include <string>
#include <climits>
#include <fstream>
#include <iostream>

#ifndef _VECTOR_TEST_TOOLS_HPP
#define _VECTOR_TEST_TOOLS_HPP

namespace _test
{
    template <typename _vector>
    void test_print(const _vector &v)
    {
        std::cout << "empty: " << v.empty() << std::endl;
        std::cout << "size: " << v.size() << std::endl;
        if (!v.empty())
        {
            std::cout << "front: " << v.front() << std::endl;
            std::cout << "back: " << v.back() << std::endl;
            std::cout << "content: " << std::endl;
            for (typename _vector::const_iterator it = v.begin(); it != v.end(); it++)
                std::cout << *it << std::endl;
            std::cout << "reverse content: " << std::endl;
            for (typename _vector::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
                std::cout << *it << std::endl;
        }
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