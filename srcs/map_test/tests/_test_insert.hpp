/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_insert.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:47:30 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_INSERT_M_HPP
#define _TEST_INSERT_M_HPP

namespace _test_map
{

/**
 * @brief TEST INSERT
 */

template <typename _map>
void test_insert(_map &X, _map &Y)
{
    std::cout << "TEST : " << mtest_no++;
    std::cout << " - INSERT" << std::endl;
    typename _map::iterator it;
    typedef typename _NAMESPACE::pair<typename _map::key_type, typename _map::mapped_type> pair_type;
    typedef typename _NAMESPACE::pair< typename _map::iterator, bool>   pair_return;
    
    pair_return     ret; 
    pair_type       value;
    try
    {
        switch (std::rand() % 4)
        {
            case (0):
                for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                {
                    ret = X.insert(rdm_val<typename _map::value_type>());
                    std::cout << "key :" << ret.first->first << std::endl;
                    std::cout << " value : " << ret.first->second << std::endl;
                    std::cout << "already in :" << ret.second << std::endl;
                }
                break;
            case (1):
                if (!X.empty())
                {
                    ret = X.insert(*(X.begin()));
                    std::cout << "key :" << ret.first->first << std::endl;
                    std::cout << " value : " << ret.first->second << std::endl;
                    std::cout << "already in :" << ret.second << std::endl;
                }
                if (!Y.empty())
                {
                    ret = Y.insert(*(--(Y.end())));
                    std::cout << "key :" << ret.first->first << std::endl;
                    std::cout << " value : " << ret.first->second << std::endl;
                    std::cout << "already in :" << ret.second << std::endl;
                }
                break;
            case (2):
                if (!Y.empty())
                    X.insert(Y.begin(), --(Y.end()));
                if (!X.empty())
                    Y.insert(X.begin(), X.end());
                break;
            case (3):
                if (!Y.empty())
                {
                    typename _map::key_type test;
                    it = Y.begin();
                    test = it->first;
                    for (int k = 0; k < std::rand() % MAX_TEST_SIZE; k++)
                    {
                        value = _NAMESPACE::make_pair(test, rdm_val<typename _map::mapped_type>());
                        it = Y.insert(it, value);
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

}   // END NAMESPACE

#endif  // _TEST_INSERT_M_HPP