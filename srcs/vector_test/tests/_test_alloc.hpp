/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_alloc.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 03:41:28 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/19 13:34:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEST_ALLOC_V_HPP
#define _TEST_ALLOC_V_HPP

namespace _test_vector
{
    template <typename _vector>
    void test_fakeallocator(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << vtest_no++;
        std::cout << " - FAKE ALLOCATOR" << std::endl;
        try
        {
            if(!Y.empty())
            {
                _NAMESPACE::vector<int, lolocator<int> > K;
                K.push_back(10);
                test_print(K);
            }
            if(!X.empty())
            {
                _NAMESPACE::vector<int, lolocator<int> > Z;
                Z.push_back(10);
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