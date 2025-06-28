#include <pqxx/pqxx>
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{

    if(!argv[1] || !argv[2])
    {
        throw std::runtime_error("2 String Required!");
    }

    try
    {
        pqxx::connection conn("dbname=mydb user=recall password=a123321b");

        pqxx::work tx(conn);

        // work::exec() returns a full result set, which can consist of any
        // number of rows.
        pqxx::result r = tx.exec("SELECT $1, $2", pqxx::params{argv[1], argv[2]});


        tx.commit();

        // Print the first field of the first row.  Read it as a C string,
        // just like std::string::c_str() does.
        std::cout << r[0][0].c_str() << ' ' << r[0][0].c_str() << std::endl;

    }

    catch(std::exception const &ex)
    {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    return 0;
}