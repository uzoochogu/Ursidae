#ifndef URSIDAE_HPP
#define URSIDAE_HPP


#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>


namespace Ursidae
{
    
    class DataTable
    {
    private:	

        std::vector<std::string> column;               //column names.
        std::vector<int> index;                //default defined as 1-n, can be assigned to column. 
        std::fstream inputFile;
        std::fstream outputFile;

        std::vector<std::vector<std::string>> data;    //raw data.


    public:
        //constructors
        DataTable();
        explicit DataTable(std::string&);


        template <typename Datatype1, typename... Datatype>
        DataTable(const std::vector<std::string_view>&,
              const std::vector<Datatype1>&, const std::vector<Datatype>&...);

        
        ~DataTable();
        
        
        DataTable(const DataTable &dt);                 //copy constructor
        DataTable(DataTable&& source);                  //move constructor



        DataTable(std::vector<std::string> data);                                             //initialize with a string of comma separated values
        DataTable(std::vector<std::string> data, std::vector<std::string> specs= {0});        //Define datatype specifications
        DataTable(std::string filepath, bool isFile = false);                    	      //initialize with a csv file.
        DataTable(std::string filepath, bool isFile = false, std::vector<std::string> specs= {0});  
          

        //template<typename key, typename value>
        //DataTable(std::unordered_map<key, value> data);  
        //or  stick with
        DataTable(std::unordered_map<std::string, std::vector<std::string>>);

        DataTable(std::vector<std::vector<std::string>> data); 
        DataTable(std::vector<std::vector<std::string>> data, std::vector<std::string> specs = {0});      //An Enum can work for the specs


        //Operators
        DataTable operator=(DataTable dt);
        std::string& operator[](int index);




        //member functions
        void read_csv(std::string filepath, std::string encoding="utf8");
        void to_csv(std::string filepath);

        //more functionality here



    };


    std::vector<std::vector<std::string>> read_csv(std::string filepath, std::string encoding="utf8"); //example of overloaded function
    void to_csv(std::string filepath, std::vector<std::vector<std::string>>);


    //more functionality here





}
#endif