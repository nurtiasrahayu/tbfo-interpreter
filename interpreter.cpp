//Irma Safitri (14117067)
//Nurul Fauzia Azizah(14117071)
//Nurtias Rahayu (14117086)

#include <bits/stdc++.h>
using namespace std;

int matrix[19][128];
void setNull() {
	matrix[0][32] = 0;
	for(int i = 0 ; i < 128 ; i++){
    	matrix[7][i] = 7;
  	}
	
	matrix[0][99] = 1;
	matrix[1][101] = 2;
	matrix[2][116] = 3;
	matrix[3][97] = 4;
	matrix[4][107] = 5;
	
	matrix[0][67] = 1;
	matrix[1][69] = 2;
	matrix[2][84] = 3;
	matrix[3][65] = 4;
	matrix[4][75] = 5;
	
	matrix[5][32] = 6;
	matrix[6][32] = 6;
	matrix[6][34] = 7;
	
	matrix[6][40]=18;
	matrix[6][41]=18;
	matrix[6][42]=18;
	matrix[6][43]=18;
	matrix[6][45]=18;
	matrix[6][47]=18;
	matrix[6][48]=18;
	matrix[6][49]=18;
	matrix[6][50]=18;
	matrix[6][51]=18;
	matrix[6][52]=18;
	matrix[6][53]=18;
	matrix[6][54]=18;
	matrix[6][55]=18;
	matrix[6][56]=18;
	matrix[6][57]=18;
	
	matrix[18][40]=18;
	matrix[18][41]=18;
	matrix[18][42]=18;
	matrix[18][43]=18;
	matrix[18][45]=18;
	matrix[18][47]=18;
	matrix[18][48]=18;
	matrix[18][49]=18;
	matrix[18][50]=18;
	matrix[18][51]=18;
	matrix[18][52]=18;
	matrix[18][53]=18;
	matrix[18][54]=18;
	matrix[18][55]=18;
	matrix[18][56]=18;
	matrix[18][57]=18;
	matrix[18][32]=18;
	matrix[18][59]=19;
	
  	matrix[7][34]=8;
  	matrix[8][32]=8;
  	matrix[8][59]=9;
  	matrix[0][115]=10;
  	matrix[10][101]=11;
  	matrix[11][108]=12;
  	matrix[12][101]=13;
  	matrix[13][115]=14;
  	matrix[14][97]=15;
  	matrix[15][105]=16;
  	matrix[16][32]=16;
  	matrix[16][59]=17;
  	matrix[0][83]=10;
  	matrix[10][69]=11;
  	matrix[11][76]=12;
  	matrix[12][69]=13;
  	matrix[13][83]=14;
  	matrix[14][65]=15;
  	matrix[15][73]=16;
}
bool operasi(char cek){
    return ( cek=='+' || cek=='-' || cek=='*' || cek=='/' || cek=='(' || cek==')' );
}
bool digit(char cek){
    return (cek >= '0' && cek <= '9');
}
int perintahoperasi(int x, int y, char z){
    if(z=='+'){
        return x+y;
    }else if(z=='-'){
        return x-y;
    }else if(z=='*'){
        return x*y;
    }else{
        return x/y;
    }
}
int penting(char cek){
    switch(cek){
    	case '+' :
    	case '-' : return 1;
    	case '*' :
    	case '/' : return 2;
    	case '(' :
    	case ')' : return 3;
    	default  : return -1;
    }
}
int init(string inputan){
    stack<int> str;
    stack<char> operatorr;

    int sementara=0;
    int i=0;
    while(i<inputan.length()){
        char karakter = inputan[i];
        if(digit(karakter)){
            sementara = (sementara*10) + (int)( karakter - '0');
        }else if(operasi(karakter)){
            if( karakter=='('){
			    operatorr.push(karakter);
                sementara=0;
			}else if(str.empty()){
                str.push(sementara);
                operatorr.push(karakter);
                sementara=0;
			}else if(karakter==')'){
                str.push(sementara);
                while(operatorr.top() != '('){
                    karakter=operatorr.top();
                    operatorr.pop();
                    sementara=str.top();
                    str.pop();
                    int pre = str.top();
                    str.pop();
                    sementara = perintahoperasi(pre,sementara, karakter);
                    str.push(sementara);
                }
                operatorr.pop();
                str.pop();
            }else{
                char prec = operatorr.top();
                if(prec=='('){
                    str.push(sementara);
                    operatorr.push(karakter);
                    sementara=0;
                }else if(penting(karakter) > penting(prec)){
                    str.push(sementara);
                    operatorr.push(karakter);
                    sementara=0;
                }else{
                    int prevval = str.top();
                    str.pop();
                    char prevop = operatorr.top();
                    operatorr.pop();
                    prevval=perintahoperasi(prevval,sementara,prevop);
                    str.push(prevval);
                    operatorr.push(karakter);
                    sementara=0;
                }
            }
        }
        i++;
    }
    while(!operatorr.empty()){
        int prev = str.top();
        str.pop();
        char preop = operatorr.top();
        operatorr.pop();
        sementara = perintahoperasi(prev,sementara,preop);
    }
    return sementara;
}
bool salah(int states){
  	if(states < 0){
    	return true;
  	}else{
    	return false;
  	}
}
bool akhir(int states){
  	if(states == 9 || states == 17 || 19){
    	return true;
  	}else{
    	return false;
  	}
}
bool berakhir(int states){
  	if(states == 17){
    	return true;
  	}else{
    	return false;
  	}
}
void operasiii(string *x, char y){
    *x = *x + y;
}
void kataaa(string *x, char y){
  	*x = *x + y;
}
void state(string x, bool *selesai){
	int i = 0;
  	int state = 0;
  	string kata="\0";
  	string oper="\0";

  	while(i < x.length() && salah(state) == false){
    	state = matrix[state][x[i]];
    	if(state == 7 && x[i] != 34){
        	kataaa(&kata, x[i]);
    	}else if(state==18 && x[i] != 59){
        	operasiii(&oper,x[i]);
    	}
    	i++;
  	}
	if(salah(state) == true || akhir(state) == false ){
    	kata = "\0";
    	cout << "Kode tidak sesuai dengan peraturan\n";
    	return;
	}else{
    	if(berakhir(state) == true){
        	cout << "Terimakasih sudah menggunakan compiler ini";
        	*selesai = true;
    	}else if(state==19){
        	int sementara = init(oper);
        	cout << "> " << sementara << endl;
    	}else{
    		cout << "> " << kata << endl;	
		} 
    	return;
  	}
}
void compile(){
  	string inputan;
  	bool selesai = false;
  	
	while(selesai == false){
    	cout <<"# ";
    	getline(cin,inputan);
    	state(inputan, &selesai);
  	}
}
void null(int matrix[19][128]){
  	for(int i = 0 ; i < 19 ; i++){
    	for(int j = 0 ; j < 128 ; j++){
    		matrix[i][j] = -1;
    	}
  	}
}
int main(){
  	null(matrix);
  	setNull();
  	compile();

  	return 0;
}
