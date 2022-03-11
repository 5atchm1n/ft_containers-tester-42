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

#include "stack_test/_test_header.hpp"

template <class _stack>
void test_stack(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_main[])(_stack &, _stack &) =
        {
            &_test::test_constructors,
            &_test::test_relational_op,
            &_test::test_push,
            &_test::test_pop,
        };

    _stack X;
    _stack Y;

    main_test_no = 0;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << main_test_no++ << std::endl;
        switch (std::rand() % _TEST_MAIN)
        {
        case (_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_main[_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (_REL_OP) :
            if (std::rand() % 2)
                _test_main[_REL_OP](X, Y);
            else
                _test_main[_REL_OP](Y, X);
        case (_PUSH):
            if (std::rand() % 2)
                _test_main[_PUSH](X, Y);
            else
                _test_main[_PUSH](Y, X);
            break;
        case (_POP):
            if (std::rand() % 2)
                _test_main[_POP](X, Y);
            else
                _test_main[_POP](Y, X);
            break;
        }
        _test::test_print(X);
        _test::test_print(Y);
    }
}

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
        test_stack<_NAMESPACE::stack<int> >(seed++);
    return 0;
}