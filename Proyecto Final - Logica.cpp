#include<iostream>
using namespace std;

int const filas=4;
int const columnas=5;

void limpiarMatriz(bool Disponibilidad[filas][columnas],int Peso[filas][columnas]);
void mostrarDisponibles(bool Disponibilidad[filas][columnas]);
float calcularocupacion(bool Disponibilidad[filas][columnas]);
int valorRecaudadoPuerto(string PuertoCarga[filas][columnas],string nombrePuerto);
void imprimircantidadcontenedores(bool Disponibilidad[filas][columnas]);
void burbuja(string puertos[],int cantidadcontenedores[], int numeropuertos);
void listadoMarcasEconomica(string Marca[filas][columnas], bool Disponibilidad[filas][columnas]);
void listadoMarcasPremium(string Marca[filas][columnas], bool Disponibilidad[filas][columnas]);
void reporteMarca(string Marcas[filas][columnas],string marcaBuscada);
float promedio (int Peso[filas][columnas]);
int filaPesada(int Peso[filas][columnas]);
int columnaliviana (int Peso[filas][columnas]);
int cantidadTipoArticulo(string TipoArticulo[filas][columnas], string tipoArticuloBuscado);
float promedioPesoPuerto(int Peso[filas][columnas],string PuertoCarga[filas][columnas],string puertoBuscado);
string nombreempresa (int Peso[filas][columnas], string Marca[filas][columnas]);
int PesoLiviano(int Peso[filas][columnas]);

