#ifndef EXP4_HEAD_H_INCLUDED
#define EXP4_HEAD_H_INCLUDED


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10

using namespace std;

class QUEUE{
    int  *const  elems;	//�����ڴ����ڴ�Ŷ��е�Ԫ��
    const  int   max;	//�����ܴ�ŵ����Ԫ�ظ���
    int   head, tail;		//����ͷ��β�����п�ʱhead=tail;��ʼʱhead=tail=0
public:
QUEUE(int m);		//��ʼ�����У����m��Ԫ��
QUEUE(const QUEUE&s); 			//�ö���s������ʼ������
virtual operator int ( ) const;			//���ض��е�ʵ��Ԫ�ظ���
virtual QUEUE& operator<<(int e); 	//��e�����,�����ض���
virtual QUEUE& operator>>(int &e);	//�����е�e,�����ض���
virtual QUEUE& operator=(const QUEUE&s); //��s������,�����ر���ֵ�Ķ���
virtual void print( ) const;			//��ӡ����
virtual ~QUEUE( );					//���ٶ���
};



#endif // EXP4_HEAD_H_INCLUDED
