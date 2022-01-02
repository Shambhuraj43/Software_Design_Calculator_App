// $Id: Array_Base.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10	     // default array size

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void)
  :data_ (new T[DEFAULT_SIZE]),
  cur_size_ (0),
  max_size_ (DEFAULT_SIZE)
{

}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
  :data_ (new T[length]),
  cur_size_ (length),
  max_size_ (length)
{

}

//
// Array_Base (size_t, T)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
  :data_ (new T[length]),
  cur_size_ (length),
  max_size_ (length)
{
  this->fill(fill);
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array)
  :data_ (new T[array.size()]),
  cur_size_ (array.size()),
  max_size_ (array.size())
{
  for(int i = 0; i < cur_size_; i++)
  {
    data_[i] = array[i];
  }
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
  delete [] data_;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
  if(index >= cur_size_)
  {
    throw std::out_of_range("Out of Range");
  }
  return data_[index];
}

//
// operator []
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
  if(index >= cur_size_)
  {
    throw std::out_of_range("Out of Range");
  }
  return data_[index];
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
  if(index >= cur_size_)
  {
    throw std::out_of_range("Out of Range");
  }
  return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
  if(index >= cur_size_)
  {
    throw std::out_of_range("Out of Range");
  }
  else
  {
    data_[index] = value;
  }
}

//
// find (<T>)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
  try
  {
    return find(value, 0);
  }

  //Catch all exceptions
  catch(...)
  {

  }
}

//
// find (<T>, size_t)
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
  if(start >= cur_size_)
  {
    throw std::out_of_range("Out of Range");
  }
  bool keepGoing = true;
  int i = start;
  while(keepGoing)
  {
    if(data_[i] == val)
    {
      keepGoing = false;
    }
    else if(i == cur_size_)
    {
      keepGoing = false;
      i = -1;
    }
    else
    {
      i++;
    }
  }
  return i;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
  bool equal = true;
  if(this != &rhs)
  {
    if(cur_size_ != rhs.size())
    {
      equal = false;
    }
    else
    {
      for(int i = 0; i < cur_size_; i++)
      {
	if(data_[i] != rhs[i])
	{
	  equal = false;
	}
      }
    }
  }
  return equal;
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
  return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
  for(int i = 0; i < this->cur_size_; i++){
    data_[i] = value;
  }
}

//
// reverse
//
template <typename T>
void Array_Base <T>::reverse (void)
{
  int swaps = cur_size_/2;
  char temp;
  for(int i = 0; i < swaps; i++)
  {
    temp = data_[i];
    data_[i] = data_[cur_size_ - i - 1];
    data_[cur_size_ - i - 1] = temp;
  }
}
