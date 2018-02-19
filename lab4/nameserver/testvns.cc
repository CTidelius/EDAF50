#include <iostream>
#include <fstream>
#include <sstream>
#include <vns.h>
#include <mns.h>
#include <umns.h>


using namespace std;
using std::cout;
using std::endl;
void testVNS(VNS vns){
    vns.insert("hej", 1);

    cout << "Satte in " << vns.lookup("hej")<< " i vektorn"<<endl;
    if (vns.remove("hej")){
        cout << "hej har " << vns.lookup("hej") << " värden i vektorn"  << endl;
    }else{
        cout<<"Fanns inte i vektorn" <<endl;
    }
    
}
void testMNS(MNS mns){
    mns.insert("banan", 1);
    cout << "Satte in " << mns.lookup("banan")<< " i mappen"<<endl;
    if (mns.remove("banan")){
        cout << "Banan har " << mns.lookup("banan") << " värden i mappen" << endl;

    }else{
        cout<<"Kunde inte hitta värdet i mappen" <<endl;
    }
    
}
void testUMNS(UMNS umns){
    umns.insert("calle", 1);
    cout << "Satte in " << umns.lookup("calle")<< " i mappen"<<endl;
    if (umns.remove("calle")){
        cout << "calle har " << umns.lookup("calle") << " värden i mappen" << endl;

    }else{
        cout<<"Kunde inte hitta värdet i mappen" <<endl;
    }
    
}

int main(){
	VNS vns;
    testVNS(vns);
	MNS mns;
    testMNS(mns);
    UMNS umns;
    testUMNS(umns);
}