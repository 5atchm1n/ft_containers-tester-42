/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_erase.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/18 14:38:06 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _SET_TEST_MODIFY_HPP
#define _SET_TEST_MODIFY_HPP

namespace _test_set
{

    
    template <typename _set>
    void test_erase(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - ERASE" << std::endl;
        typename _set::iterator it;
            switch (std::rand() % 4)
            {
                case (0) :
                    std::cout << "case 0" << std::endl;
                    if (!X.empty())
                    X.erase(X.begin());
                    break ;
                case (1) :
                    std::cout << "case 1" << std::endl;
                    std::cout << "Elements erased : " << X.erase(rdm_val<typename _set::key_type>()) << std::endl;
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

    template <typename _set>
    void
    test_clear(_set &X, _set &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - CLEAR" << std::endl;
        if (std::rand() % 2)
            X.clear();
        else
            Y.clear();
    }
    
}

#endif  // _SET_TEST_MODIFY_HPP
