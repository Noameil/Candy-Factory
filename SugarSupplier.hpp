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
    ~SugarSupplier() {}

    void supplySugar() const {std::cout<<supplierName<<" I supplying sugar!"<<std::endl;}

    inline const string getSugarName() const {return supplierName;}
    inline void setSugarName(const string sugName) {supplierName = sugName;}
};
