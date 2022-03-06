/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 04:45:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/25 22:02:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>
#include "map.hpp"

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const
	{
		return lhs < rhs;
	}
};

template<typename T1, typename T2>
void	ft_print(ft::map<T1, T2> map, std::string const name, int i)
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << " TEST : " << i << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << name << " contains:" << std::endl;
	typename ft::map<T1, T2>::const_iterator itt = map.begin();
		for (itt = map.begin(); itt != map.end(); ++itt)
		std::cout << itt->first << " => " << itt->second << '\n';
	std::cout << "size :" << map.size() << std::endl;
}

int main()
{

	int i = 1;
	
	ft::pair<ft::map<char, int>::iterator, bool> ret;
	bool (*fn_pt)(char, char) = fncomp;
	
	std::cout << "Testing constructors" << std::endl;
	ft::map<char, int> first;
	ft::map<char, int> mymap;	

	// OPERATOR [ ]	
	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	ft_print<char, int>(first, "basic test MAP - first", i++);
	// CONSTRUCTORS
	ft::map<char, int> second(first.begin(), first.end());
	ft_print<char, int>(second, "basic test MAP - second", i++);
	ft::map<char, int> third(second);
	ft::map<char, int, classcomp> fourth; // class as Compare
	ft::map<char, int, bool (*)(char, char)> fifth(fn_pt); // function pointer as Compare

	// TESTING INSERT
	std::cout << "Testing INSERT basic" << std::endl;

	// first insert function version (single parameter):
	mymap.insert(ft::pair<char, int>('a', 100));
	mymap.insert(ft::pair<char, int>('z', 200));

	// TEST 1
	ft_print<char, int>(mymap, "basic test MAP", i++);
	ret = mymap.insert(ft::pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// TEST 2
	ft_print<char, int>(mymap, "basic test MAP", i++);
	mymap['b'] = 20;
	mymap['c'] = 67;
	mymap['e'] = 67;
	mymap['x'] = 67;
	mymap['f'] = 90;
	// TEST 3
	ft_print<char, int>(mymap, "basic test MAP", i++);
	// second insert function version (with hint position):
	ft::map<char, int>::iterator it = mymap.begin();
	// third insert function version (range insertion):
	ft::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));
	// TEST 4
	ft_print<char, int>(mymap, "basic test MAP", i++);
	// TEST 5
	ft_print<char, int>(anothermap, "basic test MAP", i++);

	it=mymap.find('b');
	mymap.erase (it);                   // erasing by iterator
	std::cout << mymap.erase ('c') << std::endl;                  // erasing by key
	// TEST 6
	ft_print<char, int>(mymap, "basic test MAP", i++);

	it=mymap.find ('e');
	mymap.erase ( it, mymap.end());
	// TEST 7
	ft_print<char, int>(mymap, "basic test MAP", i++);
	typedef ft::map<int, std::string>::value_type	map_pair;

	// TEST 8 start
	std::list<map_pair> lst;
	std::list<map_pair>::iterator itlst;

	lst.push_back(map_pair(42, "lol"));
	lst.push_back(map_pair(50, "mdr"));
	lst.push_back(map_pair(35, "funny"));
	lst.push_back(map_pair(45, "bunny"));
	lst.push_back(map_pair(21, "fizz"));
	lst.push_back(map_pair(38, "buzz"));
	lst.push_back(map_pair(55, "fuzzy"));

	std::cout << "\nList contains:\n" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		std::cout << itlst->first << "=>" << itlst->second << std::endl;
	std::cout << "\nList end\n" << std::endl;

	ft::map<int, std::string> mp;
	
	mp.insert(lst.begin(), lst.end());
	
	i = 0;
	ft_print<int, std::string>(mp, "Advanced test", i++);

	lst.clear();

	lst.push_back(map_pair(87, "hey"));
	lst.push_back(map_pair(47, "eqweqweq"));
	lst.push_back(map_pair(35, "this key is already inside"));
	lst.push_back(map_pair(23, "but not that one"));
	lst.push_back(map_pair(1, "surprising isnt it?"));
	lst.push_back(map_pair(100, "is it enough??"));
	lst.push_back(map_pair(55, "inside map too"));

	std::cout << "List contains:" << std::endl;
	for (itlst = lst.begin(); itlst != lst.end(); ++itlst)
		std::cout << itlst->first << "=>" << itlst->second << std::endl;
	std::cout << "\nList end\n" << std::endl;
	
	ft::map<int, std::string>::iterator itmp;
	
	ft_print<int, std::string>(mp, "Advanced Test", i++);

	mp.insert(lst.begin(), lst.end());

	ft_print<int, std::string>(mp, "Advanced Test", i++);
	return 0;
}
