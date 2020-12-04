/*
Integrantes:
Equipo #12 Integrantes:
Carlos Servilla Silva A00826925
Edith Paulina Benvenuto Valerdi A00828840

Fecha: 25 Octubre 2020

Descripción: 
Este programa agrega a un arbol binario de busqueda los datos obtenidos del archivo de texto bitacoraOrdenada.txt, posteriormente, realiza una busqueda donde encuentra e imprime los IP con mayor numero de accesos, esto lo realiza con una busqueda inorden inversa, donde recorre el arbol de dato mayor al menor.

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "BST.h"


struct datos { //Struct donde se guarda cada registro leido
	 string fecha;
	 string falla; 
	 long long IP;
	 string IPn;
	 int cont;
};

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
	string aux,fecha,ip,prob;
	long long ipL;
	int cont;
	bool contG;
  	long long ipPas = 1;
  BST<datos> lista;
	ifstream data("bitacoraOrdenada.txt"); //Se lee el archivo bitacora
	if (data.is_open()){
		//Complejidad O(n)
		datos temp;
		while (getline(data,aux)){
			fecha="";
			ip="";
			prob="";
			cont=0;
			for(int i=0;i<=aux.size()-1;i++){
				if(cont>3){
					prob+=aux[i];
				}
				if(aux[i] != ' '){
						if(cont<3){
								fecha+=aux[i]; 
						}else if(cont==3){
								ip+=aux[i];
						}
				}else{
					cont++;
					if(cont<4)
						fecha+=' ';
				}
			}
			ipL=ipToLong(ip.substr(0, ip.size()-5));
      if(!contG){ //Para el primer valor que se lee
        ipPas = ipL;
        temp.falla=prob;
				temp.fecha=fecha;
				temp.IP=ipL;
				temp.IPn=ip;
				temp.cont=0;
        contG=true;
      }
      if(ipPas == ipL){
				//Incrementa en 1 el contador cuando las IPs sean iguales
        temp.cont+=1;
			}
			else{
				//se agrega un nuevo nodo ya con el numero de accesos y se reinician valores del struct temporal
        lista.add(temp);
        ipPas = ipL;
        temp.falla=prob;
		temp.fecha=fecha;
		temp.IP=ipL;
		temp.IPn=ip;
		temp.cont=1;
			}

		} 
    
	}//FIN WHILE
  lista.printIn2(); //Se llama a la funcion que imprime las 5 IPs con mayor numero de accesos
}