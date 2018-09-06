#pragma once
/**
*  @file    rest.h
*  @author  Jiajun Xiong (jjxiong.hk@gmail.com)
*  @date    9/5/2018
*  @version 1.0
*
*  @brief fix 4.2 trading system application using QuickFIX FIX Engine
*
*  @section DESCRIPTION
*
*/
#include "cpprest/http_listener.h"
#include "cpprest/json.h"

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

#define TRACE(msg)            wcout << msg
#define TRACE_ACTION(a, k, v) wcout << a << L" (" << k << L", " << v << L")\n"

//map<utility::string_t, utility::string_t> dictionary;


