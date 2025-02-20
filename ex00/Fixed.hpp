/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moha <ael-moha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:36 by ael-moha          #+#    #+#             */
/*   Updated: 2025/02/20 20:59:47 by ael-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {

private:
    int nbr;
    static const int fracBits;

public:
    Fixed();
    ~Fixed();

    // copy constructor
    Fixed(const Fixed & other);
    
    //copy assignment constructor 
    Fixed & operator=(const Fixed & other);
    
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};



#endif
