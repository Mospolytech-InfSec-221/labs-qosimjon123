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
	char bin[8];
	int colichestvo = 256 * 256 * 3;
	int special_info[54];
	int weight = 231;
	int height = 231;

public:
	picture_qosimov() 
	{
		this->line = "";
	}
	picture_qosimov(string filename) 
	{
		this->line = filename;
		this->file.open(this->line, fstream::in | fstream::out | fstream::app | fstream::binary);
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
	/*char ascii_to_bin(int x) {
		bin[8];
		int j = 0;
		int i;
		for (i = 1; i < 9; i++) {
			if ((x | (1 << 8 - i)) == x) {
				bin[j] = '1';
			}
			else {
				bin[j] = '0';
			};
			j++;
		}
		return bin;*/
	//}
	bool read_pic( string line) 
	{
		
		if (read(line) )
		{
			char ar;
			file2.open("result.txt", fstream::in | fstream::out | fstream::app | fstream::binary);
			while (file.get(ar)) {
				int a=ar;
				cout << a;
				file2 << ar;
				line2 += ar;
				ar =' ';

			}
			file2.close();
			return true;
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
	picture_qosimov& change_channel(char choice, double num) 
	{

	}
	void change_noir(string filename) {
		ofstream file_noir;
		file_noir.open("result.txt", ios_base::binary);
		int raschet;
		
		for (int i = 0; i < 54; i++)
			file_noir << special_info[i];


		for (int i = 0; i < this->colichestvo; i += 3) {
			if (i >= this->colichestvo) { break; }
			raschet = 0;
			for (int j = 0; j < 3; j++) {
				if (j >= this->colichestvo) { break; }
				raschet += line2[i + j];
			}
			line2[i] = line2[i + 1] = line2[i + 2] = raschet / 3;
		}
		char* c = const_cast<char*>(line2.c_str());
		
		file_noir.write(c, 256 * 256 * 3);
		file_noir.close();
	}
	void change_color(char cvet, double num) {
		char bufer;
		int pixel;
		for (int i = 0; i < 54; i++) {
			bufer = file.get();

		}
		while (file.get(bufer)) {
			std::cout << int(bufer) << " ";
		}
		cout << "vse";
	};
	void change_color(std::string filename, char cvet, double num) {
		std::ofstream fout;
		fout.open("result.text", std::ios_base::binary);
		int raschet;
		for (int i = 0; i < 54; i++)
			fout << special_info[i];
		int iiiii;
		if (cvet == 'r') {
			iiiii = 0;
		}
		else if (cvet == 'g') {
			iiiii = 1;
		}
		else if (cvet == 'b') {
			iiiii = 2;
		}
		for (int i = iiiii; i < this->colichestvo; i += 3) {
			if (i >= this->colichestvo) { break; }
			raschet = line2[i] * num;
			if (raschet > 255) {
				line2[i] = 255;
			}
			else if (raschet < 0) {
				line2[i] = 0;
			}
			else {
				line2[i] = raschet;
			}
		}
		char* c = const_cast<char*>(line2.c_str());
		fout.write(c, 256 * 256 * 3);
		fout.close();
	};

	picture_qosimov& change_noir() {};
	bool flop() {
		
		ifstream filecopy(this->line);
		if (!filecopy.is_open()) {
			cout << "cant open file " << endl;
			return false;
		}
		string data;
		string line;
		while (getline(file, line))
		{
			data += line;
		}
		ofstream file_to("Source_copy.txt");
		if (file_to.is_open() != true) {
			cout << "cant open copy file" << endl;
			return false;
		}
		int k = size(data);
		cout << k << endl;
		for (int i = 0; i < height / 2; i++) {
			for (int j = 0; j < weight; j++) {
				char tmp = data[i * weight + j];
				data[i * weight + j] = data[(231 - i) * weight + j];
				data[i * weight + j] = tmp;
			}
		}

		for (auto i : data) {
			file_to << i;
		}
		cout << "horisontal reversed picture" << endl;
		filecopy.close();
		file_to.close();
		return true;
	}
	bool flip() {

		ifstream file(this->line);
		if (!file.is_open()) {
			cout << "cant open file" << endl;
			return false;
		}
		string data;
		string line;
		while (getline(file, line))
		{
			data += line;
		}
		ofstream file_to("Source_copy2.txt");
		if (file_to.is_open() != true) {
			cout << "cant open copy file" << endl;
			return false;
		}
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < weight / 2; j++) {
				char tmp = data[i + j * weight];
				data[i + j * weight] = data[i + (231 - j) * weight];
				data[i + j * weight] = tmp;
			}
		}
		for (auto i : data) {
			file_to << i;
		}
		cout << "kartina izmeneno" << endl;
		file.close();
		file_to.close();
		return true;
	}
	picture_qosimov& rotate() {}
	
};
int main() {
	setlocale(LC_ALL, "rus");
	string filename = "Source.bmp";
	string filename2 = "Source2.bmp";
	picture_qosimov picture(filename);
	///*picture.read_pic(filename);*/
	picture.change_color(3, 34);
	picture.change_noir();
	picture.flip();
	picture.flop();
	

	

	
}