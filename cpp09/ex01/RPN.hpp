/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <thaperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:47:08 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/10 18:48:24 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class RPN
{
public:
	RPN();
	~RPN();
	RPN(const RPN& src);
	RPN& operator=(const RPN& src);

	//Member Functions
	void	calculate(std::string opStr);
};
