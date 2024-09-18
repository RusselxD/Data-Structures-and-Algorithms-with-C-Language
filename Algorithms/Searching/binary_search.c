#include <stdio.h>

int binary(int[], int len, int trgt);

int main()
{

     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
     int len = sizeof(arr) / sizeof(arr[0]);
     int trgt = 11;

     int index = binary(arr, len, trgt);

     printf("Element (%d) found at index: %d", trgt, index);

     return 0;
}

int binary(int arr[], int len, int trgt)
{

     int left = 0, right = len - 1;
     int mid;

     while (left <= right)
     {

          mid = left + (right - left) / 2;

          if (arr[mid] == trgt)
          {
               return mid;
          }
          else if (trgt < arr[mid])
          {
               right = mid - 1;
          }
          else
          {
               left = mid + 1;
          }
     }

     return -1;
}