#include <iostream>
#include <string>

using namespace std;

int main(){
	int score=0;
	string s;
	while(!cin.eof()){
		char c;
		cin.get(c);
		if(c=='<')
			while(c!='>' && !cin.eof())
				cin>>c;
		if(c>='A' && c<='Z')
			c+='a'-'A';
		s.push_back(c);
	}
	//if(score>4)
	//	score=10000;
	//else
	//	score=1;
	if(s.find("gary")!=string::npos
			&& (s.find("cookie")!=string::npos
			|| s.find("cake")!=string::npos)
			&& (s.find("i ")!=string::npos
			|| s.find("i'll")!=string::npos)
			&& (s.find("make")!=string::npos
			|| s.find("bake")!=string::npos))
		score=1000000;
	cout<<score+1<<endl;
	return 0;
}

