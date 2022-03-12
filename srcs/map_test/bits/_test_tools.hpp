/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:08:25 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 02:04:48 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_header.hpp"

#ifndef _MAP_TEST_TOOLS_HPP
#define _MAP_TEST_TOOLS_HPP

namespace _test_map
{
    /**
     * @brief PRINT VECTOR
     */
    template <typename _map>
    void test_print(const _map &M)
    {
        std::cout << "empty : " << M.empty() << std::endl;
        std::cout << "size : " << M.size() << std::endl;
        // std::cout << "max size : " << v.max_size() << std::endl;
        if (!M.empty())
        {
            std::cout << "content : " << std::endl;
            for (typename _map::const_iterator it = M.begin(); it != M.end(); it++)
                std::cout << it->first << " => " << it->second << std::endl;
            std::cout << "reverse content : " << std::endl;
            for (typename _map::const_reverse_iterator it = M.rbegin(); it != M.rend(); it++)
                std::cout << it->first << " => " << it->second << std::endl;
        }
    }
}


#endif  //_MAP_TEST_TOOLS_HPP