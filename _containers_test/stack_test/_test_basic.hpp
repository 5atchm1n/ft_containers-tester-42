/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 17:17:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _stack_TEST_BASIC_HPP
#define _stack_TEST_BASIC_HPP

namespace _test
{

    /********
     * @brief   TEST SUITE FOR VECTOR
     * @tparam _stack  vector class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _stack>
    void test_constructors(_stack &x, _stack &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _NAMESPACE::vector<int> myvector(std::rand() % _MAX_TEST_SIZE, rdm_val<int>());
        _NAMESPACE::stack<int, _NAMESPACE::vector<int> > Z(myvector);
        test_print(Z);
        (void)y;
        (void)x;
    }


    template <typename _stack>
    void test_swap(_stack &x, _stack &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - RESIZE" << std::endl;
        if (std::rand() % 2)
            x.swap(y);
        else
            y.swap(x);
    }

    template <typename _stack>
    void test_relational_op(_stack &X, _stack &Y)
    {
        if (X == Y)
            std::cout << "X == Y" << std::endl;
        if (X != Y)
            std::cout << "X != Y" << std::endl;
        if (X > Y)
            std::cout << "X > Y" << std::endl;
        if (X >= Y)
            std::cout << "X >= Y" << std::endl;
        if (X < Y)
            std::cout << "X < Y" << std::endl;
        if (X <= Y)
            std::cout << "X <= Y" << std::endl;
    }
}


#endif  //_stack_TEST_BASIC_HPP