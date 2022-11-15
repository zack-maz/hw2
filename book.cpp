#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"


Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
  Product(category, name, price, qty), isbn_(isbn), author_(author)
{
  
}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  //initialize our sets so we're not calling parseStringToWords on every iteration
  std::set<std::string> kw;
  std::set<std::string> isbnParsed = parseStringToWords(isbn_);
  std::set<std::string> authorParsed = parseStringToWords(author_);
  std::set<std::string> nameParsed = parseStringToWords(name_);
  for (std::set<std::string>::iterator it = nameParsed.begin(); it != nameParsed.end(); ++it)
  {
<<<<<<< HEAD
    //std::cout << *it << std::endl;
=======
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
    kw.insert(*it); //name keywords
  }
  for (std::set<std::string>::iterator it = isbnParsed.begin(); it != isbnParsed.end(); ++it)
  {
<<<<<<< HEAD
    //std::cout << *it << std::endl;
=======
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
    kw.insert(*it);
  }
  for (std::set<std::string>::iterator it = authorParsed.begin(); it != authorParsed.end(); ++it)
  {
<<<<<<< HEAD
    //std::cout << *it << std::endl;
    kw.insert(*it);
  }
  kw.insert(isbn_);
  kw.insert(author_);
  kw.insert(name_);
=======
    kw.insert(*it);
  }
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
  return kw;
}


std::string Book::displayString() const
{

  std::string price = std::to_string(getPrice()); //convert double to string
  price = price.substr(0, price.find(".")+3); //truncate trailing 0s

  std::string display = "";
  display += (getName() + "\n");
  display += ("Author: " + author_ + " ");
  display += ("ISBN: " + isbn_ + "\n");
<<<<<<< HEAD
  display += (price + " " + std::to_string(getQty()) + " " + "left.");
=======
  display += (price + " " + std::to_string(getQty()) + " " + "left");
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
  return display;
}


/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Book::dump(std::ostream& os) const
{
    os << "book" << "\n" << getName() << "\n" << getPrice() << "\n";
    os << getQty() << "\n" << isbn_ << "\n" << author_ << std::endl;
}



