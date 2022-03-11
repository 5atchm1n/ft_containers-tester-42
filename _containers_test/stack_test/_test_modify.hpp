/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 17:01:17 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _stack_TEST_MODIFY_HPP
#define _stack_TEST_MODIFY_HPP

namespace _test
{

        /**
     * @brief TEST INSERT
     */


    template <typename _stack>
    void test_push(_stack &X, _stack &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - PUSH_BACK" << std::endl;
        switch (std::rand() % 3)
        {
            case (0) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    X.push(rdm_val<int>());
            case (1) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
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
        std::cout << "TEST : " << test_no++;
        std::cout << " - POP" << std::endl;
        switch (std::rand() % 2)
        {
            case (0) :
                if (!X.empty())
                    for (size_t i = 0; i < X.size(); i++)
                        X.pop();
            case (1) :
                if (!Y.empty())
                    for (size_t i = 0; i < Y.size(); i++)
                        Y.pop();
        }
    }
    
}

#endif  // _stack_TEST_MODIFY_HPP