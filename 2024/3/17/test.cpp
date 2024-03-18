#include <stdio.h>

int AddToTop(int top)
{
    int i = 0;
    int result = 0;
    for (i = 0; i < top; ++i)
    {
        result += i;
    }
    return result;
}

int main()
{
    int top = 100;

    int res = AddToTop(top);
    printf("res: %d\n", res);

    return 0;
    
}

/*

mytest:mytest.c
    gcc -o mytest mytest.c
.PHONY:clean
clean: 
    rm -f mytest

*/