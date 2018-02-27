#ifndef EXP4_HEAD_H_INCLUDED
#define EXP4_HEAD_H_INCLUDED


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10

using namespace std;

class QUEUE{
    int  *const  elems;	//申请内存用于存放队列的元素
    const  int   max;	//队列能存放的最大元素个数
    int   head, tail;		//队列头和尾，队列空时head=tail;初始时head=tail=0
public:
QUEUE(int m);		//初始化队列：最多m个元素
QUEUE(const QUEUE&s); 			//用队列s拷贝初始化队列
virtual operator int ( ) const;			//返回队列的实际元素个数
virtual QUEUE& operator<<(int e); 	//将e入队列,并返回队列
virtual QUEUE& operator>>(int &e);	//出队列到e,并返回队列
virtual QUEUE& operator=(const QUEUE&s); //赋s给队列,并返回被赋值的队列
virtual void print( ) const;			//打印队列
virtual ~QUEUE( );					//销毁队列
};



#endif // EXP4_HEAD_H_INCLUDED
