#ifndef MNS_H
#define MNS_H
#include <nameserverinterface.h>
#include <string>
#include <map>


using namespace std;

class MNS: public NameServerInterface{
public:
	MNS();
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
	std::map<HostName, IPAddress> mns;
};

#endif