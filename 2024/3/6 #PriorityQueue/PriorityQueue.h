#pragma once
#include <functional>
#include <queue>
#include <iostream>
using namespace std;
#include <vector>

namespace wzf
{
    template <class T>
    struct less
    {
        bool operator()(const T &x, const T &y)
        {
            return x < y;
        }
    };

    template <class T>
    struct greater
    {
        bool operator()(const T &x, const T &y)
        {
            return x > y;
        }
    };

    template <class T, class Container = std::vector<T>, class Comapre = less<T> > // 默认为大堆
    class priority_queue
    { 
    public:
        // priority_queue();
        // ~priority_queue();

        Comapre com; // 使用仿函数

        void adjust_up(int child)
        {
            size_t parent = (child - 1) / 2;
            while (child > 0)
            {
                // if (_con[child]>_con[parent])
                if (com(_con[parent], _con[child]))
                {
                    swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;
                }
                else
                    break;
            }
        }

        void adjust_down(int parent)
        {
            size_t child = parent * 2 + 1; // 左(从0开始)
            while (child < _con.size())
            {
                // if (_con[child]<_con[child+1])
                if (com(_con[child], _con[child + 1]) && child + 1 < _con.size()) // child+1<_con.size()防止越界
                {
                    ++child;
                }

                if (com(_con[parent], _con[child]))
                {
                    swap(_con[parent], _con[child]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                    break;
            }
        }

        void push(const T &x)
        {
            _con.push_back(x);
            adjust_up(_con.size() - 1); // 向上调整
        }

        void pop()
        {
            // top与最后一个元素交换
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();
            adjust_down(0);
        }

        const T &top()
        {
            return _con[0];
        }

        size_t size()
        {
            return _con.size();
        }

        bool empty()
        {
            return _con.empty();
        }

    private:
        Container _con;
    };

    void test_priority_queue()
    {
        // priority_queue<int,vector<int>,greater<int> > pq;
        priority_queue<int> pq;
        pq.push(9);
        pq.push(2);
        pq.push(1);
        pq.push(0);
        pq.push(5);
        pq.push(7);

        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }

    class Date
    {
    public:
        Date(int year = 1900, int month = 1, int day = 1)
            : _year(year), _month(month), _day(day)
        {
        }
        bool operator<(const Date &d) const
        {
            return (_year < d._year) ||
                   (_year == d._year && _month < d._month) ||
                   (_year == d._year && _month == d._month && _day < d._day);
        }
        bool operator>(const Date &d) const
        {
            return (_year > d._year) ||
                   (_year == d._year && _month > d._month) ||
                   (_year == d._year && _month == d._month && _day > d._day);
        }
        friend ostream &operator<<(ostream &_cout, const Date &d)
        {
            _cout << d._year << "-" << d._month << "-" << d._day;
            return _cout;
        }

    private:
        int _year;
        int _month;
        int _day;
    };

    void TestPriorityQueue()
    {
        // 大堆，需要用户在自定义类型中提供<的重载 
        priority_queue<Date> q1;

        q1.push(Date(2019, 10, 29)); 
        q1.push(Date(2018, 11, 28)); 
        q1.push(Date(2018, 10, 28)); 
        q1.push(Date(2018, 10, 30));

        cout << q1.top() << endl;

        // 如果要创建小堆，需要用户提供>的重载 
        priority_queue<Date, vector<Date>, greater<Date> > q2; 

        q2.push(Date(2018, 10, 29));
        q2.push(Date(2018, 10, 28));
        q2.push(Date(2018, 10, 30));

        cout << q2.top() << endl;
    }

}