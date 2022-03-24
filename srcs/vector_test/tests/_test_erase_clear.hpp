/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_erase_clear.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:28:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _VECTOR_TEST_MODIFY_HPP
#define _VECTOR_TEST_MODIFY_HPP

namespace _test_vector
{

template <typename _vector>
void test_erase(_vector &X, _vector &Y)
{
    std::cout << "TEST : " << vtest_no++;
    std::cout << " - ERASE" << std::endl;
    typename _vector::iterator pos;
    switch (std::rand() % 4)
    {
        case (0) :
            std::cout << "ERASE : case 0" << std::endl;
            if (!X.empty())
                X.erase(X.begin());
        case (1) :
            std::cout << "ERASE : case 1" << std::endl;
            if (!X.empty())
                X.erase(X.end() - 1);
        case (2) :
            std::cout << "ERASE : case 2" << std::endl;
            if (!X.empty() && X.size() > 1)
            {   
                pos = X.begin() + (std::rand() % X.size());
                X.erase(X.begin(), pos);
            }
        case (3) :
            std::cout << "ERASE : case 3" << std::endl;
            if (!Y.empty() && Y.size() > 1)
            {
                pos = Y.begin() + (std::rand() % Y.size());
                Y.erase(Y.begin(), pos);
            }
    }
}

template <typename _vector>
void
test_clear(_vector &X, _vector &Y)
{
    std::cout << "TEST : " << vtest_no++;
    std::cout << " - CLEAR" << std::endl;
    if (std::rand() % 2)
        X.clear();
    else
        Y.clear();
    std::cout << "X size : " << X.size() << std::endl;
    std::cout << "Y size : " << Y.size() << std::endl;
}
    
}

#endif  // _VECTOR_TEST_MODIFY_HPP