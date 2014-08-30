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

int main() {
	int n;
	sd(n);
	int arr[10001];
	int i = 0;
	int value = 0;
	while(n--) sd(arr[i++]);
	int e = 0;
	forall(i,0,n-1) {
		if(arr[i] > arr[i+1] && i == 0) value = 1,e = 1,continue;
		else if(arr[i] > arr[i+1]) {
			
		}

		e += arr[i] - arr[i+1];
	}


	return 0;
}