int main(){
	
	//creacion de variables//
	bool Disponibilidad[filas][columnas];
	string Marca[filas][columnas];
	string PuertoCarga[filas][columnas];
	string TipoArticulo[filas][columnas];
	int Peso[filas][columnas];
	
    limpiarMatriz(Disponibilidad,Peso);
	
	int numeropuertos=0;
	int numerocontendores=0;
	int coordenadafila=-1;
	int coordenadacolumna=-1;
	int aux=1;
	int auxiliarpeso=0;
	float porcentajeocupacion=0.0;
	string nombrepuerto="";
	int recaudo=0;
	float promediocontenedores=0.0;
	int filamaspesada=-1;
	int columnamasliviana=-1;
	string tipoArticuloBuscado="";
	int cantidadarticulo=0;
	string puertoBuscado="";
	float pesopuertopromedio=0.0;
	string marcamaspesada="";
	int pesomasliviano=0;
	string marcaBuscada="";
	
	//Inicio//
	cout<<"Bienvenido, por favor llene la informacion que se le pedira a continuacion para realizar con exito el almacenamiento de los contenedores"<<endl;
	cout<<endl;
	cout<<"Ingrese la cantidad de puertos"<<endl;
	cin>>numeropuertos;
	string puertos[numeropuertos];
	int cantidadcontenedores[numeropuertos];
	
	for(int i=0;i<numeropuertos;i++){
		cout<<endl;
		cout<<"Ingrese el nombre del puerto numero "<<i<<endl;
		cin>> puertos[i];
	}
	
	//Proceso de llenado//
	for(int i=0;i<numeropuertos;i++){
		cout<<endl;
	    cout<<"Bienvenido al puerto "<<puertos[i]<<endl;
	    cout<<endl;
	    cout<<"Ingrese numero de contenedores para este puerto "<<endl;
	    cin>>numerocontendores;
        cantidadcontenedores[i]=numerocontendores;
	    for (int j=1;j<=numerocontendores;j=j+1){
            do{
            cout<<endl;	
            aux=1;
			mostrarDisponibles(Disponibilidad);
			cout<<endl;
		    cout<<"Ingrese las coordenadas donde quiere almacenar su siguiente contenedor"<<endl;
		    cout<<endl;
	    	cout<<"Ingrese la fila"<<endl;
	    	cin>>coordenadafila;
	    	cout<<endl;
		    cout<<"Ingrese la columna"<<endl;
		    cin>>coordenadacolumna;
            if(coordenadafila>=0 && coordenadafila<filas && coordenadacolumna>=0 && coordenadacolumna<columnas && Disponibilidad[coordenadafila][coordenadacolumna]==1){ 	 
				cout<<endl;
				cout<<"Ingrese la marca del contenedor"<<endl;
		    	cin>>Marca[coordenadafila][coordenadacolumna];
		    	do{cout<<endl;
				   cout<<"Ingrese el peso del contenedor"<<endl;
		    	   cin>>auxiliarpeso;
		    	   if(auxiliarpeso>0){
				     Peso[coordenadafila][coordenadacolumna]=auxiliarpeso;
				    } 
				    else {
				      cout<<endl;	
				      cout<<"El peso que acaba de ingresar es invalido"<<endl;
					}
				} while (auxiliarpeso<=0); 
				cout<<endl;        
		    	cout<<"Ingrese el tipo de articulo del contenedor"<<endl;
		    	cin>>TipoArticulo[coordenadafila][coordenadacolumna];
		    	PuertoCarga[coordenadafila][coordenadacolumna]=puertos[i];
		        Disponibilidad[coordenadafila][coordenadacolumna]=0;
		    }	   
		    else {
		    cout<<endl;	
			cout<<"La posicion ingresada ya esta ocupada por un contenedor, o no es valida"<<endl;
			aux=0;	
	    	} 	
	        }while(aux==0); 
    	}
	}
	
	porcentajeocupacion=calcularocupacion(Disponibilidad);
	cout<<endl;
    cout<<"El pocertanje de ocupacion del barco fue de "<<porcentajeocupacion<<endl;
    
    cout<<endl;
    cout<<"Ingrese el puerto del cual quiere el recaudo total"<<endl;
    cin>>nombrepuerto;
    recaudo=valorRecaudadoPuerto(PuertoCarga, nombrepuerto);
    cout<<endl;
    cout<<"El recaudo del puerto "<< nombrepuerto<<" fue de "<<recaudo<<endl;
    
    
	//Procedimientos//
    
    imprimircantidadcontenedores(Disponibilidad);
    
    burbuja(puertos,cantidadcontenedores,numeropuertos);
    
    listadoMarcasEconomica(Marca, Disponibilidad);
    
    listadoMarcasPremium(Marca, Disponibilidad);
    
    cout<<endl;
	cout<<"Ingrese la marca que quiere evaluar "<<endl;
    cin>>marcaBuscada;
    reporteMarca(Marca, marcaBuscada);
    
    //funciones //
    promediocontenedores=promedio (Peso);
    cout<<endl;
    cout<<"El promedio de peso de los contenedores que ocupan una celda es de "<<promediocontenedores<<endl;
    
    filamaspesada=filaPesada(Peso);
    cout<<endl;
    cout<<"La fila mas pesada del barco es la numero "<<filamaspesada<<endl;
    
    columnamasliviana=columnaliviana (Peso);
    cout<<endl;
    cout<<"La columna mas liviana del barco es la numero "<<columnamasliviana<<endl;
    
    cout<<endl;
	cout<<"Ingrese la clase de articulo que quiere evaluar "<<endl;
    cin>>tipoArticuloBuscado;
    cantidadarticulo=cantidadTipoArticulo(TipoArticulo, tipoArticuloBuscado);
    cout<<endl;
    cout<<"La cantidad de contenedores del tipo de articulo ingresado es "<<cantidadarticulo<<endl;
    
    cout<<endl;
	cout<<"Ingrese el puerto que quiere evaluar"<<endl;
    cin>>puertoBuscado;
	pesopuertopromedio=promedioPesoPuerto(Peso,PuertoCarga,puertoBuscado);
	cout<<endl;
	cout<<"El promedio de peso ingresado en ese puerto fue de "<<pesopuertopromedio<<endl;
	
    marcamaspesada= nombreempresa (Peso, Marca);
    cout<<endl;
    cout<<"La marca con el contenedor mas pesado es "<<marcamaspesada<<endl;
    
    pesomasliviano=PesoLiviano(Peso);
    cout<<endl;
    cout<<"El peso del contenedor mas liviano "<<pesomasliviano<<endl;
	
	//Imprimir matrices//
	cout<<endl;
	cout<<"La matriz de disponibilidad es "<<endl;
		for(int i=0;i<filas;i++){
		  for(int j=0;j<columnas;j++){
			cout<<Disponibilidad[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"La matriz de marcas es "<<endl;
		for(int i=0;i<filas;i++){
		  for(int j=0;j<columnas;j++){
			cout<<Marca[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	cout<<endl; 
	 
	cout<<"La matriz de pesos es "<<endl;
		for(int i=0;i<filas;i++){
		  for(int j=0;j<columnas;j++){
			cout<<Peso[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"La matriz de puertos de carga es "<<endl;
		for(int i=0;i<filas;i++){
		  for(int j=0;j<columnas;j++){
			cout<<PuertoCarga[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	cout<<endl;
	
	cout<<"La matriz de los tipos de articulo es "<<endl;
		for(int i=0;i<filas;i++){
		  for(int j=0;j<columnas;j++){
			cout<<TipoArticulo[i][j]<<"\t";
		}	
		cout<<endl;
	}
	
	
	return 0;
}

	
	
	//Limpiar matrices//
void limpiarMatriz(bool Disponibilidad[filas][columnas],int Peso[filas][columnas]){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			Disponibilidad[i][j]=1;	
			Peso[i][j]=0;
		}
	}
}
    //Mostrar disponibilidad//
void mostrarDisponibles(bool Disponibilidad[filas][columnas]){
    for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
            if(Disponibilidad[i][j]==1){
                cout<<i<<","<<j<<endl;
            }
        }
    }
}

    //Procesos//
float calcularocupacion(bool Disponibilidad[filas][columnas]){
	float contador=0.0;
	float porcentaje=0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Disponibilidad[i][j]==0){
				contador=contador+1;
			}
		}
	}
	porcentaje=contador/(filas*columnas);
	return porcentaje;
}

int valorRecaudadoPuerto(string PuertoCarga[filas][columnas],string nombrepuerto){
	int contadoreconomica=0;
	int contadorpremium=0;
	int totaleconomica=0;
	int totalpremium=0;
	int resultado=0;
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(PuertoCarga[i][j]==nombrepuerto && (i==0 || i==3 || j==0 || j==4)){
               contadoreconomica=contadoreconomica+1;
			}
			else if(PuertoCarga[i][j]==nombrepuerto && ((i==1 && j==1) || (i==1 && j==2) || (i==1 && j==3) || (i==2 && j==1) || (i==2 && j==2) || (i==2 && j==3))){
				contadorpremium=contadorpremium+1;
			}
		}
	}
	totaleconomica=contadoreconomica*100;
	totalpremium=contadorpremium*300;
	resultado=totaleconomica+totalpremium;
	
	return resultado;
			
}

//Procedimientos y funciones//

//Procedimiento 1//
void imprimircantidadcontenedores(bool Disponibilidad[filas][columnas]){
 int contador=0;
 for(int i=0;i<filas;i++){
    for(int j=0;j<columnas;j++){
        if(Disponibilidad[i][j]==0){
        contador=contador+1;
        }
    }
  }
  cout<<endl;
  cout<<"La cantidad de contenedores en el barco es "<<contador<<endl;
}

//Procedimiento 2//
void burbuja(string puertos[],int cantidadcontenedores[], int numeropuertos){
	for (int i=0;i<numeropuertos;i++){
		for (int j=0;j<numeropuertos;j++){
	        if(cantidadcontenedores[i]>cantidadcontenedores[j]){
			int auxC=cantidadcontenedores[i];
			cantidadcontenedores[i]=cantidadcontenedores[j];
			cantidadcontenedores[j]=auxC;
			string auxN=puertos[i];
			puertos[i]=puertos[j];
			puertos[j]=auxN;
		    }
    	}
	}
	cout<<endl;
	cout<<"La cantidad de contenedores por puertos es "<<endl;
	for(int i=0;i<numeropuertos;i++){ 
	cout<<puertos[i]<<" ---> "<<cantidadcontenedores[i]<<endl;
	}	
}

//Procedimiento 3//
void listadoMarcasEconomica(string Marca[filas][columnas], bool Disponibilidad[filas][columnas]){
	cout<<endl;
	cout<<"El listado de las marcas en la zona economica son"<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			  if(Disponibilidad[i][j]==0 && (i==0 || i==3 || j==0 || j==4)){
			   cout<<endl;
			   cout<<Marca[i][j]<<endl;
			}
		}
	}
}

//Procedimiento 4//
void listadoMarcasPremium(string Marca[filas][columnas], bool Disponibilidad[filas][columnas]){
	cout<<endl; 
	cout<<"El listado de las marcas en la zona premium son"<<endl;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Disponibilidad[i][j]==0 && ((i==1 && j==1) || (i==1 && j==2) || (i==1 && j==3) || (i==2 && j==1) || (i==2 && j==2) || (i==2 && j==3))) {
				cout<<endl;
			   cout<<Marca[i][j]<<endl;
			}
		}
    }
}    
   
