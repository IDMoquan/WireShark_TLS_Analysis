typedef struct Pcap_Header {
    unsigned int magic;             //0xA1 B2 C3 D4:用来标示文件的开始
    unsigned short major;           //0×02 00:当前文件主要的版本号
    unsigned short minor;           //0×04 00当前文件次要的版本号
    int thiszone;                   //当地的标准时间；全零
    unsigned int sigfigs;           //时间戳的精度；全零
    unsigned int snaplen;           //最大的存储长度
    unsigned int linktype;          //链路类型*
};

/*链路常用类型：
0           BSD loopback devices, except for later OpenBSD
1           Ethernet, and Linux loopback devices
6           802.5 Token Ring
7           ARCnet
8           SLIP
9           PPP
10          FDDI
100         LLC/SNAP-encapsulated ATM
101         “raw IP”, with no link
102         BSD/OS SLIP
103         BSD/OS PPP
104         Cisco HDLC
105         802.11
108         later OpenBSD loopback devices (with the AF_value in network byte order)
113         special Linux “cooked” capture
114         LocalTalk
*/

typedef struct Pcap_Packet_Header {
    unsigned int timestamp_sec;     //时间戳高位(second)
    unsigned int timestamp_msec;    //时间戳低位(microsecond)
    unsigned int caplen;
    unsigned int len;
};

void prinfPcapFileHeader(Pcap_Header *pfh){
	if (pfh==NULL) {
		return;
	}
	printf("=====================\n"
		   "magic:0x%0x\n"
		   "version_major:%u\n"
		   "version_minor:%u\n"
		   "thiszone:%d\n"
		   "sigfigs:%u\n"
		   "snaplen:%u\n"
		   "linktype:%u\n"
		   "=====================\n",
		   pfh->magic,
		   pfh->major,
		   pfh->minor,
		   pfh->thiszone,
		   pfh->sigfigs,
		   pfh->snaplen,
		   pfh->linktype);
}

