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
	char from[500], thread[500]="/mit/garywang/mail_scripts/ec-discuss/threads/", subject[400];
	double multiplier=1;
	cin.getline(from, 500);
	cin.getline(subject, 400);
	cin>>multiplier;
	strcat(thread, subject);
	//cout<<thread<<endl;
	ofstream threadout(thread, ios::out | ios::app);
	if(multiplier!=1)
		threadout<<"* "<<multiplier<<" ";
	threadout<<from<<endl;
	threadout.close();
	ifstream pointsin("/mit/garywang/mail_scripts/ec-discuss/points");
	map<string, double> points;
        while(!pointsin.eof()){
                string s;
		double p;
                pointsin>>s;
                if(pointsin.eof())
                        break;
		pointsin>>p;
                //cerr<<s<<" "<<p<<endl;
		points[s]=p;
        }
	pointsin.close();
	ifstream threadin(thread);
	while(!threadin.eof()){
		string s;
		double p=1;
		threadin>>s;
		if(s=="*")
			threadin>>p>>s;
		if(threadin.eof())
			break;
		if(points.count(s)==0)
			points[s]=0;
		if(s!=string(from))
			points[s]+=p;
		//cout<<s<<points[s]<<endl;
	}
	points[string(from)]+=multiplier;
	threadin.close();
	vector<pair<double, string> > vec;
	for(map<string, double>::iterator it=points.begin(); it!=points.end(); it++){
		vec.push_back(pair<double, string>(it->second, it->first));
		//pointsout<< it->first<<" "<< it->second <<endl;
	}
	sort(vec.begin(), vec.end());
	ofstream pointsout("/mit/garywang/mail_scripts/ec-discuss/points");
	for(int n=vec.size()-1; n>=0; n--){
		//cout<<n<<endl;
		pointsout.precision(12);
		pointsout<<vec[n].second<<" "<<vec[n].first<<endl;
	}
	pointsout.close();
	return 0;
}
