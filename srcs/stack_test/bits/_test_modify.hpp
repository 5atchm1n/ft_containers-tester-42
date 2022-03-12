/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 03:30:10 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _stack_TEST_MODIFY_HPP
#define _stack_TEST_MODIFY_HPP

namespace _test_stack
{

        /**
     * @brief TEST INSERT
     */


    template <typename _stack>
    void test_push(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << stest_no++;
        std::cout << " - PUSH" << std::endl;
        switch (std::rand() % 3)
        {
            case (0) :
                for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                    X.push(rdm_val<int>());
            case (1) :
                for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                    Y.push(rdm_val<int>());
            case (2) :
                _stack Z;
                Z.push(rdm_val<int>());
                test_print(Z);
        }
    }


    template <typename _stack>
    void test_pop(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << stest_no++;
        std::cout << " - POP" << std::endl;
        size_t rdm = std::rand();
        switch (std::rand() % 2)
        {
            case (0) :
                if (!X.empty())
                    for (size_t i = 0; i < rdm % X.size(); i++)
                        X.pop();
            case (1) :
                if (!Y.empty())
                    for (size_t i = 0; i < rdm % Y.size(); i++)
                        Y.pop();
        }
    }
    
}

#endif  // _stack_TEST_MODIFY_HPP