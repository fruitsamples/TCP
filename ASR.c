#include	<MacTCPCommonTypes.h>>#include	<TCPPB.h>#define		_STORAGE_	true#include	<TCP.h>pascal void ASR (StreamPtr stream, unsigned short eventCode, Ptr userData, unsigned short terminReason, struct ICMPReport *icmpMsg){	switch (eventCode) {		case TCPClosing :			DebugStr("\pTCPClosing");			break;		case TCPULPTimeout :			DebugStr("\pTCPULPTimeout");			break;		case TCPTerminate :			switch (terminReason) {				case TCPULPAbort :					DebugStr("\pTCPULPAbort");					break;				case TCPRemoteAbort :					DebugStr("\pTCPRemoteAbort");					break;				case TCPNetworkFailure :					DebugStr("\pTCPNetworkFailure");					break;				case TCPSecPrecMismatch :					DebugStr("\pTCPSecPrecMismatch");					break;				case TCPULPTimeoutTerminate :					DebugStr("\pTCPULPTimeoutTerminate");					break;				case TCPULPClose :					DebugStr("\pTCPULPClose");					break;				case TCPServiceError :					DebugStr("\pTCPServiceError");					break;			}			break;		case TCPDataArrival :			DebugStr("\pTCPDataArrival");			break;		case TCPUrgent :			DebugStr("\pTCPUrgent");			break;		case TCPICMPReceived :			switch (icmpMsg->reportType) {				case netUnreach :					DebugStr("\pTCPICMPReceived netUnreach");					break;				case hostUnreach :					DebugStr("\pTCPICMPReceived hostUnreach");					break;				case protocolUnreach :					DebugStr("\pTCPICMPReceived protocolUnreach");					break;				case portUnreach :					DebugStr("\pTCPICMPReceived portUnreach");					break;				case fragReqd :					DebugStr("\pTCPICMPReceived fragReqd");					break;				case sourceRouteFailed :					DebugStr("\pTCPICMPReceived sourceRouteFailed");					break;				case timeExceeded :					DebugStr("\pTCPICMPReceived timeExceeded");					break;				case parmProblem :					DebugStr("\pTCPICMPReceived parmProblem");					break;				case missingOption :					DebugStr("\pTCPICMPReceived missingOption");					break;			}			break;	}}