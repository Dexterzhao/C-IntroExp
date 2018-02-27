#ifndef EXP6_HEAD_H_INCLUDED
#define EXP6_HEAD_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10

using namespace std;

class STACK{
    int  *const elems;	//�����ڴ����ڴ��ջ��Ԫ��
    const int   max;	//ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos;			//ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
public:
STACK(int m=STACKSIZE);         //��ʼ��ջ�����m��Ԫ��

STACK(const STACK&s) ;          //��ջs������ʼ��ջ

virtual int  size ( ) const;	//����ջ�����Ԫ�ظ���max

virtual operator int ( ) const;	//����ջ��ʵ��Ԫ�ظ���pos

virtual int operator[ ] (int x) const;       //ȡ�±�x����ջԪ��

virtual STACK& operator<<(int e);  	//��e��ջ,������ջ

virtual STACK& operator>>(int &e); 	//��ջ��e,������ջ

virtual STACK& operator=(const STACK&s); //��s��ջ,�����ر���ֵ��ջ

virtual void print( ) const;

virtual ~STACK( );
			//����ջ
};

class QUEUE:public STACK{
    STACK s2;
public:
QUEUE(int m);		//��ʼ�����У�ÿ��ջ���m��Ԫ��
QUEUE(const QUEUE&s); 		//�ö���s������ʼ������
operator int ( ) const;			//���ض��е�ʵ��Ԫ�ظ���
QUEUE& operator<<(int e); 		//��e�����,�����ض���
QUEUE& operator>>(int &e);	//�����е�e,�����ض���
QUEUE& operator=(const QUEUE&s); //��s������,�����ر���ֵ�Ķ���
void print( ) const;			//��ӡ����
~QUEUE( );					//���ٶ���
};




#endif // EXP6_HEAD_H_INCLUDED
