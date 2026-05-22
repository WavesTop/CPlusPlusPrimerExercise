#include "helper.h"
#include <iostream>
#include <unordered_map>

class Sales_data_new {
    public:
        Sales_data_new() = default;
        Sales_data_new(std::string bookNo, std::string bookName, double price, int quantity) 
        : bookNo(bookNo), bookName(bookName), price(price), quantity(quantity) 
        {
            std::cout << "Sales_data_new constructor" << std::endl;
        }
        ~Sales_data_new()
        {
            std::cout << "Sales_data_new destructor" << std::endl;
        }

        friend std::istream& operator>>(std::istream& is, Sales_data_new& item)
        {
            is >> item.bookNo >> item.bookName >> item.price >> item.quantity;
            return is;
        }
        friend std::ostream& operator<<(std::ostream& os, const Sales_data_new& item)
        {
            os << item.bookNo << " " << item.bookName << " " << item.price << " " << item.quantity;
            return os;
        }
        Sales_data_new& operator+=(const Sales_data_new &rhs) 
        {
            std::cout << "Sales_data_new operator+=" << std::endl;
            quantity += rhs.quantity;
            return *this;
        }

        void setBookNo(std::string bookNo) 
        { 
            this->bookNo = bookNo; 
            std::cout << "Sales_data_new setBookNo" << std::endl;
        }
        void setBookName(std::string bookName) 
        { 
            this->bookName = bookName; 
            std::cout << "Sales_data_new setBookName" << std::endl;
        }
        void setPrice(double price) 
        { 
            this->price = price; 
            std::cout << "Sales_data_new setPrice" << std::endl;
        }
        void setQuantity(int quantity) 
        { 
            this->quantity = quantity; 
            std::cout << "Sales_data_new setQuantity" << std::endl;
        }

        std::string getBookNo() const 
        { 
            std::cout << "Sales_data_new getBookNo" << std::endl;
            return bookNo; 
        }
        std::string getBookName() const 
        { 
            std::cout << "Sales_data_new getBookName" << std::endl;
            return bookName; 
        }
        double getPrice() const 
        { 
            std::cout << "Sales_data_new getPrice" << std::endl;
            return price; 
        }
        int getQuantity() const 
        { 
            std::cout << "Sales_data_new getQuantity" << std::endl;
            return quantity; 
        }
        std::string getIsbn() const 
        { 
            std::cout << "Sales_data_new isbn" << std::endl;
            return bookNo; 
        }
        double getAvgPrice() const 
        { 
            std::cout << "Sales_data_new avg_price" << std::endl;
            return price / quantity; 
        }
        
private:
        std::string bookNo;
        std::string bookName;
        double price = 0.0;
        int quantity = 0;
};

Sales_data_new operator+(const Sales_data_new& lhs, const Sales_data_new& rhs)
{
    Sales_data_new sum = lhs;
    sum += rhs;
    return sum;
}

