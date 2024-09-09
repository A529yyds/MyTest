#include <MySmartPtr.h>

MySmartPtr::MySmartPtr(std::string name) : MySmartPtrBase(name)
{
    std::cout << name << " MySmartPtr build" << std::endl;
}

MySmartPtr::~MySmartPtr()
{
    std::cout << "MySmartPtr delete" << std::endl;
}

MySmartPtrBase::MySmartPtrBase(std::string name)
{
    std::cout << name << " MySmartPtrBase build" << std::endl;
}

MySmartPtrBase::~MySmartPtrBase()
{
    std::cout << _name << " MySmartPtrBase delete" << std::endl;
}

void MySmartPtrBase::SetPtrName(std::string name)
{
    _name = name;
}

void MySmartPtrBase::CoutName()
{
    std::cout << "This object name is " << _name << std::endl;
}

MySmartPtrBase::MySmartPtrBase(const MySmartPtrBase *copy)
{
    this->_name = copy->_name;
    std::cout << _name << " MySmartPtrBase copy build" << std::endl;
}
