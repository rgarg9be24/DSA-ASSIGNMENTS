// find the missing number in sorted array
#include<iostream>
using namespace std;
int main(){
  int n;
  cout<<"enter no. of elements in array: "<<endl;
  cin>>n;
  
  int arr[n];
  
  cout<<"enter elements of array: (must be a AP series)";
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  int d=min(arr[2]-arr[1],arr[1]-arr[0]);
  int sum=(n+1)*((2*arr[0])+(n)*d)/2;
  
  int sum1=0;
  for(int j=0;j<n;j++){
    sum1=sum1+arr[j];
  }
  
  int missingNumber=sum-sum1;
  
  cout<<"missing number = "<<missingNumber<<endl;
  return 0;
}