#include<iostream>
#include<fstream>
#include<queue>
#include "Head.h"
#define Pcap_File "./"

using namespace std;


int main(){
    Pcap_Header *ph;
    Pcap_Packet_Header *pph;

    ifstream pf;
    pf.open(Pcap_File, ios::in | ios::binary);
    if(!pf){
        cout << "Open File Error!" << endl;
        return -1;
    }
    pf.read(ph,sizeof(Pcap_Header));
    
    return 0;
}