/* Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).
You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn't have an exit. 
The task is to find the largest sum of a cycle in the maze(Sum of a cycle is the sum of the cell indexes of all cells present in that cycle).

Note:The cells are named with an integer value from 0 to N-1. If there is no cycle in the graph then return -1.

Example 1:

Input:
N = 4
Edge[] = {1, 2, 0, -1}
Output: 3
Explanation: 
There is only one cycle in the graph.
(i.e 0->1->2->0)
Sum of the cell index in that cycle 
= 0 + 1 + 2 = 3.
Example 2:

Input:
N = 4 
Edge[] = {2, 0, -1, 2}
Output: -1
Explanation:
1 -> 0 -> 2 <- 3
There is no cycle in the graph.

Your task:
You dont need to read input or print anything. Your task is to complete the function largestSumCycle() which takes the integer N denoting the number of cells and the array Edge[] as input parameters and returns the sum of the largest sum cycle in the maze.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
-1 < Edge[i] < N
Edge[i] != i */
class Solution
{
  public:
  long long ans = -1;
  void dfs(int node, bool vis[], bool dfsVis[], vector<int>&Edge ){
      vis[node] = true;
      dfsVis[node] = true;
      
      if(Edge[node]!= -1){
          int adj = Edge[node];
          if(!vis[adj]){ // if the adjacent is not visited
              dfs(adj,vis,dfsVis,Edge); // we will keep calling dfs
          }
          else if(dfsVis[adj]){// as soon as we get to a node which is visited, we will check if the same node is marked visited in dfsvis array or not
                // if it is visited in dfsvis, we got one cycle so we count all nodes coming in that cycle
                 int curr = adj; // store the adjacent's value in a variable.
                 long long sum = 0;
                 do{
                     sum += curr;
                     curr = Edge[curr];
                 }while(curr!=adj);
                 ans = max(ans,sum);
              
          }
      }
      dfsVis[node] = false;
  }
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // since it is a directed graph, we will use two arrays and everytime we reach at the node through which we can't go anywhere, 
    //we will mark it to be 0 while returning in dfsVis array
    bool vis[N] = {0}; 
    bool dfsVis[N] = {0};
    for(int i = 0; i<N; i++){
        if(!vis[i]){ // if the current node is not visited
            dfs(i,vis,dfsVis,Edge); // call dfs
        }
    }
    return ans;
  }

};
