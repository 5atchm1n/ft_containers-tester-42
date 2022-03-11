/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <atruphem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya          #+#    #+#             */
/*   Updated: 2022/03/07 16:37:46 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_test/_test_header.hpp"

template <class _map>
void test_map(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_main[])(_map &, _map &) =
        {
            &_test::test_constructors,
            &_test::test_copy,
            &_test::test_assign_op,
            &_test::test_insert,
            &_test::test_erase,
            &_test::test_clear,
            &_test::test_arrindex_op,
            &_test::test_bounds
        };

    _map X;
    _map Y;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "TEST : " << main_test_no++ << std::endl;
        switch (std::rand() % _TEST_MAIN)
        {
        case (_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_main[_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (_COPY_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_main[_COPY_CONSTRUCTOR](X, Y);
            else
                _test_main[_COPY_CONSTRUCTOR](Y, X);
            break;
        case (_ASSIGNMENT_OP):
            if (std::rand() % 2)
                _test_main[_ASSIGNMENT_OP](X, Y);
            else
                _test_main[_ASSIGNMENT_OP](Y, X);
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
        case (_ARRINDEX_OP):
            if (std::rand() % 2)
                _test_main[_ARRINDEX_OP](X, Y);
            else
                _test_main[_ARRINDEX_OP](Y, X);
            break;
        case (_BOUNDS):
            if (std::rand() % 2)
                _test_main[_BOUNDS](X, Y);
            else
                _test_main[_BOUNDS](Y, X);
            break;
        case (_FAKE_ALLOCATOR):
            _test::test_fakeallocator();

        }
        _test::test_print(X);
        _test::test_print(Y);
    }


}

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
        test_map<_NAMESPACE::map<int, std::string> >(seed++);
    return 0;
}