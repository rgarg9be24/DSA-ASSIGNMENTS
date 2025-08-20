// BINARY SEARCH
#include<iostream>
using namespace std;
 
int main(){
  int n;
  cout<<"Enter number of elements: "<<endl;
  cin>>n;
  int arr[n];
  

  cout<<"Enter elements of array(sorted): "<<endl;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  int key;
  cout<<"Enter element to be searched: "<<endl;
  cin>>key;
  
  int start=0 , end=n-1 , mid ;
  
  while(start<=end){
    mid=(start+end)/2 ;
    if(key==arr[mid]){
      cout<<"element is found at index "<<mid<<endl;
      break;
    }
    
    else if(key<arr[mid]){
      end=mid-1;
    }
    
    else if(key>arr[mid]){
      start=mid+1;
    }
  }
  return 0;
}