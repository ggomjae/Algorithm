#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> one = {1,2,3,4,5};
vector<int> two = {2,1,2,3,2,4,2,5};
vector<int> thr = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> t(3);
    for(int i=0; i<answers.size(); i++) {
        if(answers[i] == one[i%one.size()]) t[0]++;
        if(answers[i] == two[i%two.size()]) t[1]++;
        if(answers[i] == thr[i%thr.size()]) t[2]++;
    }
    int tm = *max_element(t.begin(),t.end());
    for(int i = 0; i< 3; i++) {
        if(t[i] == tm) answer.push_back(i+1);
    }
    return answer;
}
