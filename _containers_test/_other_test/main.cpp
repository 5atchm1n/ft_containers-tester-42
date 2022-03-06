/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:16:30 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/01 23:47:39 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.iterator.hpp"
#include "vector.hpp"
#include <vector>
#include <iostream>

int main (void)
{ 
    int test[5];
    
    ft::reverse_iterator<int *> _int2(test);
    ft::reverse_iterator<int *> _int(_int2);
   
//    _int.current = test;
    test[0] = 0;
    test[1] = 1;
    test[2] = 2;
    test[3] = 3;
    test[4] = 4;

    _int--;
    std::cout << *_int << std::endl;
    _int = _int - 1;
    std::cout << *_int << std::endl;
    _int2 = _int;
    std::cout << *_int2 << std::endl;
    if (_int == _int2)
        std::cout << *_int << " == " << *_int2 << std::endl;
    _int = _int - 1;
    std::cout << *_int << std::endl;

    if (_int == _int2)
        std::cout << *_int << " == " << *_int2 << std::endl;

    ft::vector<int> _vec_test;
/*
    std::vector<int> _vec_real;
    try {
    _vec_real.reserve(10000000000000);
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
    }
    */
    try
    {
    _vec_test.reserve(100);
    ft::vector<int>_vec_test_2(5);
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
    }

    
    return (0);
}