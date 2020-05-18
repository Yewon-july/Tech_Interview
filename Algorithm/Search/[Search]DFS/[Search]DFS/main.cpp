#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> edges[1001];
bool check_dfs[1001]={false};
bool check_bfs[1001]={false};

int n;
vector<int> ans_dfs;
vector<int> ans_bfs;

void DFS(int vertex){
    for(int i=0; i<edges[vertex].size(); i++){
        sort(edges[vertex].begin(), edges[vertex].end());
        if(check_dfs[edges[vertex][i]])continue;
        check_dfs[edges[vertex][i]]=true;

        ans_dfs.push_back(edges[vertex][i]);
        DFS(edges[vertex][i]);
    }
}

void BFS(int vertex){
    queue<int> q_bfs;
    check_bfs[vertex] = true;
    q_bfs.push(vertex);
    
    while(!q_bfs.empty()){
        int frnt = q_bfs.front();
        q_bfs.pop();
        for(int i=0; i<edges[frnt].size(); i++){
            sort(edges[frnt].begin(), edges[frnt].end());
            if(!check_bfs[edges[frnt][i]]){
                check_bfs[edges[frnt][i]] = true;
                ans_bfs.push_back(edges[frnt][i]);
                q_bfs.push(edges[frnt][i]);
            }
        }
    }
}
int main() {
    int m, v;
    cin >> n >> m >> v;
    
    for(int i=1; i<=m; i++){
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    ans_dfs.push_back(v);
    check_dfs[v]=true;
    DFS(v);
    
    ans_bfs.push_back(v);
    check_bfs[v] = true;
    BFS(v);
    for(int i=0; i<ans_dfs.size(); i++){
        cout << ans_dfs[i] << ' ';
    }
    cout << '\n';
    for(int i=0; i<ans_bfs.size(); i++){
        cout << ans_bfs[i] << ' ';
    }
    cout << '\n';
    
    
    return 0;
}
