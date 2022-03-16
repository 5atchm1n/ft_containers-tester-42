#include <string>
#include <climits>

#ifndef _SET_TEST_TOOLS_HPP
#define _SET_TEST_TOOLS_HPP

namespace _test
{
    template <typename _set>
    void test_print(const _set &M)
    {
        std::cout << "empty: " << M.empty() << std::endl;
        std::cout << "size: " << M.size() << std::endl;
        if (!M.empty())
        {
            std::cout << "content: " << std::endl;
            for (typename _set::const_iterator it = M.begin(); it != M.end(); it++)
                std::cout << *it << std::endl;
            std::cout << "reverse content: " << std::endl;
            for (typename _set::const_reverse_iterator it = M.rbegin(); it != M.rend(); it++)
                std::cout << *it << std::endl;
        }
    }

    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }

    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }

}

#endif