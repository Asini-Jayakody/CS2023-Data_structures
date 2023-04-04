// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int max_size =20;
int stack[20];
int top = -1;

void push(int n);
int pop();
void display();

void push(int n){
    
    if(top>=max_size-1){
        cout << "stack overflow\n";
    }
    else{
        top++;
        stack[top]=n;
    }
}

int pop(){
    if (top<0){
        cout << "stack underflow\n";
    }
    else{
        top--;
        return stack[top+1];
    }
}

void display(){
    if(top>-1){
        for(int i=top; i>=0; i--){
            cout<<stack[i]<<" ";
        }
    }
    else{
        cout<<"stack is empty";
    }
    cout<<"\n";
}

int main() {
    // Write C++ code here
    //std::cout << "Hello world!";
    auto start = high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout<<"\n"<<"Time taken in microseconds is "<<duration.count();
    //return 0;
}