#include <pqxx/pqxx>
#include <iostream>

int main(int argc, char *argv[])
{

    std::string const temptable("temptable");
    try
    {
        pqxx::connection conn("dbname=mydb user=recall password=a123321b");

        // Is this connection open at the moment?
        if (!conn.is_open())
        {
            throw std::runtime_error("Connection error");
        }

        /// Standard back-end transaction, templatised on isolation level.
        pqxx::nontransaction nontx(conn, "idleJob");

        // Define some prepared statement.
        // Prepared statments are Precompiled SQL queries
        // It means you must make tables and corresponding things ready
        // if we didnt execute our first query, other preparing processes will fail
        // because there is no table to work on it at the moment!!
        conn.prepare("make_table","CREATE TABLE " +temptable +" ( mynum int );");
        nontx.exec_prepared("make_table").no_rows();


        conn.prepare("insert_items", "INSERT INTO " +temptable +" VALUES ( 10 );");
        conn.prepare("some_query", "SELECT * FROM " + temptable +';');
        conn.prepare("delete_table", "DROP TABLE " +temptable +';');

        

        /*
        if your statement takes parameters, it may also make your application significantly 
        slower! The reason is that the server works out a plan for executing the query when 
        you prepare it. At that time, of course it does not know the values for the parameters
        that you will pass. If you execute a query without preparing it, then the server 
        works out the plan on the spot, with full knowledge of the parameter values.
        
        A statement's definition can refer to its parameters as $1, $2, etc.
        example:
            connection.prepare("findtable", "select * from pg_tables where name=$1");
            work tx{c};
            result r = tx.exec_prepared("findtable", "mytable");
        
        */

        nontx.exec_prepared("insert_items").no_rows();
        pqxx::row r = nontx.exec_prepared("some_query").front();

        if(std::empty(r)) throw std::runtime_error{"Query failed"};
        
        std::cout << r[0].as<int>() << std::endl;
        
        // Now we can remove our temporary table from database
        nontx.exec_prepared("delete_table").no_rows();


        // Let's see if our temporary table removed properly:
        try
        {
          nontx.exec_prepared0("insert_items");
        }
        catch (pqxx::undefined_table const &)
        {
          // Table did not exist.  Which is what we were hoping to achieve anyway.
          std::cerr << "Table not exists!\n";
        }

        conn.close();

    }

    catch(const pqxx::sql_error& e)
    {
        std::cerr << "SQL error: " << e.what() << std::endl;
        std::cerr << "Query: " << e.query() << std::endl;
        return 1;
    }

    catch (std::runtime_error const &exc)
    {
        std::cerr << exc.what() << '\n';
        return 1;
    }

    return 0;
}