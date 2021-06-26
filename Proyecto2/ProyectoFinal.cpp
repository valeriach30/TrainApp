#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>

using namespace std;

//-------------------------------Clases para las estructuras de tipo lista-----------------------------------------------------

class nodo {
   public:
   	/*---------constructor para crear nodos en listas circulares-------*/
   	nodo(int Codigo, string texto){
       valor = Codigo;
       valor2 = texto;
       siguiente = NULL;
   	}
   	nodo(int v, nodo *sig = NULL) {
       valor2 = v;
       siguiente = sig;
    }

	private:
 	 int valor;
 	 string valor2;
	 nodo *siguiente;
        
   friend class listas;
   friend class Arbol;
   friend class cola;
};
typedef nodo *pnodo;

class listas {
   public:
    listas() { primero = NULL;}
    
    /*----------Funciones basicas para manejo de datos------------*/
    bool ListaVacia() { return primero == NULL; } 
    void CrearLista();
	void InsertarFinal(int cod, string nuevo, int num);
	void ExtraerDatos(string texto, int numero);
	bool Find(int Codigo);
	void Mostrar();
    
    private:
    pnodo primero;
    
    friend class Arbol;
   	friend class cola;
};

//-----------------------------------------ARBOL B-----------------------------------------
class BTreeNode{

  int *claves;
  // el grado del arbol
  int t;
  // ramas
  BTreeNode **C;
  // orden del arbol
  int n;
  // variable que determina si un nodo es una hoja
  bool hoja;

   public:

	  BTreeNode(int _t, bool _leaf);	
	  void mostrar2();
	  void insertNonFull(int k);
	  void splitChild(int i, BTreeNode *y);
	  bool search(int k);
	  int findKey(int k);
	  void buscar(string &texto);
	  friend class BTree;
};

class BTree {
  
   public:
   	BTreeNode *root;
  	int t;
   //Constructor
   BTree(int _t){
    root = NULL;
    t = _t;
   }
 
  // funcion para imprimir
  void mostrar2() {
    if (root != NULL)
      root->mostrar2();
  }
  // insertar
  void insertion(int k);
  // buscar
  
  
  bool search(int k){
    if (root != NULL)
      root->search(k);
  }
  
  void buscar(string &texto){
    if (root != NULL)
      root->buscar(texto);
  }
  void Crear(int op);
  bool determinar(string txt, string n2);
  friend class Arbol;
};

//-----------------------Nodos para los arboles Binarios de busqueda o arboles AVL-------------------------------
class NodoBinario {
   public:

    NodoBinario(int codigo, string nombre, NodoBinario *der = NULL,
     NodoBinario *sig=NULL, NodoBinario *izq=NULL, NodoBinario * pad=NULL, NodoBinario * sublista=NULL,
	 NodoBinario * reservacion=NULL, int contador=0, int n=0):
        Hizq(izq), Hder(der), valor(codigo), valor2(nombre), siguiente(sig),padre(pad),FB(0), 
		sublista(sublista), reservacion(reservacion), contador(contador){}

    int valor;
    string valor2;
    int FB;
    int n;
    int contador;
    NodoBinario *Hizq, *Hder, *siguiente, * padre, * sublista, * reservacion;
    friend class Binario;

    void InsertaBinario(int codigo, string nombre);
    
};

typedef NodoBinario *pNodoBinario;


class Arbol{
public:
	
	/*----------RAIZ-----------*/
	pNodoBinario raiz;
    Arbol():raiz(NULL){}
    
	/*-------RECORRIDOS--------*/
	void PreordenR(NodoBinario* R);
	void InordenR(NodoBinario* R);
	void PostordenR(NodoBinario* R);
    void InordenR_AVL(NodoBinario *R);
    void InordenR_AUX(NodoBinario *R);
	
	/*------CARGAR ARCHIVOS----*/
	void CrearArboles(int op, BTree &B1, BTree &B2);
	
    /*-----INSERCION EN ABB----*/
	void InsertaNodo(int codigo, string nombre);
    
	/*-----INSERCION EN AVL----*/
	void InsertarBalanceado(pNodoBinario &ra, bool Hh, int x,string texto);
	void RotacionDobleIzquierda(NodoBinario* n, NodoBinario* n1);
	void RotacionDobleDerecha(NodoBinario* n, NodoBinario* n1);
	void RotacionSimpleDerecha(NodoBinario* n, NodoBinario* n1);
	void RotacionSimpleIzquierda(NodoBinario* n, NodoBinario* n1);
	
	/*-----INSERCION EN AATree----*/
	void BuscarAA(pNodoBinario &r, int codigo, string texto);
    void Cortar(NodoBinario *);
    bool Dividir(NodoBinario *);
    void Reequilibrar(NodoBinario *, pNodoBinario &);
    NodoBinario *InsertaAA(pNodoBinario &,NodoBinario *,NodoBinario *);
    void Imprimir(NodoBinario *);
    int ContarNodo(NodoBinario *);
    
	/*-----INSERCION EN ROJO Y NEGRO----*/
	void InsertarRojoNegro(int llave, string texto,pNodoBinario &r);
    void ArreglarRN(NodoBinario * nodo,pNodoBinario &r);
    void RotacionIzquierdaRN(NodoBinario * x,pNodoBinario &r);
    void RotacionDerechaRN(NodoBinario * x,pNodoBinario &r);
    
	/*-----FUNCIONES PARA EL MANEJO DE DATOS----*/
	void EncontrarCodigo(string texto, int numero, BTree &B1, BTree &B2);
	void InsertarBuscado(int cod1, int cod2, string texto, int op); 
	bool Repetidos(int v,pNodoBinario r);
	bool BuscarAARepetido(pNodoBinario r,int v);
    NodoBinario * retornaNodo(NodoBinario * r, int v);
    
	/*---------------MENU-------------------*/
	void Menu(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1);
    void usuario(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1);
    void administrador(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1);
    
	/*---------------MANTENIMIENTO DE BASE DE DATOS-------------------*/
	void Modificar(int op, Arbol a1, listas L1);
    void Insertar(int op, string &ultimo);
    void Consultar(int op);
    void RegistrarTren(Arbol a1, string &ult, listas L1);
    
	/*---------------MOSTRAR-------------------*/
	string precio(string palabra);
    string numeroDeAsientos(string palabra);
    void numeroDeAsientosAux(string palabra, pNodoBinario p);
    void InordenPais(NodoBinario * r);
    void InordenCiudad(NodoBinario * r);
    void InordenConexiones(NodoBinario * r);
    void InordenTrenes(NodoBinario * r);
    void InordenRutas(NodoBinario * r);
	void MostrarSub(NodoBinario *aux);
	
	void Mayor(NodoBinario *R, int &mayor, string &nombre);
	void NotUsed(NodoBinario *R);
	void Menor(NodoBinario *R, int &menor, string &nombre);
	void Mas(NodoBinario *R, int &cont, string &usuario);
	void Menos(NodoBinario *R, int &cont, string &usuario);
	
	
	
};

// -----------------------------------COLA------------------------------------------
class cola {
   public:
    cola() : ultimo(NULL), primero(NULL) {}
    ~cola();
    
    void Anadir(int codigo, string nombre);
    pNodoBinario Leer();
    void Mostrar();
    
   	int valor;
    pNodoBinario primero, ultimo;
};

cola::~cola() {
   while(primero) Leer();
}

void cola::Anadir(int codigo, string nombre){
	/*----Crear un nodo nuevo----*/
	pNodoBinario nuevo = new NodoBinario(codigo, nombre);
  	/* Si la cola no estaba vacía, añadimos el nuevo a continuación de ultimo */
  	if(ultimo) ultimo->siguiente = nuevo;
	/* Ahora, el último elemento de la cola es el nuevo nodo */
   	ultimo = nuevo;
   	/* Si primero es NULL, la cola estaba vacía, ahora primero apuntará también al nuevo nodo */
   	if(!primero) primero = nuevo;
}

pNodoBinario cola::Leer() {
	/*----variable auxiliar para manipular nodo----*/
	pNodoBinario nodo;
	/*----Nodo apunta al primer elemento de la cola----*/
	nodo = primero;
	if(nodo){
	/* Asignamos a primero la dirección del segundo nodo */
	primero = nodo->siguiente;
	/* return del nodo */
	return nodo;
	}else
		/*Si la cola quedó vacía, ultimo debe ser NULL también*/
		ultimo = NULL;
}


void cola::Mostrar(){
	
	pNodoBinario aux = primero;
	while(aux != ultimo){
		cout << aux->valor2 << " -> ";
		aux = aux->siguiente;
	}
	cout << aux->valor2 << " -> ";
}

void Arbol::MostrarSub(NodoBinario *aux){
	
	if(aux == NULL){
		cout << "No tiene elementos" << endl;
	}
	else{
		
		if(aux->siguiente == NULL){
			cout << aux->valor2 << " -> "<< endl;
		}
		else{
			while(aux != NULL){
				cout << aux->valor2 << " -> ";
				aux = aux->siguiente;
			}
		}
	}
}


//-------------------------------Funciones basicas para manejo de datos en listas-----------------------------------------------------
void listas::CrearLista()
{
	/*---------------LISTA DE RUTAS-----------*/
	ifstream Rutas;
	Rutas.open("Rutas.txt", ios::in);
	
	if(Rutas.fail()){
		cout <<"No se puede abrir";
		exit(1);
	}
	// Ciclo que crea la lista
	string texto; 
	while (!Rutas.eof()){
		getline(Rutas, texto);
		ExtraerDatos(texto, 1);
	}
}


void listas::InsertarFinal(int cod, string texto, int num)
{	
	/*-------Inserta al final de listas circulares--------*/
	if (num == 1){
		if (ListaVacia())
	    {
	     pnodo nuevo = new nodo(cod, texto);
	     primero = nuevo;
	     nuevo->siguiente=primero;
	    }  
	    else{ 
			pnodo nuevo = new nodo(cod, texto);
			pnodo aux = primero;
			while (aux->siguiente!=primero)  
				aux= aux->siguiente;
			nuevo->siguiente= primero;
			aux->siguiente = nuevo;  
	    } 	
	}
		
}

