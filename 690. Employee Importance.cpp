// 690. Employee Importance

/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,Employee*> m;
    int dfs(int id){
        int val=m[id]->importance;
        for(auto x:m[id]->subordinates)
            val+=dfs(x);
        return val;
    }
    int getImportance(vector<Employee*> employees, int id){
        ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
        for(auto x:employees)
            m[x->id]=x;
        return dfs(id);
    }
};
