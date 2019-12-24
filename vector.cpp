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
	v.pop_back(); // 마지막원소를 제거한다. 
	v.push_back(5);

	for(int i = 0 ; i < v.size() ; ++i){
		cout << v[i] << '\n';
	}	
	
	cout << v.back() << '\n'; // vector 끝 부분원소를 참조한다. 
	cout << v.front() << '\n'; // vector 처음 부분원소를 참조한다. 
	
	vector<int> v1(3); // size() 는 3이고 모두 0으로 초기화된다. 
	
	for(int i = 0 ; i < v1.size() ; ++i){
		cout << v1[i] << '\n';
	}	
	
	v.clear(); // size()가 0가 된다. 모든 원소가 clear가 된다. 
	cout << v.size() << '\n';
	
	if(v.empty()){
		cout << "비었습니다"<< '\n';
	}  // true . 1 을 반환한다. 비었으니까 
	
	cout << (v == v1) << '\n'; // 모든 원소가 같은 
	
	cout << "---------------------" <<'\n';
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for(vector<int>::iterator iter = v.begin() ; iter != v.end() ; ++iter ){
		cout << *iter << '\n';
	}
	
	return 0;
}
