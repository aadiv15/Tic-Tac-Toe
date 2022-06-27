void printgrid(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<grid[i][j];
			if(j<2) cout<<"|";
			else cout<<endl;
		}
	}

}