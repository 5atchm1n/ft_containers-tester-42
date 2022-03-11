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

#include "set_test/_test_header.hpp"

template <class _set>
void test_set(int rdm_seed)
{
    std::srand(rdm_seed);

    void (*_test_main[])(_set &, _set &) =
        {
            &_test::test_constructors,
            &_test::test_insert,
            &_test::test_erase,
            &_test::test_clear,
            &_test::test_bounds,
            &_test::test_relational_op,
            &_test::test_iterators,
            &_test::test_swap,
            &_test::test_count
        };

    _set X;
    _set Y;

    main_test_no = 1;

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
        case (_INSERT):
            if (std::rand() % 2)
                _test_main[_INSERT](X, Y);
            else
                _test_main[_INSERT](Y, X);
            break;
        case (_ERASE):
            if (std::rand() % 2)
                _test_main[_ERASE](X, Y);
            else
                _test_main[_ERASE](Y, X);
            break;
        case (_CLEAR):
            _test_main[_CLEAR](X, Y);
            break;
        case (_BOUNDS):
            if (std::rand() % 2)
                _test_main[_BOUNDS](X, Y);
            else
                _test_main[_BOUNDS](Y, X);
        case (_REL_OP):
            if (std::rand() % 2)
                _test_main[_REL_OP](X, Y);
            else
                _test_main[_REL_OP](Y, X);
        case (_ITERATORS):
            if (std::rand() % 2)
                _test_main[_ITERATORS](X, Y);
            else
                _test_main[_ITERATORS](Y, X);
        case (_SWAP) :
            if (std::rand() % 2)
                _test_main[_SWAP](X, Y);
            else
                _test_main[_SWAP](Y, X);
        case (_COUNT) :
            if (std::rand() % 2)
                _test_main[_COUNT](X, Y);
            else
                _test_main[_COUNT](Y, X);
        }
        _test::test_print(X);
        _test::test_print(Y);
    }
}

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
        test_set<_NAMESPACE::set<int> >(seed++);
    return 0;
}