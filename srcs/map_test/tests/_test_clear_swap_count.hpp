/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:56:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _MAP_TEST_MODIFY_HPP
#define _MAP_TEST_MODIFY_HPP

namespace _test_map
{
    template <typename _map>
    void
    test_clear(_map &X, _map &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - CLEAR" << std::endl;
        if (std::rand() % 2)
            X.clear();
        else
            Y.clear();
    }
    
    template <typename _map>
    void test_swap(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - SWAP" << std::endl;
        if (!X.empty() && !Y.empty())
        {
            typename _map::const_iterator it_x = X.begin();
            typename _map::const_iterator it_y = Y.begin();
            X.swap(Y);
            std::cout << "Check iterator validy" << std::endl;
            std::cout << "valid : " << (it_x == Y.begin()) << std::endl;
            std::cout << "valid : " << (it_y == X.end()) << std::endl;
        }
    }

    template <typename _map>
    void test_count(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - COUNT" << std::endl;
        
        _map Z(Y);

        for (int i = 0; i < MAX_MAP_KEY; i++)
        {
            std::cout << i ;
            if (Z.count(i) > 0)
                std::cout << " is in map" << std::endl;
            else
                std::cout << std::endl;
        }
        (void)X;
    }
}

#endif  // _map_TEST_MODIFY_HPP