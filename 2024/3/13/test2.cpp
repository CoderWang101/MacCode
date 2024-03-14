#include <iostream>
#include <stdexcept>

class Date
{
private:
    int year;
    int month;
    int day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d)
    {
        if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        {
            throw std::invalid_argument("Invalid date");
        }
    }

    bool operator<(const Date &other) const
    {
        if (year != other.year)
            return year < other.year;
        if (month != other.month)
            return month < other.month;
        return day < other.day;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        os << date.year << "-" << date.month << "-" << date.day;
        return os;
    }
};
//模版
template <class T>
bool Less(T left, T right)
{
    return *left < *right;
}
//特化
template <>
bool Less<Date *>(Date *left, Date *right)
{
    return *left < *right;
}
//重载
bool Less(Date *left, Date *right)
{
    return *left < *right;
}


int main()
{
    Date date1(2024, 3, 14);
    Date date2(2024, 3, 15);
    Date date3(2024, 3, 16);

    std::cout << "date1 < date2: " << Less(&date1, &date2) << std::endl;
    std::cout << "date2 < date3: " << Less(&date2, &date3) << std::endl;

    return 0;
}
// #include <iostream>
// #include <ctime>

// class Date
// {
// private:
//     int year;
//     int month;
//     int day;

// public:
//     // 验证输入的日期参数，如果无效则抛出异常
//     Date(int y, int m, int d) : year(y), month(m), day(d)
//     {
//         if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
//         {
//             throw std::invalid_argument("Invalid date");
//         }
//     }

//     // 定义比较操作符 <
//     bool operator<(const Date &other) const
//     {
//         if (year != other.year)
//             return year < other.year;
//         if (month != other.month)
//             return month < other.month;
//         return day < other.day;
//     }

//     // 友元函数用于输出日期对象
//     friend std::ostream &operator<<(std::ostream &os, const Date &date)
//     {
//         os << date.year << "-" << date.month << "-" << date.day;
//         return os;
//     }
// };

// // 模板函数 Less 的特化版本，用于比较指向 Date 对象的指针
// template <>
// bool Less<Date *>(Date *left, Date *right)
// {
//     return *left < *right; // 比较左右指针所指向的 Date 对象
// }

// // 模板函数 Less 的重载版本，用于比较 Date 对象的指针
// bool Less(Date *left, Date *right)
// {
//     return *left < *right; // 比较左右指针所指向的 Date 对象
// }

// int main()
// {
//     // 创建几个 Date 对象
//     Date date1(2024, 3, 14);
//     Date date2(2024, 3, 15);
//     Date date3(2024, 3, 16);

//     // 使用模板函数 Less 进行比较
//     std::cout << "date1 < date2: " << Less(&date1, &date2) << std::endl;
//     std::cout << "date2 < date3: " << Less(&date2, &date3) << std::endl;

//     return 0;
// }

// #include <iostream>
// #include <ctime>

// class Date {
// private:
//     int year;
//     int month;
//     int day;

// public:
//     Date(int y, int m, int d) : year(y), month(m), day(d) {}

//     // 定义比较操作符 <
//     bool operator<(const Date& other) const {
//         if (year != other.year)
//             return year < other.year;
//         if (month != other.month)
//             return month < other.month;
//         return day < other.day;
//     }

//     // 友元函数用于输出日期对象
//     friend std::ostream& operator<<(std::ostream& os, const Date& date) {
//         os << date.year << "-" << date.month << "-" << date.day;
//         return os;
//     }
// };

// // 模板函数 Less 的特化版本，用于比较指向 Date 对象的指针
// template<>
// bool Less<Date*>(Date* left, Date* right) {
//     return *left < *right; // 比较左右指针所指向的 Date 对象
// }

// // 模板函数 Less 的重载版本，用于比较 Date 对象的指针
// bool Less(Date* left, Date* right) {
//     return *left < *right; // 比较左右指针所指向的 Date 对象
// }

// int main() {
//     // 创建几个 Date 对象
//     Date date1(2024, 3, 14);
//     Date date2(2024, 3, 15);
//     Date date3(2024, 3, 16);

//     // 使用模板函数 Less 进行比较
//     std::cout << "date1 < date2: " << Less(&date1, &date2) << std::endl;
//     std::cout << "date2 < date3: " << Less(&date2, &date3) << std::endl;

//     return 0;
// }
// class Date
// {
// private:
//     int year;
//     int month;
//     int day;

// public:
//     Date(int y, int m, int d) : year(y), month(m), day(d) {}

//     // 定义比较操作符 <
//     bool operator<(const Date &other) const
//     {
//         if (year != other.year)
//             return year < other.year;
//         if (month != other.month)
//             return month < other.month;
//         return day < other.day;
//     }

//     // 友元函数用于输出日期对象
//     friend std::ostream &operator<<(std::ostream &os, const Date &date)
//     {
//         os << date.year << "-" << date.month << "-" << date.day;
//         return os;
//     }
// };

// // 模板函数 Less 的特化版本，用于比较指向 Date 对象的指针
// template <>
// bool Less<Date *>(Date *left, Date *right)
// {
//     return *left < *right; // 比较左右指针所指向的 Date 对象
// }

// int main()
// {
//     // 创建几个 Date 对象
//     Date date1(2024, 3, 14);
//     Date date2(2024, 3, 15);
//     Date date3(2024, 3, 16);

//     // 使用模板函数 Less 进行比较
//     std::cout << "date1 < date2: " << Less(&date1, &date2) << std::endl;
//     std::cout << "date2 < date3: " << Less(&date2, &date3) << std::endl;

//     return 0;
// }

// template <typename T, size_t N=10> //N默认为2
// void myFunction(T value)
// {
//     for (size_t i = 0; i < value; ++i)
//     {
//         std::cout << N << std::endl;
//     }
// }

// int main()
// {
//     int x=1 ,y=2;
//     myFunction<int,1+3>('A');

//     return 0;
// }
