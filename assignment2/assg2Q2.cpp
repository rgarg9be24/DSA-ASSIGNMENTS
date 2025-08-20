// BUBBLE SORT
#include<iostream>
using namespace std;
int main(){
  
  int n;
  cout<<"enter no. of elements in array: "<<endl;
  cin>>n;
  
  int arr[n];
  
  cout<<"enter elements in array"<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  int temp;
  for(int j=0;j<n;j++){
    for(int k=0;k<n-j-1;k++){
      if(arr[k]>arr[k+1]){
        temp=arr[k];
        arr[k]=arr[k+1];
        arr[k+1]=temp;
      }
    }
  }
  
  cout<<"sorted array: "<<endl;
  for(int x=0;x<n;x++){
    cout<<arr[x]<<" "<<endl;
  }
  return 0;
}