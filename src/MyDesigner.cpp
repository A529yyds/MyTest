#include "MyDesigner.h"
#include <iostream>
#include <algorithm>

Signalton *Signalton::_instance = nullptr;

Signalton::~Signalton()
{
    _iTimes = 0;
    if (_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
    std::cout << "Signalton delete!" << std::endl;
}

Signalton *Signalton::getInstance()
{
    if (!_instance)
    {
        _instance = new Signalton();
    }
    return _instance;
}

void Signalton::use()
{
    _iTimes++;
    std::cout << "Signalton use times: " << _iTimes << std::endl;
}

Signalton::Signalton()
{
    std::cout << "Signalton create!" << std::endl;
}

Product::Product()
{
    std::cout << "Product create" << std::endl;
}

Pro1::Pro1()
{
    std::cout << "Pro1 create" << std::endl;
}

void Pro1::use()
{
    std::cout << "Pro1 use" << std::endl;
}

Pro2::Pro2()
{
    std::cout << "Pro2 create" << std::endl;
}

void Pro2::use()
{
    std::cout << "Pro2 use" << std::endl;
}

Product *Fac1::createPro()
{
    return !_pro ? new Pro1() : _pro;
}

Product *Fac2::createPro()
{
    return !_pro ? new Pro2() : _pro;
}

Factory::~Factory()
{
    if (_pro)
    {
        delete _pro;
        _pro = nullptr;
    }
    std::cout << "Factory _pro delete" << std::endl;
}

void Subject::Attach(Observer *obs)
{
    _obs.push_back(obs);
}

void Subject::Detach(Observer *obs)
{
    // 需要用algorithm库里的算法
    _obs.erase(std::remove(_obs.begin(), _obs.end(), obs), _obs.end());
}

void Subject::Nodify()
{
    for (auto obs : _obs)
    {
        obs->update(_state);
    }
}

void Subject::SetState(int state)
{
    _state = state;
    Nodify();
}

int Subject::GetState()
{
    return _state;
}

ConcreteObs::ConcreteObs(std::string name, Subject &sub) : _name(name), _sub(sub)
{
}

void ConcreteObs::update(int state)
{
    std::cout << "ConcreteObs " << _name << " update state is " << state << std::endl;
}

void ConcreteStrategyA::algorithm()
{
    std::cout << "ConcreteStrategyA  algorithm" << std::endl;
}

void ConcreteStrategyB::algorithm()
{
    std::cout << "ConcreteStrategyB  algorithm" << std::endl;
}

Context::Context(Strategy *strategy) : _strategy(strategy)
{
}

void Context::SetStrategy(Strategy *strategy)
{
    _strategy = strategy;
}

void Context::ExecAlgorithm()
{
    _strategy->algorithm();
}

Adapter::Adapter(Adaptee *adaptee) : _adaptee(adaptee)
{
}

Adapter::~Adapter()
{
    // if (_adaptee)
    // {
    //     delete _adaptee;
    //     _adaptee = nullptr;
    // }
}

void Adapter::Request()
{
    _adaptee->SpecialRequest();
}

void Adaptee::SpecialRequest()
{
    std::cout << "Adaptee SpecialRequest" << std::endl;
}

TypeErasedFunc::~TypeErasedFunc()
{
    delete _func;
}

template <typename Derived>
void Base<Derived>::implementation()
{
    std::cout << "Base implementation" << std::endl;
}

void Derived::implementation()
{
    std::cout << "Derived implementation" << std::endl;
}
