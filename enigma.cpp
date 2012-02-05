#include <iostream>
#include "Enigma.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>


using namespace std;

int main(int argc, char** argv){
	Enigma* enigma = new Enigma();

	int nrotors = argc-2;
	vector<Rotor*> m_rotors;
	if(argc==1){
		cout<<"You must specify a plugboard"<<endl;
		return 1;
	}
	//setup configuration of machine
	//all but the last config file specifies
	//the wiring map for the rotors

	//setup the rotors
	for(short int i=1; i<argc-1; i++){

		ifstream f_rotor(argv[i]);
				 
		if(f_rotor.is_open()){
			string rotorConfig;

			getline(f_rotor, rotorConfig);
			enigma->addRotor(rotorConfig);
			f_rotor.close();
		}
		else {
			cout<<"Unable to open rotor file"<<endl;
			exit(1);
		}

	}

	//configure the plugboard
	ifstream f_plugboard(argv[argc-1]);
	if(f_plugboard.is_open()){
		string plugboardConfig;
		getline(f_plugboard, plugboardConfig);
		if(!plugboardConfig.empty()){
			enigma->configurePlugboard(plugboardConfig);
		}
		f_plugboard.close();
	}
	else {
		cout<<"Unable to open plugboard file"<<endl;
		exit(1);
	}
	//encrypt

		char encode;
		while(cin.get(encode)){
			//only accept A-Z as input
			if(cin.eof()||cin.fail()){
				break;
			}
			if(encode>='A' && encode<='Z'){
				int enc  = encode -'A';
				int* pEnc = &enc;
				
				enigma->encrypt(pEnc);
			}
			else if(encode == ' '|| encode == '\n' || encode == '\t' || encode == '\r'){}
			else {/*throw error?*/ cerr<<"Invalid Input"<<endl; exit(1);}
		}
		//enigma->~Enigma();
	cout<<endl;
	return 0;
}
