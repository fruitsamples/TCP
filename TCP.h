/*********************************************************** TCPSample.h*/#ifdef _STORAGE_	#define global#else	#define global	extern#endif/*********************************************************** Constants*/#define cReceivePort		1984		/* port number to listen for remote connection attempts with */#define cSendPort			4891		/* port number for sending to remote connection with */#define	cAnyIP				0			/* driver will return real IP if this IP address is used */#define	cAnyPort			0			/* driver will allocate a free port number if this port number is used *//*********************************************************** Data Structures*/#define	WDS(bufCount) struct {				\	wdsEntry			block[bufCount];	\	unsigned short		zero;				\}#define	RDS(bufCount) struct {				\	rdsEntry			block[bufCount];	\	unsigned short		zero;				\}/*********************************************************** Globals*/global	short		gIPPDriverRefNum;		/* driver reference number for PBControl interface */	/*********************************************************** PBControl Interface Prototypes*/OSErr _TCPInit			(void);OSErr _TCPGetIP			(struct IPParamBlock *pb, ip_addr *ip, long *netMask, ProcPtr ioCompletion, Boolean async);OSErr _TCPCreate		(TCPiopb *pb, StreamPtr *stream, Ptr rcvBufPtr, long rcvBufLen, TCPNotifyProc aNotifyProc, Ptr userDataPtr, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPPassiveOpen	(TCPiopb *pb, StreamPtr stream, ip_addr *remoteIP, tcp_port *remotePort, ip_addr *localIP, tcp_port *localPort, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPActiveOpen	(TCPiopb *pb, StreamPtr stream, ip_addr remoteIP, tcp_port remotePort, ip_addr *localIP, tcp_port *localPort, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPSend			(TCPiopb *pb, StreamPtr stream, wdsEntry *wdsPtr, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPNoCopyRcv		(TCPiopb *pb, StreamPtr stream, rdsEntry *rdsPtr, unsigned short rdsLength, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPRcv			(TCPiopb *pb, StreamPtr stream, Ptr rcvBufPtr, unsigned short *rcvBufLen, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPBfrReturn		(TCPiopb *pb, StreamPtr stream, Ptr rdsPtr, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPClose			(TCPiopb *pb, StreamPtr stream, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPAbort			(TCPiopb *pb, StreamPtr stream, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPStatus		(TCPiopb *pb, StreamPtr stream, struct TCPStatusPB *status, Ptr userData, TCPIOCompletionProc ioCompletion, Boolean async);OSErr _TCPRelease		(TCPiopb *pb, StreamPtr stream, Ptr *rcvBufPtr, long *rcvBufLen, TCPIOCompletionProc ioCompletion, Boolean async);OSErr TCPDotAddress		(char *dotAddress, ip_addr *ipAddress);pascal void ASR			(StreamPtr stream, unsigned short eventCode, Ptr userData, unsigned short terminReason, struct ICMPReport *icmpMsg);