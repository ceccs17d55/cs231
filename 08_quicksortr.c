// Visakh Sebastian
// s3 d
// 55


#include<stdio.h>
int main()
 {
  int arr[20],n,i;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  printf("Enter the elements to be sorted\n");
  for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
  quicksort(arr,0,n-1);
  printf("sorted array\n"); 
  for(i=0;i<n;i++)
   printf("\n %d ",arr[i]);
  return 0;
 }
 void quicksort(int*arr,int low,int high)
 {
  int pivot,i,j,temp;
  if (low<high)
   {
     pivot=low;
     i=low;
     j=high;
     while(i<j)
       {
        while (arr[i]<=arr[pivot]&&i<=high)
         i++;
        while (arr[j]>arr[pivot]&&j>=low)
         j--;
        if (i<j)
          {
           temp=arr[i];
           arr[i]=arr[j];
           arr[j]=temp;
          }
       }
     temp=arr[j];
     arr[j]=arr[pivot];
     arr[pivot]=temp;
     quicksort(arr,low,j-1);
     quicksort(arr,j+1,high);
   }
}
/*
Output
[?1h=$ ./08_quicksort_recursive 
[?1l>Enter size of the array : 5
Enter array elements
28163    
81 
1
6
3
Sorted Array
1
2
3
6
8
*/
