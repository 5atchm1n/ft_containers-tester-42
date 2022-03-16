/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:58:43 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST_ITERATOR_HPP
#define _MAP_TEST_ITERATOR_HPP

#include "../_test_header.hpp"

namespace _test_map
{
    template <typename _it, typename _rit>
    void test_iter_increment(_it & _iter, _rit &_rev_iter, int rdm)
    {
        std::cout << "test iterator increment" << std::endl;
        while (rdm--)
        {
            _iter++;
            _rev_iter++;
        }
        std::cout << _iter->first << " => " << _iter->second << std::endl;
        std::cout << _rev_iter->first << " => " << _rev_iter->second << std::endl;
    }

    template <typename _it, typename _rit>
    void test_iter_decrement(_it & _iter, _rit &_rev_iter, int rdm)
    {
        std::cout << "test iterator decrement" << std::endl;
        while (rdm--)
        {
            _iter--;
            _rev_iter--;
        }
        std::cout << _iter->first << " => " << _iter->second << std::endl;
        std::cout << _rev_iter->first << " => " << _rev_iter->second << std::endl;
    }
    
    template <typename _map>
    void test_iterators(_map &X, _map &Y)
    {
        (void)Y;
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - ITERATORS" << std::endl;

        typename _map::iterator it;
        it = X.begin();
        typename _map::iterator _it(it);
        typename _map::const_iterator cit = X.end();
        typename _map::reverse_iterator rit = X.rbegin();
        typename _map::const_reverse_iterator crit = X.rend();

        size_t rdm;
        if (X.size())
        {
            rdm = std::rand() % X.size();
            if (rdm)
            {
                test_iter_increment<typename _map::iterator, typename _map::reverse_iterator>(_it, rit, rdm);
                test_iter_decrement<typename _map::const_iterator, typename _map::const_reverse_iterator>(cit, crit, rdm);
            }
        }
    }
}

#endif  //_VECTOR_TEST_BASIC_HPP