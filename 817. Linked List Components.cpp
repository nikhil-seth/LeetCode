// 817. Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        int ctr=0;
        bool f=0;
        bool arr[10001];
        memset(arr,0,sizeof(arr));
        for(auto x:G)
            arr[x]=1;
        while(head){
            if(arr[head->val]){
                f=1;
            }
            else{
                if(f)
                    ctr++;
                f=0;
            }
            head=head->next;
        }
        if(f)
            ctr++;
        return ctr;
    }
};
