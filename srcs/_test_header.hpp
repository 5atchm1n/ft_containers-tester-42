/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:16:13 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/24 13:26:32 by sshakya          ###   ########.fr       */
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

#ifndef _TALLOC
#define _TALLOC 0
#endif


// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 8

// Number of iterations of test suite
#define _NTESTS 1024

#define MAX_TEST_SIZE 512
#define MAX_MAP_KEY 1024

#include <iostream>
#include <iomanip>
#include <string>
#include <iterator>
#include <cstdlib>
#include <climits>
#include <cstddef>

// Modify this to point to your ft::pair file
#if _TMAP
#include "pair.hpp"
#endif

#include "tools/_fake_alloc.hpp"
#include "tools/_const_class.hpp"
#include "tools/_test_tools.hpp"

#include <vector>
#include <map>
#include <stack>
#include <set>
#if _TVECTOR
#include "vector.hpp"
#include "vector_test/_test-vector.cpp"
#endif
#if _TMAP
#include "map.hpp"
#include "map_test/_test-map.cpp"
#endif
#if _TSTACK
#include "stack.hpp"
#include "stack_test/_test-stack.cpp"
#endif
#if _TSET
#include "set.hpp"
#include "set_test/_test-set.cpp"
#endif

#endif
