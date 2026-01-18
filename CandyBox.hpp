#pragma once
template <class T>

class CandyBox
{
private:
    T *box;

public:
    CandyBox(int size);
    ~CandyBox();

    bool addItem(const T &newItem);
    bool removeItem(int index);
    void displayItems() const;
};
