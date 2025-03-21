/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/21 22:38:44 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fracBits = 8; 


Fixed::Fixed()
{
    this->rawBits = 0;
}

Fixed::Fixed(const int nbr)
{
    this->rawBits = nbr << Fixed::fracBits;
}

Fixed::Fixed(const float nbr)
{
    this->rawBits = static_cast<int>(roundf(nbr * (1 << fracBits)));
}
Fixed::~Fixed()
{

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

bool Fixed::operator>(const Fixed& other) const
{
    return (this->rawBits > other.getRawBits());
}
bool Fixed::operator<(const Fixed& other) const
{
    return (this->rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->rawBits >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed& other) const
{
    return (this->rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->rawBits != other.getRawBits());
}

Fixed & Fixed::operator=(const Fixed& other) 
{
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

Fixed Fixed::operator+(const Fixed & other) const
{
    Fixed result;
    long tmp = static_cast<long>(this->getRawBits()) + 
                static_cast<long>(other.getRawBits());
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in addition" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

Fixed Fixed::operator-(const Fixed & other) const
{
    Fixed result;
    long tmp = static_cast<long>(this->getRawBits()) - 
                static_cast<long>(other.getRawBits());
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in addition" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

Fixed Fixed::operator*(const Fixed & other) const
{
    Fixed result;
    long tmp = static_cast<long>(this->getRawBits()) * static_cast<long>(other.getRawBits()); 
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in multiplication" << std::endl; 
    result.setRawBits(static_cast<int>(tmp >> this->fracBits)); 
    return (result);
}

Fixed Fixed::operator/(const Fixed & other) const
{
    Fixed result;

    if (other.getRawBits() == 0)
        throw std::runtime_error("Division by zero!");
    long tmp = static_cast<long>(this->getRawBits() << fracBits) / static_cast<long>(other.getRawBits()); 
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in division" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

// pre-increament ++x
Fixed Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}
// --x
Fixed Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

//Post-increment x++
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

//Post-decrement x--
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}

// Min function (non-const version)
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

// Min function (const version)
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

// Max function (non-const version)
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

// Max function (const version)
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

 // Overloading the << operator to insert floating-point representation
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();  
    return os;
}
