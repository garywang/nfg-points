#include <iostream>
#include <string>

using namespace std;

int main(){
	string sep;
	getline(cin, sep);
	string buf;
	getline(cin, buf);
	getline(cin, buf);
	while(!cin.eof()){
		getline(cin, buf);
		if(buf==sep)
			break;
		if(buf[0]=='>')
			break;
		cout<<buf<<endl;
	}
	return 0;
}

