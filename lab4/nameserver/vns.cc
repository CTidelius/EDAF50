#include "vns.h"
#include <string>
#include <iostream>

using namespace std;
using std::pair;
using std::vector;

VNS::VNS(){}

void VNS::insert(const HostName& h, const IPAddress& IP){
	vns.push_back(make_pair(h, IP));
}
bool VNS::remove(const HostName& h){
	auto first = find_if(vns.begin(), vns.end(), 
		[&h](const pair<HostName, IPAddress>& elem) { return elem.first == h; });
	if (first != vns.end()){
		vns.erase(first);
		return true;
	}
	return false;
}
IPAddress VNS::lookup(const HostName& h) const{
	auto first = find_if(vns.begin(), vns.end(), 
		[&h](const pair<HostName, IPAddress>& elem) { return elem.first == h; });
	if(first != vns.end()){
		return first->second;
	}
	return NON_EXISTING_ADDRESS;
}
