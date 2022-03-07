/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/07 15:42:35 by sshakya          ###   ########.fr       */
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

#ifndef _NAMESPACE
#define _NAMESPACE ft
#include "pair.hpp"
#endif

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 1

// Total number of cases
#define _TEST_BASIC 3
// Test cases
#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2

// Total number of cases
#define _TEST_MAIN 3
// Test cases
#define _INSERT 0
#define _ERASE 1
#define _CLEAR 2

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 10

// Number of iterations of test suite
#define _NTESTS 10
#define _NTESTS_BASIC 10

// For debugging
static int test_no = 0;
static int main_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_MAP_TEST_HEADER_HPP