#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"


//SEE BOOK FOR COMMENTS

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating) :
  Product(category, name, price, qty), genre_(genre), rating_(rating)
{
  
}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  std::set<std::string> kw;
  std::set<std::string> genreParsed = parseStringToWords(genre_);
  std::set<std::string> nameParsed = parseStringToWords(name_);
  for (std::set<std::string>::iterator it = nameParsed.begin(); it != nameParsed.end(); ++it)
  {
    kw.insert(*it);
  }
  for (std::set<std::string>::iterator it = genreParsed.begin(); it != genreParsed.end(); ++it)
  {
    kw.insert(*it);
  }
<<<<<<< HEAD
  kw.insert(genre_);
  kw.insert(name_);
=======
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
  return kw;
}


std::string Movie::displayString() const
{
  std::string price = std::to_string(getPrice());
  price = price.substr(0, price.find(".")+3);

  std::string display = "";
  display += (getName() + "\n");
<<<<<<< HEAD
  display += ("Genre: " + genre_ + " ");
  display += ("Rating: " + rating_ + "\n");
  display += (price + " " + std::to_string(getQty()) + " " + "left.");
=======
  display += ("Rating: " + rating_ + " ");
  display += ("Genre: " + genre_ + "\n");
  display += (price + " " + std::to_string(getQty()) + " " + "left");
>>>>>>> f46831d0f5c72f46dff7778be55cfb1118cfc9d5
  return display;
}


/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Movie::dump(std::ostream& os) const
{
    os << "movie" << "\n" << getName() << "\n" << getPrice() << "\n";
    os << getQty() << "\n" << genre_ << "\n" << rating_ << std::endl;
}



