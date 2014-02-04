// Generated by binpac_quickstart

#ifndef ANALYZER_PROTOCOL_MYSQL_MYSQL_H
#define ANALYZER_PROTOCOL_MYSQL_MYSQL_H

#include "events.bif.h"


#include "analyzer/protocol/tcp/TCP.h"

#include "mysql_pac.h"

namespace analyzer { namespace MySQL {

class MYSQL_Analyzer

: public tcp::TCP_ApplicationAnalyzer {

public:
	MYSQL_Analyzer(Connection* conn);
	virtual ~MYSQL_Analyzer();

	// Overriden from Analyzer.
	virtual void Done();
	
	virtual void DeliverStream(int len, const u_char* data, bool orig);
	virtual void Undelivered(int seq, int len, bool orig);

	// Overriden from tcp::TCP_ApplicationAnalyzer.
	virtual void EndpointEOF(bool is_orig);
	

	static analyzer::Analyzer* InstantiateAnalyzer(Connection* conn)
		{ return new MYSQL_Analyzer(conn); }

	static bool Available()
		{
		// TODO: After you define your events, || them together here.
		// See events.bif for more information
		return ( mysql_event );
		}

protected:
	binpac::MYSQL::MYSQL_Conn* interp;
	
	bool had_gap;
	
};

} } // namespace analyzer::* 

#endif