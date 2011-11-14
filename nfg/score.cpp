#include <iostream>
#include <string>

using namespace std;

int main(){
	int score=0;
	while(!cin.eof()){
		char c;
		cin>>c;
		if(c=='<')
			while(c!='>' && !cin.eof())
				cin>>c;
		if(c>='a' && c<='z')
			score--;
		else if(c>='A' && c<='Z')
			score++;
	}
	if(score>4)
		score=-10000;
	else
		score=1;
	cout<<score<<endl;
	return 0;
}

