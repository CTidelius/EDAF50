#include "mns.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;
using std::map;

MNS::MNS(){}

void MNS::insert(const HostName& h, const IPAddress& IP){
	mns[h] = IP;
}
bool MNS::remove(const HostName& h){
	return mns.erase(h) == 1;
}
IPAddress MNS::lookup(const HostName& h) const{
	if (mns.find(h) != mns.end()){
		return mns.at(h);
	}
	return NON_EXISTING_ADDRESS;
}
