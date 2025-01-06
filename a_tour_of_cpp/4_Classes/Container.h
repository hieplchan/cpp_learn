#ifndef MY_CONTAINER_H_
#define MY_CONTAINER_H_

/* 
Abstract class: A class with a pure virtual function
virtual: "maybe" defined later in derived class
= 0: pure virtual function -> derived class "must" defined this func 
    -> not posible to define object with just Container
*/
class Container {
public:
    // abstract class usually dont have constructor (no data to init)
    
    // derived class can provice destructor implementation
    virtual ~Container() {}

    virtual double& operator[](int index) = 0;
    virtual int size() const = 0;
};

#endif MY_CONTAINER_H_