#pragma once

/*
    适配器
    vector::iterator
    list::iterator 

*/ 

namespace wzf
{
    template<class Iterator ,class Ref,class Ptr >
    struct ReverseIterator
    {
        typedef ReverseIterator<Iterator, Ref, Ptr> Self;
        Iterator _cur;

        ReverseIterator(Iterator it)
        :_cur(it)
        {}

        Ref operator *()
        {
            Iterator tmp=_cur;
            --tmp;
            return *tmp;
        }
      
        Self& operator++()//与iterator相反
        {
            --_cur;
            return *this;
        }

        Self& operator--()
        {
            ++_cur;
            return *this;
        }

        bool operator!=(const Self& s)
        {
            return _cur!=s._cur;
        }


    };
    

} // namespace wzf
