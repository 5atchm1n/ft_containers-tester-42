/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/26 13:44:33 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <climits>

#define _MAX_TEST_SIZE 20
#define _NTESTS 10

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

namespace _test
{

    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }

    template <>
    std::string rdm_val<std::string>()
    {
        std::string default_val[] =
            {
                "",
                "This is a test",
                "there are many tests",
                "all tests should pass",
                "Lorem ipsum dolor sit amet",
                "consectetur adipiscing elit.",
                "Phasellus ut rutrum ante.",
                "Sed vehicula tellus eu erat",
                "congue dictum. Fusce a ultrices",
                "magna. Morbi fringilla ullamcorper",
                "nisi id scelerisque.",
                "Curabitur elementum enim",
                "a mi vestibulum eleifend.",
                "Pellentesque eget risus efficitur",
                "euismod mi ut, tristique lorem.",
                "Praesent ullamcorper venenatis augue,",
                "eget pretium velit vehicula et."
            };
        return (std::string(default_val[std::rand() % 17]));
    }

    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }

    template <typename _vector>
    void test_print(const _vector &v)
    {
        std::cout << "empty : " << v.empty() << std::endl;
        std::cout << "size : " << v.size() << std::endl;
        std::cout << "capacity : " << v.capacity() << std::endl;
        std::cout << "max size : " << v.max_size() << std::endl;
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
    template <typename _vector>
    void test_constructors(_vector &x, _vector &y)
    {
        std::cout << "test constructors" << std::endl;
        x = _vector(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(x);
        y = _vector(x.begin(), x.end());
        test_print(x);
        _vector z(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(x);
    }
    template <typename _vector>
    void test_assign(_vector &X, _vector &Y)
    {
        _vector Z;
        std::cout << "test assign" << std::endl;
        Z.assign(std::rand() % 50, rdm_val<typename _vector::value_type>());
        test_print(Z);
        X.assign(Z.begin(), Z.end());
        test_print(X);
        test_print(Y);
    }

    template <typename _vector>
    void test_copy(_vector x, _vector y)
    {
        std::cout << "test copy constructor" << std::endl;
        _vector z(x);
        test_print(x);
        test_print(y);
        test_print(z);
        std::cout << "test assignment operator" << std::endl;
        z = x;
        test_print(x);
        test_print(z);
        std::cout << "test mixed" << std::endl;
        x = z;
        x = y;
        y = z;
        test_print(x);
        test_print(y);
        test_print(z);
        z = _vector(x);
        test_print(z);
    }
    template <typename _vector>
    void test_insert(_vector &x, _vector &y)
    {
        typename _vector::iterator it;
        if (!x.empty())
            it = x.begin() + std::rand() % x.size();
        else
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
                case(2):
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
        test_print(x);
    }

    template <typename _vector>
    void test_push(_vector x, _vector y)
    {
        (void)x;
        (void)y;
    }

    template <typename _vector>
    void test_pop(_vector x, _vector y)
    {
        (void)x;
        (void)y;
    }

}
template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_testArray[])(_vector &, _vector &) =
        {
            &_test::test_constructors,
            &_test::test_assign,
            &_test::test_copy,
            &_test::test_insert,
            &_test::test_push,
            &_test::test_pop};

    _vector X;
    _vector Y;
    _vector Z;
    for (int i = 0; i < _NTESTS; i++)
    {
        int rand = std::rand() % 6;
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