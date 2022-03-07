/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/07 15:33:18 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _VECTOR_TEST_MODIFY_HPP
#define _VECTOR_TEST_MODIFY_HPP

namespace _test
{

        /**
     * @brief TEST INSERT
     */

    template <typename _vector>
    void test_insert(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
    }
    
    template <typename _vector>
    void test_erase(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - ERASE" << std::endl;
    }

    template <typename _vector>
    void
    test_clear(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
    }
    
}

#endif  // _VECTOR_TEST_MODIFY_HPP