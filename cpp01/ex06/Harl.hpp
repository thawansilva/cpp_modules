/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 07:54:32 by thaperei          #+#    #+#             */
/*   Updated: 2026/03/07 10:11:31 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
#define HARL_CPP
#include <iostream>
#define NUM_LEVELS 4

class Harl
{
public:
	Harl ();
	~Harl ();
	void complain( std::string level );

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
};

typedef void (Harl::*functionPerLevel)(void);
#endif
