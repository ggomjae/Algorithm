#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<int> dq;

int main(){
	
	int n;
	int x;
	string str;
	
	cin >> n;
	
	while(n--){
		
		cin >> str;
		if(str == "push_front"){
			cin >> x;
			dq.push_front(x);	
		}else if(str =="push_back"){
			cin >> x;
			dq.push_back(x);
		}else if(str == "pop_front"){
			if(dq.size() == 0){
				cout << "-1" << '\n';
			}else{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}else if(str =="pop_back"){
			if(dq.size() == 0){
				cout << "-1" << '\n';
			}else{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}else if(str =="size"){
			cout << dq.size() <<'\n';
		}else if(str =="empty"){
			if(dq.size()==0){
				cout << '1' << '\n';
			}else{
				cout << '0' <<'\n';
			}
		}else if(str =="front"){
			if(dq.size()==0){
				cout << "-1" <<'\n';
			}else{
				cout << dq.front()<<'\n';
			}
		}else{
			if(dq.size()==0){
				cout << "-1" <<'\n';
			}else{
				cout << dq.back()<<'\n';
			}
		}
	}
	
	return 0;
}
