// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
{

}

//
// Array (length)
//
template <typename T>
Array <T>::Array(size_t length)
  :Array_Base <T> (length)
{

}

//
// Array (length, fill)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
  :Array_Base <T> (length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
  :Array_Base <T> (array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
  //check for self
  if(this != &rhs)
  {
    int new_size = rhs.size();
    //allocate more memory if new_size is larger than max_size_
    if(new_size > this->max_size_)
    {
      T * new_block = new T [new_size];
      T * old_block = this->data_;
      this->data_ = new_block;
      delete [] old_block;
      this->max_size_ = (new_size);
    }
    this->cur_size_ = new_size;
    for(int i = 0; i < this->cur_size_; i++)
    {
      this->data_[i] = rhs[i];
    }
  }
  return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
  //allocate extra memory if the new size is greater than the max size of the array
  if(new_size > this->max_size_)
  {
    T * new_block = new T [new_size];
    for(int i = 0; i < this->cur_size_; i++)
    {
      new_block[i] = this->data_[i];
    }
    T * old_block = this->data_;
    this->data_ = new_block;
    delete [] old_block;
    this->max_size_ = new_size;
  }
  this->cur_size_ = new_size;
}

//
// shrink
//
template <typename T>
void Array <T>::shrink()
{
  //If data is no longer being tracked, free it
  if(this->cur_size_ < this->max_size_)
  {
    T * new_block = new T [this->cur_size_];
    for(int i = 0; i < this->cur_size_; i ++)
    {
      new_block[i] = this->data_[i];
    }
    T * old_block = this->data_;
    this->data_ = new_block;
    delete [] old_block;
    this->max_size_ = this->cur_size_;
  }
}
