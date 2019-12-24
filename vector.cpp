#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);		
	v.pop_back(); // ���������Ҹ� �����Ѵ�. 
	v.push_back(5);

	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] << '\n';
	}	
	
	cout << v.back() << '\n'; // vector �� �κп��Ҹ� �����Ѵ�. 
	cout << v.front() << '\n'; // vector ó�� �κп��Ҹ� �����Ѵ�. 
	
	vector<int> v1(3); // size() �� 3�̰� ��� 0���� �ʱ�ȭ�ȴ�. 
	
	for(int i = 0 ; i < v1.size() ; ++i){
		cout << v1[i] << '\n';
	}	
	
	v.clear(); // size()�� 0�� �ȴ�. ��� ���Ұ� clear�� �ȴ�. 
	cout << v.size() << '\n';
	
	if(v.empty()){
		cout << "������ϴ�"<< '\n';
	}  // true . 1 �� ��ȯ�Ѵ�. ������ϱ� 
	
	cout << (v == v1) << '\n'; // ��� ���Ұ� ���� 
	
	cout << "---------------------" <<'\n';
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for(vector<int>::iterator iter = v.begin() ; iter != v.end() ; ++iter ){
		cout << *iter << '\n';
	}
	
	return 0;
}
