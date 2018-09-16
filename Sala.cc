/** @file Sala.cc
    @brief Código de la clase Sala 
*/

#include "Sala.hh"

Sala::Sala() 
{
    t_prod = 0;    
}

Sala::Sala(int f, int c)
{
    t_prod = 0;
    est = vector < vector<string> > (f,vector<string>(c,"NULL"));
}

//Modificadoras

int Sala::poner_items(const string &p, int cant)
{
    int j, i = est.size() - 1;
    int cab = 0;
    //Colocamos p respetando la cantidad
    while (i >= 0 and cab < cant) {
        j = 0;
        while (j < est[0].size() and cab < cant) {
            if (est[i][j] == "NULL") {
                est[i][j] = p;
                ++cab;
            }
            ++j;
        }
        --i;
    }
    //Si hemos colocado algun p, lo añadimos/modificamos al catalogo propio de sala
    if (cab > 0) {
        if (cat.existe_prod(p)) cat.modificar_prod(p, cab);
        else {
            cat.poner_prod(p);
            cat.modificar_prod(p, cab);
        }
        t_prod += cab;
    }
    //Devolvemos p no colocados
    return (cant - cab);  
}


int Sala::quitar_items(const string &p, int cant)
{
    //Si existe p, miramos cuantas unidades quitamos
    if (cat.existe_prod(p)) {
        int j, i = est.size() - 1;
        int quitar = 0;
        while (i >= 0 and cant > quitar) {
            j = 0;
            while (j < est[0].size() and cant > quitar) {
                if (est[i][j] == p) {
                    est[i][j] = "NULL";
                    ++quitar;
                }
                ++j;
            }
            --i;
        }
        //Modificamos catalogo de sala, decrementando unidades quitadas
        cat.modificar_prod(p, -quitar);
        t_prod -= quitar;
        //Si hay 0 unidades del producto, lo eliminamos
        if (cat.cero_uds_prod(p)) cat.quitar_prod(p);
        //Devolvemos unidades que no hemos podido quitar
        return (cant - quitar);
    }
    //Si no existe, devolvemos todas las unidades
    else return cant;    
}


void Sala::compactar()
{
    int cont_i = est.size() - 1;
    int cont_j = 0;
    bool t = false;
    for (int i = est.size() - 1; i >= 0; --i) {
        for (int j = 0; j < est[0].size(); ++j) {
            //Recorremos la estantería hasta encontrar la primera posición vacía
            if (est[i][j] == "NULL" and not t) {
                cont_i = i;
                cont_j = j;
                t = true;
            }
            /*Una vez encontrada, vamos intercambiando (swap) la posición vacía por el primer producto que encontremos a partír de esa posición.
            Después del swap, incrementamos posiciones de la estantería hasta encontrar el siguiente porducto que pueda intercanviarse por una posición vacía.*/
            if (est[i][j] != "NULL" and t) {
                est[cont_i][cont_j] = est[i][j];
                est[i][j] = "NULL";
                if (cont_j == est[0].size() - 1) {
                    cont_j = 0;
                    --cont_i;
                } else ++cont_j;
            }
        }
    }
}


void Sala::reorganizar()
{
    //Estantería pasa a ser el nuevo vector creado en la clase Catalogo
    est = cat.reorganizar(est.size(), est[0].size());
}


void Sala::redimensionar(int f, int c)
{
    if (f*c < t_prod) cout << "  " << "error" << endl;
    else {
        int cont_i = f - 1;
        int cont_j = 0;
        vector < vector<string> > n_est (f,vector<string>(c,"NULL"));
        /*Hacemos un recorrido de la estantería inicial, copiando los productos en la 
        nueva estantería, sin dejar huecos entre ellos. */
        for (int i = est.size() - 1; i >= 0; --i) {
            for (int j = 0; j < est[0].size(); ++j) {
                if (est[i][j] != "NULL") {
                    n_est[cont_i][cont_j] = est[i][j];
                    if (cont_j == c - 1) {
                    cont_j = 0;
                    --cont_i;
                    } else ++cont_j;
                }
            }
        }
        //Estantería pasa a ser la nueva estantería inicializada previamente
        est = n_est;
    }
}


// Consultoras

void Sala::escribir() const
{
    for (int i = 0; i < est.size(); ++i) {
        cout << " ";
        for (int j = 0; j < est[0].size(); ++j) {
            cout << " " << est[i][j];
        }
        cout << endl;
    }
    cout << "  " << t_prod << endl;
    cat.inventario();
}


void Sala::consultar_pos(int f, int c) const
{
    if (f > est.size() or f < 0 or c > est[0].size() or c < 0) 
        cout << "  " << "NULL" << endl;
    else cout << "  " << est[f-1][c-1] << endl;
}
