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
		
		iter = m.find(str[i]); // str[i] �� �ش��ϴ� key�� iterator�� ��ȯ 
		
;		if(iter != m.end()){
			
			m[iter->first] += 1;   // m[key] = value;
		}else{  // iter == m.end() why? ind �Լ��� iterator ������ �������� ���ϴ� ���� ���� iterator �ݺ��� ��ġ�� ã�Ƽ� ��ȯ�Ѵ�.
                //���� �ش� ���� ã�� ���ϸ� ��ȯ�ϴ� iter �� end() �� ����ų ���̴�.			
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