void listas::ExtraerDatos(string texto, int numero)
{
	/*-=----extrae el codigo de ruta------*/
	if (numero == 1){ 
		string cod1, cod2, cod3, temp;
		cod1="";		
		cod2="";
		cod3="";
		int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0;
		for (;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tipo de tren.
		{
			temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod1+=temp;
		}
        llave=atoi(cod1.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod2+=temp;
		}
		llave2=atoi(cod2.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del ruta.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod3+=temp;
		}
		int cod = atoi(cod3.c_str());
		if (Find(cod)==false)
			InsertarFinal(cod, texto, 1);
	}
	

}

bool listas::Find(int Codigo)
{
	/*----Find para listas circulares-----*/
	if(ListaVacia())
		return false;
	pnodo aux = primero;   
   	while(aux->siguiente != primero){
   		if(aux->valor == Codigo)
   			return true;
		aux = aux->siguiente;	   
	}
	return false;
}
	

void listas::Mostrar()
{
	/*-----Muestra listas circulares-----*/
	pnodo aux=primero;
    while(aux->siguiente!=primero){                               
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
    }
    cout<<aux->valor<<"->";
    cout<<endl;
	
}
//-----------------------------------------Insercion en Arbol B-----------------------------------------------------

// Constructor para el nodo del arbol B
BTreeNode::BTreeNode(int t1, bool hoja1) {
  t = t1;
  hoja = hoja1;

  claves = new int[2 * t - 1];
  C = new BTreeNode *[2 * t];

  n = 0;
}

// Insertar
void BTree::insertion(int k) {
  
  // Si el arbol esta vacio
  if (root == NULL) {
    root = new BTreeNode(t, true); // asignar raiz
    root->claves[0] = k; // insertar valor
    root->n = 1; // actualizar orden del arbol
  }
  
  // El arbol no esta vacio
  else{
  	// Se determina si la pagina esta llena
    if (root->n == 2 * t - 1) {
    	
      	BTreeNode *s = new BTreeNode(t, false); // nueva pagina
		
	  	// Se divide el nodo
      	s->C[0] = root;
      	s->splitChild(0, root);
	    
		// Aumentar i para identificar en cual clave
	    // hay que hacer la insercion
      	int i = 0;
      	if (s->claves[0] < k)
        	i++;
        
		// Insertar el valor
      	s->C[i]->insertNonFull(k);
		// La raiz ahora es la pagina que se creo antes
      	root = s;
    }
    // Si la pagina no esta vacia
	else
		// A la raiz se le agrega el valor
      	root->insertNonFull(k);
  }
}

// Insertar en pagina que no esta llena
void BTreeNode::insertNonFull(int k) {
  int i = n - 1;
  // Si es una hoja
  if (hoja == true){
  	// Se desplazan las claves
    while (i >= 0 && claves[i] > k) {
      claves[i + 1] = claves[i];
      i--;
    }
	// Se inserta el valor
    claves[i + 1] = k; 
    // Aumentar el orden
    n = n + 1;
  } 
  // Si no es una hoja
  else {
  	// Se disminuye i mientras la clave
  	// sea mayor que i
    while (i >= 0 && claves[i] > k)
      i--;
	// Si alguna de las ramas esta llena
	// hay que dividir el nodo
    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);
	  // aumentar i 
      if (claves[i + 1] < k)
        i++;
    }
    // Llamada recursiva
    C[i + 1]->insertNonFull(k);
  }
}

// Dividir nodo
void BTreeNode::splitChild(int i, BTreeNode *y) {

  BTreeNode *z = new BTreeNode(y->t, y->hoja); // nueva pagina
  z->n = t - 1; // reducir orden de la nueva pagina

  for (int j = 0; j < t - 1; j++)
    z->claves[j] = y->claves[j + t]; // agregar los valores
  
  if (y->hoja == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t]; // agregar las ramas
  }
  
  y->n = t - 1; // reducir el orden del parametro
  
  // Se reacomodan las ramas del parametro
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j]; 

  C[i + 1] = z;

  // Reacomodar las claves del parametro
  for (int j = n - 1; j >= i; j--)
    claves[j + 1] = claves[j]; 

  claves[i] = y->claves[t - 1];
  
  // Aumentar orden del parametro
  n = n + 1; 
}
// Mostrar
void BTreeNode::mostrar2() {
  int i;
  for (i = 0; i < n; i++) {
    if (hoja == false)
      C[i]->mostrar2();
    cout << " " << claves[i];
  }

  if (hoja == false)
    C[i]->mostrar2();
}
// Busqueda
bool BTreeNode::search(int k){
  int i = 0;
  while (i < n && k > claves[i])
    i++;

  if (claves[i] == k)
    return true;

  if (hoja == true)
    return false;

}

void BTreeNode::buscar(string &texto){
  int i;
  for (i = 0; i < n; i++) {
    if (hoja == false)
      C[i]->buscar(texto);
    stringstream s1;
	s1 << claves[i];
	string numero2 = s1.str();
    texto += numero2;
    texto += ";";
  }
  if (hoja == false)
    C[i]->buscar(texto);
}
//-----------------------------------------Insercion en ABB-----------------------------------------------------

void Arbol::InsertaNodo(int codigo, string nombre)
{
    if(raiz==NULL){
        raiz = new NodoBinario(codigo, nombre);
    }else{
        raiz->InsertaBinario(codigo, nombre);
    }
}

void NodoBinario::InsertaBinario(int codigo, string nombre)
{
    
    if(codigo<valor){
        if(Hizq==NULL){
            Hizq = new NodoBinario(codigo, nombre);
        }else{
            Hizq->InsertaBinario(codigo, nombre);
        }
    }else{
        if(Hder==NULL){
            Hder = new NodoBinario(codigo, nombre);
        }else{
            Hder->InsertaBinario(codigo, nombre);
        }
    }
}

//-----------------------------------------Insercion en AVL-----------------------------------------------------
void Arbol::InsertarBalanceado(pNodoBinario &ra, bool Hh, int x,string texto){//IMPORTANTE EL &
                                                                                //SI NO, NO FUNCIONA
    pNodoBinario n1;
    
    if(ra==NULL){
        ra=new NodoBinario(x,texto);
        Hh = true;
    }else{
        if(x<ra->valor){
            InsertarBalanceado(ra->Hizq, Hh, x,texto);

        if(Hh){
            switch(ra->FB){
                case 1: ra->FB=0;
                Hh = false;
                break;
                case 0: ra->FB  = -1;
                break;
                case -1: n1=ra->Hizq;
                if(n1->FB ==-1){
                    RotacionSimpleIzquierda(ra, n1);
                }else{
                    RotacionDobleIzquierda(ra,n1);
                }
                Hh = false;
                break;
            }
        }
        }else{
            if(x>ra->valor){
                InsertarBalanceado(ra->Hder, Hh, x,texto);

                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB=0;
                        Hh = false;
                        break;
                        case 0: ra->FB=1;
                        break;
                        case 1:n1=ra->Hder;
                        if(n1->FB==1){
                            RotacionSimpleDerecha(ra, n1);
                        }else{
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh=false;
                        break;
                    }
                }
            }
        }
    }
}

