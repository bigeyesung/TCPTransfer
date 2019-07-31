#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <string>
#include <iostream>
using boost::asio::ip::tcp;

#pragma once
class IDEAI_TCPServer
{
private:
	std::string Ip_addr;
	std::string Mac_addr;
public:
	IDEAI_TCPServer(int port);
	~IDEAI_TCPServer();
	std::string GetIP_addr();
	std::string GetMac_addr();
};

