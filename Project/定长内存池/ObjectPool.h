#include <iostream>
#include <cstdlib> 
#include<new>


using std::cout;
using std::endl;

// 定长内存池
template <class T>
class ObjectPool
{
public:
    T *Nwe()
    {
        //剩余内存不够一个对象大小时,则重新开大块空间
        if(_memory==nullptr)
        {
            _memory=(char*)malloc(128*1024);
            //申请失败
            if(_memory==nullptr)
            {
                //throw bad_alloc();
                printf("malloc error");
                exit(0);
            }
        }
        T* obj=(T*)_memory;//指向(剩余)大块内存池的指针
        _memory+=sizeof(T);//切除块的大小(从_memory处开始切割)
        _remainByter-=sizeof(T);//剩余的大块内存池

        return obj;
    }

    void Dele(T* obj)
    {
        
    }

private:
    char *_memory = nullptr;   // char占1字节,方便使用(计算)
    size_t _remainByter = 0;   // 大块内存中切割后剩余字节数
    void *_freeList = nullptr; // 自由链表(还回来过程中链接的自由链表的头指针)
};