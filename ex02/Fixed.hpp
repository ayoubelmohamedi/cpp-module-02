/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:36 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/21 23:10:12 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath> 
#include <climits>

class Fixed {

private:
    int rawBits;
    static const int fracBits;

public:
    Fixed();
    Fixed(const int nbr);
    Fixed(const float nbr);
    ~Fixed();

    // copy constructor
    Fixed(const Fixed & other);
    
    //copy assignment constructor 
    Fixed & operator=(const Fixed & other);

    // comparison operators 
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const; 

    // arithmetic operators  +, -, *, / 
    Fixed operator+(const Fixed & other) const;
    Fixed operator-(const Fixed & other) const;
    Fixed operator*(const Fixed & other) const;
    Fixed operator/(const Fixed & other) const;

    //  increment and decrement operators
    // Pre-increment  ++x
    Fixed operator++();
    Fixed operator--();
    // Post-increment  x++
    Fixed operator++(int);
    Fixed operator--(int);

    // Min functions (non-const and const versions)
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
 
    // Max functions (non-const and const versions)
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    
    float toFloat( void ) const;
    int toInt( void ) const;
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);



#endif
