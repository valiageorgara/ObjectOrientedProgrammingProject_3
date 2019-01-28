#include"header.h"

#include<iostream>
#include<ostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>
#include <iomanip>

int Proton::numberOfProtons=0;
int Neutron::numberOfNeutrons=0;
int Electron::numberOfElectrons=0;
int Positron::numberOfPositrons=0;
int Neutrino::numberOfNeutrinos=0;
int Antineutrino::numberOfAntineutrinos=0;
int Photon::numberOfPhotons=0;
int Fermion::numberOfFermions=0;
int Boson::numberOfBosons=0;

int main(int argc,char*argv[]){
	
	srand (time(NULL));

	
	int M,N;
	
	if (argc !=3){
		cout<< "You should give 2 arguments."<< endl;
		return -1;
	}
	M=atoi(argv[1]);
	N=atoi(argv[2]);
	
	//////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	//first question and second question
	
	int randomParticle;
	int i;
	//Particle * p[M];
	vector<Particle *> myParticle;
	int oldtotalElectricCharge=0;
	double oldtotalMass=0;
	float oldtotalSpin=0;
	
	
	
	for(i=0;i<M;i++){
		int randomParticle = rand() % 7 +1; // 7 because there are 7 particles
		
		
		switch(randomParticle) {
			case(1):
				myParticle.push_back(new Proton());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(2):
				myParticle.push_back(new Neutron());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(3):
				myParticle.push_back(new Electron());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(4):
				myParticle.push_back(new Positron());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(5):
				myParticle.push_back(new Neutrino());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(6):
				myParticle.push_back(new Antineutrino());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
			case(7):
				myParticle.push_back(new Photon());
				oldtotalElectricCharge=oldtotalElectricCharge+myParticle[i]->electricCharge ;
				oldtotalMass=oldtotalMass+myParticle[i]->mass;
				oldtotalSpin=oldtotalSpin+myParticle[i]->spin;
				continue;
		}
		
	}
	

	int oldProtons=Proton::numberOfProtons  ;
	int oldElectrons=Electron::numberOfElectrons;
	int oldNeutrons=Neutron::numberOfNeutrons;
	int oldPositrons=Positron::numberOfPositrons;
	int oldNeutrinos=Neutrino::numberOfNeutrinos;
	int oldAntineutrinos=Antineutrino::numberOfAntineutrinos;
	int oldPhotons=Photon::numberOfPhotons ;
	int oldFermions=Fermion::numberOfFermions;
	int oldBosons=Boson::numberOfBosons;
	cout<<"Number of particles that have been constructed:" << endl
		<<"Protons: "       << oldProtons<< endl
		<<"Electrons: "     << oldElectrons<< endl
		<<"Neutrons: "      << oldNeutrons<< endl
		<<"Positrons: "     << oldPositrons<< endl
		<<"Neutrinos: "     << oldNeutrinos<< endl
		<<"Antineutrinos:  "<< oldAntineutrinos<< endl
		<<"Photons: "       << oldPhotons<< endl
		<<"IN TOTAL: "<<"Fermions: " <<oldFermions<< endl
		<<"          "<<"Bosons:   " <<oldBosons<< endl;
		
	cout<<"Total electric charge: " << oldtotalElectricCharge<< endl;
	
	
	cout << "///////////////////////////////////////////"<< endl;
	cout << "///////////////////////////////////////////"<< endl;

		
	//////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	//third question
	int j;
	int newtotalElectricCharge=oldtotalElectricCharge;
	double newtotalMass=oldtotalMass;
	float newtotalSpin=oldtotalSpin;
	
	
	for(j=0;j<N;j++) {
			i = rand() % M; 
			cout<< "checking for myParticle[" <<i<<"]" <<endl; 
			/////////////////interactions
			if(i==M-1){ //////////last in vector case
				if(((myParticle[i]->returnType() == "Neutron")&& (myParticle[i-1]->returnType() == "Neutrino"))|| ((myParticle[i]->returnType() == "Neutrino")&& (myParticle[i-1]->returnType() == "Neutron"))) {
						cout << "An interaction has happened between a neutron and a neutrino" << endl;
						myParticle.push_back(new Proton());
						myParticle.push_back(new Electron());
						newtotalElectricCharge=newtotalElectricCharge-myParticle[i]->electricCharge-myParticle[i-1]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge;
						newtotalMass=newtotalMass-myParticle[i]->mass-myParticle[i-1]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass;
						newtotalSpin=newtotalSpin-myParticle[i]->spin-myParticle[i-1]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin;
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i];
						myParticle.erase(myParticle.begin() + i);
						delete myParticle[i-1];
						myParticle.erase(myParticle.begin() + (i-1));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;
					
				}
				else if(((myParticle[i]->returnType() == "Proton")&& (myParticle[i-1]->returnType() == "Antineutrino"))|| ((myParticle[i]->returnType() == "Antineutrino")&& (myParticle[i-1]->returnType() == "Proton"))) {
						cout << "An interaction has happened between a proton and an antineutrino" << endl;
						myParticle.push_back(new Neutron());
						myParticle.push_back(new Positron());
						newtotalElectricCharge=newtotalElectricCharge-myParticle[i]->electricCharge-myParticle[i-1]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge;
						newtotalMass=newtotalMass-myParticle[i]->mass-myParticle[i-1]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass;
						newtotalSpin=newtotalSpin-myParticle[i]->spin-myParticle[i-1]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin;						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i];
						myParticle.erase(myParticle.begin() + i);
						delete myParticle[i-1];
						myParticle.erase(myParticle.begin() + (i-1));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Proton")&& (myParticle[i-1]->returnType() == "Electron"))|| ((myParticle[i]->returnType() == "Electron")&& (myParticle[i-1]->returnType() == "Proton"))) {
						cout << "An interaction has happened between a proton and an electron" << endl;
						myParticle.push_back(new Neutron());
						myParticle.push_back(new Neutrino());
						newtotalElectricCharge=newtotalElectricCharge-myParticle[i]->electricCharge-myParticle[i-1]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge;
						newtotalMass=newtotalMass-myParticle[i]->mass-myParticle[i-1]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass;
						newtotalSpin=newtotalSpin-myParticle[i]->spin-myParticle[i-1]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin;

						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i];
						myParticle.erase(myParticle.begin() + i);
						delete myParticle[i-1];
						myParticle.erase(myParticle.begin() + (i-1));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Electron")&& (myParticle[i-1]->returnType() == "Positron"))|| ((myParticle[i]->returnType() == "Positron")&& (myParticle[i-1]->returnType() == "Electron"))) {
						cout << "An interaction has happened between an electron and a positron" << endl;
						myParticle.push_back(new Photon());
						myParticle.push_back(new Photon());
						newtotalElectricCharge=newtotalElectricCharge-myParticle[i]->electricCharge-myParticle[i-1]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge;
						newtotalMass=newtotalMass-myParticle[i]->mass-myParticle[i-1]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass;
						newtotalSpin=newtotalSpin-myParticle[i]->spin-myParticle[i-1]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin;

						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i];
						myParticle.erase(myParticle.begin() + i);
						delete myParticle[i-1];
						myParticle.erase(myParticle.begin() + (i-1));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Photon")&& (myParticle[i-1]->returnType() == "Photon"))) {
						cout << "An interaction has happened between two photons" << endl;
						myParticle.push_back(new Electron());
						myParticle.push_back(new Positron());
						newtotalElectricCharge=newtotalElectricCharge-myParticle[i]->electricCharge-myParticle[i-1]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge;
						newtotalMass=newtotalMass-myParticle[i]->mass-myParticle[i-1]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass;
						newtotalSpin=newtotalSpin-myParticle[i]->spin-myParticle[i-1]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin;
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i];
						myParticle.erase(myParticle.begin() + i);
						delete myParticle[i-1];
						myParticle.erase(myParticle.begin() + (i-1));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				
			}
			else{ /////somewhere in the middle or first case
				if(((myParticle[i]->returnType() == "Neutron")&& (myParticle[i+1]->returnType() == "Neutrino"))||((myParticle[i]->returnType() == "Neutrino")&& (myParticle[i+1]->returnType() == "Neutron"))) {
						cout << "An interaction has happened between a neutron and a neutrino" << endl;
						myParticle.insert(myParticle.begin() +i,new Electron());
						myParticle.insert(myParticle.begin() +i ,new Proton());
						newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge-myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
						newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass-myParticle[i+2]->mass-myParticle[i+3]->mass;
						newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin-myParticle[i+2]->spin-myParticle[i+3]->spin;

						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;
					
				}
				else if(((myParticle[i]->returnType() == "Proton")&& (myParticle[i+1]->returnType() == "Antineutrino"))|| ((myParticle[i]->returnType() == "Antineutrino")&& (myParticle[i+1]->returnType() == "Proton"))) {
						cout << "An interaction has happened between a proton and an antineutrino" << endl;
						myParticle.insert(myParticle.begin() +i,new Positron());
						myParticle.insert(myParticle.begin() +i ,new Neutron());
						newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge-myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
						newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass-myParticle[i+2]->mass-myParticle[i+3]->mass;
						newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin-myParticle[i+2]->spin-myParticle[i+3]->spin;						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Proton")&& (myParticle[i+1]->returnType() == "Electron"))|| ((myParticle[i]->returnType() == "Electron")&& (myParticle[i+1]->returnType() == "Proton"))) {
						cout << "An interaction has happened between a proton and an electron" << endl;
						myParticle.insert(myParticle.begin() +i,new Neutrino());
						myParticle.insert(myParticle.begin() +i ,new Neutron());
						newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge-myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
						newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass-myParticle[i+2]->mass-myParticle[i+3]->mass;
						newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin-myParticle[i+2]->spin-myParticle[i+3]->spin;
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Electron")&& (myParticle[i+1]->returnType() == "Positron"))|| ((myParticle[i]->returnType() == "Positron")&& (myParticle[i+1]->returnType() == "Electron"))) {
						cout << "An interaction has happened between an electron and a positron" << endl;
						myParticle.insert(myParticle.begin() +i,new Photon());
						myParticle.insert(myParticle.begin() +i ,new Photon());
						newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge-myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
						newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass-myParticle[i+2]->mass-myParticle[i+3]->mass;
						newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin-myParticle[i+2]->spin-myParticle[i+3]->spin;
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				else if(((myParticle[i]->returnType() == "Photon")&& (myParticle[i+1]->returnType() == "Photon"))) {
						cout << "An interaction has happened between two photons" << endl;
						myParticle.insert(myParticle.begin() +i,new Positron());
						myParticle.insert(myParticle.begin() +i ,new Electron());
						newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge-myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
						newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass-myParticle[i+2]->mass-myParticle[i+3]->mass;
						newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin-myParticle[i+2]->spin-myParticle[i+3]->spin;
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER INSERTION"<<endl;
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						delete myParticle[i+2];
						myParticle.erase(myParticle.begin() + (i+2));
						//for(int k=0;k<myParticle.size();k++){
						//	cout<<myParticle[k]->returnType()<<endl;
						//}
						//cout<<"AFTER ERASE"<<endl;
						cout << "///////////////////////////////////////////"<< endl;	
				}
				
			}
			/////////////////////decays//////////////////////////////
			if(myParticle[i]->returnType() == "Neutron"){
				cout << "A decay has happened with a neutron" << endl;
				myParticle.insert(myParticle.begin() +i ,new Antineutrino());
				myParticle.insert(myParticle.begin() +i ,new Electron());
				myParticle.insert(myParticle.begin() +i,new Proton());
				newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
				newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass-myParticle[i+3]->mass;
				newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin-myParticle[i+3]->spin;
				//for(int k=0;k<myParticle.size();k++){
				//	cout<<myParticle[k]->returnType()<<endl;
				//}
				//cout<<"AFTER INSERTION"<<endl;
				delete myParticle[i+3];
				myParticle.erase(myParticle.begin() + (i+3));
				//for(int k=0;k<myParticle.size();k++){
				//	cout<<myParticle[k]->returnType()<<endl;
				//}
				//cout<<"AFTER ERASE"<<endl;
				cout << "///////////////////////////////////////////"<< endl;	

			}
			else if(myParticle[i]->returnType() == "Proton"){
				cout << "A decay has happened with a proton" << endl;
				myParticle.insert(myParticle.begin() +i ,new Neutrino());
				myParticle.insert(myParticle.begin() +i ,new Positron());
				myParticle.insert(myParticle.begin() +i,new Neutron());
				newtotalElectricCharge=newtotalElectricCharge+myParticle[i]->electricCharge+myParticle[i+1]->electricCharge+myParticle[i+2]->electricCharge-myParticle[i+3]->electricCharge;
				newtotalMass=newtotalMass+myParticle[i]->mass+myParticle[i+1]->mass+myParticle[i+2]->mass-myParticle[i+3]->mass;
				newtotalSpin=newtotalSpin+myParticle[i]->spin+myParticle[i+1]->spin+myParticle[i+2]->spin-myParticle[i+3]->spin;
				//for(int k=0;k<myParticle.size();k++){
				///	cout<<myParticle[k]->returnType()<<endl;
				//}
				//cout<<"AFTER INSERTION"<<endl;
				delete myParticle[i+3];
				myParticle.erase(myParticle.begin() + (i+3));
				//for(int k=0;k<myParticle.size();k++){
				//	cout<<myParticle[k]->returnType()<<endl;
				//}
				//cout<<"AFTER ERASE"<<endl;
				cout << "///////////////////////////////////////////"<< endl;	

			}
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	///////tetarto erwtima
	int newProtons=Proton::numberOfProtons  ;
	int newElectrons=Electron::numberOfElectrons;
	int newNeutrons=Neutron::numberOfNeutrons;
	int newPositrons=Positron::numberOfPositrons;
	int newNeutrinos=Neutrino::numberOfNeutrinos;
	int newAntineutrinos=Antineutrino::numberOfAntineutrinos;
	int newPhotons=Photon::numberOfPhotons ;
	int newFermions=Fermion::numberOfFermions;
	int newBosons=Boson::numberOfBosons;

	cout<<"In the end the number of particles that have been constructed with all the changes are:"<< endl
		<<"Protons: "       << newProtons                              << endl
		<<"Electrons: "     << newElectrons                            << endl
		<<"Neutrons: "      << newNeutrons                             << endl
		<<"Positrons: "     << newPositrons                            << endl
		<<"Neutrinos: "     << newNeutrinos                            << endl
		<<"Antineutrinos:  " << newAntineutrinos                       << endl
		<<"Photons: "       << newPhotons                              << endl
		<<"IN TOTAL: "     <<"Fermions: " << newFermions               << endl
		<<"          "     <<"Bosons:   " << newBosons                 << endl;
	
	cout<<"Total electric charge: " << newtotalElectricCharge<< endl;


	if(oldtotalElectricCharge==newtotalElectricCharge)
		cout<< "Conservation verified!" <<endl;
	
	////////////////////////////////////////////////////////////////////////////	
	////////////////////////////////////////////////////////////////////////////
	//////posostiaia metavoli
	

	cout<<"The percentage change of each particle is:(-1 means infinite)" << endl
		<<"Protons: "       << computePercentage((double)newProtons,(double)oldProtons)     <<"%" << endl
		<<"Electrons: "     << computePercentage((double)newElectrons,(double)oldElectrons)   <<"%" << endl
		<<"Neutrons: "      << computePercentage((double)newNeutrons,(double)oldNeutrons)     <<"%" << endl
		<<"Positrons: "     << computePercentage((double)newPositrons,(double)oldPositrons)   <<"%"  << endl
		<<"Neutrinos: "     << computePercentage((double)newNeutrinos,(double)oldNeutrinos)   <<"%"  << endl
		<<"Antineutrinos:  "<< computePercentage((double)newAntineutrinos,(double)oldAntineutrinos) <<"%"<< endl
		<<"Photons: "       << computePercentage((double)newPhotons,(double)oldPhotons)     <<"%"  << endl
		<<"IN TOTAL: "<<"Fermions: " <<computePercentage((double)newFermions,(double)oldFermions)  <<"%"<< endl
		<<"          "<<"Bosons:   " <<computePercentage((double)newBosons,(double)oldBosons) <<"%" << endl;
	
	/////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////
	//////mhnymata	
	
	if(newFermions>newBosons){
		cout<<"Living in a material world!" << endl;
	}else if(newFermions<newBosons){
		cout<<"Radiation prevails!"<<endl;
	}else if(newFermions==newBosons){
		cout<<"Equilibrium?"<<endl;
	}
	
	if(newtotalMass-oldtotalMass==0){
		cout<<"How it comes!"<< endl;
		cout<<"the difference of the masses is zero! "<<endl
		    <<"new Mass: "<< setprecision(15) << newtotalMass << "MeV/c^2" <<endl
		    <<"old Mass: "<< setprecision(15) << oldtotalMass << "MeV/c^2" <<endl;
		cout<<fixed;
	}	
	if(newtotalSpin-oldtotalSpin==0){
		cout<<"How it comes!"<< endl;
		cout<<"the difference of the spins is zero! "<<endl
		    <<"new Spin: " << newtotalSpin <<endl
		    <<"old Spin: " << oldtotalSpin <<endl;
	}
	
	
	for(i=0;i<myParticle.size();i++){
		delete myParticle[i];
	}
	
	myParticle.clear();
	
	
	return 0;
}