//Procedimiento 5//

void reporteMarca(string Marca[filas][columnas],string marcaBuscada){
	int contadoreconomicamarca=0;
	int contadorpremiummarca=0;
	int totalzonaeconomica=0;
	int totalzonapremium=0;
	
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(Marca[i][j]==marcaBuscada && (i==0 || i==3 || j==0 || j==4)){
               contadoreconomicamarca=contadoreconomicamarca+1;
			}
			else if (Marca[i][j]==marcaBuscada && ((i==1 && j==1) || (i==1 && j==2) || (i==1 && j==3) || (i==2 && j==1) || (i==2 && j==2) || (i==2 && j==3))){
				contadorpremiummarca=contadorpremiummarca+1;
			}
		}
	}
	totalzonaeconomica=contadoreconomicamarca*100;
	totalzonapremium=contadorpremiummarca*300;
	
	cout<<endl; 
    cout<<"La cantidad de contenedores que hay de esta marca en la zona economica es "<<contadoreconomicamarca<<" y el valor que debe pagar por estos contenedores es de "<<totalzonaeconomica<<endl;
    cout<<endl;
	cout<<"La cantidad de contenedores que hay de esta marca en la zona premium es "<<contadorpremiummarca<<" y el valor que debe pagar por estos contenedores es de "<<totalzonapremium<<endl;	
}	

