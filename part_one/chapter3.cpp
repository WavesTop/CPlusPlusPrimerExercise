#include "helper.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

// 第三章 字符串、向量、数组
void chapter3::run()
{
    //---------------------------------------------3.1 命名空间的using声明-------------------------------------------------------

    //3.1 
    /*
        使用
        using std::cin;
        using std::cout;using std::endl;即可
    */

    //---------------------------------------------3.2 标准库类型string-------------------------------------------------------

    /*
    // 定义和初始化string
    string s1; //默认初始化，s1是一个空字符串
    string s2(s1); //s2是s1的副本
    string s2 = s1; // 等价于 string s2(s1);
    string s3("value"); //s3是字面值“value”的副本，除了字面值最后的空字符外
    string s3 = "value"; //等价于 string s3("value");
    string s4(n, 'c'); //把s4初始化为由连续n个字符c组成的串

    //string的操作和读写
    os << s; //将s写到输出流os中，返回os
    is >> s; //从is中读取字符串赋给s，字符串以空白分隔，返回is
    getline(is, s); //从is中读取一行赋给s，返回is
    s.empty(); //s为空返回true，否则返回false
    s.size(); //返回s中字符的个数
    s1 + s2; //返回s1和s2连接后的结果
    s1 == s2; //如果s1和s2中的字符完全相等则返回true
    s1 != s2; //如果s1和s2中的字符不相等则返回true
    <, <=, >, >=; //利用字符的字典序进行比较

    // 处理string中的字符，cctype
    isalnum(c); //当c是字母或数字时为真
    isalpha(c); //当c是字母时为真
    iscntrl(c); //当c是控制字符时为真
    isdigit(c); //当c是数字时为真
    isgraph(c); //当c不是空格但可打印时为真
    islower(c); //当c是小写字母时为真
    isprint(c); //当c是可打印字符时为真
    ispunct(c); //当c是标点符号时为真
    isspace(c); //当c是空白字符时为真
    isupper(c); //当c是大写字母时为真
    isxdigit(c); //当c是十六进制数字时为真
    tolower(c); //如果c是大写字母，输出对应的小写字母；否则原样输出c
    等等
    */

    // 3.2 练习：编写一段程序从标准输入中一次读入一整行，然后修改该程序使其一次读入一个词。
    {
        string line;
        cout << "Enter a line of text: ";
        while (getline(cin, line))
            cout << line << endl;
        string word;
        while (cin >> word)
            cout << word << endl;
    }

    //3.3 string类的输入运算符和getline函数之间是如何处理空白字符串的。
    // string：先跳过前导的空白格cin >> word，然后读取直到遇到下一个空白格。
    // getline：不跳过前导空白格，读取直到遇到换行符。

    // 3.4 编写一段程序读入两个字符串，比较是否相等并输出结果。如果不相等，输出较大的字符串。
    {
        string s1, s2;
        cout << "Enter two strings: ";
        cin >> s1 >> s2;
        if (s1 == s2)
            cout << "They are equal." << endl;
    }
    // 比较是否等长
    {
        string s1, s2;
        cout << "Enter two strings: ";
        cin >> s1 >> s2;
        if (s1.size() == s2.size())
            cout << "They have the same length." << endl;
        else if (s1.size() > s2.size())
            cout << s1 << " is longer." << endl;
        else
            cout << s2 << " is longer." << endl;
    }

    //3.5 编写程序从标准输入中读入多个字符串，并连接在一起，输出成一个大字符串。
    {
        string s, result;
        cout<<"Please enter some strings (Ctrl+Z to end): ";
        while (cin >> s)
            result += s;
        cout << result << endl;
    }
    // 将字符串使用空格间隔
    {
        string s, result;
        cout<<"Please enter some strings (Ctrl+Z to end): ";
        while (cin >> s)
            result += s + " ";
        cout << result << endl;
    }

    // 3.6 使用for循环将字符串中的所有字符都用x来替代
    {
        string s;
        cout << "Please enter a string: ";
        cin >> s;
        for (auto &c : s)
            c = 'x';
        cout << s << endl;
    }

    //3.7 将3.6的循环控制变量的类型改为char
    {
        string s;
        cout << "Please enter a string: ";
        cin >> s;
        for (char &c : s)
            c = 'x';
        cout << s << endl;
    }

    // 3.8 分别用while循环和传统的for循环改写3.6的程序
    {
        string s;
        cout << "Please enter a string: ";
        cin >> s;
        // 使用while循环
        decltype(s.size()) i = 0;
        while (i < s.size()) {
            s[i] = 'x';
            ++i;
        };
        cout << s << endl;

        cout << "Please enter a string: ";
        cin >> s;
        // 使用for循环
        for (decltype(s.size()) i = 0; i < s.size(); ++i) {
            s[i] = 'x';
        }
        cout << s << endl;
    }

    // 3.9 下面的程序合法吗？如果不合法，如何修改？
    {
        string s;
        // cout << s[0] << endl;
        // 不合法，s为空字符串，s[0]是未定义行为
        // 修改：先检查是否为空
        if (!s.empty()) {
            cout << s[0] << endl;
        }
    }

    // 3.10 读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分
    {
        string s;
        cout << "请输入一个包含标点符号的字符串: ";
        getline(cin, s);
        string result;
        for (auto c : s) {
            if (!ispunct(c)) {
                result += c;
            }
        }
        cout << "去除标点符号后的字符串: " << result << endl;
    }

    // 3.11 下面范围的for循环合法吗，如果合法，c的类型是什么？
    {
        const string s = "Keep out!";
        for (auto& c : s) { /* ... */ }
        // 合法。c的类型是 const char&。因为 s 是 const string，所以范围 for 循环中的引用 c 是 const 引用，不能通过 c 修改 s 中的字符。
    }


    //---------------------------------------------3.3 标准库类型vector-------------------------------------------------------

    /*
    // vector是什么？
    1. 相同类型对象的集合。
    2. 容器
    3. 类模板

    // vector的定义和初始化：
    vector<T> v1;          // v1是一个空vector，它潜在的元素是T类型，执行默认初始化
    vector<T> v2(v1);        // v2中包含有v1所有元素的副本
    vector<T> v2 = v1;       // 等价于v2(v1)
    vector<T> v3(n, val);    // v3包含了n个重复的元素，每个元素的值都是val
    vector<T> v4(n);// v4包含了n个重复地执行了值初始化的对象
    vector<T> v5{a, b, c};   // v5包含了初始值个数的元素，每个元素被赋予相应的初始值
    vector<T> v5 = {a, b, c};  // 等价于v5{a, b, c}; // 列表初始化
    vector<T> v6(v5.begin(), v5.end()); // v6是v5的副本，使用迭代器范围初始化

    // vsctor的使用:
    vector<T> v;             // 声明一个vector对象
    v.push_back(val);        // 在vector末尾添加一个元素
    v.pop_back();            // 删除vector末尾的一个元素
    v.size();                // 返回vector中元素的个数
    v.empty();               // 判断vector是否为空
    v.clear();               // 清空vector中的所有元素
    v.front();               // 返回vector中第一个元素的引用
    v.back();                // 返回vector中最后一个元素的引用
    v.at(index);             // 返回指定位置的元素，带越界检查
    v[index];                // 返回指定位置的元素，不带越界检查
    */

    // 3.12 下列vector对象的定义哪些是不合法的？
    {
        vector<vector<vector<int>>> ivec;         // 合法：vector的vector
        //vector<string> svec = ivec;  // 不合法：类型不匹配，ivec是int的vector，svec是string的vector
        vector<string> svec(10, "null"); // 合法：10个string元素，每个都是"null"
    }

    // 3.13 下列vector对象各包含多少个元素？这些元素的值分别是多少？
    {
        vector<int> v1;               // 0个元素
        vector<int> v2(10);            // 10个元素，值都是0
        vector<int> v3(10, 42);        // 10个元素，值都是42
        vector<int> v4{10};            // 1个元素，值为10
        vector<int> v5{ 10, 42 };        // 2个元素，值分别为10和42
        vector<string> v6{10};          // 1个元素，值为"10"
        vector<string> v7{ 10, "hi" };      // 10个元素，值都是"hi"
        //{} 本质是：列表初始化（list initialization），如果花括号内的值无法用于列表初始化，则编译器会尝试用这些值来构造vector对象。
    }
    // 3.14 使用cin读取一段整数，并把他们存入到一个vector对象中
    {
        vector<int> nums;
        int num;
        cout<< "请输入整数（按 Ctrl+Z 结束）：";
        while (cin >> num)
        {
            nums.push_back(num);
        }
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // 3.15 改写3.14的程序，读入的是字符串，然后将一个个整数存储到vector中
    {
        string s;
        vector<int> nums;
        cout << "请输入整数（按 Ctrl+Z 结束）：";
        while (cin >> s)
        {
            // 输入不合规，则会抛异常
            nums.push_back(stoi(s));
        }
        for (auto i : nums)
            cout << i << " ";
        cout << endl;
    }

    // 3.16 输出3.13对象中的容量和具体的内容
    {
        vector<int> v1;               // 0个元素
        vector<int> v2(10);            // 10个元素，值都是0
        vector<int> v3(10, 42);        // 10个元素，值都是42
        vector<int> v4{10};            // 1个元素，值为10
        vector<int> v5{ 10, 42 };        // 2个元素，值分别为10和42
        vector<string> v6{10};          // 1个元素，值为"10"
        vector<string> v7{ 10, "hi" };      // 10个元素，值都是"hi";
        cout << "v1: size=" << v1.size() << " elements: ";
        for (auto i : v1)
            cout << i << " ";
        cout << endl;

        cout << "v2: size=" << v2.size() << " elements: ";
        for (auto i : v2)
            cout << i << " ";
        cout << endl;

        cout << "v3: size=" << v3.size() << " elements: ";
        for (auto i : v3)
            cout << i << " ";
        cout << endl;

        cout << "v4: size=" << v4.size() << " elements: ";
        for (auto i : v4)
            cout << i << " ";
        cout << endl;

        cout << "v5: size=" << v5.size() << " elements: ";
        for (auto i : v5)
            cout << i << " ";
        cout << endl;

        cout << "v6: size=" << v6.size() << " elements: ";
        for (auto i : v6)
            cout << i << " ";
        cout << endl;

        cout << "v7: size=" << v7.size() << " elements: ";
        for (auto i : v7)
            cout << i << " ";
        cout << endl;
    }
    // 3.17 从cin中读入一组词，并存入到vector对象中，然后将所有的词改为大写，并输出，每个词占一行
    {
        string word;
        vector<string> text;
        cout<<"请输入一组词(Ctrl+Z结束输入):" << endl;
        while (cin >> word)
            text.push_back(word);
        for (auto &w : text)
            for (auto& c : w)
                c = toupper(c);
        for (auto &w : text)
            cout << w << endl;
    }

    //3.18 下面的程序合法吗？如果不合法，你准备如何修改？
    {
        vector<int> ivec;
        //ivec[0] = 42;
        //不合法，因为ivec是空的，不能通过下标访问元素。应改为：
        ivec.push_back(42);
    }

    //3.19 如果想定义一个10个元素的vector对象，所有元素的值都是42，请列出三种不同的实现方法。哪种方法更好？为什么？
    {
        vector<int> ivec1(10, 42);
        vector<int> ivec2 = {42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
        vector<int> ivec3;
        for (int i = 0; i < 10; ++i)
            ivec3.push_back(42);
        // 第一种方法最好，因为它最简洁高效，直接调用构造函数初始化，避免了不必要的循环或列表初始化。
    }

    //3.20 读入一组整数并存入vector对象，将每对相邻整数的和输出。
    {
        int val;
        vector<int> ivec;
        cout << "请输入一组整数（以非数字结束）：";
        while (cin >> val)
            ivec.push_back(val);
        for (decltype(ivec.size()) i = 0; i < ivec.size() - 1; ++i)
            cout << ivec[i] + ivec[i + 1] << " ";
    }
    // 改写程序，先输出第一个和最后一个的和，其次再输出输出第二个和倒数第二个的和，以此类推。
    {
        int val;
        vector<int> ivec;
        cout << "请输入一组整数（以非数字结束）：";
        while (cin >> val)
            ivec.push_back(val);
        for (decltype(ivec.size()) i = 0; i < ivec.size() / 2; ++i)
            cout << ivec[i] + ivec[ivec.size() - 1 - i] << " ";
        if (ivec.size() % 2 != 0)
            cout << ivec[ivec.size() / 2];
    }


    //---------------------------------------------3.4 迭代器介绍-------------------------------------------------------

    /*
    // 什么是迭代器：
        迭代器是一种访问容器元素的数据类型，它类似于指针，可以指向容器中的某个元素，并支持递增、递减等操作，用于遍历容器。
    
    // 迭代器的使用：
        1. 获取迭代器：使用容器的成员函数 begin() 和 end() 获取指向第一个元素和尾后元素的迭代器。
        2. 使用迭代器：通过解引用操作符 * 获取迭代器指向的元素，通过递增操作符 ++ 将迭代器移动到下一个元素。
        3. 迭代器类型：每个容器都有对应的迭代器类型，如 vector<int>::iterator 表示 vector<int> 的迭代器类型。
        4. 迭代器运算：支持加减整数、比较等操作，如 iter + n、iter1 - iter2、iter1 < iter2 等。
        5. 使用迭代器的循环体，就不要修改容器的容量，否则会导致迭代器失效。
    */

    //3.21 请使用迭代器重写3.16题的程序，输出每个对象的容量和值。
    {
        vector<int> v1;               // 0个元素
        vector<int> v2(10);            // 10个元素，值都是0
        vector<int> v3(10, 42);        // 10个元素，值都是42
        vector<int> v4{10};            // 1个元素，值为10
        vector<int> v5{ 10, 42 };        // 2个元素，值分别为10和42
        vector<string> v6{10};          // 1个元素，值为"10"
        vector<string> v7{ 10, "hi" };      // 10个元素，值都是"hi";

        const vector<int>* vecs[] = {&v1, &v2, &v3, &v4, &v5};
        const vector<string>* str_vecs[] = {&v6, &v7};
        for (auto p : vecs)
        {
            cout << "容量: " << p->size() << " 值: ";
            for (auto it = p->cbegin(); it != p->cend(); ++it)
            {
                cout << *it << " ";

            }
            cout << endl;
        }
    }

    // 3.22 假如text的字符串向量，存放文本信息，把text中的第一段（即第一个空字符串之前的字符串）改为大写形式。
    {
        auto text = vector<string>{"hello", "world", "", "second paragraph"};
        for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
        {
            for (auto& c : *it) {
                c = toupper(c);
            }
        }
    }

    // 3.23 创建一个包含10个整数的vector，使用迭代器将所有元素的值翻倍，并暑促和vector的内容。
    {
        vector<int> v;
        for (int i = 0; i < 10; ++i)
        {
            v.push_back(i);
        }
        for (auto it = v.begin(); it != v.end(); ++it)
        {
            *it *= 2;
        }
    }

    // 3.24 使用迭代器，读入一组整数并存入vector对象先输出第一个和最后一个的和，其次再输出输出第二个和倒数第二个的和，以此类推。注意处理越界情况
    {
        vector<int> v;
        int i;
        while (cin >> i)
        {
            v.push_back(i);
        }
        auto it = v.begin();
        auto end = v.end();
        while (it < end)
        {
            cout << *it + *(end - 1) << " ";
            ++it;
            --end;
        }
        cout << endl;
    }

    // 3.25 使用迭代器统计0-100，每10分的分数段人数
    {
        vector<unsigned> scores(11, 0);
        unsigned grade;
        while (cin >> grade)
        {
            if (grade <= 100)
            {
                ++*(scores.begin() + grade / 10);
            }
        }
        for (auto s : scores)
            cout << s << " ";
    }

    // 3.26 在二分搜索程序中，为什么使用mid = beg + (end - beg) / 2 而不是 (beg + end) / 2？
    // 因为迭代器不支持加法运算，但支持减法运算。`beg + end` 会导致编译错误，
    // 而 `beg + (end - beg) / 2` 先计算距离再除以2，得到正确的中间位置。


    //---------------------------------------------3.5 数组-------------------------------------------------------

    /*
    什么是数组：
        数组是相同类型对象的集合，每个对象通过下标访问。数组的大小是固定的，不能改变。

    初始化和定义数组：
        int arr[10];                // 定义包含10个整数的数组
        int arr2[] = {1, 2, 3};     // 根据初始化列表推断大小
        int arr3[5] = {1, 2};       // 前两个元素为1,2，其余为0
        int arr4[3] = {1, 2, 3};    // 完全初始化
        int arr5[5] = {};          // 所有元素初始化为0
        char ca1[] = {'C', '+', '+'};        // 不是以空字符结尾
        char ca2[] = {'C', '+', '+', '\0'};  // 显式添加空字符
        char ca3[] = "C++";                  // 自动添加空字符，大小为4
        const char ca4[6] = "Hello";          // 大小为6，包含空字符

    数组不允许拷贝和赋值
        int arr1[] = arr2; // 错误：不允许拷贝
        int arr6[5] = arr2; // 错误：不允许赋值

    复杂的数组声明：
        int *ptrs[10];            // ptrs是含有10个整型指针的数组
        int (*Parray)[10] = &arr;   // Parray指向一个含有10个整数的数组
        int (&arrRef)[10] = arr;    // arrRef引用一个含有10个整数的数组

    指针和数组：
        int arr[] = {0,1,2,3,4,5,6,7,8,9};
        int *p = arr;  // p指向arr的第一个元素
        int *e = &arr[9]; // e指向arr的最后一个元素
        ++p; // p指向arr[1]
        // begin end
        int *b = begin(arr); // 
        int *e = end(arr);

    c风格字符串：
        char ca[] = {'C', '+', '+'};        // 不是以空字符结尾
        char cb[] = {'C', '+', '+', '\0'};  // 以空字符结尾
        const char *cc = "C++";             // 字符串字面值，自动添加空字符
    相关的函数：
        strlen(ca); // 未定义行为，ca没有空字符
        strlen(cb); // 3
        strlen(cc); // 3
        strcmp(ca, cb); // 未定义行为，ca没有空字符
        strcmp(cb, cc); // 0，相等
        strcat(cb, cc); // 拼接，但需要确保cb有足够空间
        strcpy(cb, cc); // 复制，但需要确保cb有足够空间

    新格式（vector or string or other）与旧时代代码（c风格字符串）的接口：
        1. 可以使用c_str()成员函数获取string的C风格字符串指针
            const char *str = s.c_str();
        2. 数组和vector可以使用begin()和end()获取指向第一个元素和尾后元素的指针
            int *p = begin(arr);
            int *e = end(arr);
            vector<int> test(begin(arr), end(arr)); // 使用数组的begin和end初始化vector
    */

    // 3.27 假设txt_size 是一个无参的函数，返回值为int，请回答下面哪个定义是非法的
    {
        int txt_size(); 

        unsigned buf_size = 1024;
        //int ia1[buf_size]; //buf_size是一个变量，无法在编译期间就知道该值
        constexpr unsigned buf_size_new = 1024;
        int ia1[buf_size_new];
        int ia2[4 * 7 - 14];
        // int ia3[txt_size()]; 与ia1同理，数组无法以一个不确定的值进行初始化
        //char st[11] = "fundamental"; //需要多一位空格位
        char st[12] = "fundamental";
    }

    // 3.28 下列数组中元素的值是什么
    {
        // string sa[10];
        // int ia[10];
        // int main() {
        //     string sa2[10];
        //     int ia2[10];
        // }

        // 解答：sa 和 sa2 都是空字符串，ia 是 0，ia2 是未定义的（局部内置数组不初始化）
        // 但实际运行中 ia2 的值不确定，取决于栈上残留数据
    }

    // 3.29 相对于vector来说，数组有什么缺点？
    // 数组大小固定，不能动态增长；没有拷贝和赋值操作；容易越界；不支持迭代器；类型不安全


    // 3.30 指出下面代码中的索引错误
    {
        constexpr size_t array_size = 10;
        int ia[array_size];
        // for (size_t ix = 1; ix <= array_size; ++ix)
        //     ia[ix] = ix;
        // 错误：当 ix == array_size 时，ia[ix] 越界，有效索引范围是 0~9
    }

    //3.31 编写程序，定义一个含有10个int的数组，令每个元素的值就是其下标值
    {
        constexpr size_t array_size = 10;
        int ia[array_size];
        for (size_t ix = 0; ix < array_size; ++ix)
            ia[ix] = ix;
    }

    // 3.32 将上一题创建的数组ia拷贝给另一个数组ib，然后使用vector实现同样的功能
    {
        constexpr size_t array_size = 10;
        int ia[array_size];
        for (size_t ix = 0; ix < array_size; ++ix)
            ia[ix] = ix;

        int ib[array_size];
        for (size_t ix = 0; ix < array_size; ++ix)
            ib[ix] = ia[ix];

        // 使用vector实现同样的功能
        std::vector<int> va;
        for (int i = 0; i < 10; ++i)
            va.push_back(i);
        std::vector<int> vb(va);
    }

    // 3.33 如果不初始化scores会发生什么？
    {
        unsigned scores[11] = {}; // 初始化为0，否则未定义行为
        unsigned grade;
        while (std::cin >> grade)
            if (grade <= 100)
                ++scores[grade / 10];

        // scores不初始化，无法保证里面的元素为0，得到的结果是未知的（未定义行为）
    }

    // 3.34 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？

    {
        int num[10] = {};
        int *p1 = num, *p2 = num + 5;
        p1 += p2 - p1;
        // 将p1移动到p2的位置，即p1 = p2
    }

    // 3.35 使用指针将数组置零  
    {  
        int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  
        for (int *p = arr; p != arr + 10; ++p)  
            *p = 0;  
    }

    // 3.36 编写一段程序比较数组是否相等，再编写一段程序比较vector是否相等。
    {
        int arr1[] = {1, 2, 3, 4, 5};
        int arr2[] = {1, 2, 3, 4, 5};
        bool equal = true;
        for (size_t i = 0; i < 5; ++i)
            if (arr1[i] != arr2[i])
            {
                equal = false;
                break;
            };
        cout << (equal ? "数组相等" : "数组不相等") << endl;

        // 使用指针比较数组
        int *p1 = begin(arr1), *p2 = begin(arr2);
        while (p1 != end(arr1) && p2 != end(arr2))
            if (*p1++ != *p2++)
            {
                equal = false;
                break;
            };

        // vector
        vector<int> v1 = {1, 2, 3, 4, 5};
        vector<int> v2 = {1, 2, 3, 4, 5};
        bool vec_equal = true;
        if (v1.size() != v2.size())
            vec_equal = false;
        else
            for (size_t i = 0; i < v1.size(); ++i)
            {
                if (v1[i] != v2[i]) {
                    vec_equal = false;
                    break;
                }
            }
        cout << (vec_equal ? "v1 == v2" : "v1 != v2") << endl;
    }

    // 3.37 下面的程序含义，输出的结果是什么
    {
        const char ca[] = {'h', 'e', 'l', 'l', 'o'};
        const char *cp = ca;
        while (*cp) 
        {
            cout << *cp << endl;
            ++cp;
        }
        // 输出结果：ca数组没有以空字符结尾，while循环会继续读取内存直到遇到'\0'，导致输出不确定的字符
    }

    // 3.38 两个指针相加是非法的，因为结果没有意义，指针相减才有意义（表示两个指针之间的距离），为什么相加没有意义
    // 两个指针相加的结果没有实际意义，因为指针存储的是内存地址，相加得到的新地址不指向任何有效的对象或数组元素，
    // 而指针相减可以得到同一数组中两个元素之间的偏移量。

    //3.39 比较两个string对象。再编写一个程序，比较两个C风格字符串的内容
    {
        string s1 = "hello", s2 = "world";
        if (s1 == s2) cout << "s1 == s2" << endl;
        else if (s1 < s2) cout << "s1 < s2" << endl;
        else cout << "s1 > s2" << endl;

        const char ca1[] = "hello", ca2[] = "world";
        if (strcmp(ca1, ca2) == 0)
            cout << "ca1 == ca2" << endl;
        else if (strcmp(ca1, ca2) < 0)
            cout << "ca1 < ca2" << endl;
        else
            cout << "ca1 > ca2" << endl;
    }

    // 3.40 定义两个字符串数组，并使用字符串字面值初始化，接着定义一个字符数组存放数组连接后的结果。使用strcpy和strcat将前两个数组的内容拷贝到第三个数组中
    {
        const char ca1[] = "Hello, ";
        const char ca2[] = "world!";
        char result[50]; // 确保足够大以存放连接后的字符串
        strcpy(result, ca1); // 复制ca1到result
        strcat(result, ca2); // 将ca2连接到result后面
        cout << result << endl; // 输出结果: Hello, world!
    }


    // 3.41 使用整形数组初始化一个vector对象
    {
        int arr[] = {1, 2, 3, 4, 5};
        vector<int> v(begin(arr), end(arr)); // 使用数组的begin和end初始化vector
    }

    //3.42 将含有整形元素的vector对象拷贝给一个整形数组
    {
        vector<int> v = {1, 2, 3, 4, 5};
        int arr[5];
        for (size_t i = 0; i < v.size(); ++i)
            arr[i] = v[i];
    }


    //---------------------------------------------3.6 多维数组-------------------------------------------------------

    /*
    // 多维数组的定义和初始化
    int arr[3][4]; // 定义一个3行4列的二维数组

    // 多维数组的访问
    arr[0][0] = 1; // 访问第一行第一列
    arr[2][3] = 10; // 访问第三行第四列

    // 使用for循环访问多维数组
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //指针和多维数组
    int (*p)[4] = arr; // p是一个指向含有4个整数的数组的指针
    p[0][0] = 1; // 通过指针访问多维数组元素

    // auto与decltype在多维数组中的使用
    auto p1 = arr; // p1的类型是 int (*)[4]
    decltype(arr) p2; // p2的类型也是 int [3][4]
    // for循环
    for (auto &row : arr) {
        for (auto &elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    */

    // 3.43 编写三个版本来输出ia的元素
    // 使用范围for语句管理迭代过程，不适用auto和decltype
    {
        int ia[3][4] = {0};
        for (int (&row)[4] : ia) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
    //使用普通的for，但是要使用下标运算符
    {
        int ia[3][4] = {0};
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 4; ++j) {
                cout << ia[i][j] << " ";
            }
            cout << endl;
        }
    }
    //使用普通的for，但是要使用指针运算
    {
        int ia[3][4] = { 0 };
        for (int (*p)[4] = ia; p != ia + 3; ++p) {
            for (int* q = *p; q != *p + 4; ++q) {
                cout << *q << " ";
            }
            cout << endl;
        }
    }

    //3.44 使用类型别名来代替3.43中的复杂类型
    {
        using Row = int[4];
        int ia[3][4] = {0};
        for (Row &row : ia) {
            for (int elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

    // 3.45 使用auto来简化3.44中的循环控制变量的类型
    {
        int ia[3][4] = {0};
        for (auto &row : ia) {
            for (auto elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }

     // 3.46 使用decltype来简化3.44中的循环控制变量的类型
    {
        int ia[3][4] = {0};
        for (auto &row : ia)
        {
            for (decltype(*row) elem : row)
            {
                cout << elem << " ";
            }
        }
    }


}