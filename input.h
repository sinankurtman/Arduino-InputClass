#ifndef input_h
#define input_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

class giris{
	private:
	bool kelimeAlindi;
	String alinanKelime;
	bool stringComplete;
	bool prompted;
	String inputString;
	int s;

	public:
	giris(int a);
	bool getKelimeAlindi();
	void setKelimeAlindi(bool k);
	String getAlinanKelime();
	int initInput();
	void input(String str);
	void serialEvent();
};

#endif