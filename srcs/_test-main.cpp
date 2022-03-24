/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-main.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:59:32 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:39:54 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_header.hpp"

int main(void)
{
    int seed = _SEED;
    for (int i = 0; i < MAX_SEED; i++)
    {
    #if _TVECTOR
        test_vector<_NAMESPACE::vector<std::string> >(seed);
    #endif
    #if _TMAP    
        test_map<_NAMESPACE::map<int, std::string> >(seed);
    #endif
    #if _TSTACK
        test_stack<_NAMESPACE::stack<int> >(seed);
    #endif
    #if _TSET
        test_set<_NAMESPACE::set<int> >(seed);
    #endif    
        seed++;
    }
    #if _TCONST
    
     #if _TVECTOR
        _test_vector::test_const<_NAMESPACE::vector<ft::_const_test<int> > >(seed);
     #endif
     #if _TMAP    
        _test_map::test_const<_NAMESPACE::map<ft::_const_test<int>, ft::_const_test<std::string> > >(seed);
     #endif
     #if _TSET
        _test_set::test_const<_NAMESPACE::set<ft::_const_test<int> > >(seed);
     #endif    
    
    #endif
    
    return 0;
}