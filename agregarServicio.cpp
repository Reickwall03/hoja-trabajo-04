#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;

struct servicio{
	int tipo;
	string descripcion;
	float cantidad;
	float total;
};

void agregarServicio(){
	Servicio:
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

		int i = 0, cantidad = 0;
		float precioMalaHierba = 10.00;
		float precioLangostas = 20.00;
		float precioGusanos = 30.00;
		float precioTodo = 50.00;
		float descuentoAreaMayor = 0.05;
		float descuentoServicioMayor = 0.10;
		float areaMayor = 500.00;
		float servicioMayor = 1500.00;
		float descuentoAM = 0.00;
		float descuentoSM = 0.00;
		float total;
		string mensaje;

		cout<<"-------------------"<<endl;
		cout<<"------ Menu ------"<<endl;
		cout<<"-------------------"<<endl;
		cout<<"1 - Mala hierba Q10.00."<<endl;
		cout<<"2 - Langostas Q20.00."<<endl;
		cout<<"3 - Gusanos Q30.00."<<endl;
		cout<<"4 - Todo lo anterior Q50.00."<<endl;
		cout<<"-------------------"<<endl;
		cout<<"Seleccione su opcion: ";
		cin>>i;

		if(i > 4){
			cout<<"La opcion seleccionada no existe. Intente de nuevo."<<endl;
			system("Pause");
			goto Servicio;
		}

		cout<<"Ingrese cantidad de hectareas a fumigar: "<<endl;
		cin>>cantidad;

		switch(i){
			case 1:
				total = cantidad * precioMalaHierba;
				mensaje = "Mala hierba";
				break;
			case 2:
				total = cantidad * precioLangostas;
				mensaje = "Langostas";
				break;
			case 3:
				total = cantidad * precioGusanos;
				mensaje = "Gusanos";
				break;
			case 4:
				total = cantidad * precioTodo;
				mensaje = "Todo lo anterior";
				break;
		}

		if (cantidad > areaMayor){
			descuentoAM = total * descuentoAreaMayor;
		}

		if(total > servicioMayor){
			descuentoSM = total * descuentoServicioMayor;
		}

		archivo.open(nombreArchivo.c_str(),ios::app);
		if(archivo.fail()){
			archivo.close();
			cout<<"No se pudo abrir el archivo";
			exit(1);
		}
		system("CLS");

		mensaje = regex_replace(mensaje, regex("\\s+"), "_");
		mensaje = regex_replace(mensaje, regex("\\W+"), "");

		archivo<<i<<"\t"
  		<<mensaje<<"\t"
  		<<cantidad<<"\t"
  		<<total - descuentoAM - descuentoSM<<endl;

		archivo.close();

		cout<<"Orden realizada exitosamente."<<endl;
		cout<<"----- Resumen -----"<<endl;
		cout<<"Tipo de fumigacion: "<<mensaje<<endl;
		cout<<"Cantidad: "<<cantidad<<endl;
		cout<<"Sub total: "<<total<<endl;
		cout<<"Descuento: "<<descuentoAM + descuentoSM<<endl;
		cout<<"Total: "<<total - descuentoAM - descuentoSM<<endl;
		cout<<"-------------------"<<endl;
};

void generarReporteF(){
	 ifstream archivo;
	 string nombreArchivo,s, linea, nombre;

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

     servicio lista[lineas];

     archivo.open(nombreArchivo.c_str(), ios::in);
	 if(archivo.fail()){
	 	cout<<"Se presento un error al intentar abrir el archivo.";
	 	exit(1);
	 }

	 for(int i = 0; i < lineas; i++){
		 archivo>>lista[i].tipo
		 >>lista[i].descripcion
		 >>lista[i].cantidad
		 >>lista[i].total;
	 }
	 archivo.close();

	 float total=0;
	 int malaHierba = 0;
	 int langostas = 0;
	 int gusanos = 0;
	 int todo = 0;
	 int masVendido = 0;
	 string mensaje;

	 for(int i = 0; i < lineas; i++){
	 	if(lista[i].tipo == 1){
	 		malaHierba ++;
 		}
 	 	if(lista[i].tipo == 2){
	 		langostas ++;
 		}
 		if(lista[i].tipo == 3){
	 		gusanos ++;
 		}
 		if(lista[i].tipo == 4){
	 		todo ++;
 		}
 		total = total + lista[i].total;
	 }

	 masVendido = malaHierba;
	 mensaje = "Mala hierba";
	 if (langostas > masVendido){
	 	masVendido = langostas;
	 	mensaje = "Langostas";
	 }
	 if (gusanos > masVendido){
	 	masVendido = gusanos;
	 	mensaje = "Gusanos";
	 }
	 if (todo > masVendido){
	 	masVendido = todo;
	 	mensaje = "Todo lo anterior";
	 }

	 system("CLS");
	 cout<<"----- Reporte -----"<<endl;
	 cout<<"Resumen demanda de servicios "<<endl;
	 cout<<"Mala hierba "<<endl;
	 cout<<"- Cantidad: "<<malaHierba<<endl;
	 cout<<"Langostas "<<endl;
	 cout<<"- Cantidad: "<<langostas<<endl;
	 cout<<"Gusanos "<<endl;
	 cout<<"- Cantidad: "<<gusanos<<endl;
	 cout<<"Todo lo anterior "<<endl;
	 cout<<"- Cantidad: "<<todo<<endl;
	 cout<<"----------------------"<<endl;
	 cout<<"Servicio de mayor demanda "<<endl;
	 cout<<"- "<<mensaje<<": "<<masVendido<<endl;
	 cout<<"----------------------"<<endl;
	 cout<<"Monto total de ventas "<<endl;
	 cout<<"- Total Q: "<<total<<endl;
};
