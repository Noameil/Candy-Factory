#pragma once

class ChocolateSupplier
{
private:
    const char *chocolateSupplier;

public:
    ChocolateSupplier(const char *supplierName);
    ~ChocolateSupplier();

    void supplyChocolate();

    inline const char *getChocolateName() const {}
    inline void setChocolateName(const char *newName) {}
};
