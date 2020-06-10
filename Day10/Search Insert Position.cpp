/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
*/
class Solution {
public:
    int searchInsert(vector<int>& A, int target) {
        int n=A.size();
        int s=0;
        int e =n-1;
        int index =n;
        while(s<=e)
        {
            int mid = s+(e-s)/2; 
            
            if(A[mid]==target)
                return mid;
            else if(A[mid]>target){
                index = mid;
               e = mid-1;
            }else
                s=mid+1;
                
        }
        return index;
    }
};
