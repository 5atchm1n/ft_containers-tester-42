/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 02:02:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STACK_HEADER_HPP
#define _STACK_HEADER_HPP

#include "../../_test_header.hpp"

// Total number of cases
#define S_TEST_MAIN 4
// Test cases
#define S_DEFAULT_CONSTRUCTOR 0
#define S_REL_OP 1
#define S_PUSH 2
#define S_POP 3

// For debugging
static int stest_no = 0;
static int smain_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_STACK_HEADER_HPP