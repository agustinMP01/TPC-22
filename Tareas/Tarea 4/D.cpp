#include<bits/stdc++.h>
using namespace std;

template <class T>
struct SegmentTree{
  int N; //Cantidad de elementos
  vector <T> tree; //VEctor que contiene nuestro arbol
  //La raiz del arbol va en el indice 0 del vector, el hijo izquierdo en el 1 y el derecho 2
  //Esto se generaliza: si la raiz está en i, el hijo izq esta en 2*i+1 y el derecho 2*i+2

  SegmentTree(int _N){ 
    N = _N;
    tree.resize(4*N);
    build(0, 0, N-1);
  }
  //Constructor de la clase, &init es la dirección del vector que se usará al inicializar
  SegmentTree(vector<T> &init) { 
    N = init.size(); //El tamaño es el tamaño del vector inicial
    tree.resize(4*N); // Cuando N no es potencia de 2, hay que alinear, así todo apunta a algo.
    build(0, 0, N-1, init); //Construyo el segment tree desde el nodo 0, en [0,N-1] con el arreglo init
  }

  T merge(T a, T b){ // Reemplazar esta funcion para determinar como juntar dos nodos para obtener el valor de su padre, en este caso es suma
    // e
    return a + b;
  }
  
  void build(int n, int i, int j){
    if(i == j){
      tree[n] = 0;
      return;
    }
    int mid = (i+j)/2;
    build(2*n+1, i, mid);
    build(2*n+2, mid+1, j);
    tree[n] = merge(tree[2*n+1], tree[2*n+2]);
  }

  void build(int n, int i, int j, vector<T> &init){
    //n: id del nodo actual


    if(i == j){ //Caso base, Estamos en una hoja del arbol
      tree[n] = init[i]; //Entonces, el nodo n, una hoja, le ponemos el valor del arreglo que estamos mirando
      return;
    }

    //Caso en un nodo cualquiera
    int mid = (i+j)/2; //Dividimos el intervalo a la mitad
    build(2*n+1, i, mid, init); //Construye el hijo izquierdo
    build(2*n+2, mid+1, j, init); //Construye el hijo derecho
    tree[n] = merge(tree[2*n+1], tree[2*n+2]); //Guardamos el valor del nodo actual, que es la operacion entre los hijos
  }

  T query(int l, int r){
    //Retorna la cabeza de ese intervalo
    return query(0, 0, N-1, l, r); //Llama desde la raiz, mira todo el arreglo [0, N-1] y quiero buscar en [l, r]
  }

  T query(int n, int i, int j, int l, int r){
    //"Builder de Query"
    //n: nodo actual
    //i, j: rango donde estoy mirando
    //l, r: rango objetivo, donde YO quiero ver

    if(l <= i && j <= r) return tree[n];//Caso base
    //Si contengo todo mi [i, j] en [l, r], significa que estoy mirando DENTRO de el objetivo
    //entonces, devuelvo el valor del nodo en donde estoy

    int mid = (i+j)/2; //Busco la mitad del arreglo

    if(mid < l || r < i) //Si estoy fuera totalmente del arreglo, es decir, quiero buscar a la izq o a la der
    //[i, mid][l, r] || [l, r][i, mid]
      return query(2*n+2, mid+1, j, l, r); //Query desde el hijo derecho, y "subo el piso" del rango en donde estoy buscando

    if(j < l || r < mid+1)
    //[mid+1, j][l, r] || [l, r][mid+1, j]
      return query(2*n+1, i, mid, l, r); //Query desde el hijo izquierdo, "bajo el techo" del rango en donde estoy buscando

    //Si no se cumple ninguno, significa que estoy con medio rango metido en el otro  
    return merge(
        query(2*n+1, i, mid, l, r), //Hijo izq
        query(2*n+2, mid+1, j, l, r)); //Hijo derecho
  }

  void update(int t, T val){
    //Actualiza el indice t con el valor val 
    update(0, 0, N-1, t, val); //Llama en el nodo 0, viendo el intervalo [0, N-1], busca el indice t y el valor
  }
  
  void update(int n, int i, int j, int t, T val){

    if(t < i || j < t) return; //Caso base, si no ecuentra t, no hce nada

    if(i == j){ //Llegamos a t y actualizamos el valor
      tree[n] = val;
      return;
    }

    int mid = (i+j)/2; //Veo la mitad
    update(2*n+1, i, mid, t, val); //Busco en el hijo izquierdo
    update(2*n+2, mid+1, j, t, val); //Busco en el hijo derecho

    tree[n] = merge(tree[2*n+1], tree[2*n+2]); //Al actualizar los dos hijos, tenemos que volver a mergear el nodo actual
  }

  int search(int from, T val){
    if(!from) return search(0, 0, N-1, val);
    return search(0, 0, N-1, val+query(0, from-1));
  }

  int search(int n, int i, int j, T val){
    if(tree[n] < val) return -1;
    if(i==j && tree[n] >= val) return i;
    int mid = (i+j)/2;
    if(tree[2*n+1] >= val) return search(2*n+1, i, mid, val);
    else return search(2*n+2, mid+1, j, val-tree[2*n+1]);
  }
};
// search (i, valor)
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i=0;i<n;i++) a[i] = 1; // lleno
    SegmentTree<int> st(a); // crear segment tree con el vector a
    int pos = 0;
    k += 1;
    int q = 0;
    for(int i = n; i>1; i--){
    k = k%i; // arreglar la cantidad de saltos
    int l; // donde esta la posicion
    if ( st.query(pos,n-1) < k){ 
        q = st.query(pos,n-1);
        l = st.search(pos,k-q);
    }
    else{
        l = st.search(pos,k); // indice donde esta mi respuesta
    } 
    pos += k;
    pos = pos%i;
    l += 1; // el valor 
    cout << l << '\n';
    st.update(l-1,0);
    }
    return 0;
}
