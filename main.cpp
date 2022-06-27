signed main()
{
	ios_base::sync_with_stdio(NULL);
	//cin.tie(NULL); cout.tie(NULL);
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
			cout << "Let's start then! Choose your first entry:" << endl<<endl;
			printgrid(); cout<<endl;
			while(gridnotfull(grid))
			{
				int row , col, testing;
				cin >> row >> col;
				while(row>3 || row<1 || col>3 || col<0 || grid[row-1][col-1]!='_')
				{
					if(row>0 && row<=3 && col>0 && col<=3) cout << "This cell is already filled. Remember you can't overwrite! Re-enter your move." << endl;
					else cout<<"INVALID ENTRY!! Enter values in the range 1-3"<<endl<<endl;
					printgrid(); cout<<endl;		
					cin >> row >> col;
				}
				grid[row-1][col-1]=o;
				cout<<endl;
				printgrid(); cout<<endl;
				testing = eval(grid);
				if(testing<0)
				{
					cout << "You won!" << endl;
					tot_score.first++;
					break;
				}
				_move mv = bestmove(grid);
				grid[mv.r][mv.c]=p;
				if(gridnotfull(grid)){
					cout << "My turn now! Here's my move:" << endl<<endl;
					printgrid();
					cout<<endl;
				}
				testing = eval(grid);
				if(testing > 0)
				{
					cout << "Oh no! You loose." << endl;
					tot_score.second++;
					break;
				}
				if(gridnotfull(grid))cout<<"Your turn:"<<endl;
			}
			if(eval(grid)==0){
				cout << "And that's a tie. Shall we go for another round?"<< endl;
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
