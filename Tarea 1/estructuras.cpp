#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#define T 100
struct  Notacion{
    char op;
    Notacion *next ;
};
struct Notacion *top =NULL;
void push(Notacion *nuevo){
    nuevo->next=top;
    top=nuevo;
    
}
void pop(){
    Notacion *auxiliar;
    if(top!= NULL){
        auxiliar=top;
        top=auxiliar->next;
        delete(auxiliar);
    }
    else{
        cout<<"lista vacia"<<'\n';
    }
}
int main()
{
    int i =0;
    char operacion[T];
    cout <<"digita tu operaccion de forma lineal cuando este listo precione enter:"<<'\n';
    scanf("%s",operacion);
    //printf("%s", operacion);
    while(operacion[i]!='\0'){
        if(operacion[i]>47 && operacion[i]<58){
            printf("%c",operacion[i]);
        }
         else if(operacion[i]== 42 ||operacion[i]== 43 ||operacion[i]== 45||operacion[i]== 47 ){
            if(top==NULL){
                Notacion *nuevo=new(Notacion);
                nuevo->op=operacion[i];
                push(nuevo);
            }
            else if((operacion[i]== 43||operacion[i]== 45)&&(top->op ==42||top->op==47)){
                cout<<top->op;
                pop();
                Notacion *nuevo=new(Notacion);
                nuevo->op=operacion[i];
                push(nuevo);
            }
            else{
                Notacion *nuevo=new(Notacion);
                nuevo->op=operacion[i];
                push(nuevo);
            }      
        }
        else if(operacion[i]==41){
            cout<<top->op;
            pop();
        }
        i++;
    }
    while(top!='\0'){
        cout<<top->op;
        pop();
    }

    return 0;
}
