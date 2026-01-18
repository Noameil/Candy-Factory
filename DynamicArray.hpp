#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class DynamicArray
{
private:
    int capacity;
    int size;
    T* arr;
    void resize()
    {
        using namespace std;
        int newCap = capacity * 2;

        T* newArr = new T[newCap];
        if(!newArr ) {cout<<"Memory Allocation Failed."<<endl; return;}
        int i = 0;
        for(int i = 0; i < size; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
        capacity = newCap;
    }



public:
    DynamicArray(int initCap = 2) : size(0), capacity(initCap), arr(new T[capacity]) {}
    ~DynamicArray()
    {
        if(arr != nullptr)
            delete[] arr;
        arr = nullptr;
    }
    //add element to the top of the array
    void pushBack(const T& value)
    {
        if(size == capacity)
            resize();
        arr[size] = value;
        size++;
    }
    T& operator[](int index)
    {
        if(index < 0 || index >= size )
            throw std::out_of_range("Index out of bounds!");
        return arr[index];
    }
    //returns the element at the top index and "removes it"
    T& popBack() 
    {
        if(size > 0)
            return arr[--size];
        else throw std::out_of_range("No elements in Arr!");
    }
    
    void removeAt(int index)
    {
        if(index < 0 || index >= size) return;
        for(int i = index; i < size - 1; i++)
            arr[i] = arr[i+1];
        size--;
    }
    //how many elements are actually in the array
    int getSize() const { return size; }
    //how many elements are currently allocated
    int getCapacity() const {return capacity;}
};
