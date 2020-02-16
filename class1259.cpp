#include <iostream>
#include <string>

using namespace std;

void function(string temp){
	
	int left = 0;
	int right = temp.size()-1;
	
	for(int i = 0 ; i < temp.size() ; ++i){
		if(temp[left] != temp[right]){
			cout << "no" << '\n';
			return ;
		}
		left++;
		right--;
	}
	
	cout << "yes" << '\n';
	return ;
}

int main(){
	
	
	string temp;
	
	while(true){
		
		cin >> temp;
		if(temp == "0"){
			break;
		}
		
		function(temp);
	}
	
	return 0;
}
