/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_push_pop.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:29:27 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _TEST_PUSH_POP_V_HPP
#define _TEST_PUSH_POP_V_HPP

namespace _test_vector
{
template <typename _vector>
void test_push(_vector &X, _vector &Y)
{
    std::cout << "TEST : " << vtest_no++;
    std::cout << " - PUSH_BACK" << std::endl;
    switch (std::rand() % 3)
    {
        case (0) :
            std::cout << "PUSH_BACK : case 0" << std::endl;
            for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                X.push_back(rdm_val<typename _vector::value_type>());
        case (1) :
            std::cout << "PUSH_BACK : case 1" << std::endl;
            for (int i = 0; i < std::rand() % MAX_TEST_SIZE; i++)
                Y.push_back(rdm_val<typename _vector::value_type>());
        case (2) :
            std::cout << "PUSH_BACK : case 2" << std::endl;
            _vector Z;
            Z.push_back(rdm_val<typename _vector::value_type>());
            _test_vector::test_print(Z);
    }
}
template <typename _vector>
void test_pop(_vector &X, _vector &Y)
{
    std::cout << "TEST : " << vtest_no++;
    std::cout << " - POP" << std::endl;
    switch (std::rand() % 2)
    {
        case (0) :
            std::cout << "POP : case 0" << std::endl;
            if (!X.empty())
                for (size_t i = 0; i < X.size(); i++)
                    X.pop_back();
        case (1) :
            std::cout << "POP : case 1" << std::endl;
            if (!Y.empty())
                for (size_t i = 0; i < Y.size(); i++)
                    Y.pop_back();
    }
}

}

#endif  // _TEST_PUSH_POP_V_HPP