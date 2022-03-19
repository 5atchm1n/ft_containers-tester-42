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

template <class _set>
void test_set(int rdm_seed)
{
    std::srand(rdm_seed);

    void (*_test_main[])(_set &, _set &) =
        {
            &_test_set::test_constructors,
            &_test_set::test_insert,
            &_test_set::test_erase,
            &_test_set::test_clear,
            &_test_set::test_bounds,
            &_test_set::test_relational_op,
            &_test_set::test_iterators,
            &_test_set::test_swap,
            &_test_set::test_count
        };

    _set X;
    _set Y;

    set_main_test_no = 1;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << set_main_test_no++ << std::endl;
        switch (std::rand() % _SET_MAIN)
        {
        case (SET_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[SET_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_main[SET_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (SET_INSERT):
            if (std::rand() % 2)
                _test_main[SET_INSERT](X, Y);
            else
                _test_main[SET_INSERT](Y, X);
            break;
        case (SET_ERASE):
            if (std::rand() % 2)
                _test_main[SET_ERASE](X, Y);
            else
                _test_main[SET_ERASE](Y, X);
            break;
        case (SET_CLEAR):
            _test_main[SET_CLEAR](X, Y);
            break;
        case (SET_BOUNDS):
            if (std::rand() % 2)
                _test_main[SET_BOUNDS](X, Y);
            else
                _test_main[SET_BOUNDS](Y, X);
        case (SET_REL_OP):
            if (std::rand() % 2)
                _test_main[SET_REL_OP](X, Y);
            else
                _test_main[SET_REL_OP](Y, X);
        case (SET_ITERATORS):
            if (std::rand() % 2)
                _test_main[SET_ITERATORS](X, Y);
            else
                _test_main[SET_ITERATORS](Y, X);
        case (SET_SWAP) :
            if (std::rand() % 2)
                _test_main[SET_SWAP](X, Y);
            else
                _test_main[SET_SWAP](Y, X);
        case (SET_COUNT) :
            if (std::rand() % 2)
                _test_main[SET_COUNT](X, Y);
            else
                _test_main[SET_COUNT](Y, X);
        }
        _test_set::test_print(X);
        _test_set::test_print(Y);
    }
}