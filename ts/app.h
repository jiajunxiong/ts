/**
*  @file    app.h
*  @author  Jiajun Xiong (jjxiong.hk@gmail.com)
*  @date    8/21/2018
*  @version 1.0
*
*  @brief fix 4.4 trading system application using QuickFIX FIX Engine
*
*  @section DESCRIPTION
*
*/

#ifndef TS_APP_H
#define TS_APP_H

#include "quickfix/Application.h"
#include "quickfix/Values.h"
#include "quickfix/Mutex.h"

#include "quickfix/fix42/NewOrderSingle.h"
#include "quickfix/fix42/ExecutionReport.h"
#include "quickfix/fix42/OrderCancelRequest.h"
#include "quickfix/fix42/OrderCancelReject.h"
#include "quickfix/fix42/OrderCancelReplaceRequest.h"

class Application :
    public FIX::Application {
  private:
    void onCreate( const FIX::SessionID& ) {}
    void onLogon( const FIX::SessionID& sessionID );
    void onLogout( const FIX::SessionID& sessionID );
	void toAdmin(FIX::Message&, const FIX::SessionID&);
    void toApp( FIX::Message&, const FIX::SessionID& )
    throw( FIX::DoNotSend );
    void fromAdmin( const FIX::Message&, const FIX::SessionID& )
    throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::RejectLogon ) {}
    void fromApp( const FIX::Message& message, const FIX::SessionID& sessionID )
    throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType );

public:

	Application();
	~Application();

    void newOrderSingle42(const FIX::Message& message);
    void orderCancelRequest42(const FIX::Message& message);
    void orderCancelReplaceRequest42(const FIX::Message& message);

	void executionReport42(const FIX42::ExecutionReport&, const FIX::SessionID&);
	void orderCancelReject42(const FIX42::OrderCancelReject&, const FIX::SessionID&);
};

#endif