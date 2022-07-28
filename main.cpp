#include <iostream>
#include <stdalign.h>
#include <string>
#include <fstream>

using namespace std;

void lectura();
void insertar();
void borrar();
void buscar();
void buscador();

int main()
{

    int opcion=0;

    //menu

    cout <<"Las funciones del programa son:"
    "\n1: Lectura total del archivo; lo lee de arriba a abajo en su totalidad."
    "\n2: Insertar un termino; Agrega un termino nuevo al diccionario."
    "\n3: Borrar un termino; busca y borra un termino en el diccionario."
    "\n4: Buscar un termino; busca e imprime un solo termino del diccionario"
    "\n5: Buscador personalizado; busca e imprime todos los terminos que empiecen con la letra (o combinacion de ellas) ingresada, en el diccionario.\n\n"
    "*Nota: Este programa es muy sensible a la forma en que esta escrita una palabra al buscar un termino concreto, favor de escribir bien, con la primera letra en mayusculas y agregar un '' : ''  al final de la palabra. Gracias.\n\n"
    <<endl;

    while (true){

    cout <<"Ingrese un numero del 1 al 5 segun lo que desea realizar, o cualquier otro caracter para cerrar el programa: "<<endl;
    cin>>opcion;

    if(opcion==1){
        lectura();
        cout<<"\nFuncion realizada correctamente."<<endl;
    }

    if (opcion==2){
        insertar();
        cout<<"\nFuncion realizada correctamente."<<endl;
    }

    if (opcion==3){
        borrar();
        cout<<"\nFuncion realizada correctamente."<<endl;
    }

    if (opcion==4){
        buscar();
        cout<<"\nFuncion realizada correctamente."<<endl;
    }

    if (opcion==5){
        buscador();
        cout<<"\nFuncion realizada correctamente."<<endl;
    }
    if(1>opcion || opcion>5){
        cout<<"\nCaracter ingresado no valido. Cerrando el programa."<<endl;
        cout<<"\n\n\nAutor: Christopher D. Cardenas A.\n\n\n"<<endl;
        exit(1);
    }

    }

    return 0;
}

void lectura(){
    ifstream diccionario;
    string texto;

    diccionario.open("terminos.txt",ios::in);
    if(diccionario.fail()){
       cout<<"No se puede abrir el archivo."<<endl;
       exit(1);
    }

    while(!diccionario.eof()){
        getline(diccionario,texto);
        cout<<texto<<endl;
        if (texto==" "){
            break;
        }
    }

    diccionario.close();

}

void insertar(){
    ifstream diccionario1;
    string libro[900];
    string texto;

    int i=0,j=0,cont=0;

    diccionario1.open("terminos.txt",ios::in);

    if(diccionario1.fail()){
       cout<<"No se puede abrir el archivo."<<endl;
       exit(1);
    }

    while(!diccionario1.eof()){
        getline(diccionario1,texto);
        libro[cont]=texto;
        cont++;
    }

    for(i=cont;i<800;i++){
        libro[i]=" ";
    }

    ofstream diccionario;

    diccionario.open("terminos.txt",ios::out);

    for(i=0;i<900;i++){
        if(libro[i]==" "){
            cout<<"Ingrese el termino que desea agregar al diccionario; primero el nombre, luego su definicion, y por ultimo, un codigo del mismo:"<<endl;
            for(j=0;j<3;j++){
            cin>>texto;
            libro[i]=texto;
            i++;
            if(j==2){
                i=900;
            }
            }
        }
    }

    for(i=0;i<800;i++){
        diccionario<<libro[i]<<endl;
    }

    diccionario.close();
}

void borrar(){
    ifstream diccionario1;
    string libro[900];
    string texto;
    string hunt;
    bool found=0;

    int i=0,j=0,cont=0;

    diccionario1.open("terminos.txt",ios::in);
    if(diccionario1.fail()){
       cout<<"No se puede abrir el archivo."<<endl;
       exit(1);
    }

    while(!diccionario1.eof()){
        getline(diccionario1,texto);
        libro[cont]=texto;
        cont++;
    }

    for(i=cont;i<800;i++){
        libro[i]=" ";
    }

    ofstream diccionario;

    diccionario.open("terminos.txt",ios::out);

    cout<<"Ingrese que termino desea borrar: "<<endl;
    cin>>hunt;

    for(i=0;i<900;i=i+3){
        if(libro[i]==hunt){
                cout<<"Palabra encontrada."<<endl;
                found=1;
                for(j=0;j<3;j++){
                    libro[i]=" ";
                    i++;
                    if(j==2){
                        i=900;
                    }
                }
                cout<<"Palabra eliminada."<<endl;
        }
    }

    if(found==0){
            cout<<"Palabra no encontrada."<<endl;
    }

    for(i=0;i<800;i++){
        diccionario<<libro[i]<<endl;
    }

    diccionario.close();
}

void buscar(){
    ifstream diccionario1;
    string libro[900];
    string texto;
    string hunt;
    bool found=0;

    int i=0,j=0,cont=0;

    diccionario1.open("terminos.txt",ios::in);
    if(diccionario1.fail()){
       cout<<"No se puede abrir el archivo."<<endl;
       exit(1);
    }

    while(!diccionario1.eof()){
        getline(diccionario1,texto);
        libro[cont]=texto;
        cont++;
    }

    for(i=cont;i<800;i++){
        libro[i]=" ";
    }

    cout<<"Ingrese que termino desea buscar: "<<endl;
    cin>>hunt;

    for(i=0;i<900;i=i+3){
        if(libro[i]==hunt){
                cout<<"Palabra encontrada."<<endl;
                found=1;
                for(j=0;j<3;j++){
                    cout<<libro[i]<<endl;
                    i++;
                    if(j==2){
                        i=900;
                    }
                }
        }
    }

    if(found==0){
            cout<<"Palabra no encontrada, puede estar mal escrita o no existe."<<endl;
    }

    diccionario1.close();
}

void buscador(){
    ifstream diccionario1;
    string libro[900];
    string texto;
    string hunt;
    string hunted;
    string hunted2="";
    int tamano=0;

    bool found=0;

    int i=0,j=0,cont=0;

    diccionario1.open("terminos.txt",ios::in);
    if(diccionario1.fail()){
       cout<<"No se puede abrir el archivo."<<endl;
       exit(1);
    }

    while(!diccionario1.eof()){
        getline(diccionario1,texto);
        libro[cont]=texto;
        cont++;
    }

    for(i=cont;i<800;i++){
        libro[i]=" ";
    }

    cout<<"Ingrese la letra o combinacion de ellas con la que desea buscar en el diccionario: "<<endl;
    cin>>hunt;

    for(i=0;i<900;i=i+3){
        hunted=libro[i];
        tamano=hunt.size();
        for(j=0;j<tamano;j++){
            hunted2=hunted2+hunted[j];
            //cout<<hunted2<<endl;
        if(hunt==hunted2){
            cout<<"Palabra encontrada."<<endl;
            found=1;
            for(j=0;j<3;j++){
                cout<<libro[i]<<endl;
                i++;
            }
        }
        }
        hunted2="";
    }

    if(found==0){
            cout<<"Ninguna palabra coincidia con el caracter ingresado."<<endl;
    }

    diccionario1.close();
}
