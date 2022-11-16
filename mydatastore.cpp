#include <string>
#include <set>
#include <vector>
#include "mydatastore.h"
#include "util.h"

//using namespace std;

MyDataStore::~MyDataStore() {
    
    for (std::set<Product*>::iterator itP = products_.begin(); itP != products_.end(); ++itP) delete *itP;
    for (std::map<std::string, User*>::iterator itU = usersByName.begin(); itU != usersByName.end(); ++itU) delete itU->second;
}





void MyDataStore::addProduct(Product* p)
{
    std::set<std::string> kw = p->keywords();
    for (std::set<std::string>::iterator it = kw.begin(); it != kw.end(); ++it)
    {
        productsByTerms[*it].insert(p);
    }

    products_.insert(p);
}

void MyDataStore::addUser(User* u)
{
    usersByName.insert({u->getName(), u});
}


std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{

    std::set<Product*> output;
    for (std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
    {
        if (productsByTerms.find(*it) == productsByTerms.end()) continue;

        if (output.empty()) output = productsByTerms[*it];
        else {
            std::set<Product*> fill = output;
            if (type == 0) output = setIntersection(fill, productsByTerms[*it]);
            else output = setUnion(fill, productsByTerms[*it]);
        }
    }

    std::vector<Product*> searchTerms;
    for (std::set<Product*>::iterator it = output.begin(); it != output.end(); ++it) searchTerms.push_back(*it);

    return searchTerms;
}


void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>" << "\n";
    for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) (*it)->dump(ofile);
    ofile << "</products>" << "\n";

    ofile << "<users>" << "\n";
    for (std::map<std::string, User*>::iterator it = usersByName.begin(); it != usersByName.end(); ++it) it->second->dump(ofile);
    ofile << "</users>" << "\n";
}





bool MyDataStore::userExists(std::string username)
{
    if (usersByName.find(username) == usersByName.end()) return false;
    return true;
}


void MyDataStore::add(std::string username, Product* p)
{
    if ((*products_.find(p))->getQty() == 0)
    {
        std::cout << "This item is out of stock." << std::endl;
    }
    else if (usersByName.find(username) == usersByName.end()) {
        std::cout << "Invalid request" << std::endl;
    }
    else {
        cart[username].push_back(p);
        std::cout << "Item added." << std::endl;
    }
    
}

void MyDataStore::viewCart(std::string username)
{
    int count = 1;
    for (std::vector<Product*>::iterator it = cart[username].begin(); it != cart[username].end(); ++it)
    {
        std::cout << "Item " << count << std::endl;
        std::cout << (*it)->displayString() << std::endl;
        count++;
    }

}

void MyDataStore::buyCart(std::string username) //help with this function
{
    std::vector<Product*>::iterator it = cart[username].begin();

    while (it != cart[username].end())
    {
        if ((usersByName[username]->getBalance() - (*it)->getPrice()) < 0)
        {
            std::cout << "You don't have enough funds to purchase the remaning items. $";
            std::cout << usersByName[username]->getBalance() << " remaining." << std::endl;
            return;
        }
        else if ((*products_.find(*it))->getQty() == 0)
        {
            std::cout << "This item is out of stock." << std::endl;
            cart[username].erase(it);
        }
        else
        {
            std::cout << (*it)->getName() << " purchased." << std::endl;
            usersByName[username]->deductAmount((*it)->getPrice());
            (*products_.find(*it))->subtractQty(1);
            cart[username].erase(it);
        }
    }


}