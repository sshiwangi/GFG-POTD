/* Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the 
sequence should be adjacent in the array.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
 

Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as parameters 
and returns an integer denoting the answer. It is guaranteed that your answer will always fit in the 32-bit integer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 106
1 ≤ Arri ≤ 107 */
//code
class Solution{
public:	
    int func(int *arr, int n, int i, vector<int>&dp){
        //base case
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i]; // if the value is already been calculated, return that
        int a = func(arr,n,i+1,dp); // if we do not consider the ith element, then we can take i+1th
        int b = arr[i] + func(arr,n,i+2,dp); // when we consider the ith element, then we will add it to b and check from i+2th index
    
        int maxSum = max(a,b);
        
        return dp[i] = maxSum;
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>dp(n, -1);
	    
	    return func(arr,n,0,dp);
	}
};
