#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct registro{
	int edad;
};

void agregarRegistro(){
	Registro:
		ofstream archivo;
		string nombreArchivo;
		fflush(stdin);
		system("CLS");
		cout<<"Indique nombre de archivo: ";
		getline(cin,nombreArchivo);
		archivo.open(nombreArchivo.c_str(),ios::app);

		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		archivo.close();

		fflush(stdin);
		system("CLS");

		int cantidad = 0;
		int edad = 0;

		cout<<"Ingrese cantidad de personas a registrar: "<<endl;
		cin>>cantidad;

		if(cantidad > 50){
			cout<<"La cantidad indicada excede el limite permitido. (permitido max 50 personas)"<<endl;
			system("Pause");
			goto Registro;
		}

		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

        for (int i = 0; i < cantidad; i++){
            system("cls");
            cout<<"Ingrese edad de la persona { "<<i+1<<" }: "<<endl;
            cin>>edad;

            if(edad >= 0 && edad <= 100){
                archivo<<edad<<endl;
            }else{
                cout<<"Edad fuera de rango. Intente de nuevo."<<endl;
                system("Pause");
                i--;
            }
        }

		archivo.close();

		cout<<"Registros agregados exitosamente."<<endl;
};

void generarReporteM(){
	 ifstream archivo;
	 string nombreArchivo,s, nombre;

	 fflush(stdin);
	 system("CLS");

	 cout<<"Ingrese nombre del archivo: ";
	 getline(cin, nombreArchivo);

	 archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 int lineas=0;
	 while(getline(archivo, s))
		lineas++;

     archivo.close();
     system("CLS");

     registro lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].edad;
	 }
	 archivo.close();

	 int ninos = 0;
	 int jovenes = 0;
	 int adultos = 0;
	 int adultosMayores = 0;
	 string mensaje;

	 for(int i = 0; i < lineas; i++){
	 	if(lista[i].edad >= 0 && lista[i].edad <= 12){
	 		ninos ++;
 		}
 	 	if(lista[i].edad >= 13 && lista[i].edad <= 29){
	 		jovenes ++;
 		}
 		if(lista[i].edad >= 30 && lista[i].edad <= 59){
	 		adultos ++;
 		}
 		if(lista[i].edad >= 60 ){
	 		adultosMayores ++;
 		}
	 }

	 system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"% de personas por categoria "<<endl;
	 cout<<"- Ninos 0 - 12: "<<(ninos*100)/lineas<<"%"<<endl;
	 cout<<"- Jovenes 13 - 29: "<<(jovenes*100)/lineas<<"%"<<endl;
	 cout<<"- Adultos 30 - 59: "<<(adultos*100)/lineas<<"%"<<endl;
	 cout<<"- Adultos mayores 60 en adelante: "<<(adultosMayores*100)/lineas<<"%"<<endl;
	 cout<<"--------------------------------------------------"<<endl;
	 cout<<"Total: "<<lineas<<endl;
};
