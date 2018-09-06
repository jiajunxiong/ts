/** 
*  @file    app.cpp
*  @author  Jiajun Xiong (jjxiong.hk@gmail.com)
*  @date    8/21/2018
*  @version 1.0 
*  
*  @brief fix 4.2 trading system application using QuickFIX FIX Engine
*
*  @section DESCRIPTION
*
*/

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 4267)
#else
#include "config.h"
#endif

#include "app.h"
#include "quickfix/Session.h"
#include <iostream>

Application::Application()
{
}

Application::~Application()
{
}

void Application::onLogon( const FIX::SessionID& sessionID )
{
	std::cout << std::endl << "Logon - " << sessionID << std::endl;
}

void Application::onLogout( const FIX::SessionID& sessionID )
{
	std::cout << std::endl << "Logout - " << sessionID << std::endl;
}

void Application::toAdmin(FIX::Message &message, const FIX::SessionID &sessionID)
{
	if (FIX::MsgType_Logon == message.getHeader().getField(FIX::FIELD::MsgType)) {
		//message.setField(96, "cashalgo1");
		message.setField(141, "Y");
	}
}

void Application::fromApp( const FIX::Message& message, const FIX::SessionID& sessionID )
	throw( FIX::FieldNotFound, FIX::IncorrectDataFormat, FIX::IncorrectTagValue, FIX::UnsupportedMessageType )
{
	//crack( message, sessionID );
	std::cout << std::endl << "IN: " << message << std::endl;
	if (FIX::MsgType_ExecutionReport == message.getHeader().getField(FIX::FIELD::MsgType))
		std::cout << "ExecutionReport" << std::endl;
	else if (FIX::MsgType_OrderCancelReject == message.getHeader().getField(FIX::FIELD::MsgType))
		std::cout << "Order cancel reject" << std::endl;
	else
		std::cout << "Unknow message" << std::endl;
}

void Application::toApp( FIX::Message& message, const FIX::SessionID& sessionID )
	throw( FIX::DoNotSend )
{
	try
	{
		FIX::PossDupFlag possDupFlag;
		message.getHeader().getField( possDupFlag );
		if ( possDupFlag ) throw FIX::DoNotSend();
	}
	catch ( FIX::FieldNotFound& ) {}

	std::cout << std::endl
		<< "OUT: " << message << std::endl;
}

void Application::executionReport42( const FIX42::ExecutionReport &message, const FIX::SessionID &sessionID ) 
{
	// Verify lbs order and trade 
}
void Application::orderCancelReject42( const FIX42::OrderCancelReject &message, const FIX::SessionID &sessionID)
{
	// Verify lbs order and trade 
}

void Application::newOrderSingle42( const FIX::Message& message )
{
	if (const_cast<FIX::Message&>(message).isEmpty()) return;
	FIX::Session::sendToTarget(const_cast<FIX::Message&>(message));
}

void Application::orderCancelRequest42( const FIX::Message& message )
{
	if (const_cast<FIX::Message&>(message).isEmpty()) return;
	FIX::Session::sendToTarget(const_cast<FIX::Message&>(message));
}

void  Application::orderCancelReplaceRequest42( const FIX::Message& message )
{
	if (const_cast<FIX::Message&>(message).isEmpty()) return;
	FIX::Session::sendToTarget(const_cast<FIX::Message&>(message));
}