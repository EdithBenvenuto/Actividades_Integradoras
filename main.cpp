/*
Integrantes:
Equipo #12 Integrantes:
Carlos Servilla Silva A00826925
Edith Paulina Benvenuto Valerdi A00828840

Fecha: 27 Noviembre 2020

Descripción: 


*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <unordered_map> 
#include <iterator>

using namespace std;

//Complejidad O(n)
long long ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

int main(){
	string aux,fecha,ip,razon;
	int cont;
	bool dosPuntos=false;
	unordered_map<string, vector<pair<string,string>>> registros;
	ifstream data("bitacoraACT5_2.txt");
	while (getline(data,aux)){
		fecha="";
		ip="";
		razon="";
		cont=0;
		for(int i=0;i<=aux.size()-1;i++){
			if(cont>3){
				razon+=aux[i];
			}
			if(aux[i] != ' '){
				if(cont<3){
					fecha+=aux[i]; 	
				}		
				if(cont==3 && !dosPuntos){
					ip+=aux[i];
          if(aux[i+1]==':')
            dosPuntos=true;
				}
			}else{
				cont++;
				dosPuntos=false;
				if(cont<3)
					fecha+=' ';
			}
		}     
    pair<string, string> iniFF;
		iniFF.first = fecha;
		iniFF.second = razon;
    registros[ip].push_back(iniFF); 
  }
  string ipDada;
  bool cerrar = false;
	int close=-1;
  while(!cerrar){
    cerrar = false;
		cout<<"Ingresa una IP para conocer sus accesos(sin puerto):\n";
		cin >> ipDada;
		cout <<"\nNumero de accesos: " <<registros[ipDada].size() << endl;
		cout <<"Accesos de la IP solicitada:\n";
		for(int i=0; i < registros[ipDada].size();i++){
			cout << registros[ipDada][i].first<<" ";
			cout << registros[ipDada][i].second<<endl;
		}
		cout<<endl;
    close = -1;
    while(close != 0 && close != 1){
			cout << "¿Quieres ingresar otra IP? [0 = no, 1 = si]" << endl;
    	cin >> close;
    }
		if(close==0)
			cerrar=true;
		else 
			cout<<endl;
	}
	return 0;
}
  