void Arbol::RotacionDobleIzquierda(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    n2=n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder=n;
    n1->Hder=n2->Hizq;
    n2->Hizq=n1;

    if(n2->FB==1){
        n1->FB=-1;
    }else{
        n1->FB=0;
    }
    if(n2->FB==-1){
        n->FB=1;
    }else{
        n->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void Arbol::RotacionDobleDerecha(NodoBinario* n, NodoBinario* n1){
    NodoBinario *n2;
    n2=n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq=n;
    n1->Hizq=n2->Hder;
    n2->Hder=n1;

    if(n2->FB==1){
        n->FB=-1;
    }else{
        n->FB=0;
    }
    if(n2->FB==-1){
        n1->FB=1;
    }else{
        n1->FB=0;
    }
    n2->FB=0;
    n=n2;
}

void Arbol::RotacionSimpleDerecha(NodoBinario* n, NodoBinario* n1){
    n->Hder=n1->Hizq;
    n1->Hizq=n;

    if(n1->FB==1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=1;
        n1->FB=-1;
    }
    n=n1;
}

void Arbol::RotacionSimpleIzquierda(NodoBinario* n, NodoBinario* n1){
    n->Hizq=n1->Hder;
    n1->Hder=n;

    if(n1->FB==-1){
        n->FB=0;
        n1->FB=0;
    }else{
        n->FB=-1;
        n1->FB=-1;
    }
    n=n1;
}

//-----------------------------------------Insercion AATree------------------------------------------------------------
void Arbol::BuscarAA(pNodoBinario &r, int codigo, string texto)
{
    NodoBinario *ins = new NodoBinario(codigo, texto);
    ins->FB = 1;
    ins = InsertaAA(r, r, ins);
}

NodoBinario* Arbol::InsertaAA(pNodoBinario &r, NodoBinario* temp, NodoBinario* ins)
{
    if (r == NULL)
    {
        ins->padre = NULL;
        ins->Hizq = NULL;
        ins->Hder = NULL;
        r = ins;
        return r;
    }
    if (ins->valor < temp->valor)
    {
        if (temp->Hizq)
            return InsertaAA(r, temp->Hizq, ins);
        temp->Hizq = ins;
        ins->padre = temp;
        Reequilibrar(ins, r);
        return ins;
    }
    if (ins->valor > temp->valor)
    {
        if (temp->Hder)
            return InsertaAA(r, temp->Hder, ins);
        temp->Hder = ins;
        ins->padre = temp;
        Reequilibrar(ins, r);
        return ins;
    }
    delete ins;
    return temp;
}
 
void Arbol::Cortar(NodoBinario *temp)
{
    NodoBinario *ptr = temp->Hizq;
    if (temp->padre->Hizq == temp)
        temp->padre->Hizq = ptr;
    else
        temp->padre->Hder = ptr;
    ptr->padre = temp->padre;
    temp->padre = ptr;
    temp->Hizq = ptr->Hder;
    if (temp->Hizq != NULL)
    	temp->Hizq->padre = temp;
    ptr->Hder = temp;
    temp->FB = (temp->Hizq ? temp->Hizq->FB + 1 : 1);
}
 
bool Arbol::Dividir(NodoBinario *temp)
{
    NodoBinario* ptr = temp->Hder;
    if (ptr && ptr->Hder && (ptr->Hder->FB == temp->FB))
    {
        if (temp->padre->Hizq == temp)
            temp->padre->Hizq = ptr;
        else
            temp->padre->Hder = ptr;
        ptr->padre = temp->padre;
        temp->padre = ptr;
        temp->Hder = ptr->Hizq;
        if (temp->Hder != NULL)
            temp->Hder->padre = temp;
        ptr->Hizq = temp;
        ptr->FB = temp->FB + 1;
        return true;
    }
    return false;
}
 
void Arbol::Reequilibrar(NodoBinario* temp, pNodoBinario &r)
{
    temp->Hizq = NULL;
    temp->Hder = NULL;
    temp->FB = 1;
    for (temp = temp->padre; temp != r; temp = temp->padre)
    {
        if (temp->FB != (temp->Hizq ? temp->Hizq->FB + 1 : 1 ))
        {
            Cortar(temp);
            if (temp->Hder == NULL)
                temp = temp->padre;
            else if (temp->FB != temp->Hder->FB)
                temp = temp->padre;
        }
        if (temp->padre != r)
        {
            if (Dividir(temp->padre) == false)
                break;
        }
    }
}
 
void Arbol::Imprimir(NodoBinario* temp)
{
    if (!temp)
        return;
    Imprimir(temp->Hizq);
    cout <<"Value: "<<temp->valor << "  Count:" << 1;
    cout<<"  LEVEL: "<<temp->FB<<endl;
    Imprimir(temp->Hder);
}
 
int Arbol::ContarNodo(NodoBinario* temp)
{
    if (!temp)
        return 0;
    int count = 1;
    count = count + ContarNodo(temp->Hizq);
    count = count + ContarNodo(temp->Hder);
    return count;
}


//-----------------------------------------Insercion en Rojo y Negro-----------------------------------------------------
	void Arbol::ArreglarRN (pNodoBinario k,pNodoBinario &r){
        pNodoBinario u;
        while (k->padre->FB == 1) {
            if (k->padre == k->padre->padre->Hder) {
                u = k->padre->padre->Hizq; // uncle
                if (u&&u->FB == 1) {
                    // case 3.1
                    u->FB = 0;
                    k->padre->FB = 0;
                    k->padre->padre->FB = 1;
                    k = k->padre->padre;
                } else {
                    if (k == k->padre->Hizq) {
                        // case 3.2.2
                        k = k->padre;
                        RotacionDerechaRN(k,r);
                    }
                    // case 3.2.1
                    k->padre->FB = 0;
                    k->padre->padre->FB = 1;
                    RotacionIzquierdaRN(k->padre->padre,r);
                }
            } else {
                u = k->padre->padre->Hder; // uncle

                if (u&&u->FB == 1) {
                    // mirror case 3.1
                    u->FB = 0;
                    k->padre->FB = 0;
                    k->padre->padre->FB = 1;
                    k = k->padre->padre;
                } else {
                    if (k == k->padre->Hder) {
                        // mirror case 3.2.2
                        k = k->padre;
                        RotacionIzquierdaRN(k,r);
                    }
                    // mirror case 3.2.1
                    k->padre->FB = 0;
                    k->padre->padre->FB = 1;
                    RotacionDerechaRN(k->padre->padre,r);
                }
            }
            if (k == r) {
                break;
            }
        }
        r->FB = 0;
    }
void Arbol::RotacionIzquierdaRN(pNodoBinario x, pNodoBinario &r) {
		pNodoBinario y = x->Hder;
		x->Hder = y->Hizq;
		if (y->Hizq != NULL) {
			y->Hizq->padre = x;
		}
		y->padre = x->padre;
		if (x->padre == NULL) {
			r = y;
		} else if (x == x->padre->Hizq) {
			x->padre->Hizq = y;
		} else {
			x->padre->Hder = y;
		}
		y->Hizq = x;
		x->padre = y;
	}

	// rotate Hder at node x
	void Arbol::RotacionDerechaRN(pNodoBinario x,pNodoBinario &r) {
		pNodoBinario y = x->Hizq;
		x->Hizq = y->Hder;
		if (y->Hder != NULL) {
			y->Hder->padre = x;
		}
		y->padre = x->padre;
		if (x->padre == NULL) {
			r = y;
		} else if (x == x->padre->Hder) {
			x->padre->Hder = y;
		} else {
			x->padre->Hizq = y;
		}
		y->Hder = x;
		x->padre = y;
	}
    void Arbol::InsertarRojoNegro(int llave,string texto,pNodoBinario &r) {
		// Ordinary Binary Search Insertion
		pNodoBinario node = new NodoBinario(llave,texto);
		node->FB = 1; // new node must be red

		pNodoBinario y = NULL;
		pNodoBinario x = r;

		while (x != NULL) {
			y = x;
			if (node->valor < x->valor) {
				x = x->Hizq;
			} else {
				x = x->Hder;
			}
		}

		// y is padre of x
		node->padre = y;
		if (y == NULL) {
			r = node;
		} else if (node->valor < y->valor) {
			y->Hizq = node;
		} else {
			y->Hder = node;
		}

		// if new node is a raiz node, simply return
		if (node->padre == NULL){
			node->FB = 0;
			return;
		}

		// if the grandpadre is null, simply return
		if (node->padre->padre == NULL) {
			return;
		}

		// Fix the tree
		ArreglarRN (node,r);
	}

//----------------------------------------CARGAR ARCHIVOS------------------------------------------------------

void Arbol::CrearArboles(int op, BTree &B1, BTree &B2){
	if(op == 1){

		ifstream Paises;
		string texto,nombre,codigo,temp;
		Paises.open("Paises.txt", ios::in);
		if(Paises.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		while(!Paises.eof()){
			getline(Paises, texto);
			codigo="";nombre="";
			int i=0,textoLargo=(int)texto.size(),llave=0;
			for (;i<textoLargo;i++){
				temp=texto[i];//convierte a texto[i] a string. *texto[i] es un caracter
				if(temp == ";"){
					break;
				}
				codigo+=temp;
			}
            llave=atoi(codigo.c_str());
			for (i+=1;i<textoLargo;i++){
				temp=texto[i];
				nombre+=temp;
			}
            if(Repetidos(llave,this->raiz))
			    InsertaNodo(llave, nombre);
		}
		Paises.close();
	}
	
    else if(op ==2){
        ifstream Ciudades;
		Ciudades.open("Ciudades.txt", ios::in);
		
		if(Ciudades.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		
		string texto;
		// Ciclo que crea la lista
		while (!Ciudades.eof()){
			getline(Ciudades,texto);
			EncontrarCodigo(texto, 1, B1, B2);
		}
    }
    
    else if(op ==3){
        ifstream Conexiones;
		Conexiones.open("Conexiones.txt", ios::in);
		
		if(Conexiones.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		
		string texto;
		// Ciclo que crea el arbol de conexiones
		while (!Conexiones.eof()){
			getline(Conexiones, texto);
			EncontrarCodigo(texto, 2, B1, B2);
		}
    }
	
	else if(op == 4){

		ifstream TipoTren;
		string texto,nombre,codigo,temp;
		TipoTren.open("TipoTren.txt", ios::in);
		if(TipoTren.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		while(!TipoTren.eof()){
			getline(TipoTren, texto);
			codigo="";nombre="";
			int i=0,textoLargo=(int)texto.size(),llave=0;
			for (;i<textoLargo;i++){
				temp=texto[i];//convierte a texto[i] a string. *texto[i] es un caracter
				if(temp == ";"){
					break;
				}
				codigo+=temp;
			}
            llave = llave=atoi(codigo.c_str());;
			for (i+=1;i<textoLargo;i++){
				temp=texto[i];
				nombre+=temp;
			}if(Repetidos(llave,this->raiz))
			    InsertaNodo(llave, nombre);
		}
		TipoTren.close();
	}
	
	else if (op == 5){
		
		ifstream Trenes;
		Trenes.open("Trenes.txt", ios::in);
		
		if(Trenes.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		
		string texto;
		// Ciclo que crea la lista
		while (!Trenes.eof()){
			getline(Trenes,texto);
			EncontrarCodigo(texto, 1, B1, B2);
		}
	}
    else if(op == 6){
        ifstream Rutas;
		Rutas.open("Rutas.txt", ios::in);
		
		if(Rutas.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		
		string texto;
		// Ciclo que crea el arbol de conexiones
		while (!Rutas.eof()){
			getline(Rutas, texto);
			EncontrarCodigo(texto, 3, B1, B2);
		}
    }
    else if(op == 7){
    	ifstream Usuarios;
		Usuarios.open("Usuarios.txt", ios::in);
		if(Usuarios.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		string texto;
		// Ciclo que crea el arbol de conexiones
		while (!Usuarios.eof()){
			getline(Usuarios, texto);
			EncontrarCodigo(texto, 4, B1, B2);
		}
	}
	else if(op == 8){
		ifstream Admins;
		Admins.open("Administradores.txt", ios::in);
		if(Admins.fail()){
			cout <<"No se puede abrir";
			exit(1);
		}
		string texto;
		// Ciclo que crea el arbol de conexiones
		while (!Admins.eof()){
			getline(Admins, texto);
			EncontrarCodigo(texto, 5, B1, B2);
		}
	}
}


//-------------------------------FUNCIONES DE APOYO PARA LA CREACION DE ARBOLES--------------------------------
void Arbol::EncontrarCodigo(string texto, int op, BTree &B1, BTree &B2){
	if (op == 1){ // extrae el codigo de tipotren 
		string cod1, cod2, cod3, temp;
		cod1="";		
		cod2="";
		cod3="";
		int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0;
		for (;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tipo de tren.
		{
			temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod1+=temp;
		}
		llave=atoi(cod1.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod2+=temp;
		}
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod3+=temp;
		}
        llave2=atoi(cod2.c_str());
		InsertarBuscado(llave, llave2, texto, 1);
	} 
	
	else if (op == 2){ // extrae el codigo de conexion
		string cod1, cod2, cod3, temp;
		//NodoBinario * aux3;
		cod1="";		
		cod2="";
		cod3="";
		int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0,llave3=0;
		for (;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tipo de tren.
		{
			temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod1+=temp;
		}
		llave=atoi(cod1.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod2+=temp;
		}
		llave2=atoi(cod2.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod3+=temp;
		}
        llave3=atoi(cod3.c_str());
		NodoBinario * aux=retornaNodo(this->raiz, llave);
		if(aux){
			NodoBinario * aux2=retornaNodo(aux->siguiente, llave2);
			if(aux2){
                if (aux2->siguiente){
                    if(Repetidos(llave3,aux2->siguiente)){
                        InsertarRojoNegro(llave3,texto,aux2->siguiente);//cambiar insercion a RN
                    }
                }
                else{
                    InsertarRojoNegro(llave3,texto,aux2->siguiente);//cambiar insercion a RN
                }
            }
        }
	}
    else if (op == 3){ // extrae el codigo de tipotren 
		string cod1, cod2, cod3, temp;
		//NodoBinario * aux3;
		cod1="";		
		cod2="";
		cod3="";
		int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0,llave3=0;
		for (;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tipo de tren.
		{
			temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod1+=temp;
		}
        llave=atoi(cod1.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod2+=temp;
		}
		llave2=atoi(cod2.c_str());
		for (i+=1;i<textoLargo;i++)//Este ciclo se encarga de cargar el codigo del tren.
		{
			temp=texto[i];//Convierte texto[i] a string. *texto[i] es un caracter
			if(temp == ";"){ break; }
			cod3+=temp;
		}
        llave3=atoi(cod3.c_str());
		NodoBinario * aux=retornaNodo(this->raiz, llave);
		if(aux){
			NodoBinario * aux2=retornaNodo(aux->siguiente, llave2);
			if(aux2){
				numeroDeAsientosAux(aux2->valor2, aux2);
                if (aux2->siguiente){
                    if(Repetidos(llave3,aux2->siguiente)){
                        BuscarAA(aux2->siguiente, llave3, texto);
                    }
                }
                else{
                    BuscarAA(aux2->siguiente, llave3, texto);
                }
            }
        }
	}
	else if (op == 4){ 
		string cod1, cod2, cod3, temp;
		cod1="";		
		cod2="";
		cod3="";
		int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0,llave3=0;
		for (;i<textoLargo;i++)
		{
			temp=texto[i];
			if(temp == ";"){ break; }
			cod1+=temp;
		}
		llave=atoi(cod1.c_str());
		for (i+=1;i<textoLargo;i++)
		{
			temp=texto[i];
			if(temp == ";"){ break; }
			cod2+=temp;
		}
		for (i+=1;i<textoLargo;i++)
		{
			temp=texto[i];
			if(temp == ";"){ break; }
			cod3+=temp;
		}
		llave2=atoi(cod2.c_str());
        //llave3=atoi(cod3.c_str());
        stringstream num1(cod3); 
        num1 >> llave3; 
        NodoBinario * aux=retornaNodo(this->raiz, llave);
		if(aux){
			NodoBinario * aux2=retornaNodo(aux->siguiente, llave2);
			if(aux2){
		        // Crear string
		        string txt="";
		  		B1.buscar(txt);
		  		// Determinar si esta repetido
		  		bool bandera = B1.determinar(txt, cod3);
		  		if(bandera == false){
		  			B1.insertion(llave3);
				}
			}
		}
	}
	else if(op==5){
		string cod1, temp;
		cod1="";		
		int i=0,textoLargo=(int)texto.size(),llave=0;
		for (;i<textoLargo;i++){
			temp=texto[i];
			if(temp == ";"){ break; }
			cod1+=temp;
		}
		llave=atoi(cod1.c_str());
		// Crear string
        string txt="";
  		B2.buscar(txt);
  		// Determinar si esta repetido
  		bool bandera = B2.determinar(txt, cod1);
  		if(bandera == false){
  			B2.insertion(llave);
		}
	}	 
}

void Arbol::InsertarBuscado(int cod1, int cod2, string texto, int op){
	if (op==1){
        NodoBinario * aux=retornaNodo(this->raiz, cod1);
        
		if (aux){
			if(Repetidos(cod2,aux->siguiente)){
				InsertarBalanceado(aux->siguiente, false, cod2, texto);
			}
		}
	}
}
NodoBinario * Arbol::retornaNodo(NodoBinario * r, int v){
    if(r==NULL){
        return NULL;
    }else if(r->valor == v){
        return r; 
    }else if(v < r->valor){
        return retornaNodo(r->Hizq,v);
    }
    else{
        return retornaNodo(r->Hder,v);
    }
}

bool Arbol::Repetidos(int v,pNodoBinario r){
        return BuscarAARepetido(r, v);
    }
    
bool Arbol::BuscarAARepetido(pNodoBinario r,int v){
    if(r==NULL){
        return true;
    }else if(r->valor == v){
        return false; 
    }else if(v < r->valor){
        return BuscarAARepetido(r->Hizq,v);
    }
    else{
        return BuscarAARepetido(r->Hder,v);
        }
}


//------------------------------------------------RECORRIDOS---------------------------------------------------

void Arbol::PreordenR(NodoBinario *R){
    
    if(R==NULL){
        return;
    }else{
        cout<<R->valor<<" - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void Arbol::InordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout<<R->valor<<" ";
        InordenR(R->Hder);
    }
}

void Arbol::PostordenR(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout<<R->valor<<" - ";
    }
}

void Arbol::InordenR_AVL(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR_AVL(R->Hizq);
        cout<<R->valor2<<": ";
        InordenR(R->siguiente);
        cout<<"\n";
        InordenR_AVL(R->Hder);
    }
}

void Arbol::InordenR_AUX(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenR_AUX(R->Hizq);
        cout<<R->valor2<<": ";
        InordenR_AVL(R->siguiente);
        cout<<"\n";
        InordenR_AUX(R->Hder);
    }
}

void Arbol::InordenPais(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenPais(R->Hizq);
        cout<<R->valor2<<"\n";
        InordenPais(R->Hder);
    }
}

void Arbol::InordenCiudad(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenCiudad(R->Hizq);
        cout<<R->valor2<<"\n";
        InordenCiudad(R->Hder);
    }
}

void Arbol::InordenConexiones(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenConexiones(R->Hizq);
        cout << R->valor <<"\n";
        InordenConexiones(R->Hder);
    }
}

void Arbol::InordenRutas(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenRutas(R->Hizq);
		cout << R->valor <<"\n";
        InordenRutas(R->Hder);
    }
}



void Arbol::InordenTrenes(NodoBinario *R){

    if(R==NULL){
        return;
    }else{
        InordenTrenes(R->Hizq);
        cout<<R->valor2<<"\n";
        InordenTrenes(R->Hder);
    }
}

string Arbol::precio(string palabra){
    int cont=6,i=0;
    while(cont!=0){
        if(palabra[i]==';'){
            cont--;
        }
    i++;
    }
    string nueva;
    nueva="\nEl precio de esta conexion es: ";
    int largo=(int)palabra.size();
    for(i;i<largo;i++){
        nueva+=palabra[i];
    }
    return nueva+"\n";
}

string Arbol::numeroDeAsientos(string palabra){
    int cont=0,i=0;
    while(cont!=3){
        if(palabra[i]==';'){
            cont++;
        }
    i++;
    }
    string nueva;
    nueva="\nLa cantidad de asientos de este tren: ";
    while(palabra[i]!=';'){
        nueva+=palabra[i];
        i++;
    }
    return nueva+"\n";
}

void Arbol::numeroDeAsientosAux(string palabra, pNodoBinario p){
    int cont=0,i=0;
    while(cont!=3){
        if(palabra[i] == ';'){
            cont++;
        }
    i++;
    }
    string nueva;
    while(palabra[i] != ';'){
        nueva+=palabra[i];
        i++;
    }
    int num = atoi(nueva.c_str());
    p->n = num;
}

void Arbol::Mayor(NodoBinario *R, int &mayor, string &nombre){

    if(R==NULL){
        return;
    }else{
        Mayor(R->Hizq, mayor, nombre);
        if(R->contador > mayor){
        	mayor = R->contador;
        	nombre = R->valor2;
		}
        Mayor(R->Hder, mayor, nombre);
    }
}

void Arbol::NotUsed(NodoBinario *R){
	
    if(R==NULL){
        return;
    }else{
        NotUsed(R->Hizq);
        if(R->contador == 0){
        	cout << R->valor2 << endl;
		}
        NotUsed(R->Hder);
    }
}

void Arbol::Menor(NodoBinario *R, int &menor, string &nombre){
	
    if(R==NULL){
        return;
    }else{
        Menor(R->Hizq, menor, nombre);
        if(R->contador <= menor){
        	menor = R->contador;
        	nombre = R->valor2;
		}
        Menor(R->Hder, menor, nombre);
    }
}

void Arbol::Mas(NodoBinario *R, int &cont, string &usuario){
	pNodoBinario aux = R;
	while(aux != NULL){
		
		int reservas=0;
		pNodoBinario aux2 = aux->reservacion;
		while(aux2 != NULL){
			reservas += 1;
			aux2 = aux2->siguiente;
		}
		if(reservas > cont){
			cont = reservas;
			usuario = aux->valor2;
		}
		aux = aux->siguiente;
	}
}

void Arbol::Menos(NodoBinario *R, int &cont, string &usuario){
	pNodoBinario aux = R;
	while(aux != NULL){
		
		int reservas=0;
		pNodoBinario aux2 = aux->reservacion;
		while(aux2 != NULL){
			reservas += 1;
			aux2 = aux2->siguiente;
		}
		if(reservas <= cont){
			cont = reservas;
			usuario = aux->valor2;
		}
		aux = aux->siguiente;
	}
}
//------------------------------------------------MENU---------------------------------------------------
void Arbol::Menu(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1){
	
	int op;
	do{
		cout << "\n";
		cout << "\t 				Sistema de Control de Trenes";
		cout << "\n";
		cout << "\n1. Ingresar como Usuario";
		cout << "\n2. Ingresar como Administrador";
		cout << "\n";
		cout << "Opcion: ";
		cin >> op;
	
		switch(op){
			case 1: usuario(a1, a2, a3, a4, L1); break;
			case 2: administrador(a1, a2, a3, a4, L1); break;
		}
	}while(op != 1 || op != 2 );
	
}

void Arbol::usuario(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1){
	
	
	string pais, ciudad, pasaporte, estado;
	std::string nombre;
	
	cout << "Digite el codigo de su pais: ";
	cin >> pais;
	int p=0;
	p=atoi(pais.c_str());
	pNodoBinario n1 = retornaNodo(a1.raiz, p);
	if(n1){
		cout << "Digite el codigo de su ciudad: ";
		cin >> ciudad;
		int c=0;
		c=atoi(ciudad.c_str());
		pNodoBinario n2 = retornaNodo(n1->siguiente, c);
		if(n2){
			cout << "Digite el numero de pasaporte: "; 
			cin >> pasaporte;
			std::cin.get(); //esperar
			cout << "Digite su nombre: "; 
			std::getline(cin, nombre);
			cout << "Digite su estado migratorio (0/1): "; 
			cin >> estado;
		
			// ----- String con info del usuario -----
			string texto;
			texto += pais;
			texto += ";";
			texto += ciudad;
			texto += ";";
			texto += pasaporte;
			texto += ";";
			texto += nombre;
			texto += ";";
			texto += estado;
	
	
			// ----- Validacion del usuario -----
			string txt="";
		    a3.buscar(txt);
			bool bandera = a3.determinar(txt, pasaporte);
			
			// ----- El usuario no existe -----
			if(bandera == false){
				
				// ----- Opcion de registrarlo -----
				int respuesta = 0;
				cout << "\nEste usuario no se encuentra registrado.";
				cout << "\nDesea registrarlo? (1 = No / 2 = Si): ";
				cin >> respuesta;
				
				// ----No se registra el usuario-----
				if (respuesta == 1){
					cout << "\nUsuario no registrado. Vuelva a Ingresar al Sistema";
					bandera = false;
				}
				
				// ----Se registra el usuario-----
				else{	
					
					// ---- No tiene problemas migratorios -----
					
					if (estado == "0"){
						
						int num=0;
						num=atoi(pasaporte.c_str());
						a3.insertion(num);
						cout << "\nUsuario Registrado" << endl;
						bandera = true;
					}
					
					// ---- Tiene problemas migratorios -----
					else{
						cout << "No se puede viajar con problemas migratorios";
						bandera = false;
					}
				}
			}
		
			
			// ----- El usuario si existe -----
			if (bandera == true && estado != "1"){
				int opcion;
				do{
					cout << "\n";
					cout << "\n\t---------Menu de Usuario---------";
					cout << "\n1. Consultar Paises";
					cout << "\n2. Consultar Ciudades";
					cout << "\n3. Consultar Conexiones";
					cout << "\n4. Consultar Trenes";
					cout << "\n5. Consultar Precios";
					cout << "\n6. Consultar numero de asientos disponibles en un tren";
					cout << "\n7. Consultar Rutas";
					cout << "\n8. Reservacion";
					cout << "\n9. Salir";
					cout << "\nOpcion: ";
					cin >> opcion;
					cout << "\n";
					
					switch(opcion){
						case 1:
							a1.Consultar(1); //listo
							break;
						case 2:
							a1.Consultar(2); //listo
							break;
						case 3:  
							a1.Consultar(3); //listo				
							break;
						case 4:  
							a2.Consultar(5); //listo
							break;
						case 5:  
							a1.Consultar(6); //listo
							break;
						case 6:  
							a2.Consultar(7); //listo
							break;
						case 7: 
							a2.Consultar(4); //listo
							break;
						case 8:
							string pasaporte;
							int codigoTipo;
							cout << "Digite su pasaporte: ";
							cin >> pasaporte;
							cout << "Digite su codigo de tipo de tren: ";
							cin >> codigoTipo;
							 
							// Se obtiene el nodo del tipo de tren en el que se encuentra
							pNodoBinario det;
							det = retornaNodo(a2.raiz, codigoTipo);
							 
							if(det->sublista == NULL){
								cout << "Este tipo de tren no tiene usuarios" << endl;
							}
							pNodoBinario aux = det->sublista;
							while(aux != NULL){
								
								// Se extrae el pasaporte
		
								string texto, codigo;
								texto = aux->valor2;
								
								string cod1, cod2, temp;
								cod1="";
								cod2="";	
								int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0;
								for (;i<textoLargo;i++)
								{
									temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
									if(temp == ";"){ break; }
									cod1+=temp;
								}
		
								// Si son iguales entonces se tiene que agregar en ese nodo 
								// la reservacion, de lo contrario continua con el siguiente nodo
								if(cod1 == pasaporte){
									string codtren, codruta, numasientos, precio, horas;
									cout << "Digite el codigo de tren: ";
									cin >> codtren;
									cout << "Digite el codigo de la ruta: ";
									cin >> codruta;
									cout << "Digite el numero de asientos a reservar: ";
									cin >> numasientos;
									cout << "Digite el precio unitario: ";
									cin >> precio;
									cout << "Digite la cantidad de horas: ";
									cin >> horas; 
									
									int CodigoTren=0, CodigoRuta=0;
									stringstream num1(codtren); 
								    stringstream num2(codruta); 
								    num1 >> CodigoTren; 
								    num2 >> CodigoRuta;
									pNodoBinario tren;
									tren = retornaNodo(det->siguiente, CodigoTren);
									
									if(tren != NULL){
										// Se cambia la cantidad de asientos
										int n1 = tren->n; int n2 = atoi(numasientos.c_str()); int n3 = n1 - n2;
										tren->n = n3;//Nuevo valor de numero de asientos
										pNodoBinario ruta;
										ruta = retornaNodo(tren->siguiente, CodigoRuta);
										// Se hace la reservacion si existe el tren y la ruta
										if(ruta != NULL){
											string text;
											text += codtren;
											text += ";";
											text += codruta;
											text += ";";
											text += numasientos;
											text += ";";
											text += precio;
											text += ";";
											text += horas;
											
											// Sacar el codigo de pais y ciudad
											string cod1="", cod2="", temp ="", texto=ruta->valor2;
											int cont=0;
											int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0;
											for (;i<textoLargo;i++){
												temp=texto[i];
												if(temp == ";"){
													cont++;
													i++;
												}
												if (cont == 5)
													cod1 += texto[i];
												if (cont == 6)
													cod2 += texto[i];
											}
											//cout << "CodPais: "	<< cod1 << endl;
											//cout << "CodCiudad: "	<< cod2 << endl;
											
											// Aumentar contadores de pais y ciudad
											int CodPais=0, CodCiudad=0;
											stringstream num3(cod1); 
										    stringstream num4(cod2); 
										    num3 >> CodPais; 
										    num4 >> CodCiudad;
										    
											pNodoBinario pais;
											pais = retornaNodo(a1.raiz, CodPais);
											pNodoBinario ciudad;
											ciudad = retornaNodo(pais->siguiente, CodCiudad);	
										
											if(pais != NULL){
												pais->contador += 1;
											}
											if(ciudad != NULL){
												ciudad->contador += 1;
											}
											
											// Agregar la reservacion
											if(aux->reservacion == NULL){
												aux->reservacion = new NodoBinario(0,text);
											}
											else{
									   			pNodoBinario aux2 = aux->reservacion;
									            while(aux2->siguiente != NULL){
									            	aux2= aux2->siguiente;
											    }
									            aux2->siguiente = new NodoBinario(0,text);
											}
											
											// Aumentar contadores de tren y ruta
											tren->contador += 1;
											ruta->contador += 1;
										}
										else{
											cout << "El codigo de ruta no existe" << endl;
										}
									}
									else{
										cout << "El codigo de tren no existe" << endl;
									}
								}
								aux = aux->siguiente;
							}
							cout << "Reserva realizada" << endl; 
							break;
					}
				}while(opcion != 9);
			}
			
			if (bandera == true && estado == "1"){
				cout << "No se puede viajar con problemas migratorios";
			}
		}
		else{
			cout << "\nEsta ciudad no existe" << endl;
		}
	}
	else{
		cout << "\nEste pais no existe" << endl;
	}
}

void Arbol::administrador(Arbol a1, Arbol a2, BTree a3, BTree a4, listas L1){
	cout << "\n";
	
	bool bandera;
	string pasaporte, nombre;
	
	cout << "Digite el numero de administrador: ";
	cin >> pasaporte;
	std::cin.get(); //esperar
	cout << "Digite su nombre: ";
	std::getline(cin, nombre); 
	
	string texto;
	texto += pasaporte;
	texto += ";";
	texto += nombre;


	// ----- Validacion del administrador -----
	string txt="";
	a4.buscar(txt);
	bandera = a4.determinar(txt, pasaporte);

	
	// ----- El administrador no existe -----
	if(bandera == false){
		cout << "\nEste administrador no se encuentra registrado." << endl;
	}

	
	if (bandera == true){
		int opcion;
		string ultpais, ultciudad, ultconexion, ulttren;
		cola Venta;
		do{
			
			cout << "\n1. Insertar Pais";
			cout << "\n2. Insertar Ciudad";
			cout << "\n3. Insertar Conexion";
			cout << "\n4. Insertar Tipo Tren";
			cout << "\n5. Insertar Ruta";
			cout << "\n6. Modificar Precio/Tiempo/NumAsientos/Ruta/Tren/Estado Migratorio";//falta modificar estado migratorio
			cout << "\n7. Registrar Trenes";
			cout << "\n";
			
			cout << "\n ->  REPORTES  <- ";
			cout << "\n";
			cout << "\n8. Consultar Paises";
			cout << "\n9. Consultar Ciudades";
			cout << "\n10. Consultar Conexiones";
			cout << "\n11. Consultar Trenes";
			cout << "\n12. Consultar Precios";
			cout << "\n13. Consultar Rutas";
			cout << "\n14. Ultimo pais/ciudad/conexion/tren ingresado al sistema";
			cout << "\n15. Numero de Asientos  Disponibles";
			cout << "\n16. Ruta más utilizada";
			cout << "\n17. Ruta nunca utilizada";
			cout << "\n18. Pais mas visitado";
			cout << "\n19. Ciudad mas visitada";
			cout << "\n20. Usuario que más reservo";
			cout << "\n21. Usuario que menos reservo";
			cout << "\n22. Cantidad de reservas por usuario";
			cout << "\n23. Tren mas utilizado";
			cout << "\n24. Tren menos utilizado";
			cout << "\n25. Abrir ventanilla";
			cout << "\n26. Venta de tiquetes";
			cout << "\n27. Salir";
			
			cout << "\nOpcion: ";
			cin >> opcion;
			cout << "\n";
			
			string CodPais;
			string CodCiudad;
			string TipoTren;
			string CodTren;
			bool flag;
			
			switch(opcion){
				
				// --------------------------------------------CASE 1------------------------------------------
				
				case 1:{
					// ---------------PAIS---------------------
					a1.Insertar(1, ultpais);
					break;
				}
				
				// --------------------------------------------CASE 2------------------------------------------
				
				case 2:{
					// ---------------CIUDAD-------------------
					a1.Insertar(2, ultciudad);
					break;
				}
				
				// --------------------------------------------CASE 3------------------------------------------
				
				case 3:{
					// ---------------CONEXION----------------
					a1.Insertar(3, ultconexion);
					break;
				}
				
				// --------------------------------------------CASE 4------------------------------------------
				
				case 4:{
					// ---------------TIPO TREN-----------------
					a2.Insertar(4, ulttren);	
					break;
				}
				
				// --------------------------------------------CASE 5------------------------------------------
				
				case 5:{
					
					// ---------------RUTA---------------------
					string TipoTren, CodTren, CodRuta, CodPais, CodCiudad, CodPais2, 
					CodCiudad2, Precio, NewTexto, texto; 
	
					cout << "Digite el CodTipoTren: ";cin >> TipoTren;
					int cod1 = atoi(TipoTren.c_str());
					NodoBinario * NodoTipoTren=retornaNodo(a2.raiz, cod1);
					if(NodoTipoTren){
						NewTexto += TipoTren;
						NewTexto += ";";
				        cout<<"Digite el CodTren: ";cin>>CodTren;
				        int cod2 = atoi(CodTren.c_str());
				        NodoBinario * Nodotren=retornaNodo(NodoTipoTren->siguiente, cod2);
				        if(Nodotren){
				        	NewTexto += CodTren;
							NewTexto += ";";
							cout<<"Digite el CodRuta: ";cin>>CodRuta;
							int aux = atoi(CodRuta.c_str());
							NodoBinario * Nodoruta=retornaNodo(Nodotren->siguiente, aux);
							if(!Nodoruta){
								NewTexto += CodRuta;
								NewTexto += ";";
					            cout<<"Digite el CodPais 1: ";cin>>CodPais;
					            int cod3 = atoi(CodPais.c_str());
						        NodoBinario * Nodopais=retornaNodo(a1.raiz,cod3);
						        if(Nodopais){
									NewTexto += CodPais;
									NewTexto += ";";
						            cout<<"Digite el CodCiudad 1: ";cin>>CodCiudad;
						            int cod4 = atoi(CodCiudad.c_str());
						            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,cod4);
						            if(Nodociudad){
						            	NewTexto += CodCiudad;
										NewTexto += ";";
						            	cout<<"Digite el CodPais 2: ";cin>>CodPais2;
						            	int cod5 = atoi(CodPais2.c_str());
								        NodoBinario * Nodopais2=retornaNodo(a1.raiz,cod5);
								        if(Nodopais2){
								        	NewTexto += CodPais2;
											NewTexto += ";";
								            cout<<"Digite el CodCiudad 2: ";cin>>CodCiudad2;
								            int cod6 = atoi(CodCiudad2.c_str());
								            NodoBinario * Nodociudad2=retornaNodo(Nodopais2->siguiente,cod6);
								            if(Nodociudad2){
								            	NewTexto += CodCiudad2;
												NewTexto += ";";
												
												cout << "Digite el Precio: ";cin >> Precio;
												NewTexto += Precio;
												
												// Se agrega la nueva ruta a la lista respectiva						
								            	L1.InsertarFinal(aux, NewTexto, 1);
												
												//Se agrega el codigo de ruta al arbol
												BuscarAA(Nodotren->siguiente, aux, NewTexto);
												cout << "" << endl;
												cout << "Ruta Insertada exitosamente" << endl;

											}
									    	else
									    	cout << "Codigo de ciudad 2 no existe" << endl;
										}
									    else
									       	cout << "Codigo de pais 2 no existe" << endl;
									}
									else
									   	cout << "Codigo de ciudad 1 no existe" << endl;
								}
								else
								    cout << "Codigo de pais 1 no existe" << endl;
							}
							else
								cout << "Codigo de Ruta ya existe" << endl;
						}
						else
							cout << "Codigo de tren no existe" << endl;
					}
					else
						cout << "Codigo de tipo tren no existe" << endl;
					break;
				}
				
				// --------------------------------------------CASE 6------------------------------------------
				
				case 6:{
					int numero = 0;
					do{
						cout << "Que desea modificar?" << endl;
						cout << "1. Precio" << endl;
						cout << "2. Tiempo" << endl;
						cout << "3. NumAsientos" << endl;
						cout << "4. Ruta" << endl;
						cout << "5. Tren" << endl;
						cout << "6. Estado Migratorio" << endl;
						cout << "7. Salir" << endl;
						cout << "Opcion: ";
						cin >> numero;
						
						// ---------------PRECIO------------------
						if(numero == 1){
							a1.Modificar(1, a1, L1);
							break;
						}
						
						// ---------------TIEMPO-------------------
						if(numero == 2){
							a1.Modificar(2, a1, L1);	
							break;
						}
						
						// ---------------NUM ASIENTOS-------------
						if(numero == 3){
							a2.Modificar(3, a1, L1);
							break;
						}
						
						// ---------------RUTA---------------------
						if(numero == 4){
							string CodRuta;
							cout << "Digite el codigo de la ruta: ";cin >> CodRuta;
							int n = atoi(CodRuta.c_str());
							bool flag = L1.Find(n);
							if(flag == true){
								
								string TipoTren, CodTren, CodPais, CodCiudad, CodPais2, 
								CodCiudad2, Precio, NewTexto, texto; 
		
								cout << "Digite el nuevo CodTipoTren: ";cin >> TipoTren;
								int cod1 = atoi(TipoTren.c_str());
								NodoBinario * NodoTipoTren=retornaNodo(a2.raiz, cod1);
								if(NodoTipoTren){
									NewTexto += TipoTren;
									NewTexto += ";";
							        cout<<"Digite el nuevo CodTren: ";cin>>CodTren;
							        int cod2 = atoi(CodTren.c_str());
							        NodoBinario * Nodotren=retornaNodo(NodoTipoTren->siguiente, cod2);
							        if(Nodotren){
							        	NewTexto += CodTren;
										NewTexto += ";";
										NewTexto += CodRuta;
										NewTexto += ";";
							            cout<<"Digite el nuevo CodPais 1: ";cin>>CodPais;
							            int cod3 = atoi(CodPais.c_str());
								        NodoBinario * Nodopais=retornaNodo(a1.raiz,cod3);
								        if(Nodopais){
											NewTexto += CodPais;
											NewTexto += ";";
								            cout<<"Digite el nuevo CodCiudad 1: ";cin>>CodCiudad;
								            int cod4 = atoi(CodCiudad.c_str());
								            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,cod4);
								            if(Nodociudad){
								            	NewTexto += CodCiudad;
												NewTexto += ";";
								            	cout<<"Digite el nuevo CodPais 2: ";cin>>CodPais2;
								            	int cod5 = atoi(CodPais2.c_str());
										        NodoBinario * Nodopais2=retornaNodo(a1.raiz,cod5);
										        if(Nodopais2){
										        	NewTexto += CodPais2;
													NewTexto += ";";
										            cout<<"Digite el nuevo CodCiudad 2: ";cin>>CodCiudad2;
										            int cod6 = atoi(CodCiudad2.c_str());
										            NodoBinario * Nodociudad2=retornaNodo(Nodopais2->siguiente,cod6);
										            if(Nodociudad2){
										            	NewTexto += CodCiudad2;
														NewTexto += ";";
														
														cout << "Digite el nuevo Precio: ";cin >> Precio;
														NewTexto += Precio;			
															
										            	pnodo aux = L1.primero;
										            	
														while(aux->siguiente != L1.primero){
															if(aux->valor == n){
																aux->valor2 = NewTexto;
																cout << "Ruta modificada exitosamente" << endl;
																}
															aux = aux->siguiente;	
															}
														if(aux->valor == n){
															aux->valor2 = NewTexto;
															cout << "Ruta modificada exitosamente" << endl;
														}	
													}
										            else
										            	cout << "Codigo de ciudad 2 no existe" << endl;
										    	}
										        else
										        	cout << "Codigo de pais 2 no existe" << endl;
										    }
										    else
										    	cout << "Codigo de ciudad 1 no existe" << endl;
										}
										else
										    cout << "Codigo de pais 1 no existe" << endl;
									}
									else
										cout << "Codigo de tren no existe" << endl;
								}
								else
									cout << "Codigo de tipo tren no existe" << endl;	
							}
							else
								cout << "CodRuta Incorrecto" << endl;
							break;
						}
						
						// ---------------TREN---------------------
						if(numero == 5){
							a2.Modificar(5, a1, L1);
							break;
						}
						
						// --------ESTADO MIGRATORIO--------------
						if(numero == 6){
							string CodAdmin, CodUsuario;
							std::cin.get(); //esperar
							cout << "Digite el CodUsuario al que desea cambiar el estado migratorio: ";
							std::getline(cin, CodUsuario); 
							cout << "Digite su codigo de administrador: ";
							cin >> CodAdmin;
							bool flag;
							//flag = ListaAdmins.Find(CodAdmin, 1);
							if(flag == true){
								//ListaUsuarios.ModificarEstadoMigratorio(CodAdmin, CodUsuario);
							}
							else{
								cout << "CodAdmi Incorrecto" << endl;
							}
						}
					}while(numero != 7);
				break;
				}
				
				// --------------------------------------------CASE 7------------------------------------------
				
				case 7:{
					// ---------Registrar Trenes --------
					a2.RegistrarTren(a1, ulttren, L1);
					break;
				}
				
				// --------------------------------------------CASE 8-----------------------------------------
				
				case 8:{
					//cout << "\tPaises" << endl; //LISTO 
					a1.Consultar(1);
					break;
				}
				
				// --------------------------------------------CASE 9-----------------------------------------
				
				case 9:{
					//cout << "\tCiudades" << endl; //LISTO 
					a1.Consultar(2);
					break;
				}
				
				// --------------------------------------------CASE 10-----------------------------------------
				
				case 10:{
					//cout << "\tConexiones" << endl; //LISTO
					a1.Consultar(3);
					break;
				}
				
				// --------------------------------------------CASE 11-----------------------------------------
				
				case 11:{
					//cout << "\tTrenes" << endl; //LISTO 
					a2.Consultar(5);
					break;
				}
				
				// --------------------------------------------CASE 12-----------------------------------------
				
				case 12:{
					//cout << "\tPrecios" << endl; REVISAR
					a1.Consultar(6);
					break;
				}
				
				// --------------------------------------------CASE 13-----------------------------------------
				
				case 13:{
					//cout << "\tRutas" << endl; //LISTO 
					a2.Consultar(4);
					break;
				}
				
				// --------------------------------------------CASE 14-----------------------------------------
				
				case 14:{
					int numero = 0;
					do{
						cout << endl;
						cout << "Cual ultimo desea ver?" << endl;
						cout << "1. Pais" << endl;
						cout << "2. Ciudad" << endl;
						cout << "3. Conexion" << endl;
						cout << "4. Tren" << endl;
						cout << "5. Salir" << endl;
						cout << "Opcion: ";
						cin >> numero;
						
						if(numero == 1){
							cout << "Ultimo pais: ";
							cout << ultpais;
						}
						if(numero == 2){
							cout << "Ultima ciudad: ";
							cout << ultciudad;
						}
						if(numero == 3){
							cout << "Ultima conexion: ";
							cout <<  ultconexion;
						}
						if(numero == 4){
							cout << "Ultimo tren: ";
							cout << ulttren;
						}
					}while(numero != 5);
				break;
				}

				// --------------------------------------------CASE 15-----------------------------------------
				
				case 15:{
					//cout << "\tNumero de asientos disponibles" << endl;
					a2.Consultar(7);
					break;
				}
				
				// --------------------------------------------CASE 16-----------------------------------------
				
				case 16:{
					// Ruta mas utilizada
					int mayor=0;
					int codtipo, codtren;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					cout << "Digite el codigo de tren: ";
					cin >> codtren;
					
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					pNodoBinario tren;
					tren = retornaNodo(tipo->siguiente, codtren);
					string nombre = "";
					Mayor(tren->siguiente, mayor, nombre);
					cout << "Ruta mas utilizada: " << nombre << endl;
					break;
				}
				
				// --------------------------------------------CASE 17-----------------------------------------
				
				case 17:{
					// Rutas nunca utilizadas
					int codtipo, codtren;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					cout << "Digite el codigo de tren: ";
					cin >> codtren;
					
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					pNodoBinario tren;
					tren = retornaNodo(tipo->siguiente, codtren);
					cout << "Rutas nunca utilizadas: " << endl;
					NotUsed(tren->siguiente);
					break;
				}
				
				// --------------------------------------------CASE 18-----------------------------------------
				
				case 18:{
					// Pais mas visitado
					int mayor=0;
					string nombre="";
					Mayor(a1.raiz, mayor, nombre);
					cout << "Pais mas visitado: " << nombre << endl;
					break;
				}
				
				// --------------------------------------------CASE 19-----------------------------------------
				
				case 19:{
					int codpais;
					int mayor=0;
					string nombre="";
					cout << "Digite el codigo del pais: ";
					cin >> codpais;
					pNodoBinario pais;
					pais = retornaNodo(a1.raiz, codpais);
					Mayor(pais->siguiente, mayor, nombre);
					cout << "Ciudad mas visitada: " << nombre << endl;
					break;
				}
				
				// --------------------------------------------CASE 20-----------------------------------------
				
				case 20:{
					int cont=0;
					int codtipo;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					string usuario="";
					Mas(tipo->sublista, cont, usuario);
					cout << "Usuario que mas reservo: ";
					cout << usuario << endl;
					break;
				}
				
				// --------------------------------------------CASE 21-----------------------------------------
				
				case 21:{
					int cont=0;
					int codtipo;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					string usuario="";
					Menos(tipo->sublista, cont, usuario);
					cout << "Usuario que menos reservo: ";
					cout << usuario << endl;
					break;
				}
				
				// --------------------------------------------CASE 22-----------------------------------------
				
				case 22:{
					string pasaporte;
					int codtipo;
					cout << "Digite el pasaporte del usuario: ";
					cin >> pasaporte;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					
					stringstream s1;
					s1 << codtipo;
					string cod = s1.str();
					
					string texto;
					texto += pasaporte;
					texto += ";";
					texto += cod;
					
					pNodoBinario aux = tipo->sublista;
					int reservas=0;
					while(aux != NULL){
						if(aux->valor2 == texto){
							pNodoBinario aux2 = aux->reservacion;
							while(aux2 != NULL){
								reservas += 1;
								aux2 = aux2->siguiente;
							}
						}
						aux = aux->siguiente;
					}
					cout << "Cantidad de reservas: " << reservas << endl;
					
					break;
				}
				
				// --------------------------------------------CASE 23-----------------------------------------
				
				case 23:{
					// Tren mas visitado
					int mayor=0;
					int codtipo;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					string nombre = "";
					Mayor(tipo->siguiente, mayor, nombre);
					cout << "Tren mas utilizado: " << nombre << endl;
					break;
				}
				
				// --------------------------------------------CASE 24-----------------------------------------
				
				case 24:{
					// Tren menos utilizado
					int codtipo;
					cout << "Digite el codigo de tipo de tren: ";
					cin >> codtipo;
					pNodoBinario tipo;
					tipo = retornaNodo(a2.raiz, codtipo);
					cout << "Tren menos utilizado: ";
					string nombre = "";
					int menor=0;
					Menor(tipo->siguiente, menor, nombre);
					cout << nombre << endl;
					break;
				}
				
				// --------------------------------------------CASE 25-----------------------------------------
				
				case 25:{
					
					// Abrir ventanilla
					cout << endl;
					int num = 0;
					
					do{
						cout << "Desea dejar entrar a una persona? (1- Si / 2- No): ";
						cin >> num;
						if(num == 1){
							string pasaporte, CodTipoTren;

							cout << "Digite su numero de pasaporte: ";
							cin >> pasaporte;
							cout << "Digite el Codigo de Tipo de Tren: ";
							cin >> CodTipoTren;	
							
							string texto;
							texto += pasaporte;
							texto += ";";
							texto += CodTipoTren;
							
							stringstream num1(CodTipoTren); 
							int x = 0;
							num1 >> x; 
							Venta.Anadir(x, texto);
						}
					}while(num != 2);
					
					break;
				}
				
				// --------------------------------------------CASE 26-----------------------------------------
				
				case 26:{
					
					pNodoBinario aux;
					aux = Venta.primero;

					while(aux != NULL){
						
						bool banderaPas, banderaCod;
						int EstadoMigratorio;
						
						// Extraer el pasaporte y el codigo
						string texto, pasaporte, codigo;
						texto = Venta.primero->valor2;
						
						string cod1, cod2, temp;
						cod1="";
						cod2="";	
						int i=0,textoLargo=(int)texto.size(),llave=0,llave2=0;
						for (;i<textoLargo;i++)
						{
							temp=texto[i]; //Convierte texto[i] a string. *texto[i] es un caracter
							if(temp == ";"){ break; }
							cod1+=temp;
						}
				        pasaporte = atoi(cod1.c_str());
	
						for (i+=1;i<textoLargo;i++)
						{
							temp=texto[i];
							if(temp == ";"){ break; }
							cod2+=temp;
						}
						codigo = atoi(cod2.c_str());
						
						// ------------BANDERAS------------
						
						
						stringstream num1(cod2);
						int codigofinal = 0;
						num1 >> codigofinal; 
						
						pNodoBinario determinante;
						determinante = retornaNodo(a2.raiz, codigofinal);
						
						// El elemento no esta en el arbol
						if(determinante == NULL){
							banderaCod = false;
						}
						// El elemento si esta en el arbol
						else{
							banderaCod = true;
						}
						
						// Validacion pasaporte
						string txt="";
		    			a3.buscar(txt);
						banderaPas = a3.determinar(txt, cod1);
						// Extraer el estado migratorio del usuario  **********
						string estado;
						
						// VALIDAR CON UNA FUNCION  **********
						EstadoMigratorio = 0; 
						
						// El usuario no se encuentra registrado
						if(banderaPas == false){
							
							int op1;
							cout << "Este usuario no se encuentra registrado. Desea registrarlo? (1- Si/ 2- No): ";
							cin >> op1;
							
							if(op1 == 1){
								// Se agrega al arbol de Usuarios
								a3.insertion(determinante->valor);
							}
							banderaPas = true;
						}
						
						// Problemas Migratorios
						if(EstadoMigratorio == 1){
							
							// Se elimina 
							pNodoBinario eliminado;
							eliminado = Venta.Leer();
							
							// Se vuelve ingresar a la cola
							Venta.Anadir(eliminado->valor, eliminado->valor2);
						}
						
						// El pasaporte y el estado migratorio estan bien
						if(banderaPas == true && EstadoMigratorio == 0){
							
							// El codigo no existe
							if(banderaCod == false){
								do{
									cout << "Este codigo de tren no existe. Digite uno codigo para este pasaporte " << cod1 << ": ";
									cin >> cod2;
									
									stringstream num1(cod2);
									int codf = 0;
									num1 >> codf; 

									
									determinante = retornaNodo(a2.raiz, codf);

									// El elemento no esta en el arbol
									if(determinante == NULL){
										banderaCod = false;
									}
									// El elemento si esta en el arbol
									else{
										banderaCod = true;
										aux->valor = codf;
										string t2;
										t2 += cod1;
										t2 += ";";
										t2 += cod2;
										aux->valor2 = t2;
									}
								}while(banderaCod == false);
							}
							
							// Todos los datos estan bien
							
							if(determinante->sublista == NULL){
								determinante->sublista = new NodoBinario(aux->valor, aux->valor2);	
							}
							else{
					   			pNodoBinario aux2 = determinante->sublista;
					            while(aux2->siguiente != NULL){
					            	aux2= aux2->siguiente;
							    }
					            aux2->siguiente = new NodoBinario(aux->valor, aux->valor2);
							}
						
						}
						// Se pasa al campo siguiente
						aux = aux->siguiente;
						// Se elimina el primer usuario de la cola, ya que este
						// ya fue atendido
						Venta.Leer();
					}
					cout << "Venta de tiquetes realizada con exito" << endl;
					break;
				} // cierra el case
			} // cierra el switch
		}while(opcion != 27);
	}
}
//------------------------------------------------MANTENIMIENTO DE BASES---------------------------------------------------

void Arbol::Modificar(int op, Arbol a1, listas L1){
    if(op==1){//modificar precio
        int pais,ciudad,conexion;
        cout<<"Digite el codigo de pais: ";cin>>pais;
        NodoBinario * Nodopais=retornaNodo(raiz,pais);
        if(Nodopais){
            cout<<"Digite el codigo de la ciudad: ";cin>>ciudad;
            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,ciudad);
            if(Nodociudad){
                cout<<"Digite el codigo de la conexion: ";cin>>conexion;
                NodoBinario * NodoConexion=retornaNodo(Nodociudad->siguiente,conexion);
                if(NodoConexion){
                    cout<<NodoConexion->valor2<<endl;
                    string precio;
                    cout<<"Digite el nuevo precio: ";cin>>precio;
                    string nuevoPrecio;
                    int cont=6;
                    int i=0;
                    while(cont!=0){
                        nuevoPrecio+= NodoConexion->valor2[i];
                        if(NodoConexion->valor2[i]==';')
                            cont--;
                        i++;
                    }
                    nuevoPrecio+=precio;
                    NodoConexion->valor2=nuevoPrecio;
                    cout<<"\nPrecio modificado con exito\n";
                }
                else
                    cout<<"\nEl codigo de conexion no exite\n";
            }
            else 
                cout<<"\nEl codigo de ciduad no exite\n";
        }
        else
            cout<<"\nEl pais que digito no exite\n";

    }
    else if(op==2){//modificar tiempo
    	int pais,ciudad,conexion;
        cout<<"Digite el codigo de pais: ";cin>>pais;
        NodoBinario * Nodopais=retornaNodo(raiz,pais);
        if(Nodopais){
            cout<<"Digite el codigo de la ciudad: ";cin>>ciudad;
            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,ciudad);
            if(Nodociudad){
                cout<<"Digite el codigo de la conexion: ";cin>>conexion;
                NodoBinario * NodoConexion=retornaNodo(Nodociudad->siguiente,conexion);
                if(NodoConexion){
                    string tiempo,precio;
                    cout<<"Digite el nuevo tiempo: ";cin>>tiempo;
                    string nuevoTiempo;
                    int cont=5;
                    int i=0;
                    while(cont!=0){
                        nuevoTiempo+= NodoConexion->valor2[i];
                        if(NodoConexion->valor2[i]==';')
                            cont--;
                        i++;
                    }
                    int largo = (int)NodoConexion->valor2.size();
                    for(;i< largo ;i++){
                        if(NodoConexion->valor2[i]==';'){
                            break;
                        }     
                    }
                    for(;i< largo ;i++){
                        precio+=NodoConexion->valor2[i];
                    }
                    nuevoTiempo+=tiempo;
                    nuevoTiempo+=precio;
                    NodoConexion->valor2=nuevoTiempo;
                    cout<<"\nTiempo modificada con exito\n";
                }
                else
                    cout<<"\nEl codigo de conexion no exite\n";
            }
            else 
                cout<<"\nEl codigo de ciudad no exite\n";
        }
        else
            cout<<"\nEl pais que digito no exite\n";

    }
    else if(op==3){//modificar Asientos
    	int tipotren,tren;
        cout<<"Digite el codigo de tipo tren: ";cin>>tipotren;
        NodoBinario * Nodotipotren=retornaNodo(raiz,tipotren);
        if(Nodotipotren){
            cout<<"Digite el codigo de tren: ";cin>>tren;
            NodoBinario * Nodotren=retornaNodo(Nodotipotren->siguiente,tren);
            if(Nodotren){
            	string nuevo, NumAsientos;
				cout<<"Digite el nuevo numero de asientos: ";cin>>NumAsientos;
	            int cont=6;
	            int i=0;
	            while(cont!=0){
	            	if (cont >= 4){
	                	nuevo += Nodotren->valor2[i];
					}
	                if (cont == 3){
	                	nuevo += NumAsientos;
	                	nuevo += ";";
	                	cont--;
					}
					if (cont <= 1){
	                	nuevo += Nodotren->valor2[i];
					}
	                if(Nodotren->valor2[i]==';')
	                    cont--;
	                i++;
	            }
	            string palabra = Nodotren->valor2;
                for(i;i<palabra.size();i++){
                	nuevo += palabra[i];
				}
				cout << Nodotren->valor2 << endl;
                Nodotren->valor2=nuevo;
                cout<<"\nNumero de asientos modificado con exito\n";
	        }
            else 
                cout<<"\nEl codigo de tren que digito no exite\n";
        }
        else
            cout<<"\nEl codigo de tipo tren que digito no exite\n";
	}
    else if(op==5){//modificar tren
    	string nombre,texto,tipotren,tren,Asientos, pos1, pos2;
	    cout<<"Digite el nuevo codigo de tipo tren: ";cin>>tipotren;
	    int cod = atoi(tipotren.c_str());
	    NodoBinario * Nodotipotren=retornaNodo(raiz,cod);
	    if(Nodotipotren){
	    	texto+=tipotren;texto+=";";
	        cout<<"Digite el codigo de tren que desea modificar: ";cin>>tren;
	        int cod1 = atoi(tren.c_str());
	        NodoBinario * Nodotren=retornaNodo(Nodotipotren->siguiente,cod1);
	        if(Nodotren){
	        	texto+=tren;texto+=";";
	            cout<<"Digite el nuevo nombre del tren: ";cin>>nombre;
				texto+=nombre;texto+=";";
				cout<<"Digite el nuevo numero de asientos del tren: ";cin>>Asientos;
				texto+=Asientos;texto+=";";
				cout<<"Digite la nueva posible ruta 1: ";cin>>pos1;
				int cod2 = atoi(pos1.c_str());
		        if(L1.Find(cod2)){
		        	texto+=pos1;texto+=";";
		            cout<<"Digite la nueva posible ruta 2: ";cin>>pos2;
		            int cod3 = atoi(pos2.c_str());
		            if(L1.Find(cod3)){
		            	texto+=pos2;
		            	Nodotren->valor2 = texto;
		            	cout<<"\nTren modificado con exito\n";
		            }
	        		else 
	            		cout<<"\nEl codigo de ruta 2 que digito no exite\n";	
				}
	       		else 
	            	cout<<"\nEl codigo de ruta 1 que digito no exite\n";
	        }
	        else 
	            cout<<"\nEl codigo de tren que digito no exite\n";
	    }
	    else
	        cout<<"\nEl codigo de tipo tren que digito no exite\n";
    }
    
    else if(op==6){//modificar EstadoMigratorio

    }

}

