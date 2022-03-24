/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_bounds.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:36:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _SET_TEST_MODIFY_HPP
#define _SET_TEST_MODIFY_HPP

namespace _test_set
{

    template <typename _set>
    void test_bounds(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - BOUNDS" << std::endl;
        
        typedef typename _set::iterator iterator;
        iterator it;
        iterator itlow;
        iterator itup;
        switch (std::rand() % 2)
        {
            case (0) :
                std::cout << "BOUNDS : case 0" << std::endl;
                if (!X.empty())
                {
                    it = X.begin();
                    size_t rdn = std::rand() % X.size();
                    while (rdn--)
                        it++;
                    if (it != X.end())
                    {
                        std::cout << "chosen node" << std::endl;
                        std::cout << *it << std::endl;
                        itlow = X.lower_bound(*it);
                        itup = X.upper_bound(*it);
                        std::cout << "lower" << std::endl;
                        for (iterator it = itlow; it != X.end(); ++it)
                            std::cout << *it << std::endl;
                        std::cout << "upper" << std::endl;
                        for (iterator it = itup; it != X.end(); ++it)
                            std::cout << *it << std::endl;
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
                        std::cout << *it << std::endl;
                        itlow = Y.lower_bound(*it);
                        itup = Y.upper_bound(*it);
                        std::cout << "lower" << std::endl;
                        for (iterator it = itlow; it != Y.end(); ++it)
                            std::cout << *it<< std::endl;
                        std::cout << "upper" << std::endl;
                        for (iterator it = itup; it != Y.end(); ++it)
                            std::cout << *it << std::endl;
                    }
                }
        }
    }
    
}

#endif  // _SET_TEST_MODIFY_HPP
