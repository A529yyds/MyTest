// #include "MyOop.h"

#include "MySmartPtr.h"
#include "MyDesigner.h"
#include "MyAlgorithm.h"
#include <string>
#include <list>
#include <vector>
#include <memory>
// #include <numeric>
#include <algorithm>
#define m(a) #a
#define m1(a, b) a##b // 连接符：将a、b字符连接成一个新字符ab

void exampleFunc();

void testObj()
{
    // Sub1 *sub = nullptr;// 动态分配内存需要手动释放资源
    // Sub1 sub("obj1");

    // {
    //     sub._subName = "obj2";
    //     Sub1 sub1(sub);
    //     sub1._tst_const();
    //     // sub1 = sub;
    // }
    // {
    //     Sub1 *sub1 = NULL;
    //     sub1->_test_null();
    //     sub1->_judge_this();
    // }
    // {
    //     // 常对象只能调用常函数
    //     const Sub1 sub1("obj3");
    //     sub1._tst_const();
    // }

    // sub._subName = "obj1";
    // int ab = 1;
    // int b = 2;
    // std::cout
    //     << m1(a, b) << std::endl;
}

void testPtr()
{
    // std::cout << "----- shared_ptr test start -----" << std::endl;

    // std::shared_ptr<MySmartPtrBase> pBase(new MySmartPtrBase("pBase"));
    // {
    //     pBase->SetPtrName("base1");
    //     std::shared_ptr<MySmartPtrBase> pBase1(pBase);
    //     pBase1->CoutName();
    //     std::cout << "pBase use_count is " << pBase.use_count() << std::endl;

    //     pBase->SetPtrName("base2");
    //     std::shared_ptr<MySmartPtrBase> pBase2 = std::make_shared<MySmartPtrBase>(*pBase);
    //     pBase2->CoutName();
    //     std::cout << "pBase use_count is " << pBase.use_count() << std::endl;
    //     std::cout << "pBase1 use_count is " << pBase1.use_count() << std::endl;
    //     std::cout << "pBase2 use_count is " << pBase2.use_count() << std::endl;
    // }
    // pBase->SetPtrName("pBase");
    // std::cout << "pBase use_count is " << pBase.use_count() << std::endl;

    // Signalton::getInstance()->use();
    // Fac1 fac1;
    // fac1.createPro()->use();
    // fac1.createPro()->use();
    // Signalton::getInstance()->use();
    // Fac2 fac2;
    // fac2.createPro()->use();
    // fac2.createPro()->use();
    // Signalton::getInstance()->use();

    // Subject sub;
    // ConcreteObs obs1("obs1", sub);
    // ConcreteObs obs2("obs2", sub);
    // sub.Attach(&obs1);
    // sub.Attach(&obs2);
    // sub.SetState(1);
    // sub.SetState(2);
    // sub.Detach(&obs1);
    // sub.SetState(3);

    // ConcreteStrategyA strategyA;
    // ConcreteStrategyB strategyB;
    // Context txt(&strategyA);
    // txt.ExecAlgorithm();

    // txt.SetStrategy(&strategyB);
    // txt.ExecAlgorithm();

    // Adaptee adaptee;
    // Adapter adp(&adaptee);
    // adp.Request();

    // TypeErasedFunc func(exampleFunc);
    // func();

    // Derived derived;
    // derived.interface();
}

void testSTLAlgorithm()
{
    // // accumulate
    // std::vector<int> vec{10, 20, 30};
    // // 将vec中所有元素相加
    // std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
    // // 将vec中所有元素*2后再相加
    // std::cout << std::accumulate(vec.begin(), vec.end(), 0, Mul1()) << std::endl;
    // std::cout << std::accumulate(vec.begin(), vec.end(), 0, Mul2()) << std::endl;

    // count & count_if
    // std::vector<int> vec{11, 12, 11, 13, 12, 11, 13, 11, 13, 12, 11};
    // std::string str = "asjhdhgaifadagidgaiag";
    // std::cout << std::count(vec.begin(), vec.end(), 11) << std::endl;
    // std::cout << std::count(str.begin(), str.end(), 'a') << std::endl;
    // std::cout << std::count_if(vec.begin(), vec.end(), IsOdd) << std::endl;

    // find & find_if

    // max & min
    // std::cout << std::max(13, 14) << std::endl;
    // std::cout << std::min(13, 14) << std::endl;

    // merge
    // std::vector<int> v{2, 6, 5, 8};
    // std::list<int> L{9, 3, 0, 5, 7};
    // // sort(v.begin(), v.end());
    // // L.sort();
    // std::vector<int> vRet(v.size() + L.size());
    // merge(v.begin(), v.end(), L.begin(), L.end(), vRet.begin());
    // for (auto e : vRet)
    //     std::cout << e << " ";
    // std::cout << std::endl;

    // partial_sort
    // 找该区间中前4个最小的元素, 元素最终存储在v1的前4个位置
    // std::vector<int> v1{4, 1, 8, 0, 5, 0, 9};
    // std::partial_sort(v1.begin(), v1.begin() + 4, v1.end());
    // for (auto e : v1)
    //     std::cout << e << std::endl;
    // // 找该区间中前4个最大的元素, 元素最终存储在v1的前4个位置
    // std::cout << std::endl;
    // std::cout << std::endl;
    // std::vector<int> v2{4, 1, 8, 0, 5, 0, 9};
    // std::partial_sort(v2.begin(), v2.begin() + 4, v2.end(), std::greater<int>());
    // for (auto e : v2)
    //     std::cout << e << std::endl;

    // partition
    // std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // // 将区间中元素分割成奇数和偶数两部分
    // auto div = std::partition(v.begin(), v.end(), IsOdd);

    // // 打印[begin, div)的元素
    // for (auto it = v.begin(); it != div; ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    // // 打印[div, end)的元素
    // for (auto it = div; it != v.end(); ++it)
    //     std::cout << " " << *it;
    // std::cout << std::endl;

    // 因为next_permutation函数是按照大于字典序获取下一个排列组合的
    // 因此在排序时必须保证序列是升序的
    std::vector<int> v = {4, 1, 2, 3};
    std::sort(v.begin(), v.end());
    do
    {
        std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;
    } while (std::next_permutation(v.begin(), v.end()));
    std::cout << std::endl;

    // 因为prev_permutation函数是按照小于字典序获取下一个排列组合的
    // 因此在排序时必须保证序列是降序的
    // sort(v.begin(), v.end());
    sort(v.begin(), v.end(), std::greater<int>());
    do
    {
        std::cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << std::endl;
    } while (std::prev_permutation(v.begin(), v.end()));
}

int main(int argc, char **argv)
{
    // 程序代码
    testObj();
    testPtr();
    testSTLAlgorithm();
    return 0;
}

void exampleFunc()
{
    std::cout << "exampleFunc" << std::endl;
}