void Arbol::Insertar(int op, string &ultimo)
{
	if(op == 1){//INSERTAR PAIS

		string pais;
		std::string nombre;
	    cout<<"Digite el codigo de pais: ";
		cin>>pais;
	    int cod = atoi(pais.c_str());
	    NodoBinario * Nodopais=retornaNodo(raiz,cod);
	    if(!Nodopais){
	    	std::cin.get(); //esperar
	        cout<<"Digite el nombre del pais: ";
			std::getline(cin, nombre); 
	        InsertaNodo(cod, nombre);
	        
	        // Variable que almacena el ultimo pais ingresado al sistema
	        string texto;
	        texto += pais;
	        texto += ";";
	        texto += nombre;
	        ultimo = texto;
	        cout<<"\nPais insertado con exito\n";
	    }
	    else
	        cout<<"\nEl pais que digito ya exite\n"; 
	}
	
	else if(op == 2){//INSERTAR CIUDAD
		string pais,ciudad,texto;
		std::string nombre;
        cout<<"Digite el codigo de pais: ";cin>>pais;
        int cod = atoi(pais.c_str());
        NodoBinario * Nodopais=retornaNodo(raiz,cod);
        if(Nodopais){
        	texto += pais;
        	texto += ";";
            cout<<"Digite el codigo de la ciudad: ";cin>>ciudad;
            
            int cod1 = atoi(ciudad.c_str());
            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,cod1);
            if(!Nodociudad){
            	texto += ciudad;
        		texto += ";";
        		std::cin.get(); //esperar
                cout<<"Digite el nombre de la ciudad: ";
                std::getline(cin, nombre);
                texto += nombre;
                InsertarBalanceado(Nodopais->siguiente,false,cod1,nombre);
            
                // Variable ultima ciudad ingresada al sistema
                ultimo = texto;
                cout<<"\nCiudad insertada con exito\n";
            }
            else
	        cout<<"\nEl codigo ciudad que digito ya exite\n";
        }
        else
	        cout<<"\nEl codigo pais que digito no exite\n";     
	}
	
	else if(op == 3){//INSERTAR CONEXION
	
		string CodPais, CodCiudad, CodConexion, CodPais2, 
		CodCiudad2, Precio, tiempo, Texto; 
				
        cout<<"Digite el CodPais 1: ";cin>>CodPais;
        int cod1 = atoi(CodPais.c_str());
        NodoBinario * Nodopais=retornaNodo(raiz,cod1);
        if(Nodopais){
			Texto += CodPais;
			Texto += ";";
            cout<<"Digite el CodCiudad 1: ";cin>>CodCiudad;
            int cod2 = atoi(CodCiudad.c_str());
            NodoBinario * Nodociudad=retornaNodo(Nodopais->siguiente,cod2);
            if(Nodociudad){
            	Texto += CodCiudad;
				Texto += ";";
				cout<<"Digite el CodConexion: ";cin>>CodConexion;
	            int cod3 = atoi(CodConexion.c_str());
			    NodoBinario * NodoConexion=retornaNodo(Nodociudad->siguiente,cod3);
				if(!NodoConexion){
					Texto += CodConexion;
					Texto += ";";
	            	cout<<"Digite el CodPais 2: ";cin>>CodPais2;
	            	int cod4 = atoi(CodPais2.c_str());
			        NodoBinario * Nodopais2=retornaNodo(raiz,cod4);
			        if(Nodopais2){
			        	Texto += CodPais2;
						Texto += ";";
			            cout<<"Digite el CodCiudad 2: ";cin>>CodCiudad2;
			            int cod5 = atoi(CodCiudad2.c_str());
			            NodoBinario * Nodociudad2=retornaNodo(Nodopais2->siguiente,cod5);
			            if(Nodociudad2){
			            	Texto += CodCiudad2;
							Texto += ";";
							cout << "Digite el Tiempo: ";cin >> tiempo;
							Texto += tiempo;
							Texto += ";";
							cout << "Digite el Precio: ";cin >> Precio;
							Texto += Precio;
							InsertarRojoNegro(cod3, Texto, Nodociudad->siguiente);
							
							// Variable que almacena la ultima conexion ingresada
							ultimo = Texto;
							cout<<"\nConexion insertada con exito\n";
						}
			            else
			            	cout << "Codigo de ciudad 2 no existe" << endl;
			    	}
			        else
			        	cout << "Codigo de pais 2 no existe" << endl;
			    }
			    else
			    	cout << "Codigo de Conexion ya existe" << endl;
			}
			else
			    cout << "Codigo de ciudad 1 no existe" << endl;
		}
		else
			cout << "Codigo de pais 1 no existe" << endl;
	}
	
	else if(op == 4){//INSERTAR TIPOTREN
		string tipotren;
		std::string nombre;
	    cout<<"Digite el codigo de tipo tren: ";cin>>tipotren;
	    int cod = atoi(tipotren.c_str());
	    NodoBinario * Nodotipotren=retornaNodo(raiz,cod);
	    if(!Nodotipotren){
	    	std::cin.get(); //esperar
	        cout<<"Digite el nombre del tipo tren: ";
	        std::getline(cin, nombre); 
	        InsertaNodo(cod, nombre);

	        // Almacenar el ultimo tipo de tren ingresado al sistema
			string texto;
	        texto += tipotren;
	        texto += ";";
	        texto += nombre;
	        cout<<"\nTipo tren insertado con exito\n";
	    }
	    else
	        cout<<"\nEl tipo tren que digito ya exite\n"; 
	}
	
}


