#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "datastore.h"

class MyDataStore : public DataStore //change to private and see if it works
{
public:
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void add(std::string username, Product *p);
    void viewCart(std::string username);
    void buyCart(std::string username);

    bool userExists(std::string username);
private:
    std::map<std::string, std::set<Product*>> productsByTerms;
    std::set<Product*> products_;
    std::map<std::string, User*> usersByName;

    std::map<std::string, std::vector<Product*>> cart;

    //map for cart username to vector of products

};

#endif