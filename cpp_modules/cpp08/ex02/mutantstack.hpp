#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
  typedef typename std::stack<T>::container_type::iterator  iterator;
  typedef typename std::stack<T>::container_type::const_iterator  const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator  reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

  iterator  begin(void) { return (this->c.begin()); }
  iterator  end(void) { return (this->c.end()); }
  const_iterator  cbegin(void) const { return (this->c.begin()); }
  const_iterator  cend(void) const { return (this->c.end()); }
  reverse_iterator  rbegin(void) { return (this->c.rbegin()); }
  reverse_iterator  rend(void) { return (this->c.rend()); }
  const_reverse_iterator  crbegin(void) const { return (this->c.rbegin()); }
  const_reverse_iterator  crend(void) const { return (this->c.rend()); }

  MutantStack(): std::stack<T>() {}
  MutantStack(const MutantStack<T>& src): std::stack<T>(src) {}
  MutantStack<T>&   operator=(const MutantStack<T>& src) {
    this->c = src.c;
    return (*this);
  }
  ~MutantStack() {}
};

#endif