void Arbol::Consultar(int op){
    if(op==1){//paises
    	cout<<"\tPaises\n";
        InordenPais(raiz);
    }
    else if(op==2){//ciudades
        int pais;
        cout<<"Digite el codigo de pais: ";cin>>pais;
        NodoBinario * NodoPais = retornaNodo(raiz,pais);
        if(NodoPais){
        	cout<<"\tCiudades\n";
            InordenCiudad(NodoPais->siguiente);
        }
        else
            cout<<"\nEl pais no existe\n";
    }
    else if(op==3){//conexiones
        int pais,ciudad;
        cout<<"Digite el codigo de pais: ";cin>>pais;
        NodoBinario * NodoPais = retornaNodo(raiz,pais);
        if(NodoPais){
            cout<<"Digite el codigo de ciudad: ";cin>>ciudad;
            NodoBinario * NodoCiudad = retornaNodo(NodoPais->siguiente,ciudad);
            if(NodoCiudad){
                cout<<"\tConexiones\n";
                InordenConexiones(NodoCiudad->siguiente);
            }
            else
                cout<<"\nEl codigo de ciudad no existe\n";
        } 
        else
            cout<<"\nEl codigo de pais no existe\n";
    }
    else if(op==4){//rutas
        int tipoTren,tren;
        cout<<"Digite el codigo de tipo de tren: ";cin>>tipoTren;
        NodoBinario * NodoTipoTren = retornaNodo(raiz,tipoTren);
        if(NodoTipoTren){
            cout<<"Digite el codigo de tren: ";cin>>tren;
            NodoBinario * NodoTren = retornaNodo(NodoTipoTren->siguiente,tren);
            if(NodoTren){
                cout<<"\tRutas\n";
                InordenRutas(NodoTren->siguiente);
            }
            else
            	cout<<"\nEl codigo de tren no existe\n";
        }
        else
            cout<<"\nEl codigo de tipo de tren no existe\n";
    }
    else if(op==5){//trenes
        int tipoTren;
        cout<<"Digite el codigo de tipo de tren: ";cin>>tipoTren;
        NodoBinario * NodoTipoTren = retornaNodo(raiz,tipoTren);
        if(NodoTipoTren){
            cout<<"\tTrenes\n";
            InordenTrenes(NodoTipoTren->siguiente);
        }
        else
            cout<<"\nEl codigo de tipo de tren no existe\n";
    }
    else if(op==6){//precios
        int pais,ciudad,conexion;
            cout<<"Digite el codigo de pais: ";cin>>pais;
            NodoBinario * NodoPais = retornaNodo(raiz,pais);
            if(NodoPais){
                cout<<"Digite el codigo de ciudad: ";cin>>ciudad;
                NodoBinario * NodoCiudad = retornaNodo(NodoPais->siguiente,ciudad);
                if(NodoCiudad){
                    cout<<"Digite el codigo de conexion: ";cin>>conexion;
                    NodoBinario * NodoConexion = retornaNodo(NodoCiudad->siguiente,conexion);
                    if(NodoConexion){
                        cout<<precio(NodoConexion->valor2);
                    }
                    else
                        cout<<"\nEl codigo de conexion no existe\n";
                }
                else
                    cout<<"\nEl codigo de ciudad no existe\n";
            } 
            else
                cout<<"\nEl codigo de pais no existe\n";
    }
    else if(op==7){//numero de asientos
        int tipoTren,tren;
        cout<<"Digite el codigo de tipo de tren: ";cin>>tipoTren;
        NodoBinario * NodoTipoTren = retornaNodo(raiz,tipoTren);
        if(NodoTipoTren){
            cout<<"Digite el codigo de tren: ";cin>>tren;
            NodoBinario * NodoTren = retornaNodo(NodoTipoTren->siguiente,tren);
            if(NodoTren){
                cout<<numeroDeAsientos(NodoTren->valor2);
            }
            else
                cout<<"\nEl codigo de tren no exite\n";
        }
        else
            cout<<"\nEl codigo de tipo de tren no existe\n";
    }
}

