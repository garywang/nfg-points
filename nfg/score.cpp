#include <iostream>
#include <string>

using namespace std;

int main(){
	int score=0;
	string s;
	bool four=true;
	int wordLength=0;
	while(!cin.eof()){
		char c;
		cin.get(c);
		if(c=='<')
			while(c!='>' && !cin.eof())
				cin>>c;
		if(c>='A' && c<='Z')
			c+='a'-'A';
		if(c>='a' && c<='z')
			wordLength++;
		else
			wordLength=0;
		if(wordLength>4)
			four=false;
		s.push_back(c);
	}
	if(four && wordLength<=4)
		score+=100;
	if(s.find("gary")!=string::npos
			&& (s.find("cookie")!=string::npos
			|| s.find("cake")!=string::npos)
			&& (s.find("i ")!=string::npos
			|| s.find("i'll")!=string::npos)
			&& (s.find("make")!=string::npos
			|| s.find("bake")!=string::npos))
		score+=10000000;
	if(s.find("e")==string::npos)
		score+=100;
	cout<<score+1<<endl;
	return 0;
}

