#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10

using namespace std;

template <class S_stack_type>
class STACK{
    S_stack_type  *const elems;	//申请内存用于存放栈的元素
    const int   max;	//栈能存放的最大元素个数
    int   pos;			//栈实际已有元素个数，栈空时pos=0;
public:
STACK(int m=STACKSIZE);         //初始化栈：最多m个元素

STACK(const STACK&s) ;          //用栈s拷贝初始化栈

int  size ( ) const{
    return max;
}		//返回栈的最大元素个数max

int  howMany ( ) const{
    return pos;
}	//返回栈的实际元素个数pos

int  getelem (int x) const{
   if(x<0||x>=max){
        cout << "Wrong subscript!" << endl;
        return -1;
    }
    return elems[x];
}	//取下标x处的栈元素

STACK<S_stack_type>& push(int e); 	//将e入栈,并返回栈

STACK<S_stack_type>& pop(int &e); 	//出栈到e,并返回栈

STACK<S_stack_type>& assign(const STACK&s); //赋s给栈,并返回被赋值的栈

void print( ) const{
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
		//打印栈
~STACK( ){

    delete []elems;
    *(int *)&max = 0;
    int *p=(int *)(&max);
    *p=0;
    pos=0;
}
			//销毁栈
};

template <class S_stack_type>
STACK<S_stack_type>::STACK(int m):elems(new S_stack_type[m]),max(elems==NULL? 0 : m){
    pos=0;
}

template <class S_stack_type>
STACK<S_stack_type>::STACK(const STACK&s): elems(new S_stack_type[s.max]),max(elems==NULL? 0 : s.max){
    *(S_stack_type **)&(this->elems) = NULL;
    assign(s);
}


template <class S_stack_type>
STACK<S_stack_type>& STACK<S_stack_type>::push(int e){
    if(pos>=max){
        cout<<"Stack is full!"<<endl;
        return *this;
    }
    else{
        elems[pos++]=e;
        return *this;
    }
}

template <class S_stack_type>
STACK<S_stack_type>& STACK<S_stack_type>::pop(int &e){
    if(pos<=0){
        cout<<"Stack is empty!"<<endl;
        return *this;
    }
    else{
        e=elems[--pos];
        return *this;
    }
}

template <class S_stack_type>
STACK<S_stack_type>& STACK<S_stack_type>::assign(const STACK&s){
    if(elems!=NULL){
        delete []elems;
    }

    *(int*)(&max)=s.max;
    pos=s.pos;

    *(int**)(&elems)= new S_stack_type[s.max];
    //*pe= new S_stack_type[s.max];

    for(int i=0;i<s.pos;i++){
        elems[i]=s.elems[i];
    }
    return *this;
}

void menu(void)
{
    printf("\n\n");
    printf("      Menu for sequential stack based on arrays \n");
    printf("------------------------------------------------------\n");
    printf("    	  1. Create Stack                 5. Get x element \n");
    printf("    	  2. Create Stack By S            6. Push x\n");
    printf("    	  3. Output Size                  7. Pop x\n");
    printf("    	  4. Output amount                8. Assign  \n");
    printf("    	  9. Print stack                  10. Destroy \n");
    printf("          0. For exit\n");
    printf("------------------------------------------------------\n");

}



int main()
{


    int op,x,e,choice,choice1;

    STACK<int> S(10);

    int p1=10,p2=5,p3=8;

    S.push(p1);
    S.push(p2);
    S.push(p3);
    STACK<int> S1(S);


    do
    {
        system("cls");

        menu();
        printf("          Please input your option[0-7]:");
        scanf("%d",&op);
        getchar();
        switch(op)
        {
        case 0:
            return 0;
            break;
        case 1:
            cout<<"由于不至于使后面程序发生错误，已在该选择前执行该操作并入栈三个数，3-10操作仍可进行！"<<endl;
            getchar();
            break;
        case 2:
            cout<<"由于不至于使后面程序发生错误，已在该选择前执行该操作,3-10操作仍可进行！"<<endl;
            getchar();
            break;
        case 3:
            {printf("\n     Output Size\n");
            cout<<S.size()<<endl;
            getchar();
            getchar();}
            break;
        case 4:
            {printf("\n     Output Amount\n");
            cout<<S.howMany()<<endl;
            getchar();
            getchar();
            break;}
        case 5:
            {printf("\n     Get x element\n \tinput x");
            scanf("%d",&x);
            cout<<S.getelem(x)<<endl;
            getchar();
            getchar();}
            break;
        case 6:
            {printf("\n     Push e\n \tinput e");
            scanf("%d",&e);
            S.push(e);
            getchar();
            getchar();}
            break;
        case 7:
            {printf("\n    Pop e\n");
            S.pop(e);
            getchar();
            getchar();}
            break;
         case 8:
            {printf("\n    Assign S1 By S \n");
            S1.assign(S);
            getchar();
            getchar();}
            break;
         case 9:
            {printf("\n    Print S(1)/S1(2):\n \tchoice:");
            scanf("%d",&choice);
            if(choice==1)
                S.print();
            else if(choice==2)
                S1.print();
            else
                cout<<"Wrong choice!"<<endl;
            getchar();
            getchar();}
            break;
         case 10:
            {printf("\n    Destroy S(1)/S1(2):\n choice:\n");
            scanf("%d",&choice1);
            if(choice1==1)
               delete &S;
            else if(choice1==2)
               delete &S1;
            else
                cout<<"Wrong choice!"<<endl;
            getchar();
            getchar();}
            break;

        default:
            break;

        }
    }while(op);
    printf("\n--------------------Welcome again!--------------------\n");

    return 0;
}
