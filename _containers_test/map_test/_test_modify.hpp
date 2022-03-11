/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 04:49:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_MODIFY_HPP
#define _MAP_TEST_MODIFY_HPP

namespace _test
{

        /**
     * @brief TEST INSERT
     */
    
    template <typename _map>
    void test_insert(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
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
                    for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
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
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
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
    
    template <typename _map>
    void test_erase(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
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
                    if (X.size() > _MAX_TEST_SIZE)
                    {
                        it = X.begin();
                        for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
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

    template <typename _map>
    void test_bounds(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - BOUNDS" << std::endl;
        
        typedef typename _map::iterator iterator;
        iterator it;
        iterator itlow;
        iterator itup;
        switch (std::rand() % 2)
        {
            case (0) :
                std::cout << "case 0" << std::endl;
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
                std::cout << "case 1" << std::endl;
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

    template <typename _map>
    void
    test_clear(_map &X, _map &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
        if (std::rand() % 2)
            X.clear();
        else
            Y.clear();
    }
    
}

#endif  // _map_TEST_MODIFY_HPP