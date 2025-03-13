/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/13 22:32:43 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fracBits = 8; 

Fixed::Fixed(const int nbr)
{
    std::cout << "Default Constructor called" << std::endl;
    this->rawBits = nbr << Fixed::fracBits;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Default Constructor called" << std::endl;
    this->rawBits = static_cast<int>(roundf(nbr * (1 << fracBits)));
}
Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl; 
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->rawBits) / (1 << fracBits);
}

int Fixed::toInt( void ) const
{
    return static_cast<int>(this->rawBits >> this->fracBits);  
}

Fixed::Fixed(const Fixed & other)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = other;
}
int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->rawBits); 
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->rawBits = raw;
}

Fixed & Fixed::operator= (const Fixed& other) 
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}
