/* 
1. dfs 활용
2. +- 로 하나씩 넘기면 마지막 체크
 */

#include <string>
#include <vector>

using namespace std;
int buho[2] = {1,-1};
int target_cnt=0;

void dfs(int num, int order, int target, vector<int> numbers){
    if(order == numbers.size()){  //  초기엔 order 로 비교... 그러면 마지막까지 검사 못함.. -> 맨 처음 순서를 0 부터 시작하여 마지막 검사후 +1 된게 크기와 같다면 조건문 검사
        if(num == target){
            target_cnt++;
        }
        return;
    }

    for(int i = 0 ; i < 2; i++){
        num += buho[i]*numbers[order];
        dfs(num, order+1, target, numbers);
        num -= buho[i]*numbers[order];
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(0, 0, target,numbers);
    answer = target_cnt;
    return answer;
}