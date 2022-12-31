/* There are N jobs and the start and finish time of the jobs are given in arrays start[] and end[] respectively.
Each job requires one laptop and laptops can't be shared. Find the minimum number of laptops required given that you can give your laptop to someone else
when you are not doing your job.

Example 1:

Input:
N = 3
start[] = {1, 2, 3}
end[] = {4, 4, 6}
Output:
3
Explanation:
We can clearly see that everyone's supposed to
be doing their job at time 3. So, 3 laptops
will be required at minimum.
Example 2:

Input:
N = 3
start[] = {1, 5, 2}
end[] = {2, 6, 3}
Output :
1
Explanation:
All jobs can be done using 1 laptop only.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function minLaptops() which takes an integer N and two arrays start 
and end denoting starting and ending time of N jobs and returns minimum laptops required.

Expected Time Complexity: O(N*logN)
Expected Auxiliary Space: O(N) 

Constraints:
1 ≤ N ≤ 105 
1 ≤ start[i] < end[i] ≤ 109
*/

//Greedy approach
/*1. if more than one job requires laptop at a given time and we can't share laptops then we will need more laptops to satisfy their need.

 2. sort the arrays so that we do that job first which comes first.

 3. Since to do 1st job, we require 1 laptop, so initialize lap_needed with 1.

 4. we will compare each start time with previous job's end time. If start time of current job is less than the end time of previous job, we are going to need an additional laptop.

 5. And if it is greater or equal then that means the previous job has completed it's job and freed a laptop so we can use that laptop so decrease the lap_needed.

 6. at every time we will calculate maximum laptops in use.*/

class Solution {

  public:

    int minLaptops(int N, int start[], int end[]) {

        // Code here

        sort(start, start+N); 

        sort(end, end+N);

        

        int i = 1, j = 0;

        int result = 1, lap_needed = 1;

        

        while(i<N && j<N){

            if(start[i]<end[j]){

                lap_needed++;

                i++;

            }

            else if(start[i]>=end[j]){

                lap_needed--;

                j++;

            }

            if(lap_needed>result){

                result = lap_needed;

            }

        

            

        }

        return result;

    }

};


