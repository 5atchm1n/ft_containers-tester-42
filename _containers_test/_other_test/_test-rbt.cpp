/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-rbt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:54:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/19 18:42:55 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"
#include "map.hpp"
#include "vector.hpp"
#include <map>

int main(void)
{
    ft::_rbtree<int, std::less<int>, std::allocator<int> > tree;

    ft::map<int, std::string> _map;

    tree._insert_node(5);
    std::cout << "ADD 10" << std::endl;
    tree._insert_node(10);
    std::cout << "ADD 12" << std::endl;
    tree._insert_node(12);
    std::cout << "ADD 8" << std::endl;
    tree._insert_node(8);
    tree._insert_node(3);
    tree._insert_node(14);
    std::cout << tree << std::endl;

    return 0;
}