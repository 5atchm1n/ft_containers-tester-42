/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/18 14:39:54 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_TEST_HEADER_HPP
#define _SET_TEST_HEADER_HPP

#include "../_test_header.hpp"

// Total number of cases
#define _SET_MAIN 9
// Test cases
#define SET_DEFAULT_CONSTRUCTOR 0
#define SET_INSERT 1
#define SET_ERASE 2
#define SET_CLEAR 3
#define SET_BOUNDS 4
#define SET_REL_OP 5
#define SET_ITERATORS 6
#define SET_SWAP 7
#define SET_COUNT 8

// For debugging
static int set_test_no = 0;
static int set_main_test_no = 0;

// Tests
#include "tests/_test_tools.hpp"
#include "tests/_test_basic.hpp"
#include "tests/_test_insert.hpp"
#include "tests/_test_erase.hpp"
#include "tests/_test_bounds.hpp"

#endif  //_SET_TEST_HEADER_HPP
