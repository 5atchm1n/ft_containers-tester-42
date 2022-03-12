/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:08:25 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/12 16:23:19 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_test_header.hpp"

#ifndef _TEST_TOOLS_HPP
#define _TEST_TOOLS_HPP

/**
 * @brief Template overload RDM_VAL
 */
template <typename _Type>
_Type rdm_val()
{
    return (_Type());
}
/**
 * @brief Generate a random string
 */
template <>
std::string rdm_val<std::string>()
{
    std::string default_val[18] =
        {
            "This is a test",
            "there are many tests",
            "all tests should pass",
            "Lorem ipsum dolor sit amet",
            "consectetur adipiscing elit.",
            "Phasellus ut rutrum ante.",
            "Sed vehicula tellus eu erat",
            "congue dictum. Fusce a ultrices",
            "",
            "magna. Morbi fringilla ullamcorper",
            "nisi id scelerisque.",
            "Curabitur elementum enim",
            "a mi vestibulum eleifend.",
            "Pellentesque eget risus efficitur",
            "euismod mi ut, tristique lorem.",
            "Praesent ullamcorper venenatis augue,",
            "\t",
            "eget pretium velit vehicula et."};
    return (std::string(default_val[std::rand() % 18]));
}

/**
 * @brief Generate a random UINT
 *
 */
template <>
int rdm_val<int>()
{
    return (int(std::rand() % MAX_MAP_KEY));
}

template <>
ft::_const_test<int>
rdm_val<ft::_const_test<int> >()
{
    return (ft::_const_test<int>(rdm_val<int>()));
}

template <>
std::pair<const int, std::string>
rdm_val<std::pair<const int, std::string> >()
{
    return std::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
}

template <>
ft::pair<const int, std::string>
rdm_val<ft::pair<const int, std::string> >()
{
    return ft::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
}

#endif //_TEST_TOOLS_HPP