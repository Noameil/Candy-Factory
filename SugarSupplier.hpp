#pragma once

class SugarSupplier
{
private:
    const char *supplierName;

public:
    SugarSupplier(const char *supplierName);
    ~SugarSupplier();

    void supplySugar();

    inline const char *getSugarName() const {}
    inline void setSugarName(const char *newName) {}
};
