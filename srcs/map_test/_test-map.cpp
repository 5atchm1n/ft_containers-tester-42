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

template <class _map>
void test_map(int rdm_seed)
{
    std::srand(rdm_seed);

    void (*_test_main[])(_map &, _map &) =
        {
            &_test_map::test_constructors,
            &_test_map::test_operator,
            &_test_map::test_insert,
            &_test_map::test_erase,
            &_test_map::test_clear,
            &_test_map::test_bounds,
            &_test_map::test_relational_op,
            &_test_map::test_iterators,
            &_test_map::test_swap,
            &_test_map::test_count,
            &_test_map::test_fakeallocator
        };

    _map X;
    _map Y;

    mmain_test_no = 1;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << mmain_test_no++ << std::endl;
        switch (std::rand() % M_TEST_MAIN)
        {
        case (M_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[M_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_main[M_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (M_OPERATOR) :
            _test_main[M_OPERATOR](X, Y);
        case (M_INSERT):
            if (std::rand() % 2)
                _test_main[M_INSERT](X, Y);
            else
                _test_main[M_INSERT](Y, X);
            break;
        case (M_ERASE):
            if (std::rand() % 2)
                _test_main[M_ERASE](X, Y);
            else
                _test_main[M_ERASE](Y, X);
            break;
        case (M_CLEAR):
            _test_main[M_CLEAR](X, Y);
            break;
        case (M_BOUNDS):
            if (std::rand() % 2)
                _test_main[M_BOUNDS](X, Y);
            else
                _test_main[M_BOUNDS](Y, X);
        case (M_REL_OP):
            if (std::rand() % 2)
                _test_main[M_REL_OP](X, Y);
            else
                _test_main[M_REL_OP](Y, X);
        case (M_ITERATORS):
            if (std::rand() % 2)
                _test_main[M_ITERATORS](X, Y);
            else
                _test_main[M_ITERATORS](Y, X);
        case (M_SWAP) :
            if (std::rand() % 2)
                _test_main[M_SWAP](X, Y);
            else
                _test_main[M_SWAP](Y, X);
        case (M_COUNT) :
            if (std::rand() % 2)
                _test_main[M_COUNT](X, Y);
            else
                _test_main[M_COUNT](Y, X);
        case (M_ALLOC) :
            _test_main[M_ALLOC](X, Y);
        }
        _test_map::test_print(X);
        _test_map::test_print(Y);
    }
}