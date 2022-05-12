#include <algorithm>
#include <iostream>
using namespace std;

bool findPair(int arr[], int size, int n)
{
	int i=0;
  	int j=1;
  	while(i<size && j<size){
    if(arr[j]-arr[i]==n){
      cout << "Pair Found: (" << arr[i] << ", " << arr[j] << ")";
      return true;
    }
     else if(arr[j]-arr[i]<n){
      j++;
     }
      else{
        i++;
      }
    }
	
	cout << "No such pair";
	return false;
}

int main()
{
	int arr[] = {5, 20, 3, 2, 50, 80};
	int size = sizeof(arr)/sizeof(arr[0]);
  	sort(arr,arr + size);
	int n = 1;
	findPair(arr, size, n);
	return 0;
}

