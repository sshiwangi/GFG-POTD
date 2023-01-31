/* 
Given two strings A and B. Find minimum number of times A has to be repeated such that B is a Substring of it. If B can never be a substring then return -1.

Example 1:

Input:
A = "abcd"
B = "cdabcdab"
Output:
3
Explanation:
Repeating A three times (abcdabcdabcd),
B is a substring of it. B is not a substring
of A when it is repeated less than 3 times.
Example 2:
Input:
A = "ab"
B = "cab"
Output :
-1
Explanation:
No matter how many times we repeat A, we can't
get a string such that B is a substring of it.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minRepeats() which takes 2 strings A, and B respectively and 
returns the minimum number of times A has to be repeated such that B is a substring of it. Return -1 if it's not possible.


Expected Time Complexity: O(|A| * |B|)
Expected Auxiliary Space: O(|B|)


Constraints:
1 ≤ |A|, |B| ≤ 103
String A and B consists of lower case alphabets
*/
class Solution {
  public:
    int minRepeats(string A, string B) {
        // code here
        string org = A; // storing original string in a variable
        int moves = 1;
        while(A.length()<B.length()){ // we will keep on adding A until it's length is less than b's length
            A += org;
            moves++;
        }
        if(A.find(B)!= -1)return moves; // when the length becomes equal or greater than b's length then we will check if b is a substring or not
        A += org; // if b is not a substring then we add a one more time because it might happen that this time b becomes a substr
        moves++;
        if(A.find(B)!=-1)return moves; // if this time b becomes a substr of a, return moves
        return -1; // otherwise return -1;
    }
};
