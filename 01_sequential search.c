// Visakh Sebastian
// s3 d
// 55


#include <stdio.h>
 
int main()
{
  int array[100], search, c, n;
 
  printf("Enter number of elements in array\n");
  scanf("%d", &n);
 
  printf("Enter %d integer(s)\n", n);
 
  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);
 
  printf("Enter a number to search\n");
  scanf("%d", &search);
 
  for (c = 0; c < n; c++)
  {
    if (array[c] == search)   
    {
      printf("%d is present at location %d.\n", search, c+1);
      break;
    }
  }
  if (c == n)
    printf("%d isn't present in the array.\n", search);
 
  return 0;
}


/*

Output

[?1h=$ ./01_sequential_search 
[?1l>Enter number of elements : 5
Enter elements
2
8
1
6
3
Enter element to search : 6
Element found at position 4
*/
