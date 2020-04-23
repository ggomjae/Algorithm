#include <string>
#include <vector>

using namespace std;
vector<int> answer;
vector<int> solution(vector<int> prices) {
    for(int i = 0 ; i < prices.size() ; ++i){
        int temp = prices[i];
        bool state = false;
        if(i == prices.size()-1){
            answer.push_back(0);
            break;
        }
        for(int j = i+1 ; j < prices.size() ; ++j){
            if(temp > prices[j]){
                answer.push_back(j-i);
                state = true;
                break;
            }
        }
        if(!state)
            answer.push_back(prices.size()-i-1);
    }
    return answer;
}
