/** @file Catalogo.cc
    @brief Código de la clase Catalogo 
*/

#include "Catalogo.hh"

Catalogo::Catalogo() {}

//Modificadoras

void Catalogo::poner_prod(const string &p) 
{
    cat[p] = 0;
}

void Catalogo::quitar_prod(const string &p) 
{
    cat.erase(p);
}

void Catalogo::modificar_prod(const string &p, int cant)
{
    cat[p] += cant;
}


//Consultoras
    
void Catalogo::inventario() const
{
    for (map<string, int>::const_iterator i = cat.begin(); i != cat.end(); ++i)
        cout << "  " << i->first << " " << i->second << endl;
}
    
void Catalogo::consultar_prod(const string &p) const
{
    //No se aprovecha la funcion existe_prod para que esta sea mas óptima, ya que así evitamos hacer 2 find.
    map<string, int>::const_iterator i = cat.find(p);
    if (i == cat.end()) cout << "  " << "error" << endl;
    else cout << "  " << i->second << endl;
}
    
bool Catalogo::existe_prod(const string &p) const
{
    map<string, int>::const_iterator i = cat.find(p);
    return (i != cat.end());
}

bool Catalogo::cero_uds_prod(const string &p) const
{
    map<string, int>::const_iterator it = cat.find(p);
    return (it->second == 0);
}

vector < vector <string> > Catalogo::reorganizar(int f, int c)
{
    vector < vector<string> > est (f,vector<string>(c,"NULL"));
    int cont_i = f - 1;
    int cont_j = 0;
    //Hacemos un recorrido de todos los productos.
    for (map<string, int>::const_iterator it = cat.begin(); it != cat.end(); ++it) {
        //Añadimos tantos productos a la estanteria como hay en el diccionario.
        for (int x = 0; x < it->second; ++x) {
            est[cont_i][cont_j] = it->first;
            if (cont_j == c - 1) {
                cont_j = 0;
                --cont_i;
            } else ++cont_j;
        }
    }
    return est;
}
