#pragma once
#include <iostream>
#include <string>
using std::string;
class SugarSupplier
{
private:
    string supplierName;

public:
    SugarSupplier(const string& Name) : supplierName(Name) {}
    ~SugarSupplier();

    void supplySugar();

    inline const char *getSugarName() const {}
    inline void setSugarName(const char *newName) {}
};
