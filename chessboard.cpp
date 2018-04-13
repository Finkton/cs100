#include <iostream>
#include <string>
#include <cstring>
using namespace std;


char board[8][8];
bool turn = true;

void print_board()
{
  
  cout<<endl;
  	for(int i = 0; i < 40; i++){
    	for(int j = 0; j < 75; j++){
    		if(i%5==2 && j%9==4 && j<72) 
    		{
    			if(board[i/5][j/9]!='_') cout<<board[i/5][j/9];
    			else cout<<" ";
    		}
    		else if(i%5==0 && j%9==0 && j<72) cout<<" ";
    		else if(i%5==0 && j<72) cout<<"-";
    		else if(j%9==0 && j<72) cout<<"|";
    		else if(((i/5)%2 == (j/9)%2) && (i%5<2 || j%9<2 || i%5>3 || j%9>7) && j<72) cout<<"#";
    		//else if(board[i/5][j/9]>='A' && board[i/5][j/9] <'Z') cout<<"@";
    		else if(j==74 && i%5==2){
    			cout<<i/5;
    		}
    		else if(j==72){
    			cout<<"|";
    		}
    		else{
    			cout<<" ";
    		}
    	}
    	
    		cout<<"\n";
  	}
  	for(int i = 0; i < 9; i++){
		cout<<"--------";
	}
	char a = 'A';
	cout<<"\n";
	for(int i = 0; i < 9; i++){
		a++;
		cout<<"    "<<a<<"   ";
	}
  	
}

int main(){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			board[i][j]='_';

	//pawn white
	for(int j=0;j<8;j++)
		board[1][j]='P';

	//pawn black
	for(int j=0;j<8;j++)
		board[6][j]='p';


   //rook white
	board[7][0]='c';
	board[7][7]='c';
  //rook black
	board[0][0]='C';
	board[0][7]='C';
  //knight white
	board[7][1]='n';
	board[7][6]='n';
  //knight black
	board[0][1]='N';
	board[0][6]='N';
  //bishop white
	board[7][2]='b';
	board[7][5]='b';
  //bishop black
	board[0][2]='B';
	board[0][5]='B';
  //queen white
	board[7][3]='q';
  //queen black
	board[0][3]='Q';
  //king white
	board[7][4]='k';
  //king black
	board[0][4]='K';
	
	print_board();
}