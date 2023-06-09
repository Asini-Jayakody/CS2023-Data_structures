#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   
   int l = 2*root+1;
   int r= 2*root+2;
   
   if (l<n && arr[l]>arr[root]){
       largest = l;
   }
   
    if (r<n && arr[r]>arr[largest]){
       largest = r;
    }
    
    if (largest != root){
        swap(arr[root],arr[largest]);
        heapify(arr,n,largest);
    }
   
   
  
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2 -1 ; i>=0; i--){
       heapify(arr,n,i);
   }
  
   // extracting elements from heap one by one
   for (int i = n-1; i>0; i--){
       swap(arr[i],arr[0]);
       heapify(arr,i,0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int n;
   cout << "enter the size of array : ";
   cin >> n;
   int heap_arr[n];
   for(int i = 0; i<6; i++){
       heap_arr[i]=rand()%100;
   }
   
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}