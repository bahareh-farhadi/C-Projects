//in this program data structures are used from the mongoose library
#include "mongoose.h"
#include <string>
#include <iostream>
using namespace std;

//this struct contains info on how to serve HTTP with mongoose
//define this struct as static since we don't want the value to change later on
static struct mg_serve_http_opts server_http;

//event handler that serves html files added to the server
static void event_handler(struct mg_connection* connect_ptr, int event, void*p);

//starts the server port and sets up HTTP server options
int init_server_port(int port);


int main(void) {

	//this is the server port which is initialized by the user
	int port;

	//request for server port number
	cout << "Please select a server port" << endl;
	cin >> port;

	//incase the user enters any value other than positive numbers
	if (cin.fail() || port<0) {
		port = 1000;
	}

	//set the server and HTTP options
	init_server_port(port);
	return 0;
}

//event handler
static void event_handler(struct mg_connection* connect_ptr, int event, void *p) {

	//if event is http request
	if (event == MG_EV_HTTP_REQUEST) {

		//serve static html files
		mg_serve_http(connect_ptr, (struct http_message *)p, server_http);
	}
}

int init_server_port(int port) {

	//mongoose event manager
	struct mg_mgr manager;

	//mongoose connection
	struct mg_connection *connect_ptr;

	//convert port number to a string
	string port_string = to_string(port);

	//get the contant char pointer to the string (since mg_bind takes a constant char pointer 
	//as its parameters we need to convert this
	static const char* port_char = port_string.c_str();

	//init mongoose
	mg_mgr_init(&manager, NULL);
	cout << "starting web serve on port " << port_char << endl;

	//create a listening connection
	connect_ptr = mg_bind(&manager, port_char, event_handler);

	//if the connection fails
	if (connect_ptr == NULL) {
		cout << "Connection Failed" << endl;
		return 1;
	}

	//set up HTTP server options
	mg_set_protocol_http_websocket(connect_ptr);
	server_http.document_root = ".";
	server_http.enable_directory_listing = "yes";
	while (true) {
		mg_mgr_poll(&manager, 1000);
	}

	//free all memory allocated
	mg_mgr_free(&manager);
	return 0;

}
