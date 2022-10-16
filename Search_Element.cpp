#include<bits/stdc++.h>
using namespace std;
 
// Simple binary search algorithm
int binarySearch(int Arr[], int l, int r, int x)
{
    if (r>=l)
    {
        int mid = l + (r - l)/2;
        if (Arr[mid] == x)
            return mid;
        if (Arr[mid] > x)
            return binarySearch(Arr, l, mid-1, x);
        return binarySearch(Arr, mid+1, r, x);
    }
    return -1;
}
 
// function takes an infinite size array and a key to be
//  searched and returns its position if found else -1.
int findPosition(int Arr[], int key)
{
    int low = 0, high = 1;
    int val = Arr[0];
 
    // Find h to do binary search
    while (val < key)
    {
        low = high;        // store previous high
        high = 2*high;      // double high index
        val = Arr[high]; // update new val
    }
 
    return binarySearch(Arr, low, high, key);
}
 
int main()
{
    int Arr[] = {5 , 10 , 13 , 15 , 20 , 24 , 28 , 35 , 42 , 56 , 64, 70};
    int ans = findPosition(Arr, 15);
    if (ans==-1)
        cout << "Element not found";
    else
        cout << "Element found at index " << ans;
    return 0;
}
