// 해쉬를 사용해야 시간적으로 훨씬 효율성 높다.
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    map <string, int> d;
    //sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size(); i++){
        string str = "";
        for(int j = 0; j < phone_book[i].size(); j++){
            str += phone_book[i][j];   
            d[str]++;           //하나씩 늘려가며 증가.... 겹치는 접두어 부분이 생긴다면 1이상이 될것이다.
        }
    }
    
    for(auto a : phone_book){       //전화번호 목록에 있는게 1 이상이라면 중복..
        if(d[a] > 1){
            answer = false;
            break;
        }
    }
    return answer;
}