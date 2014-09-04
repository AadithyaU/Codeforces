/* Dynamic Programming implementation of LCS problem */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define sd(x) scanf("%d",&x)

  int arr1[1001];
  int arr2[1001];

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(int m, int  n )
{
   int L[m+1][n+1];
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (arr1[i-1] == arr2[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   // Following code is used to print LCS
   int index = L[m][n];
   int len = index;
   int lcs[len];
   //cout<<"len is "<<len<<endl;

   // Create a character array to store the lcs string

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (arr1[i-1] == arr2[j-1])
      {
          lcs[index-1] = arr1[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] >= L[i][j-1])
         i--;
      else
         j--;
   }

   cout<<endl;
   for(int l = 0; l < len; l++) arr1[l] = lcs[l];
    for(int g = 0; g < len;g++) cout<<arr1[g]<<" ";
      cout<<endl;
   // Print the lcs
   return index;

}

/* Driver program to test above function */
int main()
{
  int n,k;
  sd(n);sd(k);
  k--;
  int ind = 0;
  for(;ind < n; ind++) sd(arr1[ind]);
  while(k--) {
    for(int i = 0; i < n; i++) sd(arr2[i]);
    ind = lcs(ind,n);
    cout<<"the value of  "<<ind<<endl;
    for(int g = 0; g < ind;g++) cout<<arr1[g]<<" ";
    cout<<endl;
  }
  cout<<ind<<endl;
  return 0;
}