#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    //map<string , vector<string>> clo;
    map<string, int> clo_num;
    for(int i = 0; i < clothes.size(); i++){
      //  clo[clothes[i][1]].push_back(clothes[i][0]);    // 종류별로 옷 정리
        clo_num[clothes[i][1]] += 1;                    //종류별 옷 개수
    }
    for(auto i : clo_num){
        //cout << i.first << i.second;
        answer *= (i.second+1);
    }
    return answer-1;
}