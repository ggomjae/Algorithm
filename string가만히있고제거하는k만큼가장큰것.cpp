#include <string>
#include <vector>

using namespace std;

string solution(string number, int k){
	string answer = "";
	int n = number.size() - k ;
	vector<char> v;
	
	int pos = 0 ;
	
	while(n>0){
		char temp  = 0 ;
		
		for(int i = pos ; i <= number.size() - n ; ++i){
			if(temp < number[i]){
				temp = number[i];
				post = i ;
			}
		}
		n--;
		pos++;
		v.push_back(temp);
	}	
	
	for(int i = 0 ; i < v.size() ; ++i){
		answer += v[i];
	}
	return answer;
}
