/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 05:37:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HEADER_HPP
#define _VECTOR_HEADER_HPP

#include "_test_header.hpp"

// Total number of cases
#define _VECTOR_NTESTS 13
// Test cases
#define V_BASIC_C 0
#define V_COPY_C 1
#define V_ASSIGN_OP 2
#define V_MIXED_0_3 3
#define V_REL_OP 4
#define V_INSERT 5
#define V_ASSIGN 6
#define V_PUSH 7
#define V_POP 8
#define V_ERASE 9
#define V_RESIZE 10
#define V_SWAP 11
#define V_CLEAR 12

// For debugging
static int vtest_no = 0;
static int vmain_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_VECTOR_HEADER_HPP