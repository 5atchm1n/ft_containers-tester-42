/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 03:29:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST_BASIC_HPP
#define _MAP_TEST_BASIC_HPP

#include "_test_header.hpp"

namespace _test_map
{

    /********
     * @brief   TEST SUITE FOR VECTOR
     * @tparam _vector  vector class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _map>
    void test_constructors(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _map Z;
        for (int i = 0 ; i < MAX_TEST_SIZE; i++)
            Z.insert(rdm_val<typename _map::value_type>());
        test_print(Z);
        _map W(Z.begin(),Z.end());
        test_print(W);
        _map U(Z);
        test_print(U);
        X = U;
        Y = W;
    }

    /**
     * @brief TEST OPERATOR [ ]
     */
    template <typename _map>
    void test_operator(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - OPERATOR [ ] " << std::endl;
        _map Z;

        for (int i = 0; i < MAX_TEST_SIZE; i++)
            Z[rdm_val<typename _map::key_type>()] = rdm_val<typename _map::mapped_type>();
        test_print(Z);
        (void)X;
        (void)Y;
    }

    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _map>
    void test_relational_op(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - RELATIONAL OPERATORS" << std::endl;

        _map Z(X);

        if (X < Y)
            std::cout << "X < Y" << std::endl;
        if (X > Y)
            std::cout << "X > Y" << std::endl;
        if (Y < X)
            std::cout << "Y < X" << std::endl;
        if (Y > X)
            std::cout << "Y > X" << std::endl;
        if (X <= Z)
            std::cout << "X <= Z" << std::endl;
        if (X >= Z)
            std::cout << "X >= Z" << std::endl;
        if (Y <= Z)
            std::cout << "Y <= Z" << std::endl;
        if (Y >= Z)
            std::cout << "Y >= Z" << std::endl;
        if (X == Z)
            std::cout << "X == Z" << std::endl;
        if (X != Y)
            std::cout << "X != Y" << std::endl;
    }

    template <typename _it, typename _rit>
    void test_iter_increment(_it & _iter, _rit &_rev_iter, int rdm)
    {
        std::cout << "test iterator increment" << std::endl;
        while (rdm--)
        {
            _iter++;
            _rev_iter++;
        }
        std::cout << _iter->first << " => " << _iter->second << std::endl;
        std::cout << _rev_iter->first << " => " << _rev_iter->second << std::endl;
    }

    template <typename _it, typename _rit>
    void test_iter_decrement(_it & _iter, _rit &_rev_iter, int rdm)
    {
        std::cout << "test iterator decrement" << std::endl;
        while (rdm--)
        {
            _iter--;
            _rev_iter--;
        }
        std::cout << _iter->first << " => " << _iter->second << std::endl;
        std::cout << _rev_iter->first << " => " << _rev_iter->second << std::endl;
    }
    
    template <typename _map>
    void test_iterators(_map &X, _map &Y)
    {
        (void)Y;
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - ITERATORS" << std::endl;

        typename _map::iterator it;
        it = X.begin();
        typename _map::iterator _it(it);
        typename _map::const_iterator cit = X.end();
        typename _map::reverse_iterator rit = X.rbegin();
        typename _map::const_reverse_iterator crit = X.rend();

        size_t rdm;
        if (X.size())
        {
            rdm = std::rand() % X.size();
            if (rdm)
            {
                test_iter_increment<typename _map::iterator, typename _map::reverse_iterator>(_it, rit, rdm);
                test_iter_decrement<typename _map::const_iterator, typename _map::const_reverse_iterator>(cit, crit, rdm);
            }
        }
    }

    template <typename _map>
    void test_swap(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - SWAP" << std::endl;
        if (!X.empty() && !Y.empty())
        {
            typename _map::const_iterator it_x = X.begin();
            typename _map::const_iterator it_y = Y.begin();
            X.swap(Y);
            std::cout << "Check iterator validy" << std::endl;
            std::cout << "valid : " << (it_x == Y.begin()) << std::endl;
            std::cout << "valid : " << (it_y == X.end()) << std::endl;
        }
    }

    template <typename _map>
    void test_count(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - COUNT" << std::endl;
        
        _map Z(Y);

        for (int i = 0; i < MAX_MAP_KEY; i++)
        {
            std::cout << i ;
            if (Z.count(i) > 0)
                std::cout << " is in map" << std::endl;
        }
        (void)X;
    }

}

#endif  //_VECTOR_TEST_BASIC_HPP