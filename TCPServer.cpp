#include "stdafx.h"
#include "IDEAI_TCPServer.h"


IDEAI_TCPServer::IDEAI_TCPServer(int port)
{
	try
	{
		//Server UI

		// �Ҧ�asio�����ݭnio_service��H
		boost::asio::io_service io_service;
		Ip_addr = "default";
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), port));

		for (;;)
		{
			// socket��H
			tcp::socket socket(io_service);
			// ���ݪ���Client�ݳs���i��
			std::cout << "Waiting for connect......" << std::endl;
			acceptor.accept(socket);
			std::cout << "Connected..." << std::endl;
			// ��ܳs���i�Ӫ�Client��
			std::cout << socket.remote_endpoint().address() << std::endl;
			Ip_addr = socket.remote_endpoint().address().to_string();
			//�qClient�ݱ���message
			boost::array<char, 128> buf;
			boost::system::error_code error;
			size_t len = socket.read_some(boost::asio::buffer(buf), error);
			std::string mac(buf.data(), len);
			Mac_addr = mac;
			// �VClient�ݵo�ehello world!
			std::string message = "Byebye";
			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(message), ignored_error);

			if (Ip_addr != "default")
			{
				break;
			}
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}


IDEAI_TCPServer::~IDEAI_TCPServer()
{
}


std::string IDEAI_TCPServer::GetIP_addr()
{
	return Ip_addr;
}
std::string IDEAI_TCPServer::GetMac_addr()
{
	return Mac_addr;
}