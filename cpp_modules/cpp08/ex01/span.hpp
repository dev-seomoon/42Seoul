#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
private:
  std::vector<int>  data; // vector

public:
  void  addNumber(int number);

  template <class InputIterator>
  void  addNumber(InputIterator begin, InputIterator end) {
    if (std::distance(begin, end) + data.size() > data.capacity())
      throw StoreLimitException();
    data.insert(data.begin(), begin, end);
  }

  int   shortestSpan(void);
  int   longestSpan(void);

  const std::vector<int>&   getData(void) const;

  class StoreLimitException : public std::exception {
  public:
    const char* what(void) const throw();
  };

  class NoSpanException : public std::exception {
    const char* what(void) const throw();
  };

  Span();
  Span(unsigned int N);
  Span(const Span& src);
  Span&   operator=(const Span& src);
  ~Span();
};

#endif