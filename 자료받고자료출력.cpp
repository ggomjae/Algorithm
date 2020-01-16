#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip>

using namespace std;

//변수 선언 
int _time ,price ;
string ofilePath = "data.txt";   // 데이터가 있는 파일 
string wfilePath = "result.txt"; // 가공된 데이터를 출력하는 파일 
ifstream openFile(ofilePath.data());
ofstream writeFile(wfilePath.data());
string a[5] = {"12 : 30","13 : 00","13 : 30","14 : 00","14 : 30"};

// 각 가격에 대한 정보를 담고 있는 클래스 선언  
class Information{
   public:

      int firstPrice = 0;
      int topPrice = 0;
      int downPrice = 0 ;
      int finalPrice = 0;
};

// 벡터 변수 선언 
vector<pair<string,string> > v[1000000]; 
vector<Information> result[1000000];
vector<int> v1230;
vector<int> v1300;
vector<int> v1330;
vector<int> v1400;
vector<int> v1430;

// 각 경우마다 벡터가 필요하므로 벡터초기화 하는 함수 
void init(){
   
   v1230.clear();
   v1300.clear();
   v1330.clear();
   v1400.clear();
   v1430.clear();
   
   return ;
}


// String -> Int 변환 함수 
int changeInt(string str){
   
   return atoi(str.c_str());
}

// Int -> String 변환 함수
string changeString(int val){
   
   return to_string(val);
}

// 천단위마다 콤마 찍어주는 함수 
string changeNumber(int number){
	
	string str = changeString(number);	
	
	int strl = str.length();
	
	if(strl >= 4 && strl < 7){
		str = str.substr(0,strl-3) + "," + str.substr(strl-3,3);
	}else if( strl >= 7){
	
		str = str.substr(0,strl-6) + "," + str.substr(strl-6,3) + "," + str.substr(strl-3,3);	
	} 
	
	return str;	
}

// HH:NN:SS-ZZZZZZ -> HHNNSSZZZZZ 변환 함수 
string changeTime(string time){
   
   string _time;
   
   _time = time.substr(0,2) + time.substr(3,2) + time.substr(6,2) + time.substr(9,6);
   
   return _time;
}

// 가격만 분리하는 함수 
string changePrice(string price){
   
   return price.substr(26,9);
}

//분류된 시간으로 정보를 구하고 result에 담는 함수  
void calculate(int intCode){
   
   if(v1230.size() == 0){
      Information inf;
      result[intCode].push_back(inf);
   }else{
      Information inf;
      inf.firstPrice = v1230[0];
      inf.finalPrice = v1230[v1230.size()-1];
      
      sort(v1230.begin(),v1230.end());
      
	  inf.topPrice = v1230[v1230.size()-1];
      inf.downPrice = v1230[0];
      
	  result[intCode].push_back(inf);
   }
   
   if(v1300.size() == 0){
      Information inf;
      result[intCode].push_back(inf);
   }else{
      Information inf;
      inf.firstPrice = v1300[0];
      inf.finalPrice = v1300[v1300.size()-1];
      
	  sort(v1300.begin(),v1300.end());
      
	  inf.topPrice = v1300[v1300.size()-1];
      inf.downPrice = v1300[0];
      
	  result[intCode].push_back(inf);
   }
   
   if(v1330.size() == 0){
      Information inf;
      result[intCode].push_back(inf);
   }else{
      Information inf;
      inf.firstPrice = v1330[0];
      inf.finalPrice = v1330[v1330.size()-1];
      
	  sort(v1330.begin(),v1330.end());
      
	  inf.topPrice = v1330[v1330.size()-1];
      inf.downPrice = v1330[0];
      
	  result[intCode].push_back(inf);
   }
   
   if(v1400.size() == 0){
      Information inf;
      result[intCode].push_back(inf);
   }else{
      Information inf;
      inf.firstPrice = v1400[0];
      inf.finalPrice = v1400[v1400.size()-1];
      
	  sort(v1400.begin(),v1400.end());
      
	  inf.topPrice = v1400[v1400.size()-1];
      inf.downPrice = v1400[0];
      
	  result[intCode].push_back(inf);
   }
   
   if(v1430.size() == 0){
      Information inf;
      result[intCode].push_back(inf);
   }else{
      Information inf;
      inf.firstPrice = v1430[0];
      inf.finalPrice = v1430[v1430.size()-1];
      
	  sort(v1430.begin(),v1430.end());
      
	  inf.topPrice = v1430[v1430.size()-1];
      inf.downPrice = v1430[0];
      
	  result[intCode].push_back(inf);
   }
   
   return ;
}

// 결과 파일에 써주는 함수 
void write(int intCode){
   
   if(writeFile.is_open()){
   	
      cout.setf(ios::right);
      
      writeFile << setw(6) << intCode  << "     ";
      writeFile << setw(9) << "최초가" << "     ";
      writeFile << setw(9) << "최고가" << "     ";
      writeFile << setw(9) << "최저가" << "     ";
      writeFile << setw(9) << "최종가" << "     ";
      
      writeFile << '\n';
      
      for(int i = 0 ; i < result[intCode].size() ; ++i){
         
         writeFile << setw(6) <<a[i] << "     ";
         writeFile << setw(9) << changeNumber(result[intCode][i].firstPrice)<< "     ";
         writeFile << setw(9) << changeNumber(result[intCode][i].topPrice)   << "     ";
         writeFile << setw(9) << changeNumber(result[intCode][i].downPrice)  << "     ";
         writeFile << setw(9) << changeNumber(result[intCode][i].finalPrice) << '\n';
      }
      
	  writeFile << '\n';
   }
   
   return ;
}

// 시간으로 분류하는 함수 
void solve(vector<pair<string,string> >& v,int intCode){
   
   for(int i = 0 ; i < v.size() ; ++i){
   
      _time = changeInt(v[i].first.substr(0,4));
      price = changeInt(changePrice(v[i].second));
      
      if(_time >= 1230 && _time < 1300){
         v1230.push_back(price);   
         
      }else if(_time >= 1300 && _time < 1330){
         v1300.push_back(price);
         
      }else if(_time >= 1330 && _time < 1400){
         v1330.push_back(price);
         
      }else if(_time >= 1400 && _time < 1430){
         v1400.push_back(price);
         
      }else {
         v1430.push_back(price);
      }
   }
   
   calculate(intCode);
   write(intCode);
   init();
}
 
int main(){
   
   if(openFile.is_open()){
      
	  string line;
      string code;
      int intCode;
      
      while(getline(openFile,line)){
         
         code = line.substr(15,6);
         intCode = changeInt(code);
         
         v[intCode].push_back(make_pair(changeTime(line),line));
         sort(v[intCode].begin(), v[intCode].end());   
      }
      
      for(int i = 0 ; i < 1000000 ;++i ){
      
	     if(v[i].size() == 0){
            continue;
         }      
      
	     solve(v[i],i);
      }
      
      openFile.close();
      writeFile.close();
   }
   
   return 0;
} 
