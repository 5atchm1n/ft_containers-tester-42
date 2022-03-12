/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 03:30:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _SET_TEST_BASIC_HPP
#define _SET_TEST_BASIC_HPP

namespace _test_set
{

    /********
     * @brief   TEST SUITE FOR SET
     * @tparam _set  set class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _set>
    void test_constructors(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _set Z;
        for (int i = 0 ; i < MAX_TEST_SIZE; i++)
            Z.insert(rdm_val<typename _set::value_type>());
        test_print(Z);
        _set W(Z.begin(),Z.end());
        test_print(W);
        _set U(Z);
        test_print(U);
        X = U;
        Y = W;
    }

    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _set>
    void test_relational_op(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - RELATIONAL OPERATORS" << std::endl;

        _set Z(X);

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
        std::cout << *_iter << std::endl;
        std::cout << *_rev_iter << std::endl;
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
        std::cout << *_iter << std::endl;
        std::cout << *_rev_iter << std::endl;
    }
    
    template <typename _set>
    void test_iterators(_set &X, _set &Y)
    {
        (void)Y;
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - ITERATORS" << std::endl;

        typename _set::iterator it;
        it = X.begin();
        typename _set::iterator _it(it);
        typename _set::const_iterator cit = X.end();
        typename _set::reverse_iterator rit = X.rbegin();
        typename _set::const_reverse_iterator crit = X.rend();

        size_t rdm;
        if (X.size())
        {
            rdm = std::rand() % X.size();
            if (rdm)
            {
                test_iter_increment<typename _set::iterator, typename _set::reverse_iterator>(_it, rit, rdm);
                test_iter_decrement<typename _set::const_iterator, typename _set::const_reverse_iterator>(cit, crit, rdm);
            }
        }
    }

    template <typename _set>
    void test_swap(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - SWAP" << std::endl;
        if (!X.empty() && !Y.empty())
        {
            typename _set::const_iterator it_x = X.begin();
            typename _set::const_iterator it_y = Y.begin();
            X.swap(Y);
            std::cout << "Check iterator validy" << std::endl;
            std::cout << "valid : " << (it_x == Y.begin()) << std::endl;
            std::cout << "valid : " << (it_y == X.end()) << std::endl;
        }
    }

    template <typename _set>
    void test_count(_set &X, _set &Y)
    {
        std::cout << "TEST : " << set_test_no++;
        std::cout << " - COUNT" << std::endl;
        
        _set Z(Y);

        for (int i = 0; i < MAX_MAP_KEY; i++)
        {
            std::cout << i ;
            if (Z.count(i) > 0)
                std::cout << " is in map" << std::endl;
        }
        (void)X;
    }

}


#endif  //_SET_TEST_BASIC_HPP