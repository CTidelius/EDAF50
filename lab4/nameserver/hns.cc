#include "hns.h"
#include <string>
#include <iostream>

using namespace std;
using std::pair;
using std::vector;
using std::hash;

HNS::HNS(size_t s): size(s), hns(s){}

void HNS::insert(const HostName& h, const IPAddress& IP){
	hash<HostName> hashVal;
	size_t s = hashVal(h)%size;
	hns[s].push_back(make_pair(h, IP));
}
bool HNS::remove(const HostName& h){
	hash<HostName> hashVal;
	size_t s = hashVal(h)%size;
	auto first = find_if(hns[s].begin(), hns[s].end(), 
		[&h](const pair<HostName, IPAddress>& elem) { return elem.first == h; });
	if (first != hns[s].end()){
		hns[s].erase(first);
		return true;
	}
	return false;
}
IPAddress HNS::lookup(const HostName& h) const{
	hash<HostName> hashVal;
	size_t s = hashVal(h)%size;
	auto first = find_if(hns[s].begin(), hns[s].end(), 
		[&h](const pair<HostName, IPAddress>& elem) { return elem.first == h; });
	if(first != hns[s].end()){
		return first->second;
	}
	return NON_EXISTING_ADDRESS;
}
