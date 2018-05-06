#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int x) {
   if (r >= l) {
        int mid = l + (r - l)/2;

        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

int main() {
   int arr[] = {-10,-8,-3,5,6,8};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = -3;
   int result = binarySearch(arr, 0, n-1, x);
   cout << result;

   return 0;
}
