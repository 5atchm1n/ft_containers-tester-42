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

#include "_test_header.hpp"

template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*test_vector[_VECTOR_NTESTS])(_vector &, _vector &) =
        {
            &_test_vector::test_constructors,
            &_test_vector::test_assign_op,
            &_test_vector::test_mixed_assign_copy,
            &_test_vector::test_relational_op,
            &_test_vector::test_insert,
            &_test_vector::test_assign,
            &_test_vector::test_push,
            &_test_vector::test_pop,
            &_test_vector::test_erase,
            &_test_vector::test_resize,
            &_test_vector::test_swap,
            &_test_vector::test_clear,
            &_test_vector::test_fakeallocator
        };

    _vector X;
    _vector Y;

    vmain_test_no = 0;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << vmain_test_no++ << std::endl;
        switch (std::rand() % _VECTOR_NTESTS)
        {
        case (V_BASIC_C):
            if (std::rand() % 2)
                test_vector[V_BASIC_C](X, Y);
            else
                test_vector[V_BASIC_C](Y, X);
            break;
        case (V_ASSIGN_OP):
            if (std::rand() % 2)
                test_vector[V_ASSIGN_OP](X, Y);
            else
                test_vector[V_ASSIGN_OP](Y, X);
            break;
        case (V_MIXED_0_3) :
            if (std::rand() % 2)
                test_vector[V_MIXED_0_3](X, Y);
            else
                test_vector[V_MIXED_0_3](Y, X);
            break;
        case (V_REL_OP) :
            if (std::rand() % 2)
                test_vector[V_REL_OP](X, Y);
            else
                test_vector[V_REL_OP](Y, X);
        case (V_INSERT):
            if (std::rand() % 2)
                test_vector[V_INSERT](X, Y);
            else
                test_vector[V_INSERT](Y, X);
            break;
        case (V_ASSIGN):
            if (std::rand() % 2)
                test_vector[V_ASSIGN](X, Y);
            else
                test_vector[V_ASSIGN](Y, X);
            break;
        case (V_PUSH):
            if (std::rand() % 2)
                test_vector[V_PUSH](X, Y);
            else
                test_vector[V_PUSH](Y, X);
            break;
        case (V_POP):
            if (std::rand() % 2)
                test_vector[V_POP](X, Y);
            else
                test_vector[V_POP](Y, X);
            break;
        case (V_ERASE):
            if (std::rand() % 2)
                test_vector[V_ERASE](X, Y);
            else
                test_vector[V_ERASE](Y, X);
            break;
        case (V_RESIZE):
            if (std::rand() % 2)
                test_vector[V_RESIZE](X, Y);
            else
                test_vector[V_RESIZE](Y, X);
            break;
        case (V_SWAP):
            test_vector[V_SWAP](X, Y);
            break;
        case (V_CLEAR) :
            test_vector[V_CLEAR](X, Y);
            break;
        #if _TALLOC
        case (V_ALLOC):
            test_vector[V_ALLOC](X, Y);
        #endif
        }
        _test_vector::test_print(X);
        _test_vector::test_print(Y);
    }
}