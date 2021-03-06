#ifndef EXP6_HEAD_H_INCLUDED
#define EXP6_HEAD_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10

using namespace std;

class STACK{
    int  *const elems;	//申请内存用于存放栈的元素
    const int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m=STACKSIZE);         //初始化栈：最多m个元素

STACK(const STACK&s) ;          //用栈s拷贝初始化栈

virtual int  size ( ) const;	//返回栈的最大元素个数max

virtual operator int ( ) const;	//返回栈的实际元素个数pos

virtual int operator[ ] (int x) const;       //取下标x处的栈元素

virtual STACK& operator<<(int e);  	//将e入栈,并返回栈

virtual STACK& operator>>(int &e); 	//出栈到e,并返回栈

virtual STACK& operator=(const STACK&s); //赋s给栈,并返回被赋值的栈

virtual void print( ) const;

virtual ~STACK( );
			//销毁栈
};

class QUEUE:public STACK{
    STACK s2;
public:
QUEUE(int m);		//初始化队列：每个栈最多m个元素
QUEUE(const QUEUE&s); 		//用队列s拷贝初始化队列
operator int ( ) const;			//返回队列的实际元素个数
QUEUE& operator<<(int e); 		//将e入队列,并返回队列
QUEUE& operator>>(int &e);	//出队列到e,并返回队列
QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
void print( ) const;			//打印队列
~QUEUE( );					//销毁队列
};




#endif // EXP6_HEAD_H_INCLUDED
