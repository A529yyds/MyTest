#include <string>
#include <iostream>

class Base;
class Friend
{
    friend void globalFunc(Friend *fri); // 全局函数做友元（添加friend之后可成功访问）
    // friend void Base::_tst_friend();     // 成员函数做友元
    friend class Sub1; // 类做友元

public:
    int _iPubNum;

private:
    int _iPriNum;

protected:
    int _iProNum;

public:
    Friend()
    {
        _iPubNum = 0;
        _iPriNum = 0;
        _iProNum = 0;
    }
};

// 全局函数无法直接访问类的protected和private属性的成员
void globalFunc(Friend *fri)
{
    fri->_iPubNum = 0;
    fri->_iPriNum = 1;
    fri->_iProNum = 2;
}

class Base
{
public:
    std::string _subName;
    // static int _iStaticNum;

public:
    Base()
    {
        std::cout << "base construct no parameters" << std::endl;
    }

    Base(std::string name) : _subName(name)
    {
        std::cout << _subName << " base construct" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << _subName << " base delete" << std::endl;
    }

    Base(const Base &copy)
    {
        _subName = copy._subName;
        std::cout << _subName << " base copy" << std::endl;
    }

    void _tst_friend()
    {
        // Friend *fri;
        // fri->_iPubNum = 0;
        // fri->_iPriNum = 1;
        // fri->_iProNum = 2;
    }

private:
    int _iNum = 0;
};

class Sub1 : public Base
{
public:
    Sub1()
    {
        std::cout << "Sub1 construct no parameters" << std::endl;
    }

    Sub1(std::string name) : Base(name)
    {
        std::cout << _subName << " construct" << std::endl;
    }

    Sub1(const Sub1 &copy)
    {
        _iNum = copy._iNum;
        _subName = copy._subName;
        std::cout << _subName << " copy" << std::endl;
    }

    ~Sub1()
    {
        std::cout << _subName << " delete" << std::endl;
    }

    void test()
    {
        std::cout << _subName << " output num is " << _iNum << std::endl;
    }

    void _test_null()
    {
        std::cout << "object is null" << std::endl;
    }

    void _judge_this()
    {
        if (!this)
        {
            std::cout << "this is null" << std::endl;
        }
        std::cout << "end judge this" << std::endl;
    }

    void _tst_const() const
    {
        // _iNum = 2;
        std::cout
            << "before _iNum = " << _iNum
            << "; _iNum1 = " << _iNum1 << std::endl;
        _iNum1 = 2;
        std::cout
            << "after _iNum = " << _iNum
            << "; _iNum1 = " << _iNum1 << std::endl;
    }

    void _tst_friend()
    {
        Friend *fri;
        fri->_iPubNum = 0;
        fri->_iPriNum = 1;
        fri->_iProNum = 2;
    }

private:
    int _iNum = 1;
    mutable int _iNum1 = 0;

protected:
    void testProObj(int num)
    {
        // _iNum = num;
    }
};