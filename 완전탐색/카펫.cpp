/* 
1. 가로가 세로보다 크거나 같댜.
2. 주어진 타일 개수로 카펫의 넓이를 알 수 있다. (가로 세로의 최대 길이는 넓이의 제곱근...) 
3. for문으로 하나씩 검증?
*/
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int carpet = brown+yellow;
    for(int i = 3; i <= sqrt(carpet); i++){
        if(carpet%i == 0){          //조건추가.. 나누어지는경우만 가로 세로 구할 수 있다.
            int garo = carpet / i;
            
            if((garo*2 + i*2 - 4) == brown){
                answer.push_back(garo);
                answer.push_back(i);
            }
        }
    }

    return answer;
}