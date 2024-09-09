

// 单例实现
class Signalton
{
public:
    ~Signalton();
    static Signalton *getInstance();
    void use();

private:
    Signalton();
    // 禁用
    Signalton(const Signalton &copy) = delete;
    Signalton *operator=(Signalton other) = delete;

private:
    static Signalton *_instance;
    int _iTimes;
};

// 工厂模式

// 产品
class Product
{
public:
    Product();
    // ~Product();
    virtual void use() = 0;
};

class Pro1 : public Product
{
public:
    Pro1();
    void use() override;
};

class Pro2 : public Product
{
public:
    Pro2();
    void use() override;
};
// 工厂
class Factory
{
public:
    virtual Product *createPro() = 0;
    ~Factory();

protected:
    Product *_pro = nullptr;
};

class Fac1 : public Factory
{
public:
    virtual Product *createPro();
};

class Fac2 : public Factory
{
public:
    virtual Product *createPro();
};

// 观察者模式
#include <vector>
#include <string>
class Observer
{
public:
    virtual void update(int state) = 0;
};

class Subject
{
private:
    // 观察者指针
    std::vector<Observer *> _obs;
    int _state;

public:
    void Attach(Observer *obs); // 新增观察者
    void Detach(Observer *obs); // 移除观察者
    void Nodify();              // 更新每个观察者的状态
    void SetState(int state);   // 设置当前状态
    int GetState();             // 获取当前状态
};

class ConcreteObs : public Observer
{
private:
    std::string _name;
    Subject &_sub;

public:
    ConcreteObs(std::string name, Subject &sub);
    void update(int state);
};

// 策略模式：

class Strategy
{
public:
    virtual void algorithm() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void algorithm() override;
};

class ConcreteStrategyB : public Strategy
{
public:
    void algorithm() override;
};

class Context
{
private:
    Strategy *_strategy;

public:
    Context(Strategy *strategy);
    void SetStrategy(Strategy *strategy);
    void ExecAlgorithm();
};

// 适配者
class Target
{
public:
    virtual void Request() = 0;
};

class Adaptee
{
public:
    void SpecialRequest();
};

class Adapter : public Target
{
private:
    Adaptee *_adaptee;

public:
    Adapter(Adaptee *adaptee);
    ~Adapter();
    void Request();
};

// Type Erasuere
class AnyFunction
{
public:
    virtual ~AnyFunction() = default;
    virtual void invoke() const = 0;
};

template <typename Func>
class ConcreteFunc : public AnyFunction
{
private:
    Func _func;

public:
    ConcreteFunc(Func func) : _func(func) {}
    void invoke() const override
    {
        _func();
    }
};

class TypeErasedFunc
{
private:
    AnyFunction *_func;

public:
    template <typename Func>
    TypeErasedFunc(Func func) : _func(new ConcreteFunc<Func>(func)) {}
    ~TypeErasedFunc();
    void operator()() const
    {
        _func->invoke();
    }
};

// CRTP：Curiously Recurring Template Pattern
template <typename Derived>
class Base
{
public:
    void implementation();
    void interface()
    {
        static_cast<Derived *>(this)->implementation();
    }
};

class Derived : public Base<Derived>
{
public:
    void implementation();
};