#ifndef UMNS_H
#define UMNS_H
#include <nameserverinterface.h>
#include <string>
#include <unordered_map>


using namespace std;

class UMNS: public NameServerInterface{
public:
	UMNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
	std::unordered_map<HostName, IPAddress> umns;
};

#endif