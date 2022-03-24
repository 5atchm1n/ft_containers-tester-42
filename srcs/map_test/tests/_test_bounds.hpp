/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_bounds.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:34:09 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_BOUNDS_M_HPP
#define _TEST_BOUNDS_M_HPP

namespace _test_map
{
    
template <typename _map>
void test_bounds(_map &X, _map &Y)
{
    std::cout << "TEST : " << mtest_no++;
    std::cout << " - BOUNDS" << std::endl;
    
    typedef typename _map::iterator iterator;
    iterator it;
    iterator itlow;
    iterator itup;
    switch (std::rand() % 2)
    {
        case (0) :
            std::cout << "BOUNDS - case 0" << std::endl;
            if (!X.empty())
            {
                it = X.begin();
                size_t rdn = std::rand() % X.size();
                while (rdn--)
                    it++;
                if (it != X.end())
                {
                    std::cout << "chosen node" << std::endl;
                    std::cout << it->first << " => " << it->second << std::endl;
                    itlow = X.lower_bound(it->first);
                    itup = X.upper_bound(it->first);
                    std::cout << "lower" << std::endl;
                    for (iterator it = itlow; it != X.end(); ++it)
                        std::cout << it->first << " => " << it->second << std::endl;
                    std::cout << "upper" << std::endl;
                    for (iterator it = itup; it != X.end(); ++it)
                        std::cout << it->first << " => " << it->second << std::endl;
                }
            }
        case (1) :
            std::cout << "BOUNDS : case 1" << std::endl;
            if (!Y.empty())
            {
                it = Y.begin();
                size_t rdn = std::rand() % Y.size();
                while (rdn--)
                    it++;
                if (it != Y.end())
                {
                    std::cout << "chosen node" << std::endl;
                    std::cout << it->first << " => " << it->second << std::endl;
                    itlow = Y.lower_bound(it->first);
                    itup = Y.upper_bound(it->first);
                    std::cout << "lower" << std::endl;
                    for (iterator it = itlow; it != Y.end(); ++it)
                        std::cout << it->first << " => " << it->second << std::endl;
                    std::cout << "upper" << std::endl;
                    for (iterator it = itup; it != Y.end(); ++it)
                        std::cout << it->first << " => " << it->second << std::endl;
                }
            }
    }
}

}   // END NAMESPACE

#endif  // _map_TEST_MODIFY_HPP