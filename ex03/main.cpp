/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:43:34 by ael-moha          #+#    #+#             */
/*   Updated: 2025/03/15 04:00:38 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

class Point {
    private:
        const Fixed x;
        const Fixed y;
    
    public:
        Point() : x(0), y(0) {};
        Point(const float x, const float y) : x(x), y(y) {};
        Point(const Point& other) : x(other.x), y(other.y) {};
        ~Point() {};
        
        Point& operator=(const Point& other){
            // maintain operator chaining capability, but 'other' was processed
            (void) other;
            return (*this);
        }
        
        Fixed getX() const {return x;};
        Fixed getY() const {return y;};
    };

static Fixed area(Point const &a, Point const &b, Point const &c) {
    Fixed area = ((b.getX() - a.getX()) * (c.getY() - a.getY()) -
                 (c.getX() - a.getX()) * (b.getY() - a.getY())) / 2;
    return (area < 0) ? area * -1 : area;
} 

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed totalArea = area(a, b, c);
    
    // Calculate areas of triangles PAB, PBC and PCA
    Fixed area1 = area(point, a, b);
    Fixed area2 = area(point, b, c);
    Fixed area3 = area(point, c, a);
    
    return (area1 > 0 && area2 > 0 && area3 > 0 &&
            (area1 + area2 + area3) == totalArea);
}

int main( void ) {

    Point a(0, 0);
    Point b(10, 30);
    Point c(20, 0);
    Point pnt (10 ,15);
    
    std::cout << "Point is " << (bsp(a, b, c, pnt) ? "inside" : "outside") 
              << " the triangle" << std::endl;
    
    Point pnt_outside (30, 15);

    std::cout << "Point is " << (bsp(a, b, c, pnt_outside) ? "inside" : "outside") 
              << " the triangle" << std::endl;
    
    Point pnt_onEdge (10, 0);

    std::cout << "Point is " << (bsp(a, b, c, pnt_onEdge) ? "inside" : "outside")
              << " the triangle" << std::endl;

    
    return 0;

}
