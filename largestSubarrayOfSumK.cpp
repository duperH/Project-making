//Variable size sliding window
//Longest Subarray of sum K
#include<iostream>
#include<vector>

using namespace std;
int longestSubarray(int arr[], int n, int k){
    int i=0, j=0, maxSub=0;
    long long sum=0;
    while(j<n){
        sum+=arr[j];
        if(sum<k)
            j++;
        else if(sum==k){
            maxSub=max(maxSub, j-i+1);
            j++;
        }
        else if(sum>k){
            while(sum>k){
                sum-=arr[i];
                i++;
                if(sum==k)
                    maxSub=max(maxSub, j-i+1);
            }
            j++;
        }
    }
    return maxSub;
}
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Length of the longest sub-array: "<<longestSubarray(arr, n, k)<<endl;
    return 0;
}
