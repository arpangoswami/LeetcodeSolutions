class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,vector<string>> adjList;
        map<string,int> indegree;
        vector<string> sol;
        set<string> recipeSet;
        int n = recipes.size();
        for(int i=0;i<n;i++){
            for(string x:ingredients[i]){
                adjList[x].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
            recipeSet.insert(recipes[i]);
        }
        queue<string> q;
        for(string x:supplies){
            q.push(x);
        }
        while(!q.empty()){
            string foodItem = q.front();
            q.pop();
            if(recipeSet.count(foodItem)){
                sol.push_back(foodItem);
            }
            for(string x:adjList[foodItem]){
                if(indegree.count(x) && indegree[x] == 1){
                    q.push(x);
                    indegree.erase(x);
                }else{
                    indegree[x]--;
                }
            }
        }
        return sol;
    }
};