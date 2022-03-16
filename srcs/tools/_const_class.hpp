/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _const_class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:46:20 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/16 03:18:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_CONST_CLASS_HPP
#define _TEST_CONST_CLASS_HPP

namespace ft
{

template <typename T>
class _const_test {
	public:
		typedef T	value_type;

		_const_test(void) : value() { };
		_const_test(value_type src) : value(src) { };
		_const_test(_const_test const &src) : value(src.value) { };
		~_const_test(void) { };
        
		void print(std::ostream &o) { o << "_const_test::print called [" << this->value << "]"; }
		void print(std::ostream &o) const { o << "_const_test::print const called [" << this->value << "]"; }
		_const_test &operator=(value_type src) { this->value = src; return *this; };
		_const_test &operator=(_const_test const &src) {
			this->value = src.value;
			return *this;
		}
		value_type	getValue(void) const { return this->value; }

		operator value_type(void) const
        {
			return value_type(this->value);
		}
        
	private:
		value_type	value;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, _const_test<T> const &tclass)
{
    tclass.print(o);
	return o;
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, _const_test<T> &tclass)
{
    tclass.print(o);
	return o;
}

}

#endif  //_TEST_CONST_CLASS_HPP