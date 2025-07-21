// Sample Program-1: Create a program in Cpp that implements a Finite Automata to validate strings that start with 'a' and end with 'b'.
#include <iostream>
#include <string>
using namespace std;

bool compute_finite_automata(string s){
    // vector<string>states={"q0","q1","q2","q3"};
    // vector<string>input_chars={"a","b"};
    int n=s.length();
    string start_state="q0";
    string end_state="q1";
    string current_state="q0";
    for(int i=0;i<n;i++){
        current_state =func(s[i],current_state);
        if(current_state=="q1"){
            return false;
        }
    }
    return current_state=="q3";
    }

string func(char s,string current_state){
    if(current_state=="q0"){
        if(s=='b'){
            return "q1";
        } else if(s=='a'){
            return "q2";
        }
    } else if(current_state=="q1"){
        return "q1";
    } else if(current_state=="q2"){
        if(s=='b'){
            return "q3";
        } else if(s=='a'){
            return "q2";
        }
    } else{
        if(s=='a'){
            return "q2";
        } else if(s=='b'){
            return "q3";
        }
    }
    return "0";
}

int main(){
    string s="abb";
    bool b=compute_finite_automata(s);
    if(b==1){
        cout<<"String Accepted"<<endl;
    } else{
        cout<<"String Rejected"<<endl;
    }
  
}