#include <string>
#include <vector>
using namespace std;
int answer = 0;
int number;
int ans;
vector<int> temp;
void cal(int pa , int pr){
    if(pa == number){
        if(pr == ans)
            answer++;
        return ;
    }
    cal(pa +1 , pr - temp[pa]);
    cal(pa +1 , pr + temp[pa]);
    return ;
}
int solution(vector<int> numbers, int target) {
    number = numbers.size();
    temp = numbers;
    ans = target;
    cal(0,0);
    return answer;
}
