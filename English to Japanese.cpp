#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

// Check If the character is a vowel
bool vowel(char s){
  if(s=='a' || s=='e' ||
     s=='i' || s=='o' || 
     s=='u' || s=='n' ){
         return true; 
       }
       return false ;
}

// Check if the string is convertable in 
// japanese or not
bool check (string &s){
  int l = s.size() ;
  bool flag = 0;

  for(int i=0; i<s.size(); ++i){
    if(s[i]=='('){
      while(i<l&&s[i]!=')'){
        if(i>=l){
          return 0;
    }
        ++i;
      }
      continue;
    }
    if(i<l && s[i]==' '){
      flag = 1 ;
      continue ;
    }
    
    else if(i<l && isupper(s[i])){
      s[i] = tolower(s[i]);
    }
  }
    
  
 
  for(int i=0; i<l; ++i){
    char c = s[i] ;
    
    
    if(s[i]=='('){
      while(i<l&&s[i]!=')'){
        if(s[i]!=')' && i==l-1){
          return 0;
        }
        ++i;
      }
      flag = 1;
      continue;
    }
    else if(c == ' '){flag =1;continue  ;}
    if (vowel(c)){
      flag = 1;
      continue;
    }
    
    
    // exceptions 3 letters
    else if (i < l-2 && 
          ( (c=='t' && s[i+1]=='s'&& s[i+2] =='u') ||
            (c=='s' && s[i+1]=='h'&& s[i+2] =='i') ||
            (c=='c' && s[i+1]=='h'&& s[i+2] =='i') ||
            (c=='k' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='s' && s[i+1]=='h'&& s[i+2] =='a') ||
            (c=='c' && s[i+1]=='h'&& s[i+2] =='a') ||
            (c=='n' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='h' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='m' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='r' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='g' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='b' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='p' && s[i+1]=='y'&& s[i+2] =='a') ||
            (c=='k' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='s' && s[i+1]=='h'&& s[i+2] =='u') ||
            (c=='c' && s[i+1]=='h'&& s[i+2] =='u') ||
            (c=='n' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='r' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='h' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='m' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='b' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='p' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='g' && s[i+1]=='y'&& s[i+2] =='u') ||
            (c=='k' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='s' && s[i+1]=='h'&& s[i+2] =='o') ||
            (c=='c' && s[i+1]=='h'&& s[i+2] =='o') ||
            (c=='n' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='h' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='m' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='r' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='g' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='b' && s[i+1]=='y'&& s[i+2] =='o') ||
            (c=='p' && s[i+1]=='y'&& s[i+2] =='o')) ) {
      flag = 1; 
      i+=2; 
      continue;  
    }
    
    
    // exception 2 letters
    else if(i<l-1 &&
           ((c == 'j' && s[i+1]=='a') ||
            (c == 'j' && s[i+1]=='u') ||
            (c == 'j' && s[i+1]=='o') ||
            (c == 'k' && s[i+1]=='a') ||
            (c == 'k' && s[i+1]=='i') ||
            (c == 'k' && s[i+1]=='u') ||
            (c == 'k' && s[i+1]=='e') ||
            (c == 'k' && s[i+1]=='o') ||
            (c == 's' && s[i+1]=='a') ||
            (c == 's' && s[i+1]=='e') ||
            (c == 's' && s[i+1]=='o') ||
            (c == 's' && s[i+1]=='u') ||
            (c == 't' && s[i+1]=='a') ||
            (c == 't' && s[i+1]=='e') ||
            (c == 't' && s[i+1]=='o') ||
            (c == 'n' && s[i+1]=='a') ||
            (c == 'n' && s[i+1]=='i') ||
            (c == 'n' && s[i+1]=='u') ||
            (c == 'n' && s[i+1]=='e') ||
            (c == 'n' && s[i+1]=='o') ||
            (c == 'm' && s[i+1]=='a') ||
            (c == 'm' && s[i+1]=='i') ||
            (c == 'm' && s[i+1]=='u') ||
            (c == 'm' && s[i+1]=='e') ||
            (c == 'm' && s[i+1]=='o') ||
            (c == 'h' && s[i+1]=='a') ||
            (c == 'h' && s[i+1]=='i') ||
            (c == 'f' && s[i+1]=='u') ||
            (c == 'h' && s[i+1]=='e') ||
            (c == 'h' && s[i+1]=='o') ||
            (c == 'y' && s[i+1]=='a') ||
            (c == 'y' && s[i+1]=='o') ||
            (c == 'y' && s[i+1]=='u') ||
            (c == 'r' && s[i+1]=='a') ||
            (c == 'r' && s[i+1]=='i') ||
            (c == 'r' && s[i+1]=='u') ||
            (c == 'r' && s[i+1]=='e') ||
            (c == 'r' && s[i+1]=='o') ||
            (c == 'w' && s[i+1]=='a') ||
            (c == 'w' && s[i+1]=='o') ||
            (c == 'g' && s[i+1]=='a') ||
            (c == 'g' && s[i+1]=='i') ||
            (c == 'g' && s[i+1]=='u') ||
            (c == 'g' && s[i+1]=='e') ||
            (c == 'g' && s[i+1]=='o') ||
            (c == 'z' && s[i+1]=='a') ||
            (c == 'j' && s[i+1]=='i') ||
            (c == 'z' && s[i+1]=='u') ||
            (c == 'z' && s[i+1]=='e') ||
            (c == 'z' && s[i+1]=='o') ||
            (c == 'd' && s[i+1]=='a') ||
            (c == 'd' && s[i+1]=='e') ||
            (c == 'd' && s[i+1]=='o') ||
            (c == 'b' && s[i+1]=='a') ||
            (c == 'b' && s[i+1]=='i') ||
            (c == 'b' && s[i+1]=='u') ||
            (c == 'b' && s[i+1]=='e') ||
            (c == 'b' && s[i+1]=='o') ||
            (c == 'p' && s[i+1]=='a') ||
            (c == 'p' && s[i+1]=='i') ||
            (c == 'p' && s[i+1]=='u') ||
            (c == 'p' && s[i+1]=='e') ||
            (c == 'p' && s[i+1]=='o') ||
            (c == 'd' && s[i+1]=='u') ||
            (c == 'z' && s[i+1]=='i') ||
            (c == 'w' && s[i+1]=='i') ||
            (c == 'w' && s[i+1]=='e') ||
            (c == 'd' && s[i+1]=='i') )          
            ) {
      flag = 1;
      i+= 1;
      continue; 
    }
    // predefined letters
    
    else{
      flag = 0;
      break;
    }
  }
  return flag ;
}


