/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 01:53:09 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST_HEADER_HPP
#define _MAP_TEST_HEADER_HPP

#include "../../_test_header.hpp"

// Total number of cases
#define M_TEST_MAIN 10
// Test cases
#define M_DEFAULT_CONSTRUCTOR 0
#define M_OPERATOR 1
#define M_INSERT 2
#define M_ERASE 3
#define M_CLEAR 4
#define M_BOUNDS 5
#define M_REL_OP 6
#define M_ITERATORS 7
#define M_SWAP 8
#define M_COUNT 9

// For debugging
static int mtest_no = 0;
static int mmain_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_MAP_TEST_HEADER_HPP