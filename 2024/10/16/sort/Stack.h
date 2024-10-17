#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
 
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;
}ST;
 
 
//初始化
void StackInit(ST* ps);
 
//销毁
void StackDestory(ST* ps);
 
//入栈
void StackPush(ST* ps, int x);
 
//出栈
void StackPop(ST* ps);
 
//取栈顶元素（并不删除栈顶元素）
STDataType StackTop(ST* ps);
 
//求栈中元素个数
int StackSize(ST* ps);
 
//判断是否为空
bool StackEmpty(ST* ps);