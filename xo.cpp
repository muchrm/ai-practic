#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>
using namespace std;

int index=-1;
char getPlayer(int i) {
    switch(i) {
        case 1:
            return 'O';
        
        case 2:
            return 'X';
        default:
			return ' ';
    }
}
//ggggggggggggg
//****
//ggggggggggggg
//****
//ggggggggggggg
//5555555
//ggggggggggggg
//5555555
//987
//44445
//ทดสอบการแก้ไข
//ทดลอง commit
void draw(int b[9]) {
    cout << " " << getPlayer(b[0]) << " | " << getPlayer(b[1]) << " | " << getPlayer(b[2]) << endl;
    cout << "---+---+---" << endl;
    cout << " " << getPlayer(b[3]) << " | " << getPlayer(b[4]) << " | " << getPlayer(b[5]) << endl;
    cout << "---+---+---" << endl;
    cout << " " << getPlayer(b[6]) << " | " << getPlayer(b[7]) << " | " << getPlayer(b[8]) << endl;
}

void playerMove(int board[9], int player) {
    int move;
    do {
        cout << "\nEnter move ([0..8]): ";
        cin >> move;
        cout << endl;
    } while (move >= 9 || move < 0 || board[move] != 0);
    board[move] = player;
}

int checkscore(int arr[]){
    int index[8][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }, { 2, 4, 6 } };
    for(int i=0;i<8;i++)
     {
        if(arr[index[i][0]]==arr[index[i][1]]&&arr[index[i][0]]==arr[index[i][2]])
        {
			if(arr[index[i][0]]==1)
				return -1;
			else if(arr[index[i][0]]==2)
				return 1;
		}
     }
   return 0;
}


int check(int arr[]){
    int index[8][3] = { { 0, 1, 2 }, { 3, 4, 5 }, { 6, 7, 8 }, { 0, 3, 6 }, { 1, 4, 7 }, { 2, 5, 8 }, { 0, 4, 8 }, { 2, 4, 6 } },score = 0;
    for(int i=0;i<8;i++)
     {
		int sumo=0,sumx=0;
        if(arr[index[i][0]]==arr[index[i][1]]&&arr[index[i][0]]==arr[index[i][2]])
        {
			if(arr[index[i][0]]==1)
				sumo=50;
			else if(arr[index[i][0]]==2)
				sumx=50;
		}
		else
        {
        if(arr[index[i][0]]==1)
        sumo++;
        if(arr[index[i][1]]==1)
        sumo++;
        if(arr[index[i][2]]==1)
        sumo++;
        if(arr[index[i][0]]==2)
        sumx++;
        if(arr[index[i][1]]==2)
        sumx++;
        if(arr[index[i][2]]==2)
        sumx++;
        sumx=pow(2,sumx);
        sumo=pow(2,sumo);
        }
        score+=sumx-sumo;
     }
  return score;
}

int boardMove(int b[9], int count) {
	int min=INT_MAX-1,max=INT_MIN+1,indexmax=0,indexmin=0;
	if(count<=8){
    for(int i=0;i<9;i++){
        if(b[i] == 0){
			int board[9];
			for(int j=0;j<9;j++){
				board[j]=b[j];
			}
            if ( count % 2 == 0 )
                board[i]=1;
            else
                board[i]=2;
                int num=0;
                int num2=check(board);
				if(count<8)
						num=boardMove(board, count+1);
				if(num2>num)
					num=num2;
                if(max<num)
                    {
                        max=num;
                        indexmax=i;
                    }
                if(min>num)
                    {
                        min=num;
                        indexmin=i;
                    }
            }
	}
}
    if ( count % 2 == 0 )
        {
            index=indexmin;
            return min;
        }
    else
        {
            index=indexmax;
            return max;
        }
}

int main()
{

    int board[9] = {0,0,0,0,0,0,0,0,0};

    for(int i = 0; i < 9; i++) {
        system("cls");
        draw(board);
        if ( i % 2 == 0 )
            playerMove(board, 1);
        else{
            boardMove(board, i);
            board[index]=2;
            index=-1;
        }
        if(checkscore(board)!=0)
        break;
    }
    system("cls");
    draw(board);
    if(checkscore(board)==-1)
			cout<<"O Win!!"<<endl;
	else if(checkscore(board)==1)
		cout<<"X Win"<<endl;
	else
		cout<<"Draw!!"<<endl;
}
