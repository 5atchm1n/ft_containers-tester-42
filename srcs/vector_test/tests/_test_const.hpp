/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_const.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:14:31 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/18 14:25:59 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_CONST_VECTOR_HPP
#define _TEST_CONST_VECTOR_HPP

namespace   _test_vector
{
template<class _vector>
void test_const(int rdm_seed)
{
    std::srand(rdm_seed);
    std::cout << "TEST : CONST TEST" << std::endl;

    _vector X;
    typename _vector::const_iterator cit;
    typename _vector::iterator it;
    typename _vector::const_reverse_iterator rcit;
    typename _vector::reverse_iterator rit;

    std::cout << "CREATE VECTOR" << std::endl;
    for (int i = 0; i < MAX_TEST_SIZE; i++)
        X.push_back(rdm_val<typename _vector::value_type>());
    std::cout << "X Contains :" << std::endl;
    for (it = X.begin(); it != X.end(); it++)
        std::cout << *it << std::endl;
    for (rit = X.rbegin(); rit != X.rend(); rit++)
        std::cout << *rit << std::endl;
    
    std::cout << "CREATE const VECTOR" << std::endl;
    const _vector Y(X.begin(), X.end());
    std::cout << "Const Y Contains :" << std::endl;
    for (cit = Y.begin(); cit != Y.end(); cit++)
        std::cout << *cit << std::endl;
    for (rcit = Y.rbegin(); rcit != Y.rend(); rcit++)
        std::cout << *rcit << std::endl;
 
    std::cout << "front :" << X.front() << std::endl;
    std::cout << "back :" << X.back() << std::endl;
    std::cout << "front :" << Y.front() << std::endl;
    std::cout << "back :" << Y.back() << std::endl;
}

}

#endif /* _TEST_CONST_VECTOR_HPP */