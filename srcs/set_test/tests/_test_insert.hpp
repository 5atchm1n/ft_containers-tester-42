/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_insert.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:36:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _SET_TEST_INSERT_HPP
#define _SET_TEST_INSERT_HPP

namespace _test_set
{

        /**
     * @brief TEST INSERT
     */
    
    template <typename _set>
    void test_insert(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - INSERT" << std::endl;
        typename _set::iterator it;

        typedef typename _NAMESPACE::pair< typename _set::iterator, bool>   pair_return;
        
        pair_return     ret; 

        try
        {
            switch (std::rand() % 4)
            {
                case (0):
                    std::cout << "INSERT : case 0" << std::endl;
                    for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                    {
                        ret = X.insert(rdm_val<typename _set::value_type>());
                        std::cout << "key :" << *ret.first << std::endl;
                        std::cout << "already in :" << ret.second << std::endl;
                    }
                    break;
                case (1):
                    std::cout << "INSERT : case 1" << std::endl;
                    if (!X.empty())
                    {
                        ret = X.insert(*(X.begin()));
                        std::cout << "key :" << *ret.first << std::endl;
                        std::cout << "already in :" << ret.second << std::endl;

                    }
                    if (!Y.empty())
                    {
                        ret = Y.insert(*(--(Y.end())));
                        std::cout << "key :" << *ret.first << std::endl;
                        std::cout << "already in :" << ret.second << std::endl;
                    }
                    break;
                case (2):
                    std::cout << "INSERT : case 2" << std::endl;
                    if (!Y.empty())
                        X.insert(Y.begin(), --(Y.end()));
                    if (!X.empty())
                        Y.insert(X.begin(), X.end());
                    break;
                case (3):
                    std::cout << "INSERT : case 3" << std::endl;
                    if (!Y.empty())
                    {
                        typename _set::key_type test = rdm_val<typename _set::key_type>();
                        it = Y.begin();
                        for (int k = 0; k < std::rand() % MAX_TEST_SIZE; k++)
                        {
                            it = Y.insert(it, test);
                            test++;
                        }
                    }
            }
            test_print(X);
            test_print(Y);
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
}

#endif  // _SET_TEST_INSERT_HPP
