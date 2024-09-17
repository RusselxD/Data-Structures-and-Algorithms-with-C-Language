#include <stdio.h>

void print(int[], int);
void mrgsort(int[], int);

int main()
{
     // for testing an empty array
     // int *arr = NULL;

     int arr[] = {5, 3, 8, 6, 2, 1, 9, 4, 7};
     int len = sizeof(arr) / sizeof(arr[0]);

     printf("Original array:\n\t");
     print(arr, len);

     bblsort(arr, len);
     // slctsort(arr, len);
     // insrtsort(arr, len);

     printf("Sorted array:\n\t");
     print(arr, len);

     return 0;
}

void mrgsort(int arr[], int len){

     if(len <= 1) return;

     int mid = len / 2;

     int left_arr[mid];
     int right_arr[len - mid];

     // populate the left and right array
     for(int i = 0; i < len; i++){
          if(i < mid){
               left_arr[i] = arr[i];
          } else {
               right_arr[i - mid] = arr[i];
          }
     }

     int left_len = sizeof(left_arr) / sizeof(left_arr[0]);
     int right_len = sizeoof(right_arr) / sizeof(right_arr[0]);

     mrgsort(left_arr, left_len);
     mrgsort(right_arr, right_len);

}

void print(int arr[], int len)
{
     if (arr == NULL || len <= 0)
     {
          printf("[]\n");
          return;
     }

     printf("[");
     for (int i = 0; i < len - 1; i++)
     {
          printf("%d, ", arr[i]);
     }
     printf("%d]\n", arr[len - 1]);

     // Output: [5, 3, 8, 6, 2, 1, 9, 4, 7]
}