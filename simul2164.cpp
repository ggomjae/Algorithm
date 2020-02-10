#include <iostream>
#include <deque>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	deque<int> dq;
	
	for(int i = 0 ; i < n ; ++i){
		dq.push_back(i+1);
	}
	
	
	while(true){
		
		if(dq.size() == 1){
			break;
		}
		dq.pop_front();
		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}
		
	cout << dq.front() << '\n';
	
	return 0;
}
