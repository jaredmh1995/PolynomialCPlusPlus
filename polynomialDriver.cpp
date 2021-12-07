//Name: Jared Hazel
//Class: CSS501
//Due Date: 11/24/2020
//Purpose: To show how to add and subtract polynomials
//         using doubly linked lists 
#include <iostream>
using namespace std;

#include "polynomial.h"

//Demostration of linked list 
int main( ){

  Polynomial p1;
  Polynomial p3;
  Polynomial p4;

  p1.changeCoefficient( 1, 1 );

  p1.changeCoefficient( 2, 2 );
  
  p1.changeCoefficient( 3.3, 3 );

  p1.changeCoefficient( -5.5, 4 );
  
  cout << "p1 = " << p1 << endl;

  p1.changeCoefficient( -4.4, 4 );

  cout << "Update of -5.5x^4 makes p1 = " << p1 << endl;

  cout << "With p2 = p1" << endl;

  Polynomial p2;

  p2.changeCoefficient(8,8);
  
  p2=p1;

  cout << "p2 = " << p2 << endl;

  cout<<"p1 = "<<p1<<endl;

  cout<<"p2==p1 is "<<((p2 ==p1) ? "true" : "false")<<endl;
  cout<<"p2!=p1 is "<<((p2 !=p1) ? "true" : "false")<<endl;

  
  cout<<"p1 coefficient of 3 is "<<p1.coefficient(3)<<endl;

  p3.changeCoefficient( 1, 1 );
  p3.changeCoefficient( 2, 2 );
  p4.changeCoefficient( 3, 3 );
  p4.changeCoefficient( -4, 4 );
  p4.changeCoefficient(5,5);
  p4.changeCoefficient(2,8);
  p4.changeCoefficient(2,2);
  cout<<"p3 = "<<p3<<endl;
  cout<<"p4 = "<<p4<<endl;
  
  cout<<"p1 = "<<p1<<endl;

  cout<<"p3 = "<<p3<<endl;

  cout<<"(p1 += p3) is "<<(p1+=p3)<<endl;

  cout<<"p1 = "<<p1<<endl;

  cout<<"p2 = "<<p2<<endl;

  cout<<"p3 = "<<p3<<endl;

  cout<<"p4 = "<<p4<<endl;

  cout<<"(p1 -= p2) is "<<(p1-=p2)<<endl;

  cout<<"p1 = "<<p1<<endl;

  cout<<"p2 = "<<p2<<endl;

  cout<<"p3 = "<<p3<<endl;

  cout<<"p4 = "<<p4<<endl;

  cout<<"p1 - p2 = "<<p1-p2<<endl;

  cout<<"p3 + p4 = "<<p3 + p4<<endl;

  cout<<"Degree of p1 is: "<<p1.degree()<<endl;

  cout<<"p1, p2, p3, p4 are deleted "<<endl;

  p1.~Polynomial();
  p2.~Polynomial();
  p3.~Polynomial();
  p4.~Polynomial();
}