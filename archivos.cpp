#include <iostream>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

using namespace std;

void crear();
void lectura();
void agregarTexto();
void mCrear(); 
void mLectura();
void mAgregarTexto();
void membrete();

int main(){
	int opcion;
	setlocale(LC_ALL, "");
	
	system("color 1F");
	do{	
	system("cls");
	membrete();
	cout<<"\n[1]: Crear un recuerdo"<<endl;  
	cout<<"[2]: Leer un recuerdo"<<endl;
	cout<<"[3]: Agregar texto al recuerdo"<<endl;
	cout<<"[0]: Salir"<<endl;  
	cout<<"Opción: ";
	cin>>opcion;
	cin.ignore();
	system("cls");
	
	switch(opcion){
		
		case 1:
		mCrear();
		crear(); 
		break;
		
		case 2: 
		mLectura();
		lectura();
		break;
		
		case 3: 
		mAgregarTexto();
		agregarTexto();
		break;
		
		case 0: 
		abort();
		break;
	}
		getch();	
	}while(1);
}

void crear(){ //IOS::OUT
	ofstream archivo;
	string nombreArchivo,texto;
	
	cout<<"\nNombre del archivo a crear (con .txt al final): ";
	getline(cin,nombreArchivo);
		
	archivo.open(nombreArchivo.c_str(),ios::out); //Abre el archivo, si no existe lo crea	
	
	if(archivo.fail()){
		cout<<"ERROR: no se pudo abrir el archivo"<<endl;
		getch();
	}else{
	
	cout<<"\nEscriba un título y fecha del recuerdo : ";
	getline(cin,texto,'\n');
	
	archivo<<texto<<endl;
	archivo.close();
}
}

void lectura(){
	ifstream archivoLectura;
	string textoLec,nomArchivo;
	
	cout<<"\nNombre del archivo a mostrar (Con .txt al final): ";
	getline(cin,nomArchivo);
	
	archivoLectura.open(nomArchivo.c_str(),ios::in); //Abre el archivo en modo lectura
	
	if(archivoLectura.fail()){   
		cout<<"ERROR: no se pudo abrir el archivo"<<endl;
		getch();
	}else{

	 while(!archivoLectura.eof()){ //Mientras no sea el final del archivo
	 	getline(archivoLectura,textoLec,'\n');
	 	cout<<textoLec<<endl;
	 }
	 archivoLectura.close(); //Cierre del archivo
	 
}	}
	
void agregarTexto(){
	ofstream archivoAg;
	string textoAg,nomArchivos;
	
	cout<<"\nArchivo que se agregará texto (con .txt al final): ";
	getline(cin,nomArchivos);
	
	archivoAg.open(nomArchivos.c_str(),ios::app); //Abrimos el archivo para añadir texto.
	
	if(archivoAg.fail()){
		cout<<"ERROR: no se pudo abrir el archivo"<<endl;
		getch();
	}else{

	cout<<"Escriba un texto a agregar en el recuerdo :";
	getline(cin,textoAg,'\n');
	archivoAg<<textoAg<<endl;	
	
	archivoAg.close();
}
	}
void membrete(){
cout<<" __________________________________________________"<<endl;
cout<<"|                                                  |"<<endl;
cout<<"|                Recuerdos - Menú                  |"<<endl;
cout<<"|                  Mathias Diaz                    |"<<endl;
cout<<"|__________________________________________________|"<<endl;
}

void mCrear(){
cout<<" __________________________________________________"<<endl;
cout<<"|                                                  |"<<endl;
cout<<"|                Recuerdos - Crear                 |"<<endl;
cout<<"|                  Mathias Diaz                    |"<<endl;
cout<<"|__________________________________________________|"<<endl;
}
void mLectura(){
cout<<" __________________________________________________"<<endl;
cout<<"|                                                  |"<<endl;
cout<<"|               Recuerdos - Lectura                |"<<endl;
cout<<"|                  Mathias Diaz                    |"<<endl;
cout<<"|__________________________________________________|"<<endl;
}
void mAgregarTexto(){
cout<<" __________________________________________________"<<endl;
cout<<"|                                                  |"<<endl;
cout<<"|           Recuerdos - Agregar texto              |"<<endl;
cout<<"|                  Mathias Diaz                    |"<<endl;
cout<<"|__________________________________________________|"<<endl;
}
