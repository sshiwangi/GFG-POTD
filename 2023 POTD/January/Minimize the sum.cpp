/* You are given N elements, you can remove any two elements from the list, note their sum, and add the sum to the list. 
Repeat these steps while there is more than a single element in the list. The task is to minimize the sum of these chosen sums.

Example 1:

Input:
N = 4
arr[] = {1, 4, 7, 10}

Output:
39

Explanation:
Choose 1 and 4, Sum = 1 + 4 = 5.
arr[] = {5, 7, 10} 
Choose 5 and 7, Sum = 5 + (5 + 7) = 17.
arr[] = {12, 10} 
Choose 12 and 10, Sum = 17 + (12 + 10) = 39.
arr[] = {22}
 
Example 2:

Input:
N = 5
arr[] = {1, 3, 7, 5, 6}

Output:
48
 
Your Task:

You don't need to read input or print anything. The task is to complete the function minimizeSum() which takes N as size of arr array and a arr array. 
Your task is to minimize the sum of these chosen sums and return it.

Expected Time Complexity: O(N * log(N))
Expected Auxiliary Space: O(N)

Constraints:

1 <= N, arr[i] <= 105 */

//code
class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>>pq; //Take a min queue
        for(int i = 0; i<arr.size(); i++){
            pq.push(arr[i]);
        }
        int sum = 0;
        // Take out two numbers and add their sum to the final answer and push their sum back in the queue
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int currSum = first + second;
            sum += currSum;
            pq.push(currSum);
        }
        return sum;
    }
};
