// 725. Split Linked List in Parts


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
    vector<ListNode*> splitListToParts(ListNode* root, int k){
        vector<ListNode*> v;
        if(k==0) return v;
        ListNode *x=root,*temp;
        int len=0;
        while(x){
            len+=1,x=x->next;
        }
        if(len<k){
            x=root;
            while(x){
                k-=1;
                temp=x->next;
                x->next=nullptr;
                v.push_back(x);
                x=temp;
            }
            while(k--){
                v.push_back(nullptr);
            }
        }
        else{
            int t=len/k;
            int t2,t3=len%k;
            x=root;
            while(t3--){
                t2=t+1;
                v.push_back(x);
                while(t2--){
                    temp=x;
                    x=x->next;
                }
                temp->next=nullptr;
                k-=1;
            }
            while(k--){
                t2=t;
                v.push_back(x);
                while(t2--){
                    temp=x;
                    x=x->next;
                }
                temp->next=nullptr;
            }
        }
        return v;
    }
};