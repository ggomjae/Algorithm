#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int t= 5;
	int cnt = 0;
	bool check = false;
	
	while(t--){
		string str;
		cin >> str;
		cnt++;
		bool status = false;
		
		for(int i = 0 ; i < str.length() ; ++i){
			if(str[i] == 'F' && i + 2 < str.length()){
				if(str[i+1] == 'B' && str[i+2] == 'I'){
					status = true;
					check = true;
					break;
				}
			}
		}
		
		if(status)
			cout << cnt << " " ;
		
	}	
	
	if(!check)
		cout << "HE GOT AWAY!" <<'\n';
	return 0;
}
