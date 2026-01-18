#pragma once
#include <iostream>
#include <string>

template<typename T>
class DynamicArray
{
private:
    int capacity;
    int count;
    
    T* arr;
    void resize()
    {
        using namespace std;
        int newCap = capacity * 2;

        T* newArr = new T[newCap];
        if(!newArr ) throw std::runtime_error("Memory Allocation Failed");
        int i = 0;
        for(int i = 0; i < count; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }



public:
    DynamicArray(int initCap = 2) : count(0), capacity(initCap), arr(new T[capacity]) {}
    ~DynamicArray()
    {
        if(arr != nullptr)
            delete[] arr;
        arr = nullptr;
    }
    //add element to the top of the array
    void pushBack(const T& value)
    {
        if(count == capacity)
            resize();
        arr[count] = value;
        count++;
    }
    const T& operator[](int index) const
    {
        if(index < 0 || index >= count )
            throw std::runtime_error("Index out of bounds!");
        return arr[index];
    }
    //returns the element at the top index and "removes it"
    T& popBack() 
    {
        if(count > 0)
            return arr[--count];
        else throw std::runtime_error("No elements in Arr!");
    }
    
    void removeAt(int index)
    {
        if(index < 0 || index >= count) throw std::runtime_error("Incorrect index!: " + std::to_string(index));
        for(int i = index; i < count - 1; i++)
            arr[i] = arr[i+1];
        count--;
    }
    //how many elements are actually in the array
    int getSize() const { return count; }
    //how many elements are currently allocated
    int getCapacity() const {return capacity;}
};
