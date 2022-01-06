#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
private:
  T*  data;
  unsigned int  _size;

public:
  unsigned int    size(void) const {
    return (_size);
  };

  class OutOfRangeException : public std::exception {
  public:
    const char* what(void) const throw() {
      return ("Error: Out of range!");
    }
  };

  T&  operator[](unsigned int index) {
    if (index >= _size)
      throw OutOfRangeException();
    return (data[index]);
  };

  const T&  operator[](unsigned int index) const {
    if (index >= _size)
      throw OutOfRangeException();
    return (data[index]);
  };

  Array(void): data(NULL), _size(0) {};

  Array(unsigned int n): data(NULL), _size(n) {
    if (_size > 0)
      data = new T[_size];
  };

  Array(const Array& src): data(NULL), _size(src.size()) {
    if (_size > 0)
      data = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
      data[i] = src[i];
  };

  Array&  operator=(const Array& src) {
    if (this != &src) {
      if (_size > 0)
      {
        delete[] data;
        data = NULL;
        _size = 0;
      }
      _size = src.size();
      if (_size > 0)
        data = new T[_size];
      for (unsigned int i = 0; i < _size; i++)
        data[i] = src[i];
    }
    return (*this);
  };

  ~Array() {
    if (_size > 0) {
      delete[] data;
      data = NULL;
      _size = 0;
    }
  };

};

template <typename T>
void    print_array(Array<T> arr, unsigned int size)
{
  for (unsigned int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
};

#endif