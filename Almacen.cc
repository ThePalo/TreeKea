/** @file Almacen.cc
    @brief Código de la clase Almacen 
*/

#include "Almacen.hh"


Almacen::Almacen() {}

Almacen::Almacen(int n) 
{
    val = vector<Sala>(n);
    //Inicializador de almacen
    initBinTree(id_sala);
    //Inicializador de sales
    int f, c;
    for (int i = 0; i < n; ++i) {
        cin >> f >> c;
        val[i] = Sala(f, c);
    }        
}

void Almacen::initBinTree(BinTree<int>& a) 
{
    int x;
    cin >> x;
    if (x != 0) {
        BinTree<int> a1;
        initBinTree(a1);
        BinTree<int> a2;
        initBinTree(a2);
        a = BinTree<int>(x, a1, a2);
    }
}

int Almacen::distribuir(const string &p, int cant)
{
    //Utilitzamos una función de inmersión
    return i_distribuir(p, cant, id_sala);
}

int Almacen::i_distribuir(const string &p, int cant, const BinTree<int>& a)
{
    if (a.empty()) return cant;
    else {
        //Colocamos productos en la raíz del árbol
        int no_col = val[a.value()-1].poner_items(p, cant);
        if (no_col > 0) {
            /*Distribuimos los productos no colocados para colocarlos recursivamente en los siguientes sub-árboles, otorgando la mitad de los no colocados (+1 si sín impares) al subárbol izquierdo y la otra mitad al derecho.*/
            int col_left, col_right;
            col_left = col_right = no_col/2;
            if (no_col%2 != 0) ++col_left;
            BinTree<int> a1 = a.left();
            int no_col_left = i_distribuir(p, col_left, a1);
            BinTree<int> a2 = a.right();
            int no_col_right = i_distribuir(p, col_right, a2);
            //Devolvemos las unidades que no se han podido distribuir en los subárboles
            return no_col_left + no_col_right;
        } 
        else return no_col;
    }             
}

//Modificadoras sala
int Almacen::poner_items(int s, const string &p, int cant) 
{
    return val[s-1].poner_items(p, cant);    
}

int Almacen::quitar_items(int s, const string &p, int cant) 
{
    return val[s-1].quitar_items(p, cant);
}

void Almacen::compactar(int s)
{
    val[s-1].compactar();
}
    
void Almacen::reorganizar(int s)
{
    val[s-1].reorganizar();
}
    
void Almacen::redimensionar(int s, int f, int c)
{
    val[s-1].redimensionar(f,c);
}

//Consultoras sala
void Almacen::escribir(int s) const
{
    val[s-1].escribir();
}
    
void Almacen::consultar_pos(int s, int f, int c) const
{
    val[s-1].consultar_pos(f,c);
}
