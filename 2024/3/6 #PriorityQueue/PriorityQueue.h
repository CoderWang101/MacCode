#pragma once
#include <iostream>
using namespace std;
#include <vector>

namespace wzf
{
    template <class T, class Container = std::vector<T> >
    class priority_queue
    {
    public:
        priority_queue();
        ~priority_queue();

        void adjust_up(int child)
        {
            int parent=(child-1)/2;
            while (child>0)
            {
                if (_con[child]>_con[parent])
                {
                    swap(_con[child],_con[parent]);
                    child=parent;
                    parent=(child-1)/2;
                }
                else
                    break;
            }
        }

        void adjust_down(int parent)
        {
            int child=parent*2+1;//左(从0开始)
            while (child<_con.size())
            {
                if (_con[child]<_con[child+1])
                {
                    ++child;   
                }
                
                if(_con[parent]<_con[child])
                { 
                    swap(_con[parent],_con[child]);
                    parent=child;
                    child=parent*2+1;
                }
                else
                    break;                
            }
        }

        void push(const T& x)
        {
            _con.push_back(x);
            adjust_up(_con.size()-1);//向上调整
        }

        void pop()
        {
            //top与最后一个元素交换
            swap(_con[0],_con[_con.size()-1]);
            _con.pop_back();
            //adjust_down(_con[0]);
        }

        const T& top()
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
        //priority_queue<int,vector<int>,greater<int> > pq;
        priority_queue<int> pq;
        pq.push(1);
        pq.push(7);
        pq.push(5);
        pq.push(4);
        pq.push(9);
        pq.push(2);

        while (!pq.empty())
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;

    }

}