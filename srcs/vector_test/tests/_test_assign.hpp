/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_assign.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:38:03 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:16:29 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _TEST_ASSIGN_V_HPP
#define _TEST_ASSIGN_V_HPP

/**
 * @brief TEST VECTOR ASSIGN
 */
namespace _test_vector
{

template <typename _vector>
void test_assign(_vector &X, _vector &Y)
{
    _vector Z;
    std::cout << "TEST : " << vtest_no++;
    std::cout << " - ASSIGN" << std::endl;
    switch (std::rand() % 4)
    {
    case (0):
        Z.assign(0, rdm_val<typename _vector::value_type>());
    case (1):
        Z.assign(std::rand() % MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
    case (2):
        Z.assign(Y.begin(), Y.end());
    case (3):
        if (!Y.empty())
            Z.assign(Y.begin() + (std::rand() % Y.size()), Y.end());
    case (4):
        if (!Y.empty())
            Z.assign(Y.begin(), Y.end() - (std::rand() % Y.size()));
    case (5):
        if (!Z.empty())
            X.assign(Z.begin(), Z.end() - (std::rand() % Z.size()));
    }
    _test_vector::test_print(Z);
}

}   // END NAMESPACE

#endif  // _TEST_ASSIGN_V_HPP