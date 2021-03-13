/* 
    1. 위상정렬 문제...  
    2. indegree, outdegree 벡터배열을 만들기
    3. 각 함수를 만들어서 내 위로, 내 아래로 셀 수 있는 개수 세고 그게 n개 라면 순위 ok
 */
#include <string>
#include <vector>
#include <memory.h>
#define MAX 110
using namespace std;

vector <int> indegree[MAX];
vector <int> outdegree[MAX];
int visit[MAX], re_visit[MAX];
int cnt, re_cnt;

void dfs(int cur){
    if(visit[cur])
        return;
    visit[cur]=true;
    cnt++;
    for(int i = 0 ; i < indegree[cur].size(); i++ ){
        dfs(indegree[cur][i]);
    }
}
void re_dfs(int cur){
    if(re_visit[cur])
        return;
    re_visit[cur]=true;
    re_cnt++;
    for(int i = 0 ; i < outdegree[cur].size(); i++ ){
        re_dfs(outdegree[cur][i]);
    }
}
void init(){
    cnt =0;
    re_cnt=0;
    memset(visit, 0x00, sizeof(visit) );
    memset(re_visit, 0x00, sizeof(re_visit) );
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0; i<results.size(); i++){
        int a = results[i][0];
        int b = results[i][1];
        indegree[a].push_back(b);
        outdegree[b].push_back(a);
    }
    for(int i = 1 ; i <= n; i++){
        init();
        dfs(i);
        re_dfs(i);
        if(cnt+re_cnt == n - 1){
            answer++;
        }
    }

    return answer;
}