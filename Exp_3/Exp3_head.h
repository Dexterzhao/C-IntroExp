#ifndef EXP3_HEAD_H_INCLUDED
#define EXP3_HEAD_H_INCLUDED

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

virtual int  size ( ) const{ return max; }		//����ջ�����Ԫ�ظ���max

virtual operator int ( ) const{ return pos; }	//����ջ��ʵ��Ԫ�ظ���pos

virtual int operator[ ] (int x) const{ return elems[x];}        //ȡ�±�x����ջԪ��

virtual STACK& operator<<(int e);  	//��e��ջ,������ջ

virtual STACK& operator>>(int &e); 	//��ջ��e,������ջ

virtual STACK& operator=(const STACK&s); //��s��ջ,�����ر���ֵ��ջ

virtual void print( ) const{
     if(max==0){
        cout << "Stack doesn't exist!" << endl;
        return;
    }
    int k;
    cout<<"bottom";
    for(k=0; k<pos; k++)
    {

        cout<<"\t";
        cout << elems[k]<< " ";

    }
    cout<<"top";


}

virtual ~STACK( ){

    delete []elems;
    *(int *)&max = 0;
    int *p=(int *)(&max);
    *p=0;
    pos=0;
}
			//����ջ
};
#endif // EXP3_HEAD_H_INCLUDED






