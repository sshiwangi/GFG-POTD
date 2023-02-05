/* Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

Example 1:

Input:
LinkList1 = 3->6->9->common
LinkList2 = 10->common
common = 15->30->NULL
Output: 15
Explanation:
Y ShapedLinked List
Example 2:

Input: 
Linked List 1 = 4->1->common
Linked List 2 = 5->6->1->common
common = 8->4->5->NULL
Output: 8
Explanation: 

4              5
|              |
1              6
 \             /
  8   -----  1 
   |
   4
   |
  5
  |
  NULL       
Your Task:
You don't need to read input or print anything. The task is to complete the function intersetPoint() which takes the pointer to the head of linklist1(head1) and linklist2(head2) as input parameters and returns data value of a node where two linked lists intersect. If linked list do not merge at any point, then it should return -1.
Challenge : Try to solve the problem without using any extra space.

Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ N + M ≤ 2*105
-1000 ≤ value ≤ 1000 */

//code
class Solution
{
public:
    int length(Node* head){
        int l = 0;
        Node* temp = head;
        while(temp!= NULL){
            
            temp = temp -> next;
            l++;
        }
        return l;
    }
    int intersectPoint(Node* head1, Node* head2)
    {
        // Your Code Here
        int l1 = length(head1);
        int l2 = length(head2);
        
        Node* ptr1;
        Node* ptr2;
        int d = 0;
        
        if(l1>l2){ // we will ptr1 at the longer linked list
            d = l1-l2;
            ptr1 = head1;
            ptr2 = head2;
        }
        else{
            d = l2-l1;
            ptr1 = head2;
            ptr2 = head1;
        }
        
        while(d){
            ptr1 = ptr1->next;
            if(ptr1 == NULL)return -1;
            d--;
        }
        while(ptr1!=NULL && ptr2 !=NULL){
            if(ptr1 == ptr2)return ptr1->data;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return -1;
    }
};


 
