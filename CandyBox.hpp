#pragma once
#include "DynamicArray.hpp"
template <class T>
class CandyBox
{
private:
    DynamicArray<T> items;
    int size;
    int count;

public:
    CandyBox(int capacity) : items(capacity), size(capacity), count(0) {}
    ~CandyBox() {}

    bool addItem(const T &newItem) {
        std::cout<<"Attempting to add item: " <<newItem<<std::endl;
        try
        {
            items.pushBack(newItem);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        count = items.getSize();
        size = items.getCapacity();
        std::cout<<newItem<<" Succesfully added at index "<<count-1<<std::endl;
        return true;
    }
    bool removeItem(int index)
    {
        std::cout<<"Attempting to remove item At index: "<<index<<std::endl;
        try
        {
            items.removeAt(index);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            return false;
        }
        count = items.getSize();
        size = items.getCapacity();
        std::cout<<"Item Succesfully removed at index "<<index<<std::endl;
        return true;
    }
    void displayItems() const
    {
        for (int i = 0; i < count; i++)
        {
           std::cout << items[i] << std::endl;
        }
        std::cout<<std::endl;
    }
};
