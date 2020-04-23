#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

void mp();

void menuFumigadora();
void menuMuestreo();
void agregarServicio();
void generarReporteF();
void agregarRegistro();
void generarReporteM();

int main(){
	mp();
}

void mp(){
	MenuPrincipal:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Menu Fumigadora"<<endl;
			cout<<"2 - Menu Muestreo"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{menuFumigadora();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 2:
					{menuMuestreo();}
					system("cls");
					goto MenuPrincipal;
					break;
				case 3:
					break;
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuPrincipal;
					break;
			}
}

void menuFumigadora(){
	MenuFumigadora:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Fumigadora"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Agregar servicio"<<endl;
			cout<<"2 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{agregarServicio();}
					system("Pause");
					system("cls");
					goto MenuFumigadora;
					break;
				case 2:
					{generarReporteF();}
					system("Pause");
					system("cls");
					goto MenuFumigadora;
					break;
				case 3:
					break;
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar."<<endl;
					system("Pause");
					goto MenuFumigadora;
					break;
			}
}

void menuMuestreo(){
	MenuMuestreo:
			int i;
			system("CLS");
			cout<<"-------------------"<<endl;
			cout<<"Menu Muestreo"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"1 - Agregar registro"<<endl;
			cout<<"2 - Generar reporte"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"3 - Regresar a menu principal"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"4 - Salir"<<endl;
			cout<<"-------------------"<<endl;
			cout<<"Seleccione su opcion: ";
			cin>>i;

			switch(i){
				case 1:
					{agregarRegistro();}
					system("Pause");
					system("cls");
					goto MenuMuestreo;
					break;
				case 2:
					{generarReporteM();}
					system("Pause");
					system("cls");
					goto MenuMuestreo;
					break;
				case 3:
					break;
				case 4:
					exit(1);
				default:
					system("cls");
					cout<<"No existe la opcion seleccionada, vuelva a intentar. "<<endl;
					system("Pause");
					goto MenuMuestreo;
					break;
			}
}
