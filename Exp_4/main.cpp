#include "E:\c++\Exp&lecture\exp\Exp_4\Exp4_head.h"


QUEUE::QUEUE(int m):elems(new int[m]),max(elems==NULL? 0 : m){

    head=tail=0;
}


QUEUE::QUEUE(const QUEUE&s): elems(new int[s.max]),max(elems==NULL? 0 : s.max){
    *(int **)&(this->elems) = NULL;

    *this =s;
}

QUEUE::operator int ( ) const{
    if(tail>head)   return head-tail;
    else if(tail==head) return 0;
    else return (max-(head-tail));
}

QUEUE& QUEUE:: operator<<(int e){

    if((tail+1)%max==head){
        cout<<"QUEUE is full!"<<endl;
        return *this;
    }
    else{
            if(tail!=max-1)
                elems[tail++]=e;
            else {
                elems[tail]=e;
                tail=0;
            }
        return *this;
    }
}


QUEUE& QUEUE:: operator>>(int &e){
    if(head==tail){
        cout<<"QUEUE is empty!"<<endl;
        return *this;
    }
    else{

            if(head<max-1)
                e=elems[head++];
            else {
                e=elems[head];
                head=0;
            }
        return *this;
    }
}


QUEUE& QUEUE:: operator=(const QUEUE&s){
    if(elems!=NULL){
        delete []elems;
    }

    *(int*)(&max)=s.max;
    head=s.head;
    tail=s.tail;

    *(int**)(&elems)= new int[s.max];
    //*pe= new int[s.max];

    for(int i=0;i<max;i++){
        elems[i]=s.elems[i];
    }
    return *this;
}

void QUEUE:: print( ) const{
     if(max==0){
        cout << "Stack doesn't exist" << endl;
        return;
    }
    if(head==tail){
        cout<<"Stack empty" <<endl;
        return;
    }

    if(head<tail){
    cout<<"head";
    for(int k=head; k<tail; k++){

        cout<<"\t";
        cout << elems[k]<< " ";

    }
    cout<<"tail";
    }
    else{
        cout<<"head";
        for(int k=head;k<max;k++){
            cout<<"\t";
            cout << elems[k]<< " ";

        }
        for(int k=0;k<tail;k++){
            cout<<"\t";
            cout << elems[k]<< " ";
        }
        cout<<"tail";
    }


}

QUEUE::~QUEUE(){
    delete []elems;
    *(int *)&max = 0;
    head=tail=0;
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
