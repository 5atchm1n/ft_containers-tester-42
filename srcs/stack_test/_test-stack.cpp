/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/01 17:1 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bits/_test_header.hpp"

template <class _stack>
void test_stack(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_main[])(_stack &, _stack &) =
        {
            &_test_stack::test_constructors,
            &_test_stack::test_relational_op,
            &_test_stack::test_push,
            &_test_stack::test_pop,
        };

    _stack X;
    _stack Y;

    smain_test_no = 1;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << smain_test_no++ << std::endl;
        switch (std::rand() % S_TEST_MAIN)
        {
        case (S_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[S_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_main[S_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (S_REL_OP) :
            if (std::rand() % 2)
                _test_main[S_REL_OP](X, Y);
            else
                _test_main[S_REL_OP](Y, X);
        case (S_PUSH):
            if (std::rand() % 2)
                _test_main[S_PUSH](X, Y);
            else
                _test_main[S_PUSH](Y, X);
            break;
        case (S_POP):
            if (std::rand() % 2)
                _test_main[S_POP](X, Y);
            else
                _test_main[S_POP](Y, X);
            break;
        }
        _test_stack::test_print(X);
        _test_stack::test_print(Y);
    }
}