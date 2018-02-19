#ifndef HNS_H
#define HNS_H
#include <nameserverinterface.h>
#include <vector>
#include <algorithm>
#include <functional>


using namespace std;

class HNS: public NameServerInterface{
public:
	HNS(size_t);
    void insert(const HostName&, const IPAddress&) override;
    bool remove(const HostName&) override;
    IPAddress lookup(const HostName&) const override;
private:
	size_t size;
	std::vector<std::vector<std::pair<HostName, IPAddress>>> hns;
};

#endif