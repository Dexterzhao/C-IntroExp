#include <E:\c++\Exp&lecture\exp\Exp_3\Exp3_head.h>


using namespace std;



		//打印栈


STACK::STACK(int m):elems(new int[m]),max(elems==NULL? 0 : m){
    pos=0;
}


STACK::STACK(const STACK&s): elems(new int[s.max]),max(elems==NULL? 0 : s.max){
    *(int **)&(this->elems) = NULL;

    *this =s;
}



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

    STACK S(10);

    int p1=10,p2=5,p3=8;

    S<<p1;
    S<<p2;
    S<<p3;
    STACK S1(S);


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
            int i=S;
            cout<<i<<endl;
            getchar();
            getchar();}
            break;
        case 5:
            {printf("\n     Get x element\n \tinput x");
            scanf("%d",&x);
            cout<<S[x]<<endl;
            getchar();
            getchar();}
            break;
        case 6:
            {printf("\n     Push e\n \tinput e");
            scanf("%d",&e);
            S<<e;
            getchar();
            getchar();}
            break;
        case 7:
            {printf("\n    Pop e\n");
            S>>e;
            getchar();
            getchar();}
            break;
         case 8:
            {printf("\n    Assign S1 By S \n");
            S1=S;
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
