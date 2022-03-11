/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 12:40:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _SET_TEST_MODIFY_HPP
#define _SET_TEST_MODIFY_HPP

namespace _test
{

        /**
     * @brief TEST INSERT
     */
    
    template <typename _set>
    void test_insert(_set &X, _set &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        typename _set::iterator it;

        typedef typename _NAMESPACE::pair< typename _set::iterator, bool>   pair_return;
        
        pair_return     ret; 

        try
        {
            switch (std::rand() % 4)
            {
                case (0):
                    for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    {
                        ret = X.insert(rdm_val<typename _set::value_type>());
                        std::cout << "key :" << *ret.first << std::endl;
                        std::cout << "already in :" << ret.second << std::endl;
                    }
                    break;
                case (1):
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
                    if (!Y.empty())
                        X.insert(Y.begin(), --(Y.end()));
                    if (!X.empty())
                        Y.insert(X.begin(), X.end());
                    break;
                case (3):
                    if (!Y.empty())
                    {
                        typename _set::key_type test = rdm_val<typename _set::key_type>();
                        it = Y.begin();
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
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
    
    template <typename _set>
    void test_erase(_set &X, _set &Y)
    {
        std::cout << "TEST : " << test_no++;
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

    template <typename _set>
    void test_bounds(_set &X, _set &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - BOUNDS" << std::endl;
        
        typedef typename _set::iterator iterator;
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

    template <typename _set>
    void
    test_clear(_set &X, _set &Y)
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

#endif  // _SET_TEST_MODIFY_HPP