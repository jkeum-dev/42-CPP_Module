#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <limits>

class Span
{
private:
	unsigned int n_;
	std::vector<int> vec_;
public:
	Span() {}
	Span(unsigned int n) { this->n_ = n; this->vec_.reserve(n); }
	Span(const Span& copy) { *this = copy; }
	Span& operator=(const Span& copy) { this->n_ = copy.n_; this->vec_.clear(); this->vec_ = copy.vec_; return *this; }
	~Span() { this->vec_.clear(); }
	void addNumber(int num);
	template <typename InputIt>
	void addNumber(InputIt begin, InputIt end, unsigned int size) {
		unsigned int remain = this->n_ - this->vec_.size();
		if (remain >= size)
			this->vec_.insert(this->vec_.end(), begin, end);
		else
			throw (std::length_error("Cannot add this all!!!"));
	}
	int shortestSpan(void);
	int longestSpan(void);
};

#endif