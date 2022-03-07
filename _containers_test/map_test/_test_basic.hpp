/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <atruphem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/07 18:16:11 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_BASIC_HPP
#define _MAP_TEST_BASIC_HPP

namespace _test
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
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _map W(X.begin(), X.end());
        _map K(Y.begin(), Y.end());
        test_print(W);
        test_print(K);
    }

        
    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _vector>
    void test_copy(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
    }

    /**
     * @brief TEST OPERATOR =
     */
    template <typename _vector>
    void test_assign_op(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
    }

    
}


#endif  //_VECTOR_TEST_BASIC_HPP