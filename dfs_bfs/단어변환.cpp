/* 
1. dfs 활용
2. 한 알파벳씩 변경 가능....  변경 가능한 알파벳 목록 체크? xx 문자열끼리 비교해서 한개만 다른 경우 변경 진행

------
1. dfs, 각 단어별로 한개만 다른 단어들 있을때 target이랑 같다면 그때 return 아니라면 그 단어로 다시 순회
2. 사용한 단어는 체크
 */

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool used[60];
int MinCnt=60;

void dfs(string begin, string target, vector<string> words, int cnt){
    for(int i = 0 ; i < words.size(); i++){
        string word = words[i];
        int diff = 0;
        for(int j = 0; j < word.size(); j++){
            if(begin[j]!=word[j] && !used[i]){ //두 단어의 알파벳이 같지 않고, 사용되지 않은 단어라면 diff++
                diff++;
            }
        }
        if(diff == 1){ // diff 가 1일때만 dfs 순회
            if(target == word){
                MinCnt = min(cnt+1, MinCnt);
                return;
            }
            used[i] = true;
            dfs(word, target, words, cnt+1);
            used[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    dfs(begin, target, words, 0);
    if(MinCnt == 60)        //만약 60번을 돌았다면 최대 단어수 넘어가니 변환불가...-> 0
        MinCnt = 0;
    return MinCnt;
}