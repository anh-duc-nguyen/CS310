#ifndef NGUYEN_LIST
#define NGUYEN_LIST

#include <cassert>
#include <cstdint>
#include <sstream>

/**
 * a simple generic doubly linked list class to illustrate C++ concepts
 * @author Anh Nguyen
 * @version 01 February 2018
 */
template< typename Object >
class List
{
 private:
  /**
   * A class to store data and provide a link to the next node in the list
   */
  class Node
  {
   public:
     /**
      * The constructor
      * @param value the data to be stored in this node
      */
      explicit Node( const Object & value )
        : data{ value }, next{ nullptr }, prev{ nullptr } {}

    Object data;
    Node * next;
    Node * prev;
  };

 public:
  /**
   * The constructor for an empty list
   */
  List()
    : size{ 0 }, first{ nullptr }, last{ nullptr } {}

  /**
   * the copy constructor
   */
  List( const List & rhs )
    : size{ 0 }, first{ nullptr }, last{ nullptr }
  {
    if( rhs.size > 0 )
    {
      push_front( rhs.first->data );
      auto itr = rhs.first->next;
      for( uint i = 1; i < rhs.size; i++ )
      {
        Node * new_node = new Node{ itr->data };
        last->next = new_node;
        new_node->prev = last;
        last = new_node;
        itr = itr->next;
        size++;
      }
    }
  }

  /**
   * the operator= method
   */
  List & operator=( const List & rhs )
  {
    if( this != &rhs )
    {
      // first need to reclaim all space used by current nodes
      uint count = size;
      for( uint i = 0; i < count; i++ )
      {
        pop_front();
      }

      // now need to copy the elements
      for( auto itr = rhs.first; itr != nullptr; itr = itr->next )
      {
        push_back( itr->data );
      }
    }
    return *this;
  }

  /**
   * The destructor that gets rid of everything that's in the list and
   * resets it to empty. If the list is already empty, do nothing.
   */
  ~List()
  {
    if( size != 0 )
    {
      Node * current = first;
      Node * temp;

      for( uint i = 0; i < size; i++ )
      {
        temp = current;
        current = current->next;
        delete temp;
      }
    }
  }

  /**
   * Put a new element onto the beginning of the list
   * @param item the data the new element will contain
   */
  void push_front( const Object & item )
  {
    auto new_node = new Node{ item };

    if( is_empty() )
    {
      first = last = new_node;
    }
    else
    {
      new_node->next = first; 
      first->prev = new_node;
      first = new_node;
    }
    size++;
  }
  /**
   * Put a new element onto the end of the list
   * @param item the data the new element will contain
   */
  void push_back( const Object & item )
  {
    auto new_node = new Node( item );
    if( is_empty() )
    {
      first = last = new_node;
    }
    else
    {
      last->next = new_node;
      new_node->prev = last;
      last = new_node;
    }
    size++;
  }

  /**
   * Remove the element that's at the front of the list. Causes an
   * assertion error if the list is empty.
   */
  void pop_front()
  {
    assert( !is_empty() );
    Node * temp = first;

    if( first == last )
    {
      first = last = nullptr;
    }
    else
    {
      first = first->next;
      first->prev = nullptr; //prevent dragging pointer
    }
    delete temp;
    size--;
  }
  /**
    *Remove the element that's at the end of the list. Cause an
    * assertion error if the list is empty.
    */
  void pop_back()
  {
    assert( !is_empty() );
    Node * temp = last;
    if ( first == last )
    {
      first = last = nullptr;
    }
    else
    {
      last = last->prev;
      last->next = nullptr; //prevent dragging pointer
    }
    delete temp;
    size--;
  }
  /**
    * Insert an node into the double linked list. n is the position of the new
    * element
    */
  void insert( int n , const Object & item )
  {
    assert( n <= size );
    if (n == size){
      push_back( item );
      return;
    }
    auto new_node = new Node(item);
    Node * itr1 = first;
    Node * itr2 = itr1->next;
    for (int i=1; i <= n ;i++){
      itr1 = itr1->next;
      itr2 = itr2->next;
    }
    itr1->next = new_node;
    new_node->next = itr2;
    new_node->prev = itr1;
    itr2->prev = new_node;
    size++;
  }

  /**
   * Accessor to return the data of the element at the front of the list.
   * Causes an assertion error if the list is empty.
   * @return the data in the front element
   */
  const Object & front() const
  {
    assert( !is_empty() );
    return first->data;
  }

  /**
   * Accessor to return the data of the element at the tail of the list.
   * Causes an assertion error if the list is empty.
   * @return the data in the last element
   */
  const Object & tail() const
  {
    assert( size != 0 );
    return last->data;
  }

  /**
   * Accessor to determine whether the list is empty
   * @return a boolean corresponding to the emptiness of the list
   */
  bool is_empty() const
  {
    return size == 0;
  }

  /**
   * Generate a string representation of the list
   * Requires operator<< to be defined for the list's object type
   * @return string representation of the list
   */
  std::string to_string() const
  {
    if( size == 0 )
    {
      return "";
    }
    std::stringstream buffer;
    for( auto current = first; current != nullptr; current = current->next )
    {
      buffer << current->data << ' ';
    }
    std::string result = buffer.str();
    return result.substr( 0, result.size() - 1 );
  }
  std::string to_string_r() const
  {
    if (size ==0 )
    {
      return "";
    }
    std::stringstream buffer;
    for ( auto current = last; current != nullptr; current = current->prev )
    {
      buffer << current->data << ' ';
    }
    std::string result = buffer.str();
    return result.substr( 0, result.size() - 1 );
  }

 private:
  uint size;
  Node * first;
  Node * last;
};

#endif
