#include <string>
#include <iostream>

class MySmartPtrBase
{
public:
    MySmartPtrBase(std::string name);
    ~MySmartPtrBase();
    MySmartPtrBase(const MySmartPtrBase *copy);
    void SetPtrName(std::string name);
    void CoutName();

public:
    std::string _name;

private:
protected:
};

class MySmartPtr : public MySmartPtrBase
{
public:
    MySmartPtr(std::string name);
    ~MySmartPtr();

private:
protected:
};