/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_alloc.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 03:41:28 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:42:57 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEST_ALLOC_M_HPP
#define _TEST_ALLOC_M_HPP

namespace _test_map
{
    template <typename _map>
    void test_fakeallocator(_map &X, _map &Y)
    {
        std::cout << "TEST : " << mtest_no++;
        std::cout << " - FAKE ALLOCATOR" << std::endl;
        try
        {
            if(!Y.empty())
            {
                _NAMESPACE::map<int,std::string,std::less<int>, lolocator<_NAMESPACE::pair<int, std::string> > > K(Y.begin(), Y.end(), std::less<int>(), lolocator<_NAMESPACE::pair<int, std::string> >());
                test_print(K);
            }
            if(!X.empty())
            {
                _NAMESPACE::map<int,std::string,std::less<int>, lolocator<_NAMESPACE::pair<int, std::string> > > Z(X.begin(), X.end(), std::less<int>(), lolocator<_NAMESPACE::pair<int, std::string> >());
                test_print(Z);
            }
        }
        catch (std::exception &error)
        {
            std::cout << "Vade retro fake allocator" << std::endl;
        }
    }  
}

#endif /* _TEST_ALLOC_M_HPP */