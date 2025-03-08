/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/06 01:56:53 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


const int Fixed::fracBits = 8; 

Fixed::Fixed()
{
    this->rawBits = 0;
}
Fixed::~Fixed()
{

}
Fixed::Fixed(const Fixed & other)
{
    *this = other;
}
int Fixed::getRawBits( void ) const
{
    return (this->rawBits); 
}

void Fixed::setRawBits( int const raw )
{
    this->rawBits = raw;
}


Fixed & Fixed::operator= (const Fixed& other) {

    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}
