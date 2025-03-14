/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/14 01:49:13 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits = 8; 


Fixed::Fixed()
{
    std::cout << "Default Constructor called" << std::endl;
    this->rawBits = 0;
}

Fixed::Fixed(const int nbr)
{
    std::cout << "Int Constructor called" << std::endl;
    this->rawBits = nbr << Fixed::fracBits;
}

Fixed::Fixed(const float nbr)
{
    std::cout << "Float Constructor called" << std::endl;
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
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

 // Overloading the << operator to insert floating-point representation
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();  
    return os;
}
