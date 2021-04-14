//#include "logic.cpp"

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:

    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for
    //Function to find if there exists a triplet in the
    //array arr[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr,arr+n);
        //int cnt=0;
        int i=0,j=0,k=0;
        for(i=0;i<n-2;i++){
            j=i+1;
            k=n-1;
            while(j<k){
                if(arr[i]+arr[j]+arr[k]==x){
          //          cnt++;
            //        j++;
              //      k--;
                    return true;
                }
                else if(arr[i]+arr[j]+arr[k] < x){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return false;

    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}
  // } Driver Code Ends
