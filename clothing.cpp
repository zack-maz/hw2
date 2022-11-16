#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

//SEE BOOK FOR COMMENTS

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, const std::string size, const std::string brand) :
  Product(category, name, price, qty), size_(size), brand_(brand)
{
  
}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const
{
  std::set<std::string> kw;
  std::set<std::string> brandParsed = parseStringToWords(brand_);
  std::set<std::string> nameParsed = parseStringToWords(name_);
  for (std::set<std::string>::iterator it = nameParsed.begin(); it != nameParsed.end(); ++it)
  {
    kw.insert(*it);
  }
  for (std::set<std::string>::iterator it = brandParsed.begin(); it != brandParsed.end(); ++it)
  {
    kw.insert(*it);
  }
  kw.insert(brand_);
  kw.insert(name_);
  return kw;
}


std::string Clothing::displayString() const
{

  std::string price = std::to_string(getPrice());
  price = price.substr(0, price.find(".")+3);

  std::string display = "";
  display += (getName() + "\n");
  display += ("Size: " + size_ + " ");
  display += ("Brand: " + brand_ + "\n");
  display += (price + " " + std::to_string(getQty()) + " " + "left.");
  return display;
}


/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Clothing::dump(std::ostream& os) const
{
    os << "clothing" << "\n" << getName() << "\n" << getPrice() << "\n";
    os << getQty() << "\n" << size_ << "\n" << brand_ << std::endl;
}



