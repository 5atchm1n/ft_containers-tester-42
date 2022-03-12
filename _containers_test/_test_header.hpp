/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_header.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:16:13 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 04:16:08 by sshakya          ###   ########.fr       */
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

// random number seed
#define _SEED 42
// max number of seeds to test
#define MAX_SEED 10

// Number of iterations of test suite
#ifndef _NTESTS
#define _NTESTS 1000
#endif

#define MAX_TEST_SIZE 100
#define MAX_MAP_KEY 100

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

#include "tools/_test_tools.hpp"

#include "vector_test/_test-vector.cpp"
#include "map_test/_test-map.cpp"
#include "stack_test/_test-stack.cpp"
#include "set_test/_test-set.cpp"

#endif