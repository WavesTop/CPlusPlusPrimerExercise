#include "chapter1.h"
#include <iostream>
#include <cmath>
#include "sales_item.h"
#include <unordered_map>

void chapter1::run()
{
//---------------------------------------------1.2 初识标准输入输出流 cin cout-------------------------------------------------------
    std::cout << std::endl << "1.2 初识标准输入输出流" << std::endl;
    std::cout << "please input two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    // 1.4 && 1.5
    std::cout << "the sum of " << v1 << " and " << v2
                << " is " << v1 + v2 << std::endl 
            << "the product  of " << v1 << " and " << v2
                << " is " << v1 * v2 << std::endl;
    
    // 1.6 
    // std::cout << "the sum of " << v1;
    // << " and " << v2;
    // << " is " << v1 + v2 << std::endl;

    /*
    不合法，; 分号表示一个语句的结束，编译器会认为 << " and " << v2; 是一个独立的语句，
    而 << " is " << v1 + v2 << std::endl; 是另一个独立的语句，这样就会导致编译错误，
    因为 << 输出运算符不能单独使用，其主要作用还是将数据写到ostream对象中，而不是作为一个独立的语句存在。
    */
    std::cout << "the sum of " << v1
         << " and " << v2
         << " is " << v1 + v2 << std::endl;

//------------------------------------------1.3 注释的使用 // /**/-------------------------------------------------
    std::cout << std::endl << "1.3 注释的使用" << std::endl;
    //  1.7
    /*
    
    /*
                         
    */
    
    //(测试可以删除前方的单行注释)  */

    /*
        main.cpp(37): warning C4138: 在注释外找到“* /”
        //main.cpp(37): error C2059: 语法错误:“/”
    */

    // 1.8
    // std::cout << "/*"; 
            // 正确
    // std::cout << "*/"; 
            // 正确
    // std::cout << /* "*/" */; 
            // 修改：不可注释到正常的""     "/* */ */"
    // std::cout << /* "*/" /* "/*" */; 
            // 正确

//------------------------------------------1.4 控制流 while for if-------------------------------------------------    
    std::cout << std::endl << "1.4 控制流" << std::endl;
    int sum = 0, value = 0;
    while (value <= 10) 
    {
        sum += value;
        ++value;
    }
    std::cout << "the sum of 0 to 10 inclusive is " << sum << std::endl;

    // 1.9
    sum = 0;
    value = 50;
    while (value <= 100) 
    {
        sum += value;
        ++value;
    }
    std::cout << "the sum of 50 to 100 inclusive is " << sum << std::endl;

    // 1.10
    value = 10;
    std::cout << "the number between 10 to 0: ";
    while (value >= 0) 
    {
        std::cout << value << " ";
        value--;
    }
    std::cout << std::endl;

    // 1.11
    int value1 = 0, value2 = 0;
    std::cout << "please input two numbers:" << std::endl;
    std::cin >> value1 >> value2;
    int valueMin = std::min(value1, value2);
    int valueMax = std::max(value1, value2);
    std::cout << "the number between " << valueMin << " to " << valueMax << ": ";
    while (valueMin <= valueMax)
    {
        std::cout << valueMin << " ";
        valueMin++;
    }
    std::cout << std::endl;

    // 1.12
    sum = 0;
    for (int i = -100; i <= 100; ++i) 
    {
        sum += i;
    }
    std::cout << "the sum of -100 to 100 inclusive is " << sum << std::endl;

    // 1.13
    /*
    等价替换即可
    while (value1 <= value2) => for (int value = value1; value <= value2; ++value)
    while (value1 <= value2) => for (; value1 >= value2; ++value1)
    while (true) => for (;;)
    while (false) => for (; false; )
    */

    // 1.14 for循环和while循环的区别，各自的优缺点又是什么
    /*
    1. for循环的初始化、条件、循环控制集中在一起，while循环的初始化、条件、循环控制分散在循环体内
    2. 使用场景的区别：
        for循环适用于已知循环次数的情况，比如数组或者容器的便利等
        while循环适用于循环次数未知的情况，比如读取文件、处理队列、事件驱动等

        因此for初始化和更新固定位置，较少错误；灵活，可在任意位置改变循环变量，但容易出错（死循环）
    */

    // 1.16

    sum = 0;
    value = 0;
    std::cout << "please input a series of numbers, and the program will sum them up (Ctrl + Z for windows or Ctrl + D for unix, then press Enter to end input):" << std::endl;
    while (std::cin >> value)
    {
        sum += value;
    }
    std::cout << "the sum is: " << sum << std::endl;

    /*
    上述的输入循环会在用户输入非数字或者达到 EOF 时结束，此时 std::cin 会进入失败状态，后续对 std::cin 的输入操作都会失败，
    在 C++ 中，std::cin 是一个状态化的流对象，一旦进入 EOF 或失败状态，
    后续对它的输入操作都会失败，直到你手动清除状态
    */
    // 恢复 cin 状态
    std::cin.clear();

    // 1.17
    int currVal = 0, val = 0;
    std::cout << "please input a series of numbers, and the program will count the number of times each number appears (Ctrl + Z for windows or Ctrl + D for unix, then press Enter to end input):" << std::endl;
    if (std::cin >> currVal)
    {
        std::cout << "the number " << currVal << " occurs 1 time." << std::endl;
        int count = 1;
        while (std::cin >> val)
        {
            if (val == currVal)
            {
                ++count;
            }
            else
            {
                std::cout << currVal << " occurs " << count << " times." << std::endl;
                currVal = val;
                count = 1;
            }
        }
        std::cout << currVal << " occurs " << count << " times." << std::endl;
    }

    // 1.19 上述版本已经是可以处理两者随意输入的情况

    // 恢复 cin 状态
    std::cin.clear();
    // 关于类的练习
    runForClass();
}

void chapter1::runForClass()
{
    // 1.20
    Sales_item item1;
    std::cout << "please input two sales items (ISBN, units sold, price):" << std::endl;
    std::cin >> item1;
    std::cout << "the first item is: " << item1 << std::endl;

    // 1.21
    Sales_item item2;
    std::cout << "please input another sales item (ISBN, units sold, price):" << std::endl;
    std::cin >> item2;
    std::cout << "the second item is: " << item2 << std::endl;
    if (item1.isbn() == item2.isbn())
    {
        Sales_item total = item1 + item2;
        std::cout << "the total of the two items is: " << total << std::endl;
    }
    else
    {
        std::cout << "the two items have different ISBNs, cannot be added." << std::endl;
    }

    // 1.22 && 1.23 && 1.24
    /*
    没有想到只借助之前的输入输出运算符重载和成员函数就能实现这个功能，使用了一个unordered_map来统计每个ISBN的总销售额，
    */
    std::unordered_map<std::string, Sales_item> salesMap;
    Sales_item item3;
    std::cout << "please input a series of sales items (ISBN, units sold, price), and the program will sum them up by ISBN (Ctrl + Z for windows or Ctrl + D for unix, then press Enter to end input):" << std::endl;
    /*
    input example:
        aaa 3 20
        bbb 2 50
        aaa 2 30
        aaaa 2 60
        Ctrl + Z
        Enter
    */
    while (std::cin >> item3)
    {
        salesMap[item3.isbn()] += item3;
    }
    for (const auto &pair : salesMap)
    {
        std::cout << "the total for ISBN " << pair.first << " is: " << pair.second << std::endl;
    }
}
