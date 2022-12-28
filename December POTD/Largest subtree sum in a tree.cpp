/* Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

Example 1:

Input:
              1
            /   \
           2      3
          / \    / \
         4   5  6   7
Output: 28
Explanation: 
As all the tree elements are positive,
the largest subtree sum is equal to
sum of all tree elements.

Example 2:
Input:
               1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
Output: 7
Explanation: 
Subtree with largest sum is : 
  -2
 /  \ 
4    5
Also, entire tree sum is also 7.
 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function findLargestSubtreeSum() which takes the root of a binary tree and returns an integer.
 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <= 10^5
-10^3 <= tree.val <= 10^3 */

//code
class Solution {
  public:
  int solve(Node* root, int& ans){
      
      if(root == NULL)return 0; // if tree doesnot exist
      int left = solve(root->left,ans);
      int right = solve(root->right,ans);
      int currsum; 
      currsum = left + right + root->data; // find sum of left, right and root and compare it with
      // ans, if it is greater than the ans, update the ans.
      ans = max(ans, currsum);
      return currsum; // return current subtree sum for further calculation.
  }
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        //Write your code here
        int ans = INT_MIN;
        solve(root,ans);
        return ans;
        
    }
};