//Funciones 6//
float promedio (int Peso[filas][columnas]){
    float acumulador = 0.0;
	float contador = 0.0; 
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			if (Peso[i][j]>0){
				acumulador = acumulador + Peso[i][j];
				contador = contador + 1;
			}
		}
	}
	float respuesta = 0;
	respuesta = acumulador/contador;
	return respuesta;
} 


//Funciones 7//
int filaPesada(int Peso[filas][columnas]){
	int mayor=INT_MIN;
	int acumulador=0;
	int filaMayor=-1;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			acumulador=acumulador+Peso[i][j];
		}
		if(acumulador>mayor){
			mayor=acumulador;
			filaMayor=i;
		}
		acumulador=0;
	}
	return filaMayor;
}

//Funciones 8//
int columnaliviana (int Peso[filas][columnas]){
	int menor = INT_MAX;
	int columnamenor = -1;
	int acumulador=0;
	for(int j=0;j<columnas;j++){
		for (int i=0; i<filas; i++){
		    acumulador=acumulador+Peso[i][j];
		}
		if(acumulador<menor){
			menor=acumulador;
			columnamenor=j;
		}
		acumulador=0;
	}
	return columnamenor; 
}

//Funciones 9//
int cantidadTipoArticulo(string TipoArticulo[filas][columnas], string tipoArticuloBuscado){
	int contadorarticulo=0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(TipoArticulo[i][j]==tipoArticuloBuscado){
				contadorarticulo=contadorarticulo+1;
			}
	 	}
   }
   return contadorarticulo;
}   

//Funciones 10//
float promedioPesoPuerto(int Peso[filas][columnas],string PuertoCarga[filas][columnas],string puertoBuscado){
	float acumuladorpesos=0.0;
	float contadorpesos=0.0;
	float promediopesos= 0.0;
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(PuertoCarga[i][j]==puertoBuscado){
				acumuladorpesos=acumuladorpesos+Peso[i][j];
				contadorpesos=contadorpesos+1;  
            }
	   }
    }
    promediopesos=acumuladorpesos/contadorpesos;
    
    return promediopesos;
}

//Funciones 11//
string nombreempresa (int Peso[filas][columnas], string Marca[filas][columnas]){
	int mayor = INT_MIN;
	string nombre = "";
	string mejornombre = "";
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			if (Peso[i][j] > mayor){
				mayor = Peso[i][j];
				mejornombre = Marca [i][j];
			}
		}
	}
	return mejornombre;
}

//Funciones 12//
int PesoLiviano(int Peso[filas][columnas]){
	int Liviano=INT_MAX;
	for (int i=0; i<filas; i++){
		for (int j=0; j<columnas; j++){
			if(Peso[i][j]>0 && Peso[i][j]<Liviano){
			   Liviano=Peso[i][j];
			}
		}
	}
	
	return Liviano;
}

