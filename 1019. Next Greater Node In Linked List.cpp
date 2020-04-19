// 1019. Next Greater Node In Linked List
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        vector<int> ans;
        stack<pair<int,int>> s;
        int i=0;
        while(head){
            while(!s.empty() && s.top().first<head->val){
                ans[s.top().second]=head->val;
                s.pop();
            }
            s.push(make_pair(head->val,i++));
            ans.push_back(0);
            head=head->next;
        }
        return ans;
    }
};