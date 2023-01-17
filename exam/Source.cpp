#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class picture_qosimov
{
private:
	string line;
	string line2;
	fstream file;
	fstream file2;

public:
	picture_qosimov() 
	{
		this->line = "";
	}
	picture_qosimov(string filename) 
	{
		this->line = filename;
		this->file.open(this->line, fstream::in | fstream::out | fstream::app|fstream::binary);
	}
	picture_qosimov(const picture_qosimov& other) {
		this->line = other.line;
	}
	~picture_qosimov()
	{
		this->file.close();
	}
	bool read(string &filename)
	{
		if (this->line != filename) 
		{
			return false;
		}
		if (this->file.is_open()) 
		{
			cout << "otkrito" << endl;
			return true;
		}
		
	}
	void read_pic( string line) 
	{
		
		if (read(line) )
		{
			char ar;
			file2.open("result.txt", fstream::in | fstream::out | fstream::app | fstream::binary);
			while (file.get(ar)) {
				cout << ar;
				file2 << ar;
				line2 += ar;
				ar =' ';

			}
			file2.close();
		}
	}
	bool write(string filename)
	{
		if (this->line != filename)
		{
			return false;
		}
		if (this->file.is_open())
		{
			return true;
		}
	}
	void write_pic(string filename)
	{
		
			fstream dobav;
			string address=filename;
			char ar2;
			dobav.open(address, fstream::in | fstream::out | fstream::app | fstream::binary);
			file2.open("result.txt", fstream::in | fstream::out | fstream::app | fstream::binary);
			while (dobav.get(ar2))
			{
				file2 << ar2;
				
			}
			cout << "otvet zapisan na fayl result.txt" << endl;
		
		
	}
	
};
int main() {
	setlocale(LC_ALL, "rus");
	string filename = "Source.bmp";
	string filename2 = "Source2.bmp";
	picture_qosimov picture(filename);
	picture.read_pic(filename);
	picture.write_pic(filename2);

	/*file.open(filename, fstream::in | fstream::out | fstream::app|fstream::binary);
	file.read()*/

	
}