#pragma once
#include <iostream>
#include "person.h"
#include "address.h"
#include <stdexcept>

template <typename T>
class Array {
private:
    T* arr;
    int capacity;
    int size;
    void Resize(int new_capacity)
    {
        T* newarr = new T[new_capacity];
        for (int i = 0; i < size; i++)
        {
            newarr[i] = arr[i];
        }
        delete[] arr;
        arr = newarr;
        capacity = new_capacity;
    }
public:

    Array(int cap = 2) : capacity(cap), size(0)
    {
        arr = new T[capacity];
    }

    Array(const Array& cop)
    {
        size = cop.size;
        capacity = cop.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = cop.arr[i];
        }
    }

    T& operator[](int i) {
        if (i < 0 || i >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[i];
    }

    Array& operator=(const Array& cop)
    {
        if (this != &cop) {
            delete[] arr; // Free existing memory
            size = cop.size;
            capacity = cop.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = cop.arr[i];
            }
        }
    }
    void operator=(Array<T>& c)
    {

        size = c.size;
        capacity = c.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = c.arr[i];
        }

    }
    void AddContact(T ele)
    {
        if (size == capacity) {
            Resize(capacity * 2);
        }
        arr[size++] = ele;
    }

    void insert(T cont, int index) {
        if (size == capacity) {
            Resize(capacity * 2);
        }
        for (int i = size; i > index; i--) // Change to i > index
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = cont;
        size++;
    }

    void Delete_Contact(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::overflow_error("Index out of Range...");
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];  //shift to left 
        }
        size--;
        if (size <= capacity / 4)
        {
            Resize(capacity / 2);
        }
    }

    int getSize()
    {
        return size;
    }

    void clear()
    {
        size = 0;
        Resize(2);
    }


    void display()
    {
        for (size_t i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    ~Array() {
        delete[] arr;
    }
};
