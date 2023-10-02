// You are given a sorted array of N integers from 1 to N with one number missing find the missing number Expected time complexity O(logn) 

// Examples: 
 

// Input :ar[] = {1, 3, 4, 5}
// Output : 2

// Input : ar[] = {1, 2, 3, 4, 5, 7, 8}
// Output : 6

// A simple solution is to linearly traverse the given array. Find the point where current element is not one more than previous.
// An efficient solution is to use binary search. We use the index to search for the missing element and modified binary search. 
//  If element at mid != index+1 and this is first missing element then mid + 1 is the missing element. 
//  Else if this is not first missing element but ar[mid] != mid+1 search in left half. Else search in right half and if left>right then no element is missing. 


#include<bits/stdc++.h>
using namespace std;

int findMissingElement(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    int ans = -1;

    while(start <= end){
        int diff = arr[mid] - mid;

        if(diff == 1){
            // right me 
            start = mid+1;
        }
        else{
            // store ans 
            ans = mid;
            // left me jana 
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    if(ans+1 == 0)
    return n+1;
    return ans+1;
}

int main(){
 
//  int arr[] = {1,2,3,4,6,7,8};
int arr[] = {1,2,3,4,5,6,7,8};
 int n = 8;

 int missintNumber = findMissingElement(arr, n);
 cout<<"missing number is: "<<missintNumber<<endl;

 return 0;
}
