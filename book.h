#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"
#include "util.h"

class Book : public Product
{
public:
  Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author);
  ~Book();
  std::set<std::string> keywords() const;
  bool isMatch(std::vector<std::string>& searchTerms) const;
  std::string displayString() const;
  void dump(std::ostream& os) const;

private:
    std::string isbn_;
    std::string author_;
};
  //setUnion(parseStringToWords(isbn), parseStringToWords(author));

#endif