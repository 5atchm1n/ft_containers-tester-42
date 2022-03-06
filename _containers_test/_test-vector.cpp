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

#include "vector_test/_test_header.hpp"

template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_test_basic[])(_vector &, _vector &) =
        {
            &_test::test_constructors,
            &_test::test_copy,
            &_test::test_assign_op,
            &_test::test_mixed_assign_copy,
            &_test::test_relational_op
        };
    
    std::srand(rdm_seed);
    void (*_test_main[])(_vector &, _vector &) =
        {
            &_test::test_insert,
            &_test::test_assign,
            &_test::test_push,
            &_test::test_pop,
            &_test::test_erase,
            &_test::test_resize,
            &_test::test_swap,
            &_test::test_clear
        };

    _vector X;
    _vector Y;

    for (int i = 0; i < _NTESTS_BASIC; i++)
    {
        std::cout << "BASIC TEST : " << main_test_no++ << std::endl;
        switch (std::rand() % _TEST_BASIC)
        {
        case (_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_basic[_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _test_basic[_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (_COPY_CONSTRUCTOR):
            if (std::rand() % 2)
                _test_basic[_COPY_CONSTRUCTOR](X, Y);
            else
                _test_basic[_COPY_CONSTRUCTOR](Y, X);
            break;
        case (_ASSIGNMENT_OP):
            if (std::rand() % 2)
                _test_basic[_ASSIGNMENT_OP](X, Y);
            else
                _test_basic[_ASSIGNMENT_OP](Y, X);
            break;
        case (_MIXED_0_3) :
            if (std::rand() % 2)
                _test_basic[_MIXED_0_3](X, Y);
            else
            _test_basic[_MIXED_0_3](Y, X);
            break;
        case (_REL_OP) :
            if (std::rand() % 2)
                _test_basic[_REL_OP](X, Y);
            else
                _test_basic[_REL_OP](Y, X);
        }
        _test::test_print(X);
        _test::test_print(Y);
    }

    main_test_no = 0;

    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << main_test_no++ << std::endl;
        switch (std::rand() % _TEST_MAIN)
        {
        case (_INSERT):
            if (std::rand() % 2)
                _test_main[_INSERT](X, Y);
            else
                _test_main[_INSERT](Y, X);
            break;
        case (_ASSIGN):
            if (std::rand() % 2)
                _test_main[_ASSIGN](X, Y);
            else
                _test_main[_ASSIGN](Y, X);
            break;
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
        case (_ERASE):
            if (std::rand() % 2)
                _test_main[_ERASE](X, Y);
            else
                _test_main[_ERASE](Y, X);
            break;
        case (_RESIZE):
            if (std::rand() % 2)
                _test_main[_RESIZE](X, Y);
            else
                _test_main[_RESIZE](Y, X);
            break;
        case (_SWAP):
            _test_main[_SWAP](X, Y);
            break;
        case (_CLEAR) :
            _test_main[_CLEAR](X, Y);
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
        test_vector<_NAMESPACE::vector<std::string> >(seed++);
    return 0;
}