/**
 * a useless program to show some vector operations
 * @author Jon Beck
 * @version 23 January 2018
 */

#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // declare a vector with an initializer list
  vector< int > values{ 27, -14, 33 };

  // put some stuff in it
  for( uint i = 0; i < 15; i++ )
  {
    cout << "capacity: " << values.capacity() << "  size: " <<
      values.size() << "  now adding another element" << endl;
    values.push_back( 100 );
  }

  // look at the first element
  cout << "first element: " << *(values.cbegin()) << " or " <<
    values.at( 0 ) << " or " << values.front() << endl;

  // look at the last element
  cout << "last element: " << *(values.crbegin()) << " or " <<
    values.at( values.size() - 1 ) << " or " << values.back() << endl;

  // get rid of all elements and make size zero
  values.clear();
  cout << "capacity: " << values.capacity() << "  size: " <<
    values.size() << endl;
  return 0;
}