void Arbol::RegistrarTren(Arbol a1, string &ult, listas L1){
	string nombre,texto,tipotren,tren,Asientos, pos1, pos2;
    cout<<"Digite el codigo de tipo tren: ";cin>>tipotren;
    int cod = atoi(tipotren.c_str());
    NodoBinario * Nodotipotren=retornaNodo(raiz,cod);
    if(Nodotipotren){
    	texto+=tipotren;texto+=";";
        cout<<"Digite el codigo de tren: ";cin>>tren;
        int cod1 = atoi(tren.c_str());
        NodoBinario * Nodotren=retornaNodo(Nodotipotren->siguiente,cod1);
        if(!Nodotren){
        	texto+=tren;texto+=";";
            cout<<"Digite el nombre del tren: ";cin>>nombre;
			texto+=nombre;texto+=";";
			cout<<"Digite el numero de asientos del tren: ";cin>>Asientos;
			texto+=Asientos;texto+=";";
			cout<<"Digite la posible ruta 1: ";cin>>pos1;
			int cod2 = atoi(pos1.c_str());
	        if(L1.Find(cod2)){
	        	texto+=pos1;texto+=";";
	            cout<<"Digite la posible ruta 2: ";cin>>pos2;
	            int cod3 = atoi(pos2.c_str());
	            if(L1.Find(cod3)){
	            	texto+=pos2;
	            	InsertarBalanceado(Nodotipotren->siguiente,false,cod1,texto);
	            	ult = texto;
	            	cout<<"\nTren ingresado con exito\n";
	            }
        		else 
            		cout<<"\nEl codigo de ruta 2 que digito no exite\n";	
			}
       		else 
            	cout<<"\nEl codigo de ruta 1 que digito no exite\n";
        }
        else 
            cout<<"\nEl codigo de tren que digito ya exite\n";
    }
    else
        cout<<"\nEl codigo de tipo tren que digito no exite\n";

}


