#pragma once
#include<string>
#include<iostream>

using namespace std;
class Image
{
public:
	virtual void display() = 0;
};

class RealIMage :public Image
{
private:
	string fileName;
public:
	RealIMage(string filename)
	{
		this->fileName = filename;
		loadFromDisk(filename);
	}
	virtual void display()
	{
		cout << "Dispalying " + fileName << endl;
	}
private:
	void loadFromDisk(string fileName)
	{
		cout << "Loading " + fileName << endl;
	}
};

class ProxyImage :public Image
{

private:
	RealIMage *realImage;
	string fileName;
public:
	ProxyImage(string filename)
	{
		this->fileName = filename;
	}
	virtual void display()
	{
		if (realImage == NULL)
		{
			realImage = new RealIMage(fileName);
		}
		realImage->display();
	}
};

