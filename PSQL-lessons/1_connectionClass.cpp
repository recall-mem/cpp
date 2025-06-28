#include <iostream>
#include <pqxx/pqxx>



int main() {

    pqxx::connection conn("dbname=mydb user=recall password=a123321b");

    pqxx::work tx(conn);

    // These are probably not of great interest, since most are 
    // derived from information supplied by the client program itself, 
    // but they are included for completeness.
    std::cout << "database name: " <<conn.dbname() << '\n'
        << "username: " <<conn.username() << '\n'
        << "hostname: " <<conn.hostname() << '\n'
        << "port: " <<conn.port() << '\n'
        << "protocol: " <<conn.protocol_version() << '\n'
        << "server version: " <<conn.server_version() << '\n'
        << "*process ID*  " <<conn.backendpid() << std::endl;

    // There are some text encoding functions
    // I'm not gonna write full code for them
    /*
        get_client_encoding () const
        set_client_encoding (zview encoding) &
        set_client_encoding (char const encoding[]) &
        encoding_id () const

        example:
            pqxx::connection::set_client_encoding("UTF8")
    */
   
    const char* user_input = "Da'nger";
    std::string safe_input = conn.quote(user_input); // returns std::string

    std::cout << user_input << '\n'
              << safe_input << std::endl;


    // And some more. just in case i probably will use future 
    /*
        cancel_query ()
 	    Attempt to cancel the ongoing query, if any. 

        close ()
 	    Explicitly close the connection. 

        get_variable (std::string_view) returns std::string
 	    Read session variable, using SQL's SHOW command. 

        connection_string () const
 	    Return a connection string encapsulating this connection's options. 
        example:
            std::quoted(conn.connection_string())
            output: "user=recall password=a123321b dbname=mydb"

    */
    

    return 0;
}