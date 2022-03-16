/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:59:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST_BASIC_HPP
#define _MAP_TEST_BASIC_HPP

#include "../_test_header.hpp"

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

}

#endif  //_VECTOR_TEST_BASIC_HPP