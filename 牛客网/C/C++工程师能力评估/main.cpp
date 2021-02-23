#include<iostream>
#include<stdio.h>x
using namespace std;
enum string{    
    x1,    
    x2,    
    x3=10,    
    x4,    
    x5,    
} x;

void example(char acWelcome[]){
    printf("%d",sizeof(acWelcome));
    return;
}
int main(){
    char acWelcome[]="Welcome to Huawei Test";
    example(acWelcome);
    return 0;
}