#pragma once

class CandyMaker : public SugarSupplier, public ChocolateSupplier
{
private:
    const char *sugarSupplierName;
    const char *chocolateSupplierName;

public:
    CandyMaker(const char *sugarSupplierName, const char *chocolateSupplierName);
    ~CandyMaker();

    void makeCandy(const char *candyName);
};
