#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<char,int> m;
	string str;
	int i;
	
	map<char,int>::iterator iter;
	map<char,int>::iterator max_iter = m.begin();
		
	cin >> str;
	
	for( i = 0 ; i < str.size() ; ++i ){
	
		if(str[i] >= 'a'){
			str[i] -= ('a'- 'A');	
		}
		
		iter = m.find(str[i]); // str[i] 에 해당하는 key값 iterator을 반환 
		
;		if(iter != m.end()){
			
			m[iter->first] += 1;   // m[key] = value;
		}else{  // iter == m.end() why? ind 함수는 iterator 순차열 범위에서 원하는 값을 가진 iterator 반복자 위치를 찾아서 반환한다.
                //만약 해당 값을 찾지 못하면 반환하는 iter 는 end() 를 가리킬 것이다.			
			m[str[i]] = 1;
		}
	}
	
	for( iter = m.begin()++; iter != m.end(); ++iter){
		if(max_iter->second < iter->second){
			max_iter = iter;
		}
	}
	
	for(iter = m.begin() ; iter != m.end(); ++iter){
		if(max_iter->second == iter ->second && max_iter->first != iter->first){
			cout << "?";
			return 0;
		}
	}
	cout << max_iter->first << '\n';
	
	return 0;
}
