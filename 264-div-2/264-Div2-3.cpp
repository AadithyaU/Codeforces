#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <fstream>
#include <iomanip>   
#include <stack>
#include <cassert>
using namespace std;

//Useful input scanners
#define sd(x) 						scanf("%d",&x)

// Useful constants
#define INF                         (int)1e9
#define EPS                         1e-9

// Useful hardware instructions
#define bitcount                    __builtin_popcount
#define gcd                         __gcd

// Useful container manipulation / traversal macros
#define forall(i,a,b)               for(int i=a;i<b;i++)
#define foreach(v, c)               for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define in(a,b)                     ( (b).find(a) != (b).end())
#define pb                          push_back
#define fill(a,v)                    memset(a, v, sizeof a)
#define sz(a)                       ((int)(a.size()))

// Some common useful functions
#define maX(a,b)                     ( (a) > (b) ? (a) : (b))
#define miN(a,b)                     ( (a) < (b) ? (a) : (b))
#define checkbit(n,b)                ( (n >> b) & 1)
#define DREP(a)                      sort(all(a)); a.erase(unique(all(a)),a.end())
#define INDEX(arr,ind)               (lower_bound(all(arr),ind)-arr.begin())

int n;
int arr[2001][2001];
int findmax(int row1,int col1,int row2,int col2) {
	bool vis[n][n];
	fill(vis,0);
	int val = 0;
	int i, j;
	/* Check upper diagonal on left side */
    for (i = row1, j = col1; i >= 0 && j >= 0; i--, j--)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
 
    /* Check lower diagonal on left side */
    for (i = row1, j = col1; j >= 0 && i < n; i++, j--)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
    for (i = row1, j = col1; i < n && j < n; i++, j++)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
 	for (i = row1, j = col1; i >= 0 && j < n; i--, j++)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
    for (i = row2, j = col2; i >= 0 && j >= 0; i--, j--)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
 
    /* Check lower diagonal on left side */
    for (i = row2, j = col2; j >= 0 && i < n; i++, j--)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
    for (i = row2, j = col2; i < n && j < n; i++, j++)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
 	for (i = row2, j = col2; i >= 0 && j < n; i--, j++)
    {
        if(!vis[i][j])val += arr[i][j];
        vis[i][j] = 1;
    }
    return val;
}

int main() {
	sd(n);
	int i = 0,j = 0;
	int cx1,cy1,cx2,cy2;
	int max = INT_MIN;
	forall(i,0,n)
		forall(j,0,n)
			sd(arr[i][j]);
	forall(i,0,n)
		forall(j,0,n)
			forall(k,i,n)
				forall(l,j,n) {
				if(i == k && j == l) continue; 
					int res = findmax(i,j,k,l);
			//		cout<<"the res is "<<res<<" for values at "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
					if(res > max) cx1 = i,cy1 = j,cx2 = k,cy2 = l,max = res;
				}
	cout<<max<<"\n"<<cx1+1<<" "<<cy1+1<<" "<<cx2+1<<" "<<cy2+1<<"\n";
	return 0;
}