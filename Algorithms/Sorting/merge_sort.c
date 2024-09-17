#include <stdio.h>

void print(int[], int);
void mrgsort(int[], int);
void merge(int[], int[], int, int[], int);

int main()
{
     // for testing an empty array
     // int *arr = NULL;

     int arr[] = {5, 3, 8, 6, 2, 1, 9, 4, 7};
     int len = sizeof(arr) / sizeof(arr[0]);

     printf("Original array:\n\t");
     print(arr, len);

     mrgsort(arr, len);

     printf("Sorted array:\n\t");
     print(arr, len);

     return 0;
}

void mrgsort(int arr[], int len)
{
     if (len <= 1)
          return;

     int mid = len / 2;

     int left_arr[mid];
     int right_arr[len - mid];

     // populate the left and right array
     for (int i = 0; i < len; i++)
     {
          if (i < mid)
          {
               left_arr[i] = arr[i];
          }
          else
          {
               right_arr[i - mid] = arr[i];
          }
     }

     // recursive call
     mrgsort(left_arr, mid);
     mrgsort(right_arr, len - mid);

     merge(arr, left_arr, mid, right_arr, len - mid);
}

// merge the contents of left and right array into the original array
void merge(int arr[], int left_arr[], int left_len, int right_arr[], int right_len)
{
     int i = 0, l = 0, r = 0;

     while (l < left_len && r < right_len)
     {
          if (left_arr[l] < right_arr[r])
          {
               arr[i++] = left_arr[l++];
          }
          else
          {
               arr[i++] = right_arr[r++];
          }
     }

     while (l < left_len)
     {
          arr[i++] = left_arr[l++];
     }

     while (r < right_len)
     {
          arr[i++] = right_arr[r++];
     }
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