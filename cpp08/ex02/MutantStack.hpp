/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 20:43:42 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/04 20:04:54 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>

template < typename T >
class MutantStack : public std::stack<T>
{

public:
	MutantStack(): std::stack<T>() {}
	~MutantStack() {}
	MutantStack(const MutantStack& src): std::stack<T>(src) {}
	MutantStack& operator=(const MutantStack& src)
	{
		if (this != &src)
			std::stack<T>::operator=(src);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	//Member Functions
	iterator	begin()
	{
		return (std::stack<T>::c.begin());
	}

	iterator	rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}
	
	iterator	end()
	{
		return (std::stack<T>::c.end());
	}

	iterator	rend()
	{
		return (std::stack<T>::c.rend());
	}
};
