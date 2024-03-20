#include <iostream>
#include <fstream>
#include <iomanip>

double funcMap(double N)
{
    return (N*4/5)-2;
}


int main()
{
    std::string fileName = "data.csv";
    std::ifstream ifstr(fileName);

    if (ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }


    std::string outFile = "result.csv";
    std::ofstream ofstr(outFile);
    ofstr << "# N Mean" << std::endl;

    double val;
    int countVal = 1;
    double sum = 0;
    while (ifstr >> val)
    {
        double valMapp = funcMap(val);
        sum = sum + valMapp;
        double mean = sum/countVal;
        countVal++;
        ofstr << countVal << " " << std::setiosflags(std::ios::scientific) << mean << std::endl;
    }

    return 0;
}
