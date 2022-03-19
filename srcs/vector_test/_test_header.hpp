/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/19 13:22:41 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HEADER_HPP
#define _VECTOR_HEADER_HPP

#include "../_test_header.hpp"

// Total number of cases
#define _VECTOR_NTESTS 13
// Test cases
#define V_BASIC_C 0
#define V_ASSIGN_OP 1
#define V_MIXED_0_3 2
#define V_REL_OP 3
#define V_INSERT 4
#define V_ASSIGN 5
#define V_PUSH 6
#define V_POP 7
#define V_ERASE 8
#define V_RESIZE 9
#define V_SWAP 10
#define V_CLEAR 11
#define V_ALLOC 12

// For debugging
static int vtest_no = 0;
static int vmain_test_no = 0;

// Tests
#include "tests/_test_tools.hpp"
#include "tests/_test_assign.hpp"
#include "tests/_test_insert.hpp"
#include "tests/_test_basic.hpp"
#include "tests/_test_push_pop.hpp"
#include "tests/_test_erase_clear.hpp"
#include "tests/_test_alloc.hpp"

#if _TCONST
#include "tests/_test_const.hpp"
#endif

#endif  //_VECTOR_HEADER_HPP