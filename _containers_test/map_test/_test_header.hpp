/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 03:53:56 by sshakya          ###   ########.fr       */
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
#endif

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 10

#define _MAP_MAX_KEY 1024

// Total number of cases
#define _TEST_MAIN 10
// Test cases
#define _DEFAULT_CONSTRUCTOR 0
#define _OPERATOR 1
#define _INSERT 2
#define _ERASE 3
#define _CLEAR 4
#define _BOUNDS 5
#define _REL_OP 6
#define _ITERATORS 7
#define _SWAP 8
#define _COUNT 9

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 100

// Number of iterations of test suite
#define _NTESTS 1000

// For debugging
static int test_no = 0;
static int main_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_MAP_TEST_HEADER_HPP