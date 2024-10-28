#pragma once

#include <iostream>
#include "person.h"
#include "address.h"
#include <stdexcept>

template <typename T>
//class Array {
//private:
//    T* arr;
//    int capacity;
//    int size;
//    void Resize(int new_capacity)
//    {
//        T* newarr = new T[new_capacity];
//        for (int i = 0; i < size; i++)
//        {
//            newarr[i] = arr[i];
//        }
//        delete[] arr;
//        arr = newarr;
//        capacity = new_capacity;
//    }
//public:
//    //Person f;
//    Array(int cap = 10) : capacity(cap), size(0)
//    {
//        arr = new T[capacity];
//    }
//    ~Array() {
//        delete[] arr;
//    }
//    Array(const Array& cop) //copy constractor
//    {
//        size = cop.size;
//        capacity = cop.capacity;
//        arr = new T[capacity];
//        for (int i = 0; i < size; i++) {
//            arr[i] = cop.arr[i];
//        }
//    }
//    Array& operator=(const Array& cop) {
//        if (this != &cop) {
//            size = cop.size;
//            capacity = cop.capacity;
//            arr = new T[capacity];
//            for (int i = 0; i < size; i++) {
//                arr[i] = cop.arr[i];
//            }
//        }
//        return *this;
//    }
//    void AddContact(T ele)  //åÎáí Çá Êí Ïí ÈÚÏíä ãä äæÚ ÈíÑÓæä
//    {
//        if (size == capacity) {
//            Resize(capacity * 2);
//        }
//        arr[size++] = ele;
//        std::cout << "The contact has been added successfully." << "\n";
//    }
//   
//    int getSize()
//    {
//        return size;
//    }
//    T& operator[](int i)
//    {
//        if (i < 0 || i >= size)
//        {
//            return arr[i];
//        }
//        throw std::out_of_range("Index out of range");
//    }
//    
//    void Delete_Contact(int index)
//    {
//        if (size > capacity)
//        {
//            throw std::overflow_error("Index out of Range...");
//        }
//        for (int i = size; i < index; i++)
//        {
//            arr[i] = arr[i + 1];  //shift to left 
//        }
//        size--;
//        if (size <= capacity / 4)
//        {
//            Resize(capacity / 2);
//        }
//    }
//    /*void deleteContact(std::string name)
//   {
//       for (int i = 0; i < size; i++) {
//           if (contacts[i].get_FName() == name) {
//               for (int j = i; j < size - 1; j++) {
//                   contacts[j] = contacts[j + 1];
//               }
//               size--;
//               std::cout << "The contact has been deleted Sucessfully." << "\n";
//           }
//       }
//       cout << "This Nmae is not found!!" << endl;
//   }*/
//    void display_c()
//    {
//        for (size_t i = 0; i < size; i++)
//        {
//            std::cout << arr[i] << " ";
//        }
//        std::cout << std::endl;
//    }
//   
//
//};
class Array {
private:
    int* arr;
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
    T& operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            return arr[i];
        }
        throw std::out_of_range("Index out of range");
    }
    Array& operator=(const Array& cop) {
        if (this != &cop) {
            size = cop.size;
            capacity = cop.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = cop.arr[i];
            }
        }
        return *this;
    }
    void AddContact(T ele)  //åÎáí Çá Êí Ïí ÈÚÏíä ãä äæÚ ÈíÑÓæä
    {  
        if (size == capacity) {
            Resize(capacity * 2);
        }
        arr[size++] = ele;
    }
    void insert(T cont, int index)
    {
        if (size == capacity) {
            Resize(capacity * 2);
        }
        for (int i = size; i < index; i++)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = cont;
        size++;
    }
    void Delete_Contact(int index)
    {
        if (size > capacity)
        {
            throw std::overflow_error("Index out of Range...");
        }
        for (int i = size; i < index; i++)
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
        Resize(2);//Çæá ÞíãÉ ßÇäÊ Ýí Çá capacity
    }
    void inverse()
    {
        int temp;
        int end = size - 1;
        for (int i = 0;i < end;i++)
        {
            temp = arr[i];
            arr[i] = arr[end];
            arr[end] = temp;
            end--;
        }
    }
    void sort()
    {
        for (int i = 0;i < size - 1;i++)
        {
            for (int j = 0; j < size - i - 1;j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[i + 1];
                    arr[j + 1] = temp;
                }
            }
        }
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

//power bi service