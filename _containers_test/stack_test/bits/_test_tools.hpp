/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:08:25 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 02:05:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_header.hpp"

#ifndef _stack_TEST_TOOLS_HPP
#define _stack_TEST_TOOLS_HPP

namespace _test_stack
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
}

#endif  //_stack_TEST_TOOLS_HPP