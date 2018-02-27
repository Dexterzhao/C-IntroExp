#include "E:\c++\Exp&lecture\exp\Exp_6\Exp6_head.h"



STACK::STACK(int m):elems(new int[m]),max(elems==NULL? 0 : m){
    pos=0;
}


STACK::STACK(const STACK&s): elems(new int[s.max]),max(elems==NULL? 0 : s.max){
    *(int **)&(this->elems) = NULL;

    *this =s;
}

int STACK::size() const { return max; }

STACK::operator int ( ) const{ return pos; }

int STACK::operator[ ] (int x) const{ return elems[x];}


void STACK::print( ) const{
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

STACK::~STACK( ){

    delete []elems;
    *(int *)&max = 0;
    int *p=(int *)(&max);
    *p=0;
    pos=0;
}
				//销毁栈



STACK& STACK:: operator<<(int e){
    if(pos>=max){
        cout<<"Stack is full!"<<endl;
        return *this;
    }
    else{
        elems[pos++]=e;
        return *this;
    }
}


STACK& STACK:: operator>>(int &e){
    if(pos<=0){
        cout<<"Stack is empty!"<<endl;
        return *this;
    }
    else{
        e=elems[--pos];
        return *this;
    }
}


STACK& STACK:: operator=(const STACK&s){
    if(elems!=NULL){
        delete []elems;
    }

    *(int*)(&max)=s.max;
    pos=s.pos;

    *(int**)(&elems)= new int[s.max];
    //*pe= new int[s.max];

    for(int i=0;i<s.pos;i++){
        elems[i]=s.elems[i];
    }
    return *this;
}




QUEUE::QUEUE(int m):STACK(m),s2(m){ }


QUEUE::QUEUE(const QUEUE&s): STACK((STACK)s),s2(s.s2){ }

QUEUE::operator int ( ) const{
   int t=STACK::operator int () ;
   return t;
}

QUEUE& QUEUE:: operator<<(int e){
    int s1_pos=STACK::operator int () ;
    if(s1_pos>=STACK::size()){
        cout<<"QUEUE is full!"<<endl;
        return *this;
    }
    int t;

    int s2_pos;

    for(int i=0;i<s1_pos;i++)
    {
        STACK::operator>>(t);
        s2<<t;
    }
    s2<<e;
    s2_pos=s2;
    for(int j=0;j<s2_pos;j++)
    {
        s2>>t;
        STACK::operator<<(t);
    }
    return *this;
}


QUEUE& QUEUE:: operator>>(int &e){
    int t=STACK::operator int ();
    if(t<=0){
        cout<<"QUEUE is empty!"<<endl;
        return *this;
    }
    STACK::operator>>(e);
    return *this;
}


QUEUE& QUEUE:: operator=(const QUEUE&s){
    //((STACK)*this)=s;  右值表达式不能被赋值

    STACK:: operator =(s);
    s2=s.s2;
    return *this;
}

void QUEUE:: print( ) const{
    STACK::print();
}

QUEUE::~QUEUE(){

}


void menu(void)
{
    printf("\n\n");
    printf("      Menu for sequential QUEUE based on arrays \n");
    printf("------------------------------------------------------\n");
    printf("    	  1. Create QUEUE                 4. Push x\n");
    printf("    	  2. Create QUEUE By S            5. Pop x \n");
    printf("    	  3. Output amount                6. Assign \n");
    printf("    	  7. Print QUEUE                  8. Destroy  \n");
    printf("          0. For exit\n");
    printf("------------------------------------------------------\n");

}



int main()
{


    int op,e,choice,choice1;

    QUEUE S(10);

    int p1=10,p2=5,p3=8;

    S<<p1;
    S<<p2;
    S<<p3;
    QUEUE S1(S);


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
            cout<<"由于不至于使后面程序发生错误，已在该选择前执行该操作并入队列三个数，3-10操作仍可进行！"<<endl;
            getchar();
            break;
        case 2:
            cout<<"由于不至于使后面程序发生错误，已在该选择前执行该操作,3-10操作仍可进行！"<<endl;
            getchar();
            break;

        case 3:
            {printf("\n     Output Amount\n");
            int i=S;
            cout<<i<<endl;
            getchar();
            getchar();}
            break;

        case 4:
            {printf("\n     Push e\n \tinput e");
            scanf("%d",&e);
            S<<e;
            getchar();
            getchar();}
            break;
        case 5:
            {printf("\n    Pop e\n");
            S>>e;
            getchar();
            getchar();}
            break;
         case 6:
            {printf("\n    Assign S1 By S \n");
            S1=S;
            getchar();
            getchar();}
            break;
         case 7:
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
         case 8:
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
