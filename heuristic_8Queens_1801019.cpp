//This code is impletentation of heuristic function to reduce the cost to some level.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool solved=false;
int cost=0;
struct chessboard{
	int matrix[8][8],queens,h,p,t;
};
vector<chessboard> q1;

bool com(chessboard board1,chessboard board2){
	return (board1.h+board1.p<board2.h+board2.p);
}


bool validity(chessboard &temporaray){
	int q=temporaray.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(temporaray.matrix[q-1][i]==1) break;
	}
	for(int j=q-2;j>=0;j--){
		if(temporaray.matrix[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) break;
		if(temporaray.matrix[j][i2]==1) return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) break;
		if(temporaray.matrix[j][i2]==1) return false;
		i2++;
	}
	return true;
}

void print(chessboard &temporaray){
	cout<<"temporaray"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<temporaray.matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Heuristic:"<<temporaray.h<<endl;
	cout<<"Cost:"<<temporaray.p<<endl;
	cout<<"No.of queens"<<temporaray.queens<<endl<<endl<<endl;
}

void states(vector<chessboard> &q1){
	chessboard temporaray;
	bool oc=true;
	int size=q1.size();
	sort(q1.begin(),q1.end(),com);
	temporaray=q1.front();
        vector<chessboard>::iterator it; 
        it = q1.begin(); 
        q1.erase(it); 
	int q=temporaray.queens;
       if(temporaray.queens==8) {
    	print(temporaray);
    	cout<<"Solution found\n"<<endl;
    	cout<<"cost is "<<cost<<endl;
    	solved=true;
    	return;
	}
	for(int i=0;i<8;i++){
		temporaray.matrix[q][i]=1;
		int pre=temporaray.p;
		temporaray.queens++;
		temporaray.h--;
		temporaray.p=pre+1;
		if(q==0||validity(temporaray)){
			print(temporaray);
			q1.push_back(temporaray);
			cost++;
		}
		temporaray.queens--;
		temporaray.h++;
		temporaray.p=pre;
		temporaray.matrix[q][i]=0;
	}
}
int main(){
	chessboard board1;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			board1.matrix[i][j]=0;
		}
	}
	board1.queens=0;
	board1.p=0;
	board1.h=(8-board1.queens);
        board1.t=0;
	q1.push_back(board1);
        while(!q1.empty()&&solved==false){
    	states(q1);	
	}
	return 0;
}
