/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/21 22:38:23 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fracBits = 8; 

Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    this->rawBits = 0;
}
Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl; 
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
