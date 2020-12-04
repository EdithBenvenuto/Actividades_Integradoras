/*
Equipo 12 integrantes:
Carlos Servilla Silva A00826925
Edith Paulina Benvenuto Valerdi A00828840

Fecha: 10 Octubre 2020

Descripción: 
El programa lee una lista de registros de un documento .txt llamado bitacora, donde se almacena la fecha, la ip y la falla registrada.
Posteriormente, ordena los resitros almacenados segun la IP, esta ip se pasa a un numero, quitandole los "." y ":" y en base a estos
numeros se realiza un ordenamiento por BubbleSort de complejidad O(n). 
Despues de realizar el ordenamiento, el programa le pide al usuario que ingrese una IP inicial y una IP final, y el programa devuelve
una lista creciente del rango segun las IPs dadas por el usuario.

*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#include "DoubleLinkedList.h"

struct datos { //Struct donde se guarda cada registro leido
	 string fecha;
	 string falla; 
	 long long IP;
	 string IPn;
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
  	DoubleLinkedList<datos> lista;

	ifstream data("bitacora.txt");
	if (data.is_open()){
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
			ipL=ipToLong(ip);
			datos temp;
			temp.falla=prob;
			temp.fecha=fecha;
			temp.IP=ipL;
			temp.IPn=ip;
			lista.addLast(temp); //Se agrega el registro al vector

		}
    
	}
  	lista.sort();
	//lista.print();
	string IPini,IPfin;
	long long ini,fin;
	cout<<"Ingresa el rango de IP que deseas buscar\n";
	cout<<"IP inicial: ";
	cin>>IPini;
  	ini = ipToLong(IPini);
	cout<<"\nIP final: ";
	cin>>IPfin;
	fin=ipToLong(IPfin);
	cout<<endl<<"---Registros dentro del rango dado---\n";
	lista.printR(ini, fin);
	cout<<endl;
}