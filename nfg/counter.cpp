#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	char from[500], thread[500]="/mit/garywang/mail_scripts/nfg/threads/", subject[400];
	cin.getline(from, 500);
	cin.getline(subject, 400);
	strcat(thread, subject);
	//cout<<thread<<endl;
	ofstream threadout(thread, ios::out | ios::app);
	threadout<<from<<endl;
	threadout.close();
	ifstream pointsin("/mit/garywang/mail_scripts/nfg/points");
	map<string, int> points;
        while(!pointsin.eof()){
                string s;
		int p;
                pointsin>>s;
                if(pointsin.eof())
                        break;
		pointsin>>p;
                //cout<<s<<" "<<p<<endl;
		points[s]=p;
        }
	pointsin.close();
	ifstream threadin(thread);
	while(!threadin.eof()){
		string s;
		getline(threadin, s);
		if(threadin.eof())
			break;
		if(points.count(s)==0)
			points[s]=0;
		if(s!=string(from))
			points[s]++;
		//cout<<s<<points[s]<<endl;
	}
	points[string(from)]++;
	threadin.close();
	vector<pair<int, string> > vec;
	for(map<string, int>::iterator it=points.begin(); it!=points.end(); it++){
		vec.push_back(pair<int, string>(it->second, it->first));
		//pointsout<< it->first<<" "<< it->second <<endl;
	}
	sort(vec.begin(), vec.end());
	ofstream pointsout("/mit/garywang/mail_scripts/nfg/points");
	for(int n=vec.size()-1; n>=0; n--){
		//cout<<n<<endl;
		pointsout<<vec[n].second<<" "<<vec[n].first<<endl;
	}
	pointsout.close();
	return 0;
}
