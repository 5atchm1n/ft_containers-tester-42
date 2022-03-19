/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_const.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:14:31 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/18 14:42:05 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_CONST_SET_HPP
#define _TEST_CONST_SET_HPP

namespace   _test_set
{
template<class _set>
void test_const(int rdm_seed)
{
    std::srand(rdm_seed);
    std::cout << "TEST : CONST TEST" << std::endl;

    _set X;
    typename _set::const_iterator cit;
    typename _set::const_reverse_iterator crit;
    typename _set::iterator it;
    typename _set::reverse_iterator rit;

    size_t rdm = std::rand();
    std::cout << "CREATE MAP" << std::endl;
    for (size_t i = 0; i < rdm % MAX_TEST_SIZE; i++)
        X.insert(rdm_val<typename _set::value_type>());

    std::cout << "X Contains :" << std::endl;
    for (it = X.begin(); it != X.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "reverse :" << std::endl;
    for (rit = X.rbegin(); rit != X.rend(); rit++)
        std::cout << rit->first << " " << rit->second << std::endl;
    
    std::cout << "CREATE const MAP" << std::endl;
    const _set Y(X.begin(), X.end());
    std::cout << "Const Y Contains :" << std::endl;
    for (cit = Y.begin(); cit != Y.end(); cit++)
        std::cout << cit->first << " " << cit->second << std::endl;
    std::cout << "reverse :" << std::endl;
    for (crit = Y.rbegin(); crit != Y.rend(); crit++)
        std::cout << crit->first << " " << crit->second << std::endl;
 
}

}

#endif /* _TEST_CONST_set_HPP */