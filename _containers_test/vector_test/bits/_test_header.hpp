/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:15 by sshakya           #+#    #+#             */
<<<<<<< HEAD:_containers_test/vector_test/bits/_test_header.hpp
/*   Updated: 2022/03/12 02:06:05 by sshakya          ###   ########.fr       */
=======
/*   Updated: 2022/03/10 03:56:50 by sshakya          ###   ########.fr       */
>>>>>>> master:_containers_test/vector_test/_test_header.hpp
/*                                                                            */
/* ************************************************************************** */

#ifndef _VECTOR_HEADER_HPP
#define _VECTOR_HEADER_HPP

<<<<<<< HEAD:_containers_test/vector_test/bits/_test_header.hpp
#include "_test_header.hpp"
=======
#include "vector.hpp"
#include <string>
#include <vector>
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
>>>>>>> master:_containers_test/vector_test/_test_header.hpp

// Total number of cases
#define _VECTOR_NTESTS 13
// Test cases
<<<<<<< HEAD:_containers_test/vector_test/bits/_test_header.hpp
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
=======
#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _MIXED_0_3 3
#define _REL_OP 4

// Total number of cases
#define _TEST_MAIN 8
// Test cases
#define _INSERT 0
#define _ASSIGN 1
#define _PUSH 2
#define _POP 3
#define _ERASE 4
#define _RESIZE 5
#define _SWAP 6
#define _CLEAR 7

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 10

// Number of iterations of test suite
#define _NTESTS 5000
#define _NTESTS_BASIC 50
>>>>>>> master:_containers_test/vector_test/_test_header.hpp

// For debugging
static int vtest_no = 0;
static int vmain_test_no = 0;

// Tests
#include "_test_tools.hpp"
#include "_test_basic.hpp"
#include "_test_modify.hpp"

#endif  //_VECTOR_HEADER_HPP