/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <atruphem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 17:31:26 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_BASIC_HPP
#define _MAP_TEST_BASIC_HPP

namespace _test
{

    template <typename _map>
    void test_constructors(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _map W(X.begin(), X.end());
        _map K(Y.begin(), Y.end());
        test_print(W);
        test_print(K);
    }
        
    template <typename _map>
    void test_copy(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
        _map W(X);
        _map K(Y);
        test_print(W);
        test_print(K);
    }

    template <typename _map>
    void test_assign_op(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
        _map W;
        _map K;
        W = X;
        X = Y;
        Y = K;
        K = W;
        test_print(W);
        test_print(K);
        test_print(X);
        test_print(Y);
    }

    template <typename _map>
    void test_arrindex_op(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR[]" << std::endl;
        try
        {
            std::cout << X[std::rand() % X.size()] << std::endl; 
            std::cout << Y[Y.size()] << std::endl;
        }
        catch (std::exception &error)
        {
            std::cout << "error" << std::endl;
        }
    }
    
    template <typename _map>
    void test_bounds(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - BOUNDS" << std::endl;
        try
        {
            typename _map::key_type k;
            switch (std::rand() % 4)
            {
            case (0):
                if (!X.empty())
                {    
                    k = (*(--(X.end()))).first;
                    if (X.lower_bound(k) != X.end())
                        std::cout << (*(X.lower_bound(k))).second << std::endl;
                    k--;
                    while (k)
                    {
                        if (X.lower_bound(k) != X.end())
                            std::cout << (*(X.lower_bound(k))).second << std::endl;
                        k--;    
                    }
                }
                break;
            case (1):
                if (!Y.empty())
                {    
                    k = (*(Y.begin())).first;
                    while (Y.upper_bound(k) != Y.end())
                    {
                        std::cout << (*(X.upper_bound(k))).second << std::endl;
                        k++;
                    }
                }
                break;
            case (2):
                k = 0;
                if (X.lower_bound(k) != X.end())
                    std::cout << (*(X.lower_bound(k))).second << std::endl;
                break;
            case (3):
                if (!X.empty())
                {    
                    k = (*(--(X.end()))).first;
                    std::cout << (*(X.equal_range(k).first)).first << std::endl;
                }
                break;   
            }
        }
        catch (std::exception &error)
        {
            std::cout << "error" << std::endl;
        }
        
    }
            
    
}


#endif