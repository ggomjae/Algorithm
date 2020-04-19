#include <string>
#include <vector>

using namespace std;

bool cal(string a, string b){
    int len = a.size();
    int count = 0 ;
    
    for(int i = 0 ; i < b.size() ; ++i){
        if(a[i] == b[i])
            count++;
        else
            count = 0 ;
        
        if(count == len)
            return false;
    }
    return true;
}

bool solution(vector<string> phone_book) {

    string arr,brr;
    
    for(int i = 0 ; i < phone_book.size() ; ++i){
        arr = phone_book[i];
        bool s = true;
        for(int j = i + 1; j < phone_book.size() ; ++j){
            brr = phone_book[j];
            if(arr.size() <= brr.size()){
                if(!cal(arr,brr))
                   return false;
            }
    
            if(arr.size() > brr.size()){
                 if(!cal(brr,arr))
                    return false;
            }
        }
    }

    return true;
}
