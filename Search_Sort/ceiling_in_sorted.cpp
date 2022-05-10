#include <iostream>
using namespace std;
 
int ceilSearch(int arr[], int low, int high, int x)
{
    int size=high-low+1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(low<size)
        return low;
    else
     return -1;
}
 