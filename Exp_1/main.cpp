#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct STACK
{
    int  *elems;//�����ڴ����ڴ��ջ��Ԫ��
    int   max; //ջ�ܴ�ŵ����Ԫ�ظ���
    int   pos; //ջʵ������Ԫ�ظ�����ջ��ʱpos=0;
};
void initSTACK( STACK *const p, int m)//��ʼ��pָ���ջ�����m��Ԫ��
{
    p->elems=(int *)malloc(m*sizeof(int));
    if(!p->elems) return;
    p->pos=0;
    p->max=m;
}
void init_STACK(STACK *const p, const STACK&s)//��ջs��ʼ��pָ��Ŀ�ջ
{
    p->elems=(int *)malloc((s.max)*sizeof(int));
    int i;
    for(i=0; i<s.pos; i++)
    {
        p->elems[i]=s.elems[i];
    }
    p->pos=s.pos;
    p->max=s.max;
}
int size(const STACK *const p)  //����pָ���ջ�����Ԫ�ظ���max
{
    return p->max;

}
int  howMany (const STACK *const p) //����pָ���ջ��ʵ��Ԫ�ظ���pos
{
    return p->pos;
}
int getelem(const STACK *const p, int x)    //ȡ�±�x����ջԪ��
{
    if(x<0||x>=p->max){
        printf("Wrong subscript!");
        return -1;
    }
    return p->elems[x];

}
STACK *const push(STACK *const p, int e)  //��e��ջ��������p
{
    if(p->pos==p->max){
        printf("Stack is full!");
        return p;
    }
    else p->elems[p->pos++]=e;
    return p;
}
STACK *const pop(STACK *const p, int &e) //��ջ��e��������p
{
    if(p->pos<=0){
        printf("Stack is empty!");
        return p;
    }
    else e=p->elems[--p->pos];
    return p;
}
STACK *const assign(STACK *const p, const STACK&s) //��s��pָ��ջ,������p
{
    if(p!=NULL&&p->max!=0){
        free(p);
    }
    init_STACK(p,s);
    return p;
}
void print(const STACK*const p)   //��ӡpָ���ջ
{
    if(p->max==0){
        printf("Stack doesn't exist!\n");
        return;
    }
    int k;
    printf("stack bottom\t");
    for(k=0; k<p->pos; k++)
    {
        printf("%d\t",p->elems[k]);
    }
    printf("stack top\t");
    printf("\n");
}
void destroySTACK(STACK*const p)  //����pָ���ջ
{
    if(p!=NULL&&p->max!=0){
        p->max=0;
        free(p);
    }

}
int main()
{

    int a,b,c,d;
    int Max=20;

    STACK s1,s2;

    initSTACK(&s1,Max);
    a=5,b=9,c=3;
    push(&s1,a);
    push(&s1,b);
    push(&s1,c);
    printf("we've pushed 5 9 3 into the stack.");

    printf("Stack s1:");
    print(&s1);
    putchar('\n');
    printf("The size of the stack s1 is %d\n",size(&s1));
    printf("The  element 2 is %d\n",getelem(&s1,1));
    printf("The capacity of the stack is��%d\n",howMany(&s1));
    pop(&s1,d);
    printf("Stack s1:");
    print(&s1);
    assign(&s2,s1);
    printf("Stack s2:");
    print(&s2);

    printf("we've destroyed the stack.\n");

    destroySTACK(&s2);
    destroySTACK(&s1);
    printf("Stack s1:");
    print(&s1);
    printf("Stack s2:");
    print(&s1);
}
