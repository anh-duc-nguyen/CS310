/**
 * Driver program to test and exercise the double linked list class.
 * @author Anh Nguyen
 * @version 01 February 2018
 */

#include <cstdint>
#include <iostream>
#include "list.h"
using namespace std;

int main()
{
  List< uint > list_0;

  list_0.push_front( 1 );
  list_0.push_front( 3 );
  list_0.push_front( 5 );
  list_0.push_front( 4 );
  list_0.push_front( 2 );

  cout << list_0.to_string() << endl << endl;
  cout << "The end element is: " << list_0.tail() << endl;

  // over-write list 0 using assignment
  List< uint > list_1;
  list_1.push_front( 10 );
  list_1.push_front( 20 );
  list_0 = list_1;

  cout << list_0.to_string() << endl << endl;

  List< string > list_2;

  list_2.push_front( "Ali" );
  list_2.push_front( "Bec" );
  list_2.push_front( "Cai" );
  list_2.push_front( "Dov" );
  cout << "The front element is: " << list_2.front() << endl;
  cout << "The entire list is" << endl << list_2.to_string() << endl;
  cout << endl;

  list_2.pop_front();
  cout << "After removing the first element" << endl;
  cout << "the last element is: " << list_2.tail() << endl;
  cout << list_2.to_string() << endl << endl;

  List< string > list_3{ list_2 };
  cout << "a copy of list 2 is: " << endl;
  cout << list_3.to_string() << endl << endl;

  List< string > list_4;
  cout << "about to make another copy" << endl;
  list_4 = list_3;
  cout << "a copy of list 3 appears as: " << endl;
  cout << list_4.to_string() << endl;

  return 0;
}
