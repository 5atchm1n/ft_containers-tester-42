#ifndef _VECTOR_TEST_HEADER_HPP
#define _VECTOR_TEST_HEADER_HPP

#include "vector.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <climits>
#include <iostream>

#ifndef _NAMESPACE
# define _NAMESPACE ft
#endif

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 100

// Total number of cases
#define _TEST_NB 13
#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _REL_OP 3
#define _INSERT 4
#define _ASSIGN 5
#define _PUSH 6
#define _POP 7
#define _ERASE 8
#define _RESIZE 9
#define _SWAP 10
#define _CLEAR 11
#define _RESERVE 12

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 21

// Number of iterations of test suite
#define _NTESTS 100

// Tests
#include "_test_tools.hpp"
#include "_test.hpp"

#endif