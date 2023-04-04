// Online C++ compiler to run C++ program online
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct node{
    int data;
    node *next;
};

node *top = NULL;

void push(int n){
    node *temp = new node();
    temp->data = n;
    temp->next = top;
    top = temp;
}

void pop(){
    if (top==NULL){
        cout << "stack underflow\n";
    }
    else{
        node *temp = top;
        top = top->next;
        delete(temp);
    }
}

void display(){
    if (top==NULL){
        cout << "stack is empty\n";
    }
    else{
        node *temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp -> next;
        }
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
    return 0;
}