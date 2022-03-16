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
# define _NAMESPACE ft
#endif

// seed for randomness
#define _SEED 42
#define MAX_SEED 100

// Total number of cases
#define _TEST_NB 11
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
#define _SWAP 9
#define _OTHER_OPS 10

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 21

// Number of iterations of test suite
#define _NTESTS 1000

// Tests
#include "_test_tools.hpp"
#include "_test.hpp"

#endif 