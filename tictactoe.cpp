#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

char grid[3][3];
pair<int,int> tot_score={0,0}; //stores the overall score after any number of games
struct _move
{
	int r , c;
	_move(){
		r=0; c=0;
	}
};

char p='X';
char o='O';

bool gridnotfull(char grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(grid[i][j]=='_')
				return 1;
		}
	}
	return 0;
}

void rules(){
	cout<<"*****RULES AND REGULATIONS*****"<<endl<<endl;
	cout<<"1. The game is played on a grid that's 3 squares by 3 squares."<<endl<<"2. Your moves will be represented by 'O', and mine with 'X'."<<endl<<"3. Players take turns putting their marks in empty squares."<<endl<<"4. The first player to get 3 of their marks in a row (up, down, across, or diagonally) is the winner!"<<endl<<"5. When all 9 squares are full, the game is over. If no player has 3 marks in a row, the game ends in a tie."<<endl;
	cout<<endl<<"**********************************************"<<endl;
}
void printgrid(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<grid[i][j];
			if(j<2) cout<<"|";
			else cout<<endl;
		}
	}

}

int eval(char grid[3][3])
{
	//row victory
	for (int i = 0; i < 3; i++)
	{
		if(grid[i][0]==grid[i][1] and grid[i][1]==grid[i][2] and grid[i][1]=='X')
			return 10;
		if(grid[i][0]==grid[i][1] and grid[i][1]==grid[i][2] and grid[i][1]=='O')
			return -10;
	}
	//column victory
	for (int i = 0; i < 3; i++)
	{
		if(grid[0][i]==grid[1][i] and grid[1][i]==grid[2][i] and grid[2][i]=='X')
			return 10;
		if(grid[0][i]==grid[1][i] and grid[1][i]==grid[2][i] and grid[2][i]=='O')
			return -10;
	}
	//diagonal victory
	if(grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2] and grid[2][2]=='X')
		return 10;
	if(grid[0][0]==grid[1][1] and grid[1][1]==grid[2][2] and grid[2][2]=='O')
		return -10;
	if(grid[2][0]==grid[1][1] and grid[1][1]==grid[0][2] and grid[2][0]=='X')
		return 10;
	if(grid[2][0]==grid[1][1] and grid[1][1]==grid[0][2] and grid[2][0]=='O')
		return -10;

	return 0;
}

int minmax(char grid[3][3], int d, bool im)
{
	int score = eval(grid);
	if(score == 10)
		return 10;
	if(score == -10)
		return -10;

	if(gridnotfull(grid)==0)
		return 0;

	if(im)
	{
		int b= -100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(grid[i][j]=='_')
				{
					grid[i][j]=p;
					b=max(b,minmax(grid,d+1, !im));
					grid[i][j]='_';
				}				
			}
		}
		return b;
	}
	else
	{
		int b= 100000000;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if(grid[i][j]=='_')
				{
					grid[i][j]=o;
					b=min(b,minmax(grid,d+1, !im));
					grid[i][j]='_';
				}				
			}
		}
		return b;	
	}
}

_move bestmove(char grid[3][3])
{
	int bestval= -100000000;
	_move bestMove;
	bestMove.r = -1;
	bestMove.c = -1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if(grid[i][j]=='_')
			{
				grid[i][j] = p;
				int tmp = minmax(grid , 0 , false);
				grid[i][j]='_';
				if(tmp>bestval)
				{
					bestMove.r=i;
					bestMove.c=j;
					bestval=tmp;
				}
			}
		}
	}
	return bestMove;
}

signed main()
{
	ios_base::sync_with_stdio(NULL);
	//cin.tie(NULL); cout.tie(NULL);
	//uncomment the above line if you wish to input moves in one go.
	cout<<"Welcome to Tic-Tac-Toe!"<<endl;
	while(true)
	{
		cout <<"Enter x for new game or any other key for exiting." << endl;
		char choice;
		cin >> choice;
		if(choice=='x' || choice=='X')
		{
			//initialisation of the grid
			for(int i=0; i<3 ; i++)
				for(int j=0; j<3 ; j++)
					grid[i][j]='_';

			cout<<"Thanks for choosing to play! Rusty with the rules? Enter R for a brief introduction to the rules and regulations. If you do not need them, enter any other key to start!!"<<endl;
			cin>>choice;
			if (choice=='R' || choice=='r'){
				rules();
			}
			cout << "Let's start then! Choose your first entry:" << endl;
			printgrid();
			while(gridnotfull(grid))
			{
				int row , col, testing;
				cin >> row >> col;
				while(row>3 || row<1 || col>3 || col<0 || grid[row-1][col-1]!='_')
				{
					if(row>0 && row<=3 && col>0 && col<=3) cout << "This cell is already filled. Remember you can't overwrite! Re-enter your move." << endl;
					else cout<<"INVALID ENTRY!! Enter values in the range 1-3"<<endl;
					printgrid();		
					cin >> row >> col;
				}
				grid[row-1][col-1]=o;
				printgrid();
				testing = eval(grid);
				if(testing<0)
				{
					cout << "You won!" << endl;
					tot_score.first++;
					break;
				}
				_move mv = bestmove(grid);
				grid[mv.r][mv.c]=p;
				cout << "My turn now! Here's my move:" << endl;
				printgrid();
				testing = eval(grid);
				if(testing > 0)
				{
					cout << "Oh no! You loose." << endl;
					tot_score.second++;
					break;
				}
				cout<<"Your turn:"<<endl;
			}
			if(eval(grid)==0){
				cout << "And that's a tie. Shall we go for another game?"<< endl;
				tot_score.first++;
				tot_score.second++;
			}
		}
		else{
			cout<<"FINAL SCORE: "<<endl<<"You"<<"\t"<<"Me"<<endl<<tot_score.first<<"\t"<<tot_score.second<<endl;
			if(tot_score.first>tot_score.second){
				cout<<"Congratulations on winning!"<<endl;
			}
			else if(tot_score.first<tot_score.second){
				cout<<"You lose. Better luck next time!"<<endl;
			}
			else{
				cout<<"And that's a tie! What a thrill."<<endl;
			}
			cout<<"Thanks for joining! Hope to see you again soon~"<<endl;
			return 0;
		}
	}
}
