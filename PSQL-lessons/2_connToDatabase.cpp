#include <iostream>
#include <pqxx/pqxx>

int main()
{

    try
    {
        // Connect to the database.  In practice we may have to pass some
        // arguments to say where the database server is, and so on.
        pqxx::connection conn("dbname=mydb user=recall password=a123321b");

        // Start a transaction.  In libpqxx, you always work in one.
        pqxx::work tx(conn);

        // work::exec1() executes a query returning a single row of data.
        // We'll just ask the database to return the number 1 to us.
        pqxx::row r = tx.exec1("SELECT 1, 'Hello'");

        // Commit your transaction.  If an exception occurred before this
        // point, execution will have left the block, and the transaction will
        // have been destroyed along the way.  In that case, the failed
        // transaction would implicitly abort instead of getting to this point.
        tx.commit();

        // "r[0]" returns the first field, which has an "as<...>()" member
        // function template to convert its contents from their string format
        // to a type of your choice.
        std::cout << r[0].as<int>() << std::endl;


        // You can also convert an entire row to a series of C++-side types in one go
        // using the as member function on the row.
        auto [num, line] = r.as<int, std::string>();
        std::cout << "num: " << num
                  << "\nline: " << line 
                  << std::endl;
    }

    catch(std::exception const &ex)
    {
        std::cerr << ex.what() << '\n';
        return 1;
    }

    return 0;
}