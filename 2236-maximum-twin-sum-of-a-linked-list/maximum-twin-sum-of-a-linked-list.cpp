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
    int pairSum(ListNode* head) {
        ListNode *temp=head;
        vector<int>v;
        int mx=0;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i<v.size()/2;i++)
        {
            int sum=v[i]+v[v.size()-i-1];
            mx=max(mx,sum);
        }
        return mx;
        
    }
};