void chapter2::run()
{
    //---------------------------------------------2.1 基本内置类型-------------------------------------------------------
        /*
        C++基本数据类型：
            - 算术类型（arithmetic type）
                - 布尔型（bool）
                - 字符型（char）
                    - 扩展字符类型（wchar_t, char16_t, char32_t）
                    - 有符号、无符号字符类型（signed char, unsigned char）
                - 浮点类型
                    - 单精度（float）
                    - 双精度（double）
                    - 扩展精度（long double）
                - 带符号类型（signed）
                    - 短整形（short）
                    - 整形（int）
                    - 长整形（long）
                    - 长长整形（long long）
                - 无符号类型（unsigned）
                    - 无符号短整形（unsigned short）
                    - 无符号整形（unsigned int）
                    - 无符号长整形（unsigned long）
                    - 无符号长长整形（unsigned long long）
            - 空类型（void）
        算术类型分为整数类型（integer type, 包含字符和布尔类型）和浮点类型（floating-point type）
        */

        // 2.1
        /*
        1. int, long, long long, short 的区别是什么？
            - int：通常是编译器默认的整数类型，大小至少为16位，通常为32位
            - long：大小至少为32位，通常为64位
            - long long：大小至少为64位，通常为64位
            - short：大小至少为16位，通常为16位
        2. 无符号和有符号类型的区别是什么？
            - 有符号类型（signed）可以表示正数、负数和零，而无符号类型（unsigned）只能表示非负数（正数和零）。
            - 无符号类型的范围通常是从0到2^n-1，而有符号类型的范围通常是从-2^(n-1)到2^(n-1)-1，其中n是该类型的位数。
        3. float 和 double 的区别是什么？
            - float：单精度浮点数，通常占用4字节（32位），有效数字约为6-7位十进制数，占用空间小，速度快，适合一般计算
            - double：双精度浮点数，通常占用8字节（64位），有效数字约为15-16位十进制数，高精度计算，科学计算、财务计算等
        */

        // 2.2
        /*
        计算按揭贷贷款时，对于利率、本金、付款分别应该采用什么数据类型？
            - 利率：通常使用浮点类型（float 或 double），因为利率可能包含小数部分

            - 本金：通常使用整数类型（int 或 long），因为本金通常是一个整数金额
            - 付款：通常使用整数类型（int 或 long），因为付款通常是一个整数金额
                - 浮点数无法精确表示十进制，比如0.1(double) + 0.2(double) = 0.30000000000000004，可能导致计算结果不准确
                - 可以12.34 元 存储为 1234 分，使用整数类型进行计算
        */

        /*
        各种类型之间的转换、计算规则：
            - 整数提升（Integer Promotion）：在表达式中，较小的整数类型（如 char、short）会被提升为 int 或 unsigned int，以便进行计算，位数一样有无符号则最终为无符号类型。
            - 算术转换（Arithmetic Conversion）：当不同类型的算术操作数参与运算时，编译器会将它们转换为一个共同的类型，以确保运算的正确性。通常会按照以下规则进行转换：
                1. 如果其中一个操作数是 long double，则另一个操作数也会被转换为 long double。
                2. 否则，如果其中一个操作数是 double，则另一个操作数也会被转换为 double。
                3. 否则，如果其中一个操作数是 float，则另一个操作数也会被转换为 float。
                4. 否则，如果其中一个操作数是 unsigned long long，则另一个操作数也会被转换为 unsigned long long。
                5. 否则，如果其中一个操作数是 long long，则另一个操作数也会被转换为 long long。
                6. 否则，如果其中一个操作数是 unsigned long，则另一个操作数也会被转换为 unsigned long。
                7. 否则，如果其中一个操作数是 long，则另一个操作数也会被转换为 long。
                8. 否则，如果其中一个操作数是 unsigned int，则另一个操作数也会被转换为 unsigned int。
                9. 否则，两个操作数都被转换为 int。
                - 总结：浮点 > 有符号整数 > 无符号整数
        */

        //2.3
    {
        unsigned u = 10, u2 = 42;
        std::cout << u2 - u << std::endl; // 32
        std::cout << u - u2 << std::endl; // 4294967264 (unsigned underflow)

        int i = 10, i2 = 42;
        std::cout << i2 - i << std::endl; // 32
        std::cout << i - i2 << std::endl; // -32
        std::cout << i - u << std::endl; // 4294967286 (unsigned underflow)
        std::cout << u - i << std::endl; // 4294967286 (unsigned underflow)
    }
    //2.4 同上

    /*
    字面值常量，直接就能得知其内容的常量，比如 42、3.14、"hello" 等等
        - 整形和浮点
        - 字符和字符串
        - 转义序列 （如 '\n'、'\t' 等）
        - 指定字面值
            - 前缀 u8、u、U、L 分别表示 UTF-8 字符串字面值、UTF-16 字符串字面值、UTF-32 字符串字面值和宽字符串字面值
            - 后缀 f、l 分别表示 float 和 long double 字面值
        - 布尔和空指针
            - true、false 是布尔字面值常量
            - nullptr 是空指针字面值常量
    */

    // 2.5
    /*
    1. 第一组
    'a': char 类型的字符字面值常量，表示字符 'a'，通常占用1字节
    L'a': wchar_t 类型的字符字面值常量，表示宽字符 'a'，通常占用2或4字节
    "a" : const char* 类型的字符串字面值常量，表示字符串 "a"，占用2字节（'a' 和 '\0'）
    L"a": const wchar_t* 类型的宽字符串字面值常量，表示宽字符串 "a"，占用4字节（'a' 和 L'\0'）
    2. 第二组
    10: int 类型的整数字面值常量，表示整数 10，通常占用4字节
    10u: unsigned int 类型的无符号整数字面值常量，表示整数 10，通常占用4字节
    10L: long 类型的长整数字面值常量，表示整数 10，通常占用4或8字节
    10UL: unsigned long 类型的无符号长整数字面值常量，表示整数 10，通常占用4或8字节
    012: int 类型的八进制整数字面值常量，表示整数 10，通常占用4字节
    0xC: int 类型的十六进制整数字面值常量，表示整数 12，通常占用4字节
    3. 第三组
    3.14: double 类型的浮点字面值常量，表示浮点数 3.14，通常占用8字节
    3.14f: float 类型的单精度浮点字面值常量，表示浮点数 3.14，通常占用4字节
    3.14L: long double 类型的扩展精度浮点字面值常量，表示浮点数 3.14，通常占用8或16字节
    4. 第四组
    10: int 类型的整数字面值常量，表示整数 10，通常占用4字节
    10u: unsigned int 类型的无符号整数字面值常量，表示整数 10，通常占用4字节
    10.: double 类型的浮点字面值常量，表示浮点数 10.0，通常占用8字节
    10e-2: double 类型的浮点字面值常量，表示浮点数 0.1，通常占用8字节
    */

    //2.6 下面两组定义是否有区别
    int month = 9, day = 7;
    // int month = 09, day = 07; // 这种写法在某些编译器中可能被视为八进制数

    //2.7 下面字面值的含义，和各自的数据类型
    /*
    "Who goes with F\145rgus?\012" : const char* 类型的字符串字面值常量，表示字符串 "Who goes with Fergus?\n"，占用24字节（23个字符和一个终止符 '\0'）
    3.14e1L: long double 类型的扩展精度浮点字面值常量，表示浮点数 314.0，通常占用8或16字节
    1024f: float 类型的单精度浮点字面值常量，表示浮点数 1024.0，通常占用4字节
    3.14L: long double 类型的扩展精度浮点字面值常量，表示浮点数 3.14，通常占用8或16字节
    */

    //2.8 使用转义序列编写一段程序，要求先输出2M,然后转到输出新的一行。修改程序使其先输出2，然后输出制表符，再输出M，最后转到新的一行。
    std::cout << "2M\n";
    std::cout << "2\tM\n";

    //---------------------------------------------2.2 变量-------------------------------------------------------

        /*
        定义：类型说明符 + 变量名
        初始化：创建变量的同时为其赋予一个初始值。如果没有显式初始化，内置类型的变量会有一个未定义的值（垃圾值），而类类型的变量会调用默认构造函数进行初始化。
        */

        //2.9 下面的定义是否合法？
        // std::cin >> int input_value; // 不合法，变量定义和输入操作不能放在同一行
        // int i = { 3.14 }; // 不合法，列表初始化禁止窄化（narrowing）转换,浮点数不能直接初始化为整数
        // inti = 3.14; // 合法，允许隐式转换，i 的值将是 3
        // double salary = wage = 9999.99; // 是否合法，取决于 wage 是否已经声明过：ruguo wage 已经声明过，则合法；如果 wage 没有声明过，则不合法

        //2.10 下列变量的初值是什么
        /*
        std::string global_str; // 空字符串 ""
        int global_int; // 0，全局变量属于静态存储区，C++ 规定静态存储期对象自动零初始化
        int main()
        {
            int local_int; // 未定义（垃圾值）
            std::string local_str; // string是类，有默认的构造函数空字符串 ""
        }
        */

        /*
        声明和定义的区别：
            - 声明（Declaration）：告诉编译器某个名字（变量、函数、类等）的存在和类型，但不分配内存或提供实现。例如：extern int x; 是一个变量的声明，告诉编译器有一个名为 x 的整数变量，但没有定义它。
            - 定义（Definition）：不仅告诉编译器名字的存在和类型，还分配内存或提供实现。例如：int x; 是一个变量的定义，告诉编译器有一个名为 x 的整数变量，并且分配内存来存储它。
            - 变量能且只能定义一次，但可以声明多次。函数和类也是如此。
        */
        //2.11 下面的语句是声明还是定义
        /*
        extern int ix = 1024; // 定义，extern 关键字在这里被忽略，因为它有一个初始值
        int iy; // 定义，虽然没有初始值，但它是一个定义
        extern int iz; // 声明，没有定义，因为没有初始值
        */

        /*
        C++ 标识符的命名规则：
            - 只能包含字母、数字和下划线，且不能以数字开头
            - 不能使用 C++ 关键字作为标识符
            - 区分大小写
            - 不同的标识符之间必须唯一
        */

        // 2.12 下面的标识符是否合法？
        /*
        int double = 3.14; // 不合法，double 是 C++ 关键字
        int _; // 合法，但不推荐，虽然 _ 是一个合法的标识
        int catch-22; // 不合法，标识符不能包含连字符
        int 1_or_2 = 1; // 不合法，标识符不能以数字开头
        double Double = 3.14; // 合法，Double 是一个合法的标识符，虽然不推荐使用与关键字相似的名字
        */

        /*
        名字的作用域
            - 局部作用域（Local Scope）：在函数、代码块或类的内部定义的名字只能在其所在的作用域内访问。
            - 全局作用域（Global Scope）：在所有函数和类的外部定义的名字可以在整个程序中访问。
            - 命名空间作用域（Namespace Scope）：在命名空间内部定义的名字只能在该命名空间内访问，除非使用 using 声明或限定符。
        */

        //2.13 下面程序中j的值
        /*
        int i = 42;
        int main()
        {
            int i = 100; //在 C/C++ 中，允许局部变量的名字和全局变量相同，这种情况称为 变量遮蔽（shadowing）。不会重复定义
            int j = i;
        }
        j 的值是 100，因为在 main 函数内部定义了一个局部变量 i，它遮蔽了全局变量 i，所以 j 初始化时使用的是局部变量 i 的值。
        */

        //2.14 下面程序合法吗？，如果合法输出什么
    {
        int i = 100, sum = 0;
        for (int i = 0; i != 10; ++i)
        {
            sum += i;
        }
        std::cout << i << " " << sum << std::endl;
        //该程序合法，输出结果是 "100 45"。
    }


    //---------------------------------------------2.3 复合类型-------------------------------------------------------

        /*
        引用、指针的定义和使用：
            - 引用（Reference）：引用是一个别名，必须在定义时初始化，并且不能改变引用的对象。使用 & 符号定义引用，例如：int& ref = x; 表示 ref 是 x 的一个引用。
            - 指针（Pointer）：指针是一个变量，存储另一个变量的地址，可以在程序运行时改变指针指向的对象。使用 * 符号定义指针，例如：int* ptr = &x; 表示 ptr 是一个指向 x 的指针。
                - 获取对象的地址：使用 & 取地址符，例如：&x 获取变量 x 的地址。
                - 访问指针指向的对象：使用 * 解引用符，例如：*ptr 获取 ptr 指向的变量的值。
                - 空指针：指针可以被赋值为 nullptr，表示它不指向任何对象。
                - void* 指针：void* 是一种特殊的指针类型，可以指向任何类型的对象，但不能直接解引用，必须先转换为具体类型的指针。

        引用和指针的区别：
            - 引用必须在定义时初始化，而指针可以在任何时候被赋值。
            - 引用一旦绑定到一个对象，就不能再绑定到另一个对象，而指针可以随时改变指向。
            - 引用的对象的值改变时，引用的值也会改变。

        引用和指针的复合类型：
            - 定义多个变量：int* p1, p2; // p1 是一个指针，p2 是一个整数变量, 所以最好将*与&放在变量名旁边以避免混淆
            - 引用的引用：C++ 不允许引用的引用。
            - 指针的指针：int *pi = &ival; int **ppi = &pi; // 可以不断累加
            - 指针的引用：
                int i = 42;
                int *p; int *&rp = p; // rp 是一个指向 int *p 的引用
                    - 离变量名最近的符号决定了类型：* 表示指针，& 表示引用。即rp 是一个引用，它引用了一个int*类型的变量p。
                    - 修改rp，等于修改了p，因为rp是p的一个引用。修改*rp，等于修改了p指向的对象，因为*rp就是p指向的对象。
        */

        // 2.15 下面定义是否合法
    {
        int ival = 1024;
        // int &rval1 = 1.01; // 不合法，引用必须绑定到一个对象，而 1.01 是一个字面值常量，不是一个对象
        int& rval2 = ival; // 合法，rval2 是 ival 的一个引用
        // int &rval3; // 不合法，引用必须在定义时初始化
    }

    // 2.16 哪些赋值是合法的，它们执行了什么样的操作
    {
        int i = 0, & r1 = i;
        double d = 0, & r2 = d;

        r2 = 3.14159; // 合法，r2 是 d 的一个引用，赋值操作将 3.14159 赋给 d
        r2 = r1; // 合法，r1 是 i 的一个引用，赋值操作将 i 的值（0）赋给 d，d 变为 0.0
        i = r2; // 合法，r2 是 d 的一个引用，赋值操作将 d 的值（0.0）赋给 i，i 变为 0
        r1 = d; // 合法，r1 是 i 的一个引用，赋值操作将 d 的值（0.0）赋给 i，i 变为 0
    }

    //2.17 执行下面的代码会输出什么结果
    {
        int i, & ri = i;
        i = 5;
        ri = 10;
        std::cout << i << " " << ri << std::endl;
        //该程序输出 "10 10"，因为 ri 是 i 的一个引用，对 ri 的赋值操作实际上是对 i 的赋值操作，所以 i 的值被更新为 10。
    }

    // 2.18 编写代码分别更改指针的值以及指针所指对象的值
    {
        int a = 10;
        int b = 20;

        int* ptr = &a; // 指针 ptr 指向 a

        std::cout << "初始状态：" << std::endl;
        std::cout << "*ptr = " << *ptr << ", ptr 指向的地址 = " << ptr << std::endl;

        // 修改指针所指对象的值
        *ptr = 15;  // 通过指针修改 a 的值
        std::cout << "修改指针指向对象后的状态：" << std::endl;
        std::cout << "a = " << a << ", *ptr = " << *ptr << std::endl;

        // 修改指针本身的值（让它指向 b）
        ptr = &b;
        std::cout << "修改指针本身后的状态：" << std::endl;
        std::cout << "ptr 指向的地址 = " << ptr << ", *ptr = " << *ptr << std::endl;
    }

    // 2.19 说明指针和引用的主要区别 同上

    // 2.20 下面这段代码的作用
    {
        int i = 42;
        int* p1 = &i; // p1 是一个指针，指向 i 的地址
        *p1 = *p1 * *p1; // 通过解引用操作修改 i 的值，将 i 的值更新为 i*i，即 1764
        std::cout << "修改后的 i 的值: " << i << std::endl;
    }

    // 2.21 解释下方的定义，有非法的吗？
    {
        int i = 0;

        //double* dp = &i; // 不合法，类型不匹配，不能将 int* 转换为 double*
        //int* ip = i; // 不合法，不能将 int 转换为 int*
        int *p = &i; // 合法，p 是一个指向 int 的指针，指向 i 的地址
    }

    // 2.22 假设p是一个int类型的指针，说明下列表达式的含义
    {
        int i = 0;
        // int* p = 0; // p 是一个指向 int 的指针，初始化为 nullptr，表示它不指向任何对象
        int *p = &i; // p 现在指向 i 的地址

        if (p) // 判断指针 p 是否非空（即是否指向一个有效的地址）
        {
            std::cout << "*p = " << *p << std::endl; // 如果 p 非空，输出 p 指向的整数值
        }
        else
        {
            std::cout << "p is a null pointer." << std::endl; // 如果 p 是空指针，输出提示信息
        }

        if(*p) // 判断指针 p 指向的整数值是否非零（即是否为真），注意如果 p 是空指针，解引用 *p 会导致未定义行为
        {
            std::cout << "*p = " << *p << std::endl;
        }
    }

    // 2.23 给定指针p， 你能知道它是否指向一个合法的对象吗？如果不能，为什么？如果能，怎么做？
    /*
        编译器无法知道指针是否合法，因为指针只是一个地址。但是你不知道这个地址上是否已经释放、未分配、或者是超出了作用域的局部变量。
        运行时也无法绝对判断指针是否合法，除非你自己维护状态（比如置空指针、智能指针）。
        最安全的方法是 初始化指针、避免裸指针、使用智能指针或引用。
    */

    // 2.24 下面代码中为什么p合法，但是lp非法
    {
        int i = 42;
        int* p = &i; // p 是一个指向 i 的指针，合法
        // long* lp = &i; // lp 是一个指向 long 的指针，非法，因为类型不匹配，不能将 int* 转换为 long*
    }

    // 2.25说明下列变量的类型和值
    {
        int* ip, i, & r = i; // ip 是一个指向 int 的指针，i 是一个 int 变量，r 是 i 的一个引用
    }
    {
        int i, * ip = 0; // i 是一个 int 变量，ip 是一个指向 int 的指针，初始化为 nullptr
    }
    {
        int* ip, ip2; // ip 是一个指向 int 的指针，ip2 是一个 int 变量
    }

//---------------------------------------------2.4 const 限定符-------------------------------------------------------

    /*
    const 限定符的作用：值不可以被修改

    const变量的初始化：
        - const变量必须在定义时初始化，因为它的值不能被修改。
        - 可以使用常量表达式、字面值常量或其他已初始化的const变量来初始化const变量.

    跨文件使用const变量：
        - 默认情况下，const变量具有内部链接（internal linkage），只能在定义它的文件中访问。
        - 如果需要在多个文件中访问同一个const变量，可以使用extern关键字声明它，并在一个文件中定义它。例如：
            // 在 header.h 中
            extern const int myConst; // 声明但不定义,只声明没有问题，是因为添加了extern，告诉编译器这个变量在其他地方定义了
            // 在 source.cpp 中
            const int myConst = 42; // 定义并初始化


    引用和指针的const使用：
        - const的引用：
            - const int& ref = x; 表示 ref 是一个对 int 的 const 引用，不能通过 ref 修改 x 的值，但可以修改 x 本身。
                ref = 10; // 不合法，不能通过 ref 修改 x 的值
                int &ref2 = ref; // 不合法，不能将 const 引用绑定到非 const 引用
        - const的指针：
            - 指向 const 的指针：const int* ptr; 表示 ptr 是一个指向 const int 的指针，可以修改 ptr 的值（即指向不同的地址），但不能通过 ptr 修改它指向的对象的值。


    顶层和底层const：（距离变量的远近，与变量相邻就是顶层const，否则是底层const）
        - 顶层const：指针本身是const，不能改变指针的值，即不能指向其他的地址
            - int* const ptr; // ptr 是一个 const 指针，必须在定义时初始化，指向一个 int 变量的地址，但不能改变 ptr 的值（即不能指向其他地址）
            - const int p; //此时也是一个顶层const，因为其值不能被修改
        - 底层const：指针指向的对象是const，不能通过指针修改对象的值，但可以指向其他地址
            - const int* ptr; // ptr 是一个指向 const int 的指针，可以指向一个 int 变量的地址，但不能通过 ptr 修改该变量的值

    constexpr：在 C++11 中引入的关键字，表示一个常量表达式 (在编译过程中就能得到计算结果的表达式)，可以用于定义常量、数组大小等需要编译时常量的场景。
        - constexpr所使用的类型必须是字面值类型（literal type），即算术类型、引用类型、指针类型。
            - constexpr的指针和引用必须是nullptr、0、或者存储在某个固定地址的对象（全局对象、静态对象、另一个constexpr对象、字符串字面值）。
    */

    // 2.26 下面句子哪些是合法的，哪些不合法？为什么
    {
        // const int buf;
        // buf = 1024; // 不合法，const变量必须在定义时初始化，且值不能被修改
        int cnt = 0;
        const int sz = cnt; // 合法，sz 是一个 const int 变量，在定义时被初始化为 cnt 的值（0）
        ++cnt; // 合法，cnt 是一个非 const 变量，可以被修改
        //++sz; // 不合法，sz 是一个 const 变量，不能被修改
    }

    // 2.27 下面哪些初始化是合法的
    {
        //int i = -1, & r = 0; // 不合法，引用必须绑定到一个对象，而 0 是一个字面值常量，不是一个对象
    }
    {
        //int* const p2 = &i2; // 合法，p2 是一个 const 指针，必须在定义时初始化，指向 i2 的地址，但不能改变 p2 的值（即不能指向其他地址）
    }
    {
        const int i = -1, & r = 0; // 合法，i 是一个 const int 变量，初始化为 -1；r 是一个 const int 引用，绑定到字面值常量 0 上
    }
    {
        //const int* const p3 = &i2; // 合法，p3 是一个指向 const int 的 const 指针，必须在定义时初始化，指向 i2 的地址，但不能改变 p3 的值（即不能指向其他地址），也不能通过 p3 修改 i2 的值
    }
    {
        //const int* p1 = &i2; // 合法，p1 是一个指向 const int 的指针，可以指向 i2 的地址，但不能通过 p1 修改 i2 的值
    }
    {
        //const  int& const r2; // 不合法，引用本身不能是 const，因为引用必须在定义时初始化，并且不能改变绑定的对象，所以没有意义将引用声明为 const
    }
    {
        //const int i2 = i, & r = i; // 合法，i2 是一个 const int 变量，初始化为 i 的值（-1）；r 是一个 const int 引用，绑定到 i2 上
    }

    // 2.28 说明下面定义的意思，指出不合法的地方
    {
        // int i, * const cp; // 不合法，const指针必须在定义时初始化
        // int* p1, * const p2; // 不合法，const指针必须在定义时初始化
        // const int ic, & r = ic; // 不合法，const变量必须在定义时初始化,ic没有初始化
        // const int* const p3;   // 不合法，const指针必须在定义时初始化
        const int* p; // 合法，p 是一个指向 const int 的指针，可以指向一个 const int 变量的地址，但不能通过 p 修改该变量的值。
            //但是可以 int i = 10; p = &i; // 合法，p 现在指向 i 的地址，但不能通过 p 修改 i 的值，因为 p 是一个指向 const int 的指针
    }

    // 2.29 假设已经有了2.28练习的定义的变量，下面的语句是否合法
    {
        int i = 10;
        const int ic = 10;
        int* p1 = &i;
        int* const p2 = &i;
        const int* const p3 = &ic;

        i = ic; // 合法，i 是一个 int 变量，可以被修改，ic 是一个 const int 变量，可以被读取
        // p1 = p3; // 不合法，p1 是一个指向 int 的指针，而 p3 是一个指向 const int 的 const 指针，不能将 const int* 转换为 int*
        // p1 = &ic; // 不合法，p1 是一个指向 int 的指针，而 &ic 是一个指向 const int 的地址，不能将 const int* 转换为 int*
        // p3 = &ic; // 不合法，p3 是一个 const 指针，不能改变它的值（即不能指向其他地址）
        // p2 = p1; // 不合法，p2 是一个 const 指针，不能改变它的值（即不能指向其他地址）
        // ic = *p3; // 不合法，ic 是一个 const int 变量，不能被修改，而 *p3 是一个 const int 的值，不能赋值给 ic
    }

    // 2.30 对于下面的语句，说明是顶层const还是底层const
    {
        const int v2 = 0; // v2 是一个 const int 变量，具有底层 const
        int v1 = v2;
        int* p1 = &v1, & r1 = v1;
        const int* p2 = &v2, * const p3 = &v1, & r2 = v2;
        // p2 是一个指向 const int 的指针，具有底层 const
        // p3 是一个 const 指针，具有顶层 const
        // r2 是一个 const int 引用，具有底层 const

        // 2.31 假设已经拥有了2.30的定义的变量，下面的语句是否合法
        r1 = v2; // 不合法，v2 是一个 const int 变量，不能被修改，而 r1 是一个 int 引用，试图通过 r1 修改 v2 的值是不合法的
        //p1 = p2; // 不合法，p1 是一个指向 int 的指针，而 p2 是一个指向 const int 的指针，不能将 const int* 转换为 int*
        p2 = p1; // 合法，p2 是一个指向 const int 的指针，可以指向一个 int 变量的地址，因为 const int* 可以接受 int*，但不能通过 p2 修改 p1 指向的对象的值
        //p1 = p3; // 不合法，p1 是一个指向 int 的指针，而 p3 是一个 const 指针，不能将 const int* const 转换为 int*
        //p2 = p3; // 不合法，p2 是一个指向 const int 的指针，而 p3 是一个 const 指针，不能将 const int* const 转换为 const int*
    }

    // 2.31 下面的代码是否合法，如果非法请修改
    {
        //int null = 0, * p = null; // 不合法，null 是一个 int 变量，不能直接赋值给一个指针变量 p。
        int null = 0, * p = &null; // 合法，p 是一个指向 int 的指针，指向 null 变量的地址
    }

//---------------------------------------------2.5 处理类型-------------------------------------------------------

    /*
    类型别名（Type Alias）：
        - 使用 typedef 定义类型别名，例如：typedef unsigned int uint; 表示 uint 是 unsigned int 的一个别名。
        - 使用 using 定义类型别名，例如：using uint = unsigned int; 表示 uint 是 unsigned int 的一个别名。

    auto 关键字：
        - auto 关键字用于自动类型推断，编译器会根据变量的初始化表达式来推断变量的类型。例如：auto x = 42; 表示 x 是一个 int 类型的变量，auto y = 3.14; 表示 y 是一个 double 类型的变量。
        - auto会忽略顶层const，但不会忽略底层const。例如：
            const int ci = 42;
            auto x = ci; // x 是一个 int 类型的变量，值为 42，顶层 const 被忽略
            auto& y = ci; // y 是一个 const int& 类型的变量，绑定到 ci 上，底层 const 没有被忽略
        - auto &时，auto会推断为引用类型，保持底层const的属性。例如：
            const int ci = 42;
            auto& z = ci; // z 是一个 const int& 类型的变量，绑定到 ci 上，底层 const 没有被忽略

    decltype 关键字：decltype会根据表达式类型和表达式值类别推导结果
        - 针对普通变量名：如果参数是一个普通变量名（或类成员访问），decltype 返回变量声明时的原始类型，不会因为它是左值而自动添加引用
            int i = 0;
            const int ci = 42;
            decltype(i) a = 10;   // a 的类型是 int
            decltype(ci) b = 20; // b 的类型是 const int
        - 其他表达式：对于普通表达式，decltype 会根据表达式的值类别推导：
            - lvalue（左值）  -> T&
            - xvalue（将亡值）-> T&&
            - prvalue（纯右值）-> T

            int i = 0;
            int *p = &i;

            // 1. lvalue（左值）
            decltype(*p) a = i;
            // a 的类型是 int&
            // 因为 *p 是左值表达式
            // 2. xvalue（将亡值）
            decltype(std::move(i)) b = 10;
            // b 的类型是 int&&
            // std::move(i) 是将亡值（xvalue）
            // 3. prvalue（纯右值）
            decltype(i + 1) c = 1;
            // c 的类型是 int
            // i + 1 是纯右值（prvalue）

        - 加括号会改变结果：decltype(x) 和 decltype((x)) 结果可能完全不同。
            int i = 0；
            decltype(i) a = 1;     // a 是 int
            decltype((i)) b = i;   // b 是 int&

            原因：
                i 是“变量名”，触发特殊规则；
                (i) 是“左值表达式”，因此推导为引用类型。
        - decltype会保留表达式的所有类型信息，包括顶层const和底层const。例如：
            const int ci = 42;
            decltype(ci) x; // x 是一个 const int 类型的变量，值未定义，decltype 保留了 ci 的 const 属性

    decltype和auto的区别：
        - auto 用于变量定义时的类型推断，编译器根据初始化表达式来推断变量的类型，auto会忽略顶层const，但不会忽略底层const。
        - decltype 用于查询表达式的类型，编译器根据表达式的类型来推断结果类型，decltype会保留表达式的所有类型信息，包括顶层const和底层const。

    */

    // 2.33 利用书本上本节定义的变量，判断下列语句的运行结果
    {
        int i = 0, & r = i;
        auto a = r; // a 是一个 int 类型的变量，初始化为 r 的值（0）

        const int ci = i, & cr = ci;
        auto b = ci; // b 是一个 int 类型的变量，初始化为 ci 的值（0），const 修饰符被忽略
        auto c = cr; // c 是一个 int 类型的变量，初始化为 cr 的值（0），const 修饰符被忽略
        auto d = &i; // d 是一个 int* 类型的变量，初始化为 i 的地址
        auto e = &ci; // e 是一个 const int* 类型的变量，初始化为 ci 的地址
        auto& g = ci; // g 是一个 const int& 类型的变量，绑定到 ci 上

        a = 42; // 合法，a 是一个 int 变量，可以被修改
        b = 42; // 合法，b 是一个 int 变量，可以被修改
        c = 42; // 合法，c 是一个 int 变量，可以被修改
        //d = 42; // 不合法，d 是一个 int* 变量，不能直接赋值一个整数值
        //e = 42; // 不合法，e 是一个 const int* 变量，不能直接赋值一个整数值
        //g = 42; // 不合法，g 是一个 const int& 变量，不能被修改
    }

    // 2.34 同上

    // 2.35判断下列推断的定义是什么
    {
        const int i = 42;
        auto j = i; // j 是一个 int 类型的变量，初始化为 i 的值（42），const 修饰符被忽略
        const auto& k = i; // k 是一个 const int& 类型的变量，绑定到 i 上，由于是&，const 修饰符没有被忽略。与auto &k = i 相同。
        auto* p = &i; // p 是一个 const int* 类型的变量，初始化为 i 的地址，因为 i 是一个 const int 变量，所以 p 被推断为指向 const int 的指针
        const auto j2 = i; // j2 是一个 const int 类型的变量，初始化为 i 的值（42），const 修饰符被忽略，但是手动添加了
        const auto &k2 = i; // k2 是一个 const int& 类型的变量，绑定到 i 上，由于是&，const修饰符没有被忽略。与 auto& k2 = i 相同。
    }

    // 2.36 写出每个变量的类型以及程序结束时各自的值
    {
        int a = 3, b = 4;
        decltype(a) c = a; // c 是一个 int 类型的变量，初始化为 a 的值（3）
        decltype((b)) d = b; // d 是一个 int& 类型的变量，绑定到 b 上，由于是(b)，所以 d 被推导为引用类型
        ++c; // c 是一个 int 类型的变量，可以被修改
        ++d; // d 是一个 int& 类型的变量，可以被修改
        std::cout << "c = " << c << std::endl; // 输出 c 的值（4）
        std::cout << "d = " << d << std::endl; // 输出 d 的值（5）
        std::cout << "a = " << a << std::endl; // 输出 a 的值（3）
    }

    // 2.37 赋值表达式会导致，最终的类型是左值。指出下面代码中每一个变量的类型和值
    {
        int a = 3, b = 4;
        decltype(a) c = a; // c 是一个 int 类型的变量，初始化为 a 的值（3）
        decltype(a = b) d = a; // a=b 是一个赋值表达式，最终的类型是左值，所以 d 是一个 int& 类型的变量，绑定到 a 上
    }

    // 2.38 说明decltype和auto的区别，并举例子说明类型是一样的和不一样的情况
    {
        /*
        auto 默认去掉顶层 const 和引用
        decltype 完全保留原类型，包括引用和 const
        */
        int x = 10;
        const int cx = 20;
        int& rx = x;

        auto a = x;      // int
        decltype(x) b;   // int
        auto c = cx;     // int （忽略顶层 const）
        //decltype(cx) d;  // const int
        auto e = rx;     // int （引用被忽略）
        //decltype(rx) f;  // int& （保留引用）

        /*
        *p 是左值：
        auto → 去掉引用 → int
        decltype(*p) → 保留左值引用 → int&
        */
        int y = 5;
        int* p = &y;
        auto v1 = *p;        // int  （引用被剥离）
        decltype(*p) v2 = y; // int& （*p 是左值，decltype保留引用）

        /* 加括号
        auto 总是得到变量的“去除引用和顶层 const 后类型”
        decltype 会保留表达式的值类别 → 左值返回引用
        */
        int z = 1;
        auto m = (z);        // int （auto 不考虑括号）
        decltype((z)) n = z; // int& （括号形成左值表达式，decltype返回引用）

        /* 将亡值
        auto → 转换为右值 → int
        decltype(std::move(t)) → 保持右值引用 → int&&
        */
        int t = 42;
        auto x1 = std::move(t);       // int
        //decltype(std::move(t)) x2 = t; // int&&
    }

//---------------------------------------------2.6 自定义数据结构-------------------------------------------------------

    /*
    初步了解结构体 struct 与类 class 的使用
    */

    // 2.39 查看下面程序的运行结果

    {
        //struct Foo {}
        // 需要;结尾，否则会报错
    }

    // 2.40 见文件顶部定义的类 Sales_data_new

    // 2.41
    {
        Sales_data_new item1;
        std::cin >> item1;
        std::cout << item1 << std::endl;

        Sales_data_new item2;
        std::cin >> item2;
        std::cout << item2 << std::endl;

        if(item1.getIsbn() == item2.getIsbn())
        {
            Sales_data_new total = item1 + item2;
            std::cout << total << std::endl;
        }
        else
        {
            std::cout << "the two items have different ISBNs, cannot be added." << std::endl;
        }

        std::unordered_map<std::string, Sales_data_new> salesMap;
        Sales_data_new item3;
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
            salesMap[item3.getIsbn()] += item3;
        }
        for (const auto &pair : salesMap)
        {
            std::cout << "the total for ISBN " << pair.first << " is: " << pair.second << std::endl;
        }
    }
}