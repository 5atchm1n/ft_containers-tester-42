/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/27 07:11:46 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <climits>

#define _MAX_TEST_SIZE 20
#define _NTESTS 50

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

static int test_no = 0;
static int main_test_no = 0;

namespace _test
{

    /**
     * @brief Template overload RDM_VAL
     */
    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }
    /**
     * @brief Generate a random string
     */
    template <>
    std::string rdm_val<std::string>()
    {
        std::string default_val[] =
            {
                "This is a test",
                "there are many tests",
                "all tests should pass",
                "Lorem ipsum dolor sit amet",
                "consectetur adipiscing elit.",
                "Phasellus ut rutrum ante.",
                "Sed vehicula tellus eu erat",
                "congue dictum. Fusce a ultrices",
                "",
                "magna. Morbi fringilla ullamcorper",
                "nisi id scelerisque.",
                "Curabitur elementum enim",
                "a mi vestibulum eleifend.",
                "Pellentesque eget risus efficitur",
                "euismod mi ut, tristique lorem.",
                "Praesent ullamcorper venenatis augue,",
                "\t",
                "eget pretium velit vehicula et."};
        return (std::string(default_val[std::rand() % 17]));
    }
    /**
     * @brief Generate a random UINT
     *
     */
    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }

    /**
     * @brief PRINT VECTOR
     */
    template <typename _vector>
    void test_print(const _vector &v)
    {
        std::cout << "empty : " << v.empty() << std::endl;
        std::cout << "size : " << v.size() << std::endl;
        // std::cout << "capacity : " << v.capacity() << std::endl;
        // std::cout << "max size : " << v.max_size() << std::endl;
        if (!v.empty())
        {
            std::cout << "front : " << v.front() << std::endl;
            std::cout << "back : " << v.back() << std::endl;
            std::cout << "content : " << std::endl;
            for (typename _vector::const_iterator it = v.begin(); it != v.end(); it++)
                std::cout << *it << std::endl;
            std::cout << "reverse content : " << std::endl;
            for (typename _vector::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
                std::cout << *it << std::endl;
        }
    }
    /**
     * @brief CONSTRUCTORS
     */
    template <typename _vector>
    void test_constructors(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        std::cout << "test constructors" << std::endl;
        x = _vector(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(x);
        y = _vector(x.begin(), x.end());
        test_print(x);
        _vector z(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(x);
    }
    /**
     * @brief TEST VECTOR ASSIGN
     */
    template <typename _vector>
    void test_assign(_vector &X, _vector &Y)
    {
        _vector Z;
        std::cout << "TEST : " << test_no++ << std::endl;
        std::cout << "test assign" << std::endl;
        Z.assign(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(Z);
        X.assign(Z.begin(), Z.end());
        test_print(X);
        test_print(Y);
    }
    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _vector>
    void test_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        std::cout << "test copy constructor" << std::endl;
        _vector z(x);
        _vector w(y);
        test_print(x);
        test_print(w);
        test_print(z);
    }

    /**
     * @brief TEST OPERATOR =
     */
    template <typename _vector>
    void test_assign_op(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        std::cout << "test assignment operator" << std::endl;
        _vector Z(x);
        Z = x;
        y = Z;
        test_print(x);
        test_print(y);
        test_print(Z);
        x = _vector(Z);
        test_print(x);
        y = Z;
        test_print(y);
        y = _vector(Z);
        test_print(y);
    }

    /**
     * @brief TEST MIXED OP = and COPY
     */
    template <typename _vector>
    void test_mixed_assign_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        std::cout << "test mixed" << std::endl;
        _vector Z(x);
        Z = x;
        test_print(Z);
        x = Z;
        x = y;
        y = Z;
        test_print(x);
        test_print(y);
        test_print(Z);
    }

    /**
     * @brief TEST INSERT
     */

    template <typename _vector>
    void test_insert(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        typename _vector::iterator it;
        if (!x.empty())
            it = x.begin() + std::rand() % x.size();
        else
        {
            it = x.end();
            try
            {
                switch (std::rand() % 3)
                {
                case (0):
                    std::cout << *x.insert(it, rdm_val<typename _vector::value_type>()) << std::endl;
                    break;
                case (1):
                    if (!x.empty() && !y.empty())
                        y.insert(y.begin() + (std::rand() % y.size()), it, it + (std::rand() % (x.size() - (it - x.begin()))));
                    else if (!y.empty())
                        y.insert(y.begin() + (std::rand() % y.size()), it, x.end());
                    else
                        y.insert(y.begin(), it, x.end());
                    break;
                case (2):
                    if (!y.empty())
                        y.insert(y.begin(), (std::rand() % y.size()), rdm_val<typename _vector::value_type>());
                    else
                        y.insert(y.begin(), std::rand() % 5, rdm_val<typename _vector::value_type>());
                }
            }
            catch (std::exception &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        test_print(x);
    }

    template <typename _vector>
    void test_push(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        (void)x;
        (void)y;
    }

    template <typename _vector>
    void test_pop(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++ << std::endl;
        (void)x;
        (void)y;
    }

}

#define _TEST 8

template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_testArray[])(_vector &, _vector &) =
        {
            &_test::test_constructors,
            &_test::test_copy,
            &_test::test_assign_op,
            &_test::test_mixed_assign_copy,
            &_test::test_insert,
            &_test::test_assign,
            &_test::test_push,
            &_test::test_pop};

    _vector X;
    _vector Y;
    _vector Z;
    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << main_test_no++ << std::endl;
        int rand = std::rand() % _TEST;
        if (std::rand() % 2)
            _testArray[rand](X, Y);
        else
            _testArray[rand](Y, X);
        _test::test_print(X);
        _test::test_print(Y);
    }
}

int main(void)
{
    int seed = 42;
    test_vector<_NAMESPACE::vector<std::string> >(seed);

    return 0;
}
