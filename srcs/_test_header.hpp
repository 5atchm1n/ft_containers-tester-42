/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:16:13 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/13 04:44:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TEST_HEADER_HPP
#define _TEST_HEADER_HPP

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

#ifndef _TVECTOR
#define _TVECTOR 0
#endif

#ifndef _TMAP
#define _TMAP 0
#endif

#ifndef _TSTACK
#define _TSTACK 0
#endif

#ifndef _TSET
#define _TSET 0
#endif

#ifndef _TCONST
#define _TCONST 0
#endif


// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 8

// Number of iterations of test suite
#define _NTESTS 1024

#define MAX_TEST_SIZE 256
#define MAX_MAP_KEY 128

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstdlib>
#include <climits>

#include <vector>
#include <map>
#include <stack>
#include <set>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "set.hpp"

#include "tools/_const_class.hpp"
#include "tools/_test_tools.hpp"

#include "vector_test/_test-vector.cpp"
#include "map_test/_test-map.cpp"
#include "stack_test/_test-stack.cpp"
#include "set_test/_test-set.cpp"

#endif
