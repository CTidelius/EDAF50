#include "umns.h"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
using std::unordered_map;

UMNS::UMNS(){}

void UMNS::insert(const HostName& h, const IPAddress& IP){
	umns[h] = IP;
}
bool UMNS::remove(const HostName& h){
	return umns.erase(h) == 1;
}
IPAddress UMNS::lookup(const HostName& h) const{
	if (umns.find(h) != umns.end()){
		return umns.at(h);
	}
	return NON_EXISTING_ADDRESS;
}
