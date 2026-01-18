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
    ~ChocolateSupplier();

    void supplyChocolate();

    inline const char *getChocolateName() const {}
    inline void setChocolateName(const char *newName) {}
};
