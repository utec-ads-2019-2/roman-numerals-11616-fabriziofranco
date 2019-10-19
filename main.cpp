#include <iostream>
using namespace std;

int from_roman_to_dec(char actual, char next){
    if(actual=='I'){
        if(next=='V' or next=='X')
            return -1;
        return 1;}
    else if(actual=='V')
        return 5;
    else if(actual=='X'){
        if(next=='L' or next=='C')
            return -10;
        return 10;}
    else if(actual=='C'){
        if(next=='D' or next=='M')
            return -100;
        return 100;}
    else if(actual=='M')
        return 1000;
    else if(actual=='D')
        return 500;
    else
        return 50;
}



string from_arabic_to_roman(const string& number){
    string answer;
    int base;
    switch(number.length()){
        case 1:
            base =1;
            break;
        case 2:
            base=10;
            break;
        case 3:
            base=100;
            break;
        default:
            base=1000;

    }
    auto y=0;
    if(base==1000){
        int actual=number[y]-'0';
        for(auto i=0; i<actual;i++){
            answer+="M";
        }
        y++;
        base/=10;
    }
    if(base==100){
        int actual=number[y]-'0';
        if(actual<4){
            for(auto i=0;i<actual;i++)
                answer+="C";
        }
        else if(actual==4)
            answer+="CD";
        else if(actual==9)
            answer+="CM";
        else{
            answer+="D";
            for(int i=10-actual;i<5;i++)
                answer+="C";
        }
        y++;
        base/=10;
    }
    if(base==10){
        int actual=number[y]-'0';
        if(actual<4){
            for(auto i=0;i<actual;i++)
                answer+="X";
        }
        else if(actual==4)
            answer+="XL";
        else if(actual==9)
            answer+="XC";
        else{
            answer+="L";
            for(int i=10-actual;i<5;i++)
                answer+="X";
        }
        y++;
        base/=10;
    }
    if(base==1){
        int actual=number[y]-'0';
        if(actual<4){
            for(auto i=0;i<actual;i++)
                answer+="I";
        }
        else if(actual==4)
            answer+="IV";
        else if(actual==9)
            answer+="IX";
        else{
            answer+="V";
            for(int i=10-actual;i<5;i++)
                answer+="I";
        }
    }

    return answer;
}


int main(){
    string number;
    int result;
    while(cin>>number){
        if(isalpha(number[0])){
            result=0;
            for(size_t i=0,j=1;i<number.size();i++,j++){
                result+=from_roman_to_dec(number[i],number[j]);
            }
            cout<<result<<endl;
        }
        else{
            cout<<from_arabic_to_roman(number)<<endl;
        }
    }
    return 0;
}