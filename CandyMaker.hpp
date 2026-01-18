#pragma once
#include <iostream>
#include <string>
using std::string;
class CandyMaker : public SugarSupplier, public ChocolateSupplier
{
private:
public:
    CandyMaker(const string& sugName, const string& chocName)
    : SugarSupplier(sugName), ChocolateSupplier(chocName) {
        std::cout<<"CanyMaker Created"<<std::endl;
    } 
    ~CandyMaker() {}

    void makeCandy(const string& candyName) const
    {
        ;
        std::cout << "Using sugar from " << getSugarName() 
                  << " and chocolate from " << getChocolateName() 
                  << " to make " << candyName << std::endl;
    }
};
