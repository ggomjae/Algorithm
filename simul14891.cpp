#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<deque<int> > v;
int check[4];

void init(){
   
   for(int i = 0 ; i < 4 ; ++i){
      check[i] = 0;
   }   
   
   return ;
}

void function(int realNumber , int direction){
   
   check[realNumber] = direction;

   if(realNumber-1 >= 0 && check[realNumber-1] == 0){
      if(v[realNumber-1][2] != v[realNumber][6]){
         function(realNumber-1,-direction);
      } 
   }
   
   if(realNumber+1 < 4 && check[realNumber+1] == 0){
      if(v[realNumber+1][6] != v[realNumber][2]){
         function(realNumber+1,-direction);
      }
   }
   
   return ;
}

void solved(){
   for(int i = 0 ; i < 4 ; ++i){
      if(check[i] != 0){
         if(check[i] == -1){
            v[i].push_back(v[i].front());
            v[i].pop_front();
         }else{
            v[i].push_front(v[i].back());
            v[i].pop_back();
         }
      }
   }
   
   return ;
}

int main(){
   
   for(int i = 0 ; i < 4; ++i){
      deque<int> dq;
      
      for(int j = 0 ; j < 8 ; ++j){
         int temp;
         scanf("%1d",&temp);
         dq.push_back(temp);   
      }
      v.push_back(dq);
   }
   
   int t;
   cin >> t;
   
   while(t--){
      int number,direction,realNumber;
      cin >> number >> direction;
      
      realNumber = number - 1;
     
      function(realNumber,direction);
	 
      solved();

      init();      
   }
   
   int ans = 0 ;
   
   for(int i = 0 ; i < 4 ; ++i){
      if(v[i][0]){
         if(i == 0){
            ans += 1;
         }else if( i == 1){
            ans += 2;
         }else if( i == 2){
            ans += 4;
         }else{
            ans += 8;
         }
      }
   }
   
   cout << ans << '\n';
   
   return 0;
}