bool BTree::determinar(string texto, string n2){
	
	if(texto == ""){
		return false;
	}
	else{
	    int i=0,textoLargo=(int)texto.size();
	    string temp ="";
		string n1="";
		
	    for (;i<textoLargo;i++){
	        temp=texto[i];
			if(temp == ";"){
				if(n1 == n2){
		            return true;
	        	}
	        	else
	        		n1="";	
	    	}
			else if(temp != ";") n1 += temp;
	    }
	    return false;
    }
}

int main()
{	
	/*-------------Arboles de la estructura-----------------*/
	Arbol arbol, Apaises, Atipotren, a3, a4;
	BTree Busuario(5);
	BTree Badmin(5);
	/*-------------Listas de la estructura-----------------*/
	listas ListaRutas;
	//cout << "--------------ARBOL DE PAISES-----------" << endl;
	Apaises.CrearArboles(1, Busuario, Badmin);
	/*Apaises.InordenR(Apaises.raiz);
	cout <<endl;
	cout << endl;*/
	//cout << "--------------ARBOL DE CIUDADES-----------" << endl;
    Apaises.CrearArboles(2, Busuario, Badmin);
    /*Apaises.InordenR_AVL(Apaises.raiz);
    cout<<endl;*/
    //cout << "--------------ARBOL DE CONEXIONES-----------" << endl;
    Apaises.CrearArboles(3, Busuario, Badmin);
    /*Apaises.InordenR_AUX(Apaises.raiz);
    cout<<endl;*/
	//cout << "--------------ARBOL DE TIPOTREN-----------" << endl;
	Atipotren.CrearArboles(4, Busuario, Badmin);
	/*Atipotren.InordenR(Atipotren.raiz);
	cout << endl;
	cout << endl;*/
	//cout << "--------------ARBOL DE TREN-----------" << endl;
	Atipotren.CrearArboles(5, Busuario, Badmin);
    /*Atipotren.InordenR_AVL(Atipotren.raiz);
    cout << endl;*/
    //cout << "--------------ARBOL DE RUTA-----------" << endl;
	Atipotren.CrearArboles(6, Busuario, Badmin);
    /*Atipotren.InordenR_AUX(Atipotren.raiz);
    cout << endl;*/
    //cout << "-----------ARBOL USUARIO-----------" << endl;
    Apaises.CrearArboles(7, Busuario, Badmin);
    //Busuario.mostrar2();
    //cout << "\n-----------ARBOL ADMIN-----------" << endl;
	Apaises.CrearArboles(8, Busuario, Badmin);
	//Badmin.mostrar2();
    //cout << "--------------LISTA RUTAS-------------" << endl;
	ListaRutas.CrearLista();
	/*ListaRutas.Mostrar();
	cout << endl;*/
	
    arbol.Menu(Apaises, Atipotren, Busuario, Badmin, ListaRutas);
    
}
