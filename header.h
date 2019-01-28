//File: header.h ==> function declarations
#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<ostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<vector>


using namespace std;

class Particle{
	public:
		double mass;
		double spin;
		double electricCharge;
		Particle(double m, double s, double eC){
				mass = m;
				spin = s;
				electricCharge = eC;
			
		}
		virtual ~Particle(){};
		virtual string returnType(){
			return "Particle";
		}	
};

class Fermion : public Particle{

		
	public:
		static int numberOfFermions;
		string statistics;
		
		Fermion(double m, double s, double eC):Particle(m,s,eC){
				statistics = "Fermi-Dirac";
				numberOfFermions++;
		}
		virtual ~Fermion(){
			numberOfFermions--;
		};
		
	
};

class Boson : public Particle{

		
	public:
		static int numberOfBosons;
		string statistics;
		
		Boson(double m, double s, double eC):Particle(m,s,eC){
				statistics = "Bose-Einstein";
				numberOfBosons++;	
		}
		virtual ~Boson(){
			numberOfBosons--;
		};
		
	
};

class Proton : public Fermion {
	public:
		static int numberOfProtons;
		
	
		Proton():Fermion(938.27208,1.0/2.0,1.0){
			numberOfProtons++;
			cout<<"A proton has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Proton(){
			numberOfProtons--;
			cout<<"A proton will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Proton";
		}
		
		
};

class Neutron : public Fermion {
	public:
	
		static int numberOfNeutrons;

		Neutron():Fermion(939.56541,1.0/2.0,0.0){
			numberOfNeutrons++;
			cout<<"A Neutron has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Neutron(){
			numberOfNeutrons--;
			cout<<"A neutron will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Neutron";
		}
};

class Electron : public Fermion {
	public:
	
		static int numberOfElectrons;
	
		Electron():Fermion(0.510998946 ,1.0/2.0,-1.0){
			numberOfElectrons++;
			cout<<"An Electron has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Electron(){
			numberOfElectrons--;
			cout<<"An Electron will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Electron";
		}
};

class Positron : public Fermion {
	public:
	
		static int numberOfPositrons;
	
		Positron():Fermion(0.510998946 ,1.0/2.0,1.0){
			numberOfPositrons++;
			cout<<"A Positron has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Positron(){
			numberOfPositrons--;
			cout<<"A Positron will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Positron";
		}
};

class Neutrino : public Fermion {
	
	public:
		static int numberOfNeutrinos;
	
		Neutrino():Fermion(0.320*0.000001,1.0/2.0,0.0){
			numberOfNeutrinos++;
			cout<<"A Neutrino has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Neutrino(){
			numberOfNeutrinos--;
			cout<<"A Neutrino will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Neutrino";
		}
};

class Antineutrino : public Fermion {
	
	public:
		static int numberOfAntineutrinos;
	
		Antineutrino():Fermion(0.320*0.000001,1.0/2.0,0.0){
			numberOfAntineutrinos++;
			cout<<"An Antineutrino has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Antineutrino(){
			numberOfAntineutrinos--;
			cout<<"An Antineutrino will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Antineutrino";
		}
};


class Photon : public Boson {
	
	public:
		static int numberOfPhotons;
	
		Photon():Boson(0.0 ,1.0,0.0){
			numberOfPhotons++;
			cout<<"A Photon has been constructed with statistics:" << statistics << endl;
		}
		virtual ~Photon(){
			numberOfPhotons--;
			cout<<"A Photon will be destroyed"<< endl;
		}
		
		virtual string returnType(){
			return "Photon";
		}
};

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
long double computePercentage(int teliko,int arxiko){
	if(arxiko!=0){
		if(teliko>arxiko){
				return (((double)(teliko-arxiko))/arxiko)*100;
		}else{
				return (((double)(arxiko-teliko))/arxiko)*100;
		}
	}
	else{
		return -1.0;
	}
}
#endif

