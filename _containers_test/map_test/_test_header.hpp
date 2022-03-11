/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atruphem <atruphem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 19:11:48 by atruphem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_TEST_HEADER_HPP
#define _MAP_TEST_HEADER_HPP

#include "map.hpp"
#include <string>
#include <map>
#include <iterator>
#include <cstdlib>
#include <climits>
#include <iostream>

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 1

// Total number of cases
#define _TEST_MAIN 9
// Test cases
#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _INSERT 3
#define _ERASE 4
#define _CLEAR 5
#define _ARRINDEX_OP 6
#define _BOUNDS 7
#define _FAKE_ALLOCATOR 8


// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 21

// Number of iterations of test suite
#define _NTESTS 1000

// For debugging
static int test_no = 0;
static int main_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"


#endif 