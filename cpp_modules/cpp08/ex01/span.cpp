#include "span.hpp"

void  Span::addNumber(int number)
{
  if (data.size() == data.capacity())
    throw StoreLimitException();
  data.push_back(number);
}

int   Span::shortestSpan(void)
{
  if (data.size() < 2)
    throw NoSpanException();

  std::vector<int>::iterator first = data.begin();
  std::vector<int>::iterator next = ++data.begin();

  int shortestSpan = std::abs(*next - *first);
  first++;
  next++;

  while (next != data.end()) {
    int span = std::abs(*next - *first);
    if (span < shortestSpan)
      shortestSpan = span;
    first++;
    next++;
  }
  return (shortestSpan);
}

int   Span::longestSpan(void)
{
  if (data.size() < 2)
    throw NoSpanException();
  
  int max = *std::max_element(data.begin(), data.end());
  int min = *std::min_element(data.begin(), data.end());
  int longestSpan = std::abs(max - min);
  return (longestSpan);
}

const std::vector<int>&   Span::getData(void) const
{
  return (data);
}

const char*   Span::StoreLimitException::what(void) const throw()
{
	return ("Out of limit !");
}

const char*   Span::NoSpanException::what(void) const throw()
{
	return ("Lack of elements !");
}

Span::Span() {
  data.reserve(0);
}

Span::Span(unsigned int N)
{
  data.reserve(N);
}

Span::Span(const Span& src)
{
  *this = src;
}

Span&   Span::operator=(const Span& src)
{
  if (this != &src) {
    data.clear();
    data.reserve(src.getData().capacity());
    std::copy(std::begin(src.getData()), std::end(src.getData()), std::back_inserter(data));
  }
  return (*this);
}

Span::~Span()
{
  data.clear();
}