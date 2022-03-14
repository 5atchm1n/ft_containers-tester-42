#ifndef _STACK_TEST_HEADER_HPP
#define _STACK_TEST_HEADER_HPP

#include "stack.hpp"
#include <string>
#include <stack>
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
#define _TEST_NB 5
#define _DEFAULT_CONSTRUCTOR 0
#define _REL_OP 1
#define _PUSH 2
#define _POP 3

// MAX amount of values to assign/insert
#define _MAX_TEST_SIZE 21

// Number of iterations of test suite
#define _NTESTS 1000

// Tests
#include "_test_tools.hpp"
#include "_test.hpp"

#endif