#include "input.h"

giris::giris(int a){
	s = a;
}

int giris::initInput(){
	inputString.reserve(100); // Hafızada 100 karakterlik yer ayrıldı.
	inputString = "";      // a String to hold incoming data
	stringComplete = false;  // whether the string is complete
	alinanKelime = "";
	prompted = false;
	kelimeAlindi = false;
	return s;
}

void giris::input(String str) {
  if (prompted == false) {
    Serial.println(str);
    prompted = true;
  }
  if (stringComplete) {
    alinanKelime = inputString;
    kelimeAlindi = true;
    inputString = "";
    stringComplete = false;
    prompted = false;
  }
}

void giris::serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    if(inChar=='q' || inChar=='Q'){Serial.println("Program sonlandı."); for(;;);}
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}

bool giris::getKelimeAlindi(){
	return kelimeAlindi;
}

void giris::setKelimeAlindi(bool k){
	kelimeAlindi = k;
}

String giris::getAlinanKelime(){
	return alinanKelime;
}
