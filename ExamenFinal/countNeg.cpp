// Examen Final Problema 1
// Luis Gerardo Bravo Ramones A01282014
#include <iostream>

using namespace std;

int countBinarySearch(int arr[], int n) {
    int l = 0, r = n;
    int mid;

    while (l < r) {
        mid = l + (r-l)/2;

        if (mid <= 1 && arr[mid] >= 0) return 0;

        if (arr[mid] > -1) r = mid;
        else l = mid + 1;
    }

    while (arr[mid] > -1)
        mid--;

    return mid + 1;
}

int main() {
   int arr[] = {-10,-8,-2,-1};
   int n = sizeof(arr) / sizeof(arr[0]);
   int result = countBinarySearch(arr, n);
   cout << result;

   return 0;
}
