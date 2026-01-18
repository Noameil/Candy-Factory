#pragma once
#include <iostream>
#include <string>
using std::string;
class ChocolateSupplier
{
private:
    string chocolateSupplier;
    

public:
    ChocolateSupplier(const string& Name) : chocolateSupplier(Name) {}
    ~ChocolateSupplier() {}

    void supplyChocolate() const {std::cout<< chocolateSupplier <<" is supplying chocolate!"<<std::endl; }

    inline const string getChocolateName() const {return chocolateSupplier;}
    inline void setChocolateName(const string& chocName) {chocolateSupplier = chocName;}
};
