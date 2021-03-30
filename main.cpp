#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>

using namespace std;
int count = 0;
int numberOfLine = 0;
int main()
{
    string Data[100];
    string line;

    ifstream daftar;
    ofstream fileCSV;

    daftar.open("daftar-nama.txt");
    fileCSV.open("4210191016_JoaneVanesa.csv");

    if(daftar.is_open())
    {
        while (!daftar.eof())
        {
            getline(daftar, line);
            numberOfLine++;
            int position = line.find("	");
            while (position != string::npos)
            {
                line.replace(position, 1, ",    ");
                position = line.find("	", position +1);
            }
            for (int i=0; i<1; i++)
            {
                Data[i] = line;
                cout << Data[i]<<endl;
                fileCSV << Data[i] <<endl;
            }
        }

    }daftar.close();


   daftar.open("4210191016_JoaneVanesa.csv");
   ofstream csvFile;
   csvFile.open("4210191016_JoaneVanesa.csv", ios::app);

    if(daftar.is_open())
    {
        string reverse[28];
        std::list<std::string> list;
        string buffer;
        string header = "Daftar Mahasiswa PENS";
        string header2 = "#,    Nrp,    Nama,    Jenis_kelamin";

        while(!daftar.eof())
        {
            while (getline(daftar,buffer))
            {
                list.push_front(buffer);

            }

       copy(
             list.begin(),
             list.end(),
             std::ostream_iterator<string>(csvFile, "\n")
             );
        }


}
}


