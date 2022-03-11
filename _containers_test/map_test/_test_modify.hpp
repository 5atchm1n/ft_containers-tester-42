/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <atruphem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 16:48:42 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_MODIFY_HPP
#define _MAP_TEST_MODIFY_HPP

namespace _test
{

    template <typename _map>
    void test_insert(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        try
        {
            switch (std::rand() % 4)
            {
                case (0):
                    for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                        std::cout << "pair<iterator,bool> insert (const value_type& val) test (1 if ok) : " << (X.insert(rdm_val<typename _map::value_type>())).second << std::endl;
                    break;
                case (1):
                    if (!X.empty())
                        std::cout << (X.insert(*(X.begin()))).second << std::endl;
                    if (!Y.empty())
                        std::cout << (Y.insert(*(--(Y.end())))).second << std::endl;
                    break;
                case (2):
                    if (!Y.empty())
                        Y.insert(Y.begin(), --(Y.end()));
                    if (!X.empty())
                        X.insert(X.begin(), X.end());
                    break;
                case (3):
                    if (!Y.empty())
                    {
                        typename _map::key_type test;
                        typename _map::iterator it = Y.begin();
                        test = it->first;
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        {
                            _NAMESPACE::pair<typename _map::key_type, typename _map::mapped_type> pr = _NAMESPACE::make_pair(test, rdm_val<typename _map::mapped_type>());
                            it = Y.insert(it, pr);
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
        try
        {
            switch (std::rand() % 3)
            {
            case (0):
                if (!X.empty())
                    X.erase(X.begin());
                if (!Y.empty())
                    Y.erase((--Y.end()));
                break;
            case (1):
                typename _map::key_type k;
                    k = 0;
                    X.erase(k);
                    Y.erase(k);
                if (!X.empty())
                {
                    k = (*(X.begin())).first;
                    X.erase(k);
                }
                break;
            case (2):
                X.erase(X.begin(), X.end());
                Y.erase(Y.begin(), Y.begin());
                if (!Y.empty())
                {
                    Y.erase(--(--Y.end()), --(Y.end()));
                }
                break;
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
    void test_clear(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
        try
        {
            switch (std::rand() % 2)
            {
            case (0):
                X.clear();
                break;
            case (1):
                Y.clear();
                break;
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
#endif  // _VECTOR_TEST_MODIFY_HPP