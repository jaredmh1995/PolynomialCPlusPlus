//Name: Jared Hazel
//Class: CSS501
//Due Date: 11/24/2020
//Purpose: To show how to add and subtract polynomials
//         using doubly linked lists 

#include "polynomial.h"
#include <iostream>
using namespace std;

//Default constructor, creates new polynomial
Polynomial::Polynomial( ){
  head = new Term;
  head->next = NULL;
  head->prev = NULL;
  head->coeff = 0.0;
  head->power = 0;
}

//Copy constructor and creates dummy header
Polynomial::Polynomial( const Polynomial &p ){
  head = new Term;
  head->next = NULL;
  head->prev = NULL;
  head->coeff = 0.0;
  head->power = 0;
  *this = p;
}

//Destructor.  Goes through linked list and deletes all nodes
//Sends value to remove to ensure all values are removed.
//Then head and all creates Term variables are deleted
Polynomial::~Polynomial( ){
  Term *del = nullptr;
  Term *temp;
  del=head->next;
  while(del != NULL){
    temp=del->next;
    del->next=NULL;
    del->prev=NULL;
    delete del;
    del=temp;
  }
  Term* zero = nullptr;
  zero=0,0;
  remove(zero);
  delete head;
  delete del;
  delete temp;
  delete zero;
}

//Returns the degree of a polynomial.  
//Goes through linked list to find the highest degree
int Polynomial:: degree( ) const{
  Term *p=nullptr;
  p=head->next;
  int degree =0;
  while(p != NULL){
    if(p->coeff> degree){
      degree = p->coeff;
    }
    p=p->next;
  }
  delete p;
  return degree;
}

//Returns the coefficient of the x^power term
//Goes through linked list to find the matching exponent
//Then the coeff variable is returned
double Polynomial::coefficient( const int power ) const{
  Term *p = nullptr;
  p=head->next;
  double returnValue=0;
  while(p != NULL){
    if(power == p->power){
      returnValue = p->coeff;
    }
    p=p->next;
  }
  return returnValue;
  delete p;
}

//Replaces the coefficient of the xpower term with newCoeffcient.
//Then sends linked list to the remove function to confirm no
//0 coefficients are in the linked list
//Assumption: if the request is not already in the linked lists
//it gets added
bool Polynomial::changeCoefficient( const double newCoefficient, const int power ){
  Term *p=nullptr;
  p=head;
  int test=0;
  while(p != NULL){
    if(p->power == power){
      p->coeff = newCoefficient;
      test++;
    }
    p=p->next;
  }
  if(test == 0){
    p=head;
    insert(p, newCoefficient, power);
  }
  Term* zero = nullptr;
  zero=0,0;
  remove(zero);
  return true;
  delete p;
  delete zero;
}

// Arithmetic operators
//Adds two polynomials together.  First the left linked list is added
//to a newly created Polynomial. Then the right linked list is
//added to the Polynomial variable, either increasing exisiting 
//coefficient, or added as a new node.  Then the temp Polynomial 
//is returned and all variables created are deleted.
//NOTE: I had issues with this method and the minus method with 
//memory leak.  Could you let me know what I'm doing wrong/ what can 
//I do differently? Thanks!
Polynomial Polynomial::operator+( const Polynomial& p ) const{
  Term *one=nullptr;
  Term *two=nullptr;
  one = p.head->next;
  two = head->next;
  Polynomial *answer=nullptr;
  answer=new Polynomial;
  bool test=false;
  while(two != NULL){
    answer->changeCoefficient(two->coeff, two->power);
    two=two->next;
  }
  Term *six=nullptr;
  six = answer->head->next;
  while(one != NULL){
    while(six != NULL){
      if(one->power == six->power){
        test=true;
        answer->changeCoefficient((six->coeff+one->coeff), six->power);
      }
      six=six->next;
    }
    if(test == false){
      answer->changeCoefficient((one->coeff), one->power);
    }
    six=answer->head->next;
    one=one->next;
    test=false;
  }
  return *answer;
  answer->~Polynomial();
  delete one;
  delete two;
  delete six;
  free(answer);
  delete answer;
}

//Subtracts two polynomials
//Adds two polynomials together.  First the left linked list is added
//to a newly created Polynomial. Then the right linked list is
//added to the Polynomial variable, either decreasing exisiting 
//coefficient, or added as a new node.  Then the temp Polynomial 
//is sent to remove, returned, and all variables created are deleted.
//NOTE: I had issues with this method and the minus method with 
//memory leak.  Could you let me know what I'm doing wrong/ what can 
//I do differently? Thanks!
Polynomial Polynomial::operator-( const Polynomial& p ) const{
  Term *four4=nullptr;
  Term *five5=nullptr;
  four4 = p.head->next;
  five5 = head->next;
  Polynomial *answer2;
  answer2 = new Polynomial;
  bool test = false;
  while(five5 != NULL){
    answer2->changeCoefficient(five5->coeff, five5->power);
    five5=five5->next;
  }
  Term *six6=nullptr; 
  six6 = answer2->head->next;
  while(four4 != NULL){
    while(six6 != NULL){
      if(four4->power == six6->power){
        test=true;
        answer2->changeCoefficient((six6->coeff-four4->coeff), six6->power);
      }
      six6=six6->next;
    }
    if(test == false){
      answer2->changeCoefficient(-(four4->coeff), four4->power);
    }
    six6=answer2->head->next;
    four4=four4->next;
    test=false;
  }
  Term* zero = nullptr;
  zero=0,0;
  answer2->remove(zero);
  return *answer2;
  answer2->~Polynomial();
  delete four4;
  delete five5;
  delete six6;
  delete answer2;
  delete zero;
}



