#include<Iterator.h>

//Constructor
template <typename T>
Iterator<T>::Iterator (Stack <T> & s):
    s_ (s), curr_ (s.size())
    {
    }

// Destructor
template <typename T>
Iterator<T>::~Iterator (void)
{
}

// isDone method
template <typename T>
bool Iterator<T>::isDone (void)
{
    this->curr_ >= this.s_.size();
}

// operator ->
template <typename T>
T * Iterator<T>::operator -> (void)
{
    //return address of the top of the stack
    return &this->s_.top();
}



// advance method
template <typename T>
void Iterator<T>::advance (void)
{
    this->curr_++;
}

// operator *
template <typename T>
T Iterator<T>::operator *(void)
{
    //get top of the stack
    return this->s_.top();
}
