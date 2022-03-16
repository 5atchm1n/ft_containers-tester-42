/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_erase.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:47:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_ERASE_M_HPP 
#define _TEST_ERASE_M_HPP

namespace _test_map
{
    
    template <typename _map>
    void test_erase(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - ERASE" << std::endl;
        typename _map::iterator it;
            switch (std::rand() % 4)
            {
                case (0) :
                    std::cout << "case 0" << std::endl;
                    if (!X.empty())
                    X.erase(X.begin());
                    break ;
                case (1) :
                    std::cout << "case 1" << std::endl;
                    std::cout << "Elements erased : " << X.erase(rdm_val<typename _map::key_type>()) << std::endl;
                    break ;
                case (2) :
                    std::cout << "case 2" << std::endl;
                    if (X.size() > MAX_TEST_SIZE)
                    {
                        it = X.begin();
                        for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                            it++;
                        X.erase(it, X.end());
                    }
                    break ;
                case (3) :
                    std::cout << "case 3" << std::endl;
                    it = Y.begin();
                    if (!Y.empty() && Y.size() > 5)
                    {
                        for (int i = 0; i < std::rand() % 5; i++)
                            it++;
                        Y.erase(it);
                    }
                
            }
    }
}   // END NAMESPACE

#endif  // _TEST_ERASE_M_HPP