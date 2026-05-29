/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:54:48 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 18:07:45 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Data
{
	const char *data;

public:
	Data();
	~Data();
	Data(const Data &src);
	Data &operator=(const Data &src);

	const char *getData() const;
};
