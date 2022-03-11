/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:08:25 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 17:11:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <climits>

#ifndef _stack_TEST_TOOLS_HPP
#define _stack_TEST_TOOLS_HPP

namespace _test
{
    /**
     * @brief PRINT VECTOR
     */
    template <typename _stack>
    void test_print(_stack &v)
    {
        std::cout << "empty : " << v.empty() << std::endl;
        std::cout << "size : " << v.size() << std::endl;
        // std::cout << "capacity : " << v.capacity() << std::endl;
        // std::cout << "max size : " << v.max_size() << std::endl;
        if (!v.empty())
        {
            std::cout << "top : " << v.top() << std::endl;
            std::cout << "content : " << std::endl;
            while (!v.empty())
            {
                std::cout << v.top() << std::endl;
                v.pop();
            }
        }
    }

    /**
     * @brief Template overload RDM_VAL
     */
    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }
    /**
     * @brief Generate a random string
     */
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

    /**
     * @brief Generate a random UINT
     *
     */
    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }
}

#endif  //_stack_TEST_TOOLS_HPP