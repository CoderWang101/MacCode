#include <iostream>
#include <cstdlib>
#include <new>

using std::cout;
using std::endl;

// 定长内存池
template <class T>
class ObjectPool
{
public:
    T *Nwe()
    {
        T *obj = nullptr;

        // 优先把换回来的内存块,再次重复利用
        if (_freeList)
        {
            // 头删
            void *next = *((void **)_freeList); // 获取第一个节点元素的位置
            obj = _freeList;                    // 获取要利用内存块的位置(一个节点元素)
            _freeList = next;                   // 指针指向下一元素
            return obj;
        }
        else
        {
            // 剩余内存不够一个对象大小时,则重新开大块空间
            if (_memory == nullptr)
            {
                _memory = (char *)malloc(128 * 1024);
                // 申请失败
                if (_memory == nullptr)
                {
                    // throw bad_alloc();
                    printf("malloc error");
                    exit(0);
                }
            }
            obj = (T *)_memory;                                                       // 指向(剩余)大块内存池的指针
            size_t objSize = sizeof(T) < sizeof(void *) ? sizeof(void *) : sizeof(T); // 剩余容量<void* 则给一个void*的大小
            _memory += objSize;                                                       // 切除块的大小(从_memory处开始切割)
            _remainByter -= objSize;                                                  // 剩余的大块内存池
        }

        // 定位new,显示调用T的构造函数初始化
        new (obj) T; // 在已经分配的内存地址 obj 上构造一个类型为 T 的对象

        return obj;
    }

    void Delete(T *obj)
    {
        //显示调用析构函数清理对象
        obj->~T();

        // 头插
        //*(void**)obj=_freeList 即 *obj=_freeList的头节点地址
        *(void **)obj = _freeList; // obj 所指向的内存位置现在存储的是 _freeList 的值，即第一个元素的地址
        //_freeList指针指向obj
        _freeList = obj; // obj被插入到了自由列表的头部 |freelist-> obj -> A -> B -> C
    }

private:
    char *_memory = nullptr;   // char占1字节,方便使用(计算)
    size_t _remainByter = 0;   // 大块内存中切割后剩余字节数
    void *_freeList = nullptr; // 自由链表(还回来过程中链接的自由链表的头指针)
};