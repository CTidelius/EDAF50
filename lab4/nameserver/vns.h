#ifndef VNS_H
#define VNS_H
#include <nameserverinterface.h>
#include <string>
#include <vector>


using namespace std;

class VNS: public NameServerInterface{
public:
	VNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
	std::vector<std::pair<HostName, IPAddress>> vns;
};

#endif