/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/06 14:23:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _VECTOR_TEST_BASIC_HPP
#define _VECTOR_TEST_BASIC_HPP

namespace _test
{

    /********
     * @brief   TEST SUITE FOR VECTOR
     * @tparam _vector  vector class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _vector>
    void test_constructors(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        x = _vector(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        y = _vector(x.begin(), x.end());
        _vector z(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(z);
    }

    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _vector>
    void test_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
        _vector z(x);
        _vector w(y);
        test_print(w);
        test_print(z);
    }

    /**
     * @brief TEST OPERATOR =
     */
    template <typename _vector>
    void test_assign_op(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
        _vector Z = x;
        y = Z;
        test_print(Z);
        x = _vector(Z);
        y = Z;
        y = _vector(Z);
    }

    /**
     * @brief TEST MIXED OP = and COPY
     */
    template <typename _vector>
    void test_mixed_assign_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - MIXED BASIC" << std::endl;
        _vector Z(x);
        Z = x;
        test_print(Z);
        x = Z;
        x = y;
        y = Z;
        test_print(Z);
    }

    /**
     * @brief 
     * 
     */
    template <typename _vector>
    void test_resize(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - RESIZE" << std::endl;
        if (!x.empty())
            x.resize(std::rand() % (x.size() * 2), rdm_val<typename _vector::value_type>());
        else
            x.resize(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        if (!y.empty())
            y.resize(std::rand() % (y.size() * 2), rdm_val<typename _vector::value_type>());
        else
            y.resize(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
    }

    template <typename _vector>
    void test_swap(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - RESIZE" << std::endl;
        if (std::rand() % 2)
            x.swap(y);
        else
            y.swap(x);
    }

    template <typename _vector>
    void test_relational_op(_vector &X, _vector &Y)
    {
        _vector Z1;
        _vector Z2;
        Z1.insert(Z1.begin(), _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        Z2.insert(Z2.begin(), Z1.begin(), Z1.end());
        if (Z1 == Z2)
            std::cout << "Z1 == Z2" << std::endl;
        Z2.pop_back();
        if (Z1 != Z2)
            std::cout << "Z1 != Z2" << std::endl;
        if (Z1 > Z2)
            std::cout << "Z1 > Z2" << std::endl;
        if (Z1 >= Z2)
            std::cout << "Z1 >= Z2" << std::endl;
        if (X < Y)
            std::cout << "X < Y" << std::endl;
        if (X <= Y)
            std::cout << "X <= Y" << std::endl;
        _test::test_print(Z1);
        _test::test_print(Z2);
    }
}


#endif  //_VECTOR_TEST_BASIC_HPP