// Boolean comparison operators
//Tests to see if two polynomials are the same. 
//Goes through each linked lists and count the same nodes and length
//If both are the same then the linked lists are the same, if not then they are not
//NOTE: Did not create seperate method for this and != because the way they
//      use count is different.  This method looks for same count, != looks for different 
//      length
bool Polynomial::operator==( const Polynomial& p ) const{
  int count=0;
  int count2=0;
  Term *one=nullptr;
  Term *two=nullptr;
  one = p.head->next;
  two = head->next;
  while (one != NULL){
    while(two != NULL){
      if((one->power == two->power) && (one->coeff == two->coeff) ){
        count2++;
      }
      two=two->next;
    }
    count++;
    two=head->next;
    one=one->next;
  }
  if(count == count2){
    return true;
  }
  else{
    return false;
  }
  delete one;
  delete two;
}

//Tests to see if two polynomials are different
//Goes through each linked lists and count the same nodes and length
//If both are not the same then the linked lists are different, 
//if they are the same, then the linked lists are equal.
//NOTE: Did not create seperate method for this and == because the way they
//      use count is different.  
bool Polynomial::operator!=( const Polynomial& p ) const{
  int count=0;
  int count2=0;
  Term *one=nullptr;
  Term *two=nullptr;
  one = p.head->next;
  two = head->next;
  while (one != NULL){
    while(two != NULL){
      if((one->power == two->power) && (one->coeff == two->coeff)){
        count2++;
      }
      two=two->next;
    }
    count++;
    two=head->next;
    one=one->next;
  }
  if(count != count2){
    return true;
  }
  else{
    return false;
  }
  delete one;
  delete two;
}

//Assignment opertors
//Makes one polynomial equal another.  Deletes any nodes in left side linked list
//then adds nodes from the right side linked list 
Polynomial& Polynomial:: operator=( const Polynomial& p ){
  Term *one=nullptr;
  Term *two=nullptr;
  one = p.head->next;
  two = head->next;
  while(two != NULL){
    remove(two);
    two=two->next;
  }
  two=head;
  while(one != NULL){
    insert(two, one->coeff, one->power);
    one=one->next;
  }
  return *this;
  delete one;
  delete two;
}

//Adds two polynomials together and then makes the answer a new polynomial.
//Goes through the right side linked list and either increases the left side
//linked list coefficients, or the node is added 
//Note: Didn't create seperate method between += and -= because of the sign change
Polynomial& Polynomial::operator+=( const Polynomial& p ){
  Term *one = nullptr;
  Term *two = nullptr;
  one = p.head->next;
  two = head->next;
  bool test = false;
  while(one != NULL){
    while(two != NULL){
      if(two->power == one->power){
        test=true;
        changeCoefficient((one->coeff+two->coeff), two->power);
      }
      two=two->next;
    }
    if(test == false){
      changeCoefficient(one->coeff, one->power);
    }
    two=head->next;
    one=one->next;
    test=false;
  }
  return *this;
  delete one;
  delete two;
}

//Subtract two polynomials together and then makes the answer a new polynomial.
//Goes through the right side linked list and either subtracts the left side
//linked list coefficients, or the node is added.  Remove method is used to move 
//any node with 0 coefficient
//Note: Didn't create seperate method between += and -= because of the sign change
Polynomial& Polynomial::operator-=( const Polynomial& p ){
  Term *one = nullptr;
  Term *two = nullptr;
  one = p.head->next;
  two = head->next;
  bool test = false;
  while(one != NULL){
    while(two != NULL){
      if(two->power == one->power){
        test=true;
        changeCoefficient((two->coeff-one->coeff), two->power);
      }
      two=two->next;
    }
    if(test == false){
      changeCoefficient(one->coeff, one->power);
    }
    two=head->next;
    one=one->next;
    test=false;
  }
  Term* zero = nullptr;
  zero=0,0;
  remove(zero);
  return *this;
  delete zero;
  delete one;
  delete two;
}

//Inserts intem into linked list.  Create new Term and inserts into 
//The linked list.  Size is increased.
//Assumption: the order of linked list doesn't matter 
bool Polynomial::insert(Term *pos, const double newCoefficient, const int power){
  Term *newPtr = nullptr;
  newPtr = new Term;
  newPtr->coeff=newCoefficient;
  newPtr->power=power;
  while(pos->next != NULL){
    pos = pos->next;
  }
  pos->next = newPtr;
  newPtr->prev = pos;
  size++;
  return true;
  delete newPtr;
  delete pos;
}

//Removes value from linked list.  Finds either matching Term or if the 
//coefficient is zero and removes it from linked list.
bool Polynomial::remove( Term* pos ){
  Term *del = nullptr;
    del = head->next;
    while(del != NULL){
      if(del == pos || del->coeff == 0){
        if(del->next != NULL){
          del->next->prev = del->prev;
        }
        if (del->prev != NULL){
          del->prev->next = del->next; 
        }
        size--;
      }
      del=del->next;
    }
    delete del;
    delete pos;
  return true;
}

//Prints out the Polynomial linked list based on the power and coefficient
//Assumtption: the order of the linked list does matter
ostream& operator<<( ostream &output, const Polynomial& p ){
  Term *w = nullptr;
  w = p.head->next;
  while (w != NULL){
    if(w->coeff == 0){
      output<<"";
    }
    else if(w->coeff < 0){
      output<<""<<w->coeff<<"x^"<<w->power;
    }
    else if(w->prev == p.head){
      output<<""<<w->coeff<<"x^"<<w->power;
    }
    else{
      output<<"+"<<w->coeff<<"x^"<<w->power;
    }
    w = w->next;
  }
  cout<<endl;
  w=NULL;
  return output;
  delete w;
}