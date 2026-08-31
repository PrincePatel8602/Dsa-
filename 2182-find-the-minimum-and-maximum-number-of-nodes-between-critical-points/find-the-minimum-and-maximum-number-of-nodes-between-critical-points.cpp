/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minp=INT_MAX;
        int maxp=-1;
        vector<int>arr;
        int count=1;
        while(head->next!=NULL && head->next->next!=NULL){
            int a=head->val;
            int b=head->next->val;
            int c=head->next->next->val;
            if(b>a && b>c){
                 arr.push_back(count);
            }
            if(b<a && b<c){
                arr.push_back(count);
            }
            count++;
            head=head->next;
        }
        if(arr.size()<2){
            return {-1,-1};
        }
        for(int i=0;i<arr.size()-1;i++){
            if((arr[i+1]-arr[i])<minp){
                minp=(arr[i+1]-arr[i]);
            }
        }
       maxp=arr[arr.size()-1]-arr[0];
        return {minp,maxp};
        
    }
};