void convert(string &s){// n

  int l=s.size() ;
  for(int i=0; i<l; ++i){
    char c = s[i];
    if(s[i]==' '){
      cout << ' ';
      
    }
    else if(s[i]=='('){
      cout << ' ' ;
      ++i;
      while (i<l && s[i]!=')'){
        cout << s[i] ;
        ++i ;
      }
      
      
      cout <<' ';
      
      ++i;
    }
    else if(c=='a'){
      cout << "\u3041";
    }
    else if(c=='i'){
      cout << "\u3044";
    }
    else if(c=='u'){
      cout << "\u3045";
    }
    else if(c=='e'){
      cout << "\u3047";
    }
    else if(c=='o'){
      cout << "\u3049";
    }
    else if(c=='k' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u304D" <<"\u3083";
      i+=2;
    }
    else if(c=='s' && s[i+1]=='h'&& s[i+2] =='a'){
      cout<<"\u3057" <<"\u3083";
      i+=2;
    }
    else if(c=='c' && s[i+1]=='h'&& s[i+2] =='a'){
      cout<<"\u3061" <<"\u3083";
      i+=2;
    }
    else if(c=='n' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u306B" <<"\u3083";
      i+=2;
    }
    else if(c=='h' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u3072" <<"\u3083";
      i+=2;
    }
    else if(c=='m' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u307F" <<"\u3083";
      i+=2;
    }
    else if(c=='r' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u308A" <<"\u3083";
      i+=2;
    }
    else if(c=='g' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u304E" <<"\u3083";
      i+=2;
    }
    else if(c=='b' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u3073" <<"\u3083";
      i+=2;
    }
    else if(c=='p' && s[i+1]=='y'&& s[i+2] =='a'){
      cout<<"\u3074" <<"\u3083";
      i+=2;
    }
    else if(c=='k' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u304D" <<"\u3086";
      i+=2;
    }
    else if(c=='s' && s[i+1]=='h'&& s[i+2] =='u'){
      cout<<"\u3057" <<"\u3086";
      i+=2;
    }
    else if(c=='c' && s[i+1]=='h'&& s[i+2] =='u'){
      cout<<"\u3061" <<"\u3086";
      i+=2;
    }
    else if(c=='n' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u306B" <<"\u3086";
      i+=2;
    }
    else if(c=='h' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u3072" <<"\u3086";
      i+=2;
    }
    else if(c=='m' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u307F" <<"\u3086";
      i+=2;
    }
    else if(c=='r' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u308A" <<"\u3086";
      i+=2;
    }
    else if(c=='g' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u304E" <<"\u3086";
      i+=2;
    }
    else if(c=='b' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u3073" <<"\u3086";
      i+=2;
    }
    else if(c=='p' && s[i+1]=='y'&& s[i+2] =='u'){
      cout<<"\u3074" <<"\u3086";
      i+=2;
    }
    else if(c=='k' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u304D" <<"\u3088";
      i+=2;
    }
    else if(c=='k' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u304D" <<"\u3088";
      i+=2;
    }
    else if(c=='k' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u304D" <<"\u3088";
      i+=2;
    }
    else if(c=='n' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u306B" <<"\u3088";
      i+=2;
    }
    else if(c=='s' && s[i+1]=='h'&& s[i+2] =='o'){
      cout<<"\u3057" <<"\u3088";
      i+=2;
    }
    else if(c=='c' && s[i+1]=='h'&& s[i+2] =='o'){
      cout<<"\u3061" <<"\u3088";
      i+=2;
    }
    else if(c=='m' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u307F" <<"\u3088";
      i+=2;
    }
    else if(c=='r' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u308A" <<"\u3088";
      i+=2;
    }
    else if(c=='g' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u304E" <<"\u3088";
      i+=2;
    }
    else if(c=='b' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u3073" <<"\u3088";
      i+=2;
    }
    else if(c=='p' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u3074" <<"\u3088";
      i+=2;
    }
    else if(c=='h' && s[i+1]=='y'&& s[i+2] =='o'){
      cout<<"\u3072" <<"\u3088";
      i+=2;
    }
    else if(i<l-1&&c=='j' && s[i+1]=='a'){
      cout << "\u3058" <<"\u3083";
      i+=1;
    }
    else if(i<l-1&&c=='j' && s[i+1]=='u'){
      cout << "\u3058" <<"\u3085";
      i+=1;
    }
    else if(i<l-1&&c=='j' && s[i+1]=='o'){
      cout << "\u3058" <<"\u3087";
      i+=1;
    }
    else if(i<l-1&&c=='z' && s[i+1]=='i'){
      cout << "\u3058" ;
      i+=1;
    }
    else if(i<l-1&&c=='k' && s[i+1]=='a'){
      cout << "\u304B" ;
      i+=1;
    }
    else if(i<l-1&&c=='k' && s[i+1]=='i'){
      cout << "\u304D" ;
      i+=1;
    }
    else if(i<l-1&&c=='g' && s[i+1]=='a'){
      cout << "\u304C" ;
      i+=1;
    }
    else if(i<l-1&&c=='g' && s[i+1]=='i'){
      cout << "\u304E" ;
      i+=1;
    }
    else if(i<l-1&&c=='k' && s[i+1]=='u'){
      cout << "\u304F" ;
      i+=1;
    }
    else if(i<l-1&&c=='g' && s[i+1]=='u'){
      cout << "\u3050" ;
      i+=1;
    }
    else if(i<l-1&&c=='k' && s[i+1]=='e'){
      cout << "\u3051" ;
      i+=1;
    }
    else if(i<l-1&&c=='g' && s[i+1]=='e'){
      cout << "\u3052" ;
      i+=1;
    }
    else if(i<l-1&&c=='k' && s[i+1]=='o'){
      cout << "\u3053" ;
      i+=1;
    }
    else if(i<l-1&&c=='g' && s[i+1]=='o'){
      cout << "\u3054" ;
      i+=1;
    }
    else if(i<l-1&&c=='s' && s[i+1]=='a'){
      cout << "\u3055" ;
      i+=1;
    }
    else if(i<l-1&&c=='z' && s[i+1]=='a'){
      cout << "\u3056" ;
      i+=1;
    }
    else if(i<l-1&&c=='j' && s[i+1]=='i'){
      cout << "\u3058" ;
      i+=1;
    }
    else if(i<l-2&&c=='s'&&s[i+1]=='h'&&s[i+2]=='i'){
      cout << "\u3057" ;
      i+=2;
    }
    else if(i<l-2&&c=='c'&&s[i+1]=='h'&&s[i+2]=='i'){
      cout << "\u3061" ;
      i+=2;
    }
    else if(i<l-2&&c=='t'&&s[i+1]=='s'&&s[i+2]=='u'){
      cout << "\u3063" ;
      i+=2;
    }
    else if(i<l-1&&c=='s' && s[i+1]=='u'){
      cout << "\u3059" ;
      i+=1;
    }
    else if(i<l-1&&c=='z' && s[i+1]=='u'){
      cout << "\u305A" ;
      i+=1;
    }
    else if(i<l-1&&c=='s' && s[i+1]=='e'){
      cout << "\u305B" ;
      i+=1;
    }
    else if(i<l-1&&c=='z' && s[i+1]=='e'){
      cout << "\u305C" ;
      i+=1;
    }
    else if(i<l-1&&c=='s' && s[i+1]=='o'){
      cout << "\u305D" ;
      i+=1;
    }
    else if(i<l-1&&c=='z' && s[i+1]=='o'){
      cout << "\u305E" ;
      i+=1;
    }
    else if(i<l-1&&c=='t' && s[i+1]=='a'){
      cout << "\u305F" ;
      i+=1;
    }
    else if(i<l-1&&c=='d' && s[i+1]=='a'){
      cout << "\u3060" ;
      i+=1;
    }
    else if(i<l-1&&c=='d' && s[i+1]=='u'){
      cout << "\u3065" ;
      i+=1;
    }
    else if(i<l-1&&c=='t' && s[i+1]=='e'){
      cout << "\u3066" ;
      i+=1;
    }
    else if(i<l-1&&c=='d' && s[i+1]=='e'){
      cout << "\u3067" ;
      i+=1;
    }
    else if(i<l-1&&c=='t' && s[i+1]=='o'){
      cout << "\u3068" ;
      i+=1;
    }
    else if(i<l-1&&c=='d' && s[i+1]=='o'){
      cout << "\u3069" ;
      i+=1;
    }
    else if(i<l-1&&c=='n' && s[i+1]=='a'){
      cout << "\u306A" ;
      i+=1;
    }
    else if(i<l-1&&c=='n' && s[i+1]=='i'){
      cout << "\u306B" ;
      i+=1;
    }
    else if(i<l-1&&c=='n' && s[i+1]=='u'){
      cout << "\u306C" ;
      i+=1;
    }
    else if(i<l-1&&c=='n' && s[i+1]=='e'){
      cout << "\u306D" ;
      i+=1;
    }
    else if(i<l-1&&c=='n' && s[i+1]=='o'){
      cout << "\u306E" ;
      i+=1;
    }//-*()
    else if(i<l-1&&c=='h' && s[i+1]=='a'){
      cout << "\u306F" ;
      i+=1;
    }
    else if(i<l-1&&c=='b' && s[i+1]=='a'){
      cout << "\u3070" ;
      i+=1;
    }
    else if(i<l-1&&c=='p' && s[i+1]=='a'){
      cout << "\u3071" ;
      i+=1;
    }
    else if(i<l-1&&c=='h' && s[i+1]=='i'){
      cout << "\u3072" ;
      i+=1;
    }
    else if(i<l-1&&c=='b' && s[i+1]=='i'){
      cout << "\u3073" ;
      i+=1;
    }
    else if(i<l-1&&c=='p' && s[i+1]=='i'){
      cout << "\u3074" ;
      i+=1;
    }
    else if(i<l-1&&c=='f' && s[i+1]=='u'){
      cout << "\u3075" ;
      i+=1;
    }
    else if(i<l-1&&c=='b' && s[i+1]=='u'){
      cout << "\u3076" ;
      i+=1;
    }
    else if(i<l-1&&c=='p' && s[i+1]=='u'){
      cout << "\u3077" ;
      i+=1;
    }
    else if(i<l-1&&c=='h' && s[i+1]=='e'){
      cout << "\u3078" ;
      i+=1;
    }
    else if(i<l-1&&c=='b' && s[i+1]=='e'){
      cout << "\u3079" ;
      i+=1;
    }
    else if(i<l-1&&c=='p' && s[i+1]=='e'){
      cout << "\u307A" ;
      i+=1;
    }
    else if(i<l-1&&c=='h' && s[i+1]=='o'){
      cout << "\u307B" ;
      i+=1;
    }
    else if(i<l-1&&c=='b' && s[i+1]=='o'){
      cout << "\u307C" ;
      i+=1;
    }
    else if(i<l-1&&c=='p' && s[i+1]=='o'){
      cout << "\u307D" ;
      i+=1;
    }
    else if(i<l-1&&c=='m' && s[i+1]=='a'){
      cout << "\u307E" ;
      i+=1;
    }
    else if(i<l-1&&c=='m' && s[i+1]=='i'){
      cout << "\u307F" ;
      i+=1;
    }
    else if(i<l-1&&c=='m' && s[i+1]=='u'){
      cout << "\u3080" ;
      i+=1;
    }
    else if(i<l-1&&c=='m' && s[i+1]=='e'){
      cout << "\u3081" ;
      i+=1;
    }
    else if(i<l-1&&c=='m' && s[i+1]=='o'){
      cout << "\u3082" ;
      i+=1;
    }
    else if(i<l-1&&c=='y' && s[i+1]=='a'){
      cout << "\u3083" ;
      i+=1;
    }
    else if(i<l-1&&c=='y' && s[i+1]=='u'){
      cout << "\u3085" ;
      i+=1;
    }
    else if(i<l-1&&c=='y' && s[i+1]=='o'){
      cout << "\u3087" ;
      i+=1;
    }
    else if(i<l-1&&c=='r' && s[i+1]=='a'){
      cout << "\u3089" ;
      i+=1;
    }
    else if(i<l-1&&c=='r' && s[i+1]=='i'){
      cout << "\u308A" ;
      i+=1;
    }
    else if(i<l-1&&c=='r' && s[i+1]=='u'){
      cout << "\u308B" ;
      i+=1;
    }
    else if(i<l-1&&c=='r' && s[i+1]=='e'){
      cout << "\u308C" ;
      i+=1;
    }
    else if(i<l-1&&c=='r' && s[i+1]=='o'){
      cout << "\u308D" ;
      i+=1;
    }
    else if(i<l-1&&c=='w' && s[i+1]=='a'){
      cout << "\u308E" ;
      i+=1;
    }
    else if(i<l-1&&c=='w' && s[i+1]=='i'){
      cout << "\u3090" ;
      i+=1;
    }
    else if(i<l-1&&c=='w' && s[i+1]=='e'){
      cout << "\u3091" ;
      i+=1;
    }
    else if(i<l-1&&c=='w' && s[i+1]=='o'){
      cout << "\u3092" ;
      i+=1;
    }
    else if(i<l-1&&c=='v' && s[i+1]=='u'){
      cout << "\u3094" ;
      i+=1;
    }
    else if(c=='n'){
      cout << "\u3093" ;
    }
    else if(i<l-1&&c=='d' && s[i+1]=='i'){
      cout << "\u3062" ;
      i+=1;
    } 
  }
}

