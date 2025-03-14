/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:38 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/14 22:30:09 by macbookpro       ###   ########.fr       */
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
    return (this->rawBits); 
}

void Fixed::setRawBits( int const raw )
{
    this->rawBits = raw;
}

bool Fixed::operator>(const Fixed& other)
{
    return (this->rawBits < other.getRawBits());
}
bool Fixed::operator<(const Fixed& other)
{
    return (this->rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other)
{
    return (this->rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other)
{
    return (this->rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other)
{
    return (this->rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other)
{
    return (this->rawBits != other.getRawBits());
}

Fixed & Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->rawBits = other.getRawBits();
    }
    return (*this);
}

Fixed Fixed::operator+(const Fixed & other) const
{
    Fixed result;
    long long tmp = static_cast<long long>(this->getRawBits()) + 
                static_cast<long long>(other.getRawBits());
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in addition" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

Fixed Fixed::operator-(const Fixed & other) const
{
    Fixed result;
    long long tmp = static_cast<long long>(this->getRawBits()) - 
                static_cast<long long>(other.getRawBits());
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in addition" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

Fixed Fixed::operator*(const Fixed & other) const
{
    Fixed result;
    long long tmp = static_cast<long long>(this->getRawBits()) * static_cast<long long>(other.getRawBits()); 
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
    long long tmp = static_cast<long long>(this->getRawBits() << fracBits) / static_cast<long long>(other.getRawBits()); 
    if (tmp > INT_MAX || tmp < INT_MIN)
        std::cerr << "Warning: Overflow in division" << std::endl;
    result.setRawBits(static_cast<int>(tmp)); 
    return (result);
}

// pre-increament ++x
Fixed & Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}
// --x
Fixed & Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

//Post-increment x++
Fixed & Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

//Post-decrement x--
Fixed & Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}

 // Overloading the << operator to insert floating-point representation
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();  
    return os;
}
