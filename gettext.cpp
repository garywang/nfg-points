#include <iostream>
#include <string>

using namespace std;

int main(){
	string sep;
	do{
		getline(cin, sep);
	} while (sep=="");
	string buf;
	getline(cin, buf);
	getline(cin, buf);
	while(!cin.eof()){
		getline(cin, buf);
		if(buf==sep)
			break;
		if(buf[0]=='>')
			break;
		if(buf[0]=='O' && buf[1]=='n' && buf.find("wrote:")!=string::npos)
			break;
		cout<<buf<<endl;
	}
	return 0;
}