string pass (string s){
    while (s.back()==' '){
        s.pop_back() ;
    }
    return s ;
}


int main ()
{
  
  system("CLS") ;
  system("COLOR A") ;
  cout << "\n\tWelcome to the English to Japanese Text Converter\n" << endl ;
  cout << "\t** Instructions :--" << endl ;
  cout << "\t1. Use correct spellings." <<endl ;
  cout << "\t2. Do not input any unnecessary words or alphabets."<<endl;
  cout << "\t3. Enter a valid Japanese Text." <<endl ;
  cout << "\t4. No other language is supported besides Japanese." <<endl ;
  cout << "\t5. If you don't want some words to be converted then enclose them in brackets - (...)"<<endl;
  cout << "\n\t\t\t- By Satish Kumar Prajapati\n\t" ;
  cout << "\t\t\t- "<<"\u3041"<<"\u308A"<<"\u304C"<<"\u3068"<<" "<<"\u3054"<<"\u3056"<<"\u3044"<<"\u307E"<<"\u3059" << endl;
  string s ;
  cout << "\n\t Enter the English Text : ";
  getline(cin , s) ;
  
  
  if (!check(s)){
  
    system("CLS") ;
    cout << "\n\t Sorry the text you entered is either invalid text or it cannot be converted to Japanese Hiragana ...\n";
    cout << "\n\tSuggestions :- "<<endl<<"\n\t**Try :- \n" ;
    cout << "\n\t1. Checking the Spelling again ...\n" ;
    cout << "\t2. Check if it is really a Japanese word ..." << endl ;
    cout << "\t3. Check if there are some unnessecary typos or digits or numbers in the text" << endl  <<endl ;
  
  cout << "\tTry again ... (Yes / No) " << endl <<"\t** Press (y) to try again -> " ;
  char opt = getch() ;
  
  if (opt == 'y' || opt == 'Y'){
    main () ;
  }
  else {
    exit(0) ;
  }
}

  else {
    cout << "\n\tJapanese :\t" ;
    convert(s) ;
    cout << endl;
    
    cout << "\n\t Press (y) to try again -> " ;
    char op = getch() ;
    if (op == 'y' || op == 'Y'){
      main();
    }
    else {
      exit(0) ;
    }
    
  }
  
}
