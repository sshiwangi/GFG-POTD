/* Given an array arr[ ] of size n having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

Example 1:

Input: 
n = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3, 3 is 4, 2 is 4 and for 4? 
since it doesn't exist, it is -1.
Example 2:

Input: 
n = 5, arr[] = [6 8 0 1 3]
Output:
8 -1 1 3 -1
Explanation:
In the array, the next larger element to 
6 is 8, for 8 there is no larger elements 
hence it is -1, for 0 it is 1, for 1 it 
is 3 and then for 3 there is no larger 
element on right and hence -1.
Your Task:
This is a function problem. You only need to complete the function nextLargerElement() that takes list of integers arr[ ] and n as input parameters and returns list of integers of length N denoting the next greater elements for all the corresponding elements in the input array.

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)

Constraints:
1 ≤ n ≤ 106
0 ≤ arri ≤ 1018 */
//code
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans; // this will store answer in reverse order
        stack<long long>st; 
        for(int i = n-1; i>=0; i--){ // traverse the array from the last
            if(st.empty()){ // if stack is empty, meaning the current element doesn't have any greater element next to it.
                st.push(arr[i]);
                ans.push_back(-1);
            }
            else if(st.top() > arr[i]){ // if stack is not empty and the top of the stack is greater than the current element then it means it is the next greater element of current element
                ans.push_back(st.top()); // so push the value of ngr that is top of stack in ans vector
                st.push(arr[i]); // and also push the current element in the stack
                    
            }
            else if(st.top()<=arr[i]){ // if the top element's value is less than the current element
                    while(!st.empty() && st.top()<arr[i]){ // then keep popping elements from the stack until a greater element is found
                        st.pop();
                    }
                    if(st.empty()){ // if in the process the stack becomes empty, do this
                        ans.push_back(-1);
                        st.push(arr[i]);
                    }
                    else if(st.top()>arr[i]){ // is the stack isn't empty and we found an element greater than the current element then push it in answer
                        ans.push_back(st.top());
                        st.push(arr[i]);
                    }
            }
        }
        vector<long long>res; // this will store the final answer in correct order
        for(int i = ans.size()-1; i>=0; i--){
            res.push_back(ans[i]);
        }
        return res;
    }
};
