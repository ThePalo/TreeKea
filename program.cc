/**
 * @mainpage Diseño modular: Gestión de un almacén (TreeKea).
 
Programa modular que ofrece un menú de opciones para gestionar un almacén. Se introducen las clases <em>Almacen</em>, <em>Sala</em> y <em>Catalogo</em>.
*/

/** @file program.cc
    @brief Programa principal para la práctica <em>TreeKea</em>.
*/

#include "Almacen.hh"
#include "Sala.hh"
#include "Catalogo.hh"

/** @brief Programa principal para la práctica <em>TreeKea</em>.
*/
int main ()
{   
    int n;
    cin >> n;
    Almacen al(n);
    
    Catalogo cat;
    
    string op;
    cin >> op;
    
    string p;
    int cant, s, f, c;
    
    while (op != "fin") {
        
        if (op == "poner_prod") {
            cin >> p;
            cout << "poner_prod " << p << endl;
            if (cat.existe_prod(p)) 
                cout << "  " << "error" << endl;
            else cat.poner_prod(p);
        }
        
        else if (op == "quitar_prod") {
            cin >> p;
            cout << "quitar_prod " << p << endl;
            if (not cat.existe_prod(p) or not cat.cero_uds_prod(p)) 
                cout << "  " << "error" << endl;
            else cat.quitar_prod(p);
        }
        
        else if (op == "poner_items") {
            cin >> s >> p >> cant;
            cout << "poner_items " << s << " " << p << " " << cant << endl;
            if (not cat.existe_prod(p)) 
                cout << "  " << "error" << endl;
            else {
                int no_col = al.poner_items(s, p, cant);
                //Incrementamos el catálogo con los items que hemos colocado
                cat.modificar_prod(p, cant - no_col);
                cout << "  " << no_col << endl;
            }
        }
        
        else if (op == "quitar_items") {
            cin >> s >> p >> cant;
            cout << "quitar_items " << s << " " << p << " " << cant << endl;
            if (not cat.existe_prod(p)) 
                cout << "  " << "error" << endl;
            else {
                int no_quit = al.quitar_items(s, p, cant);
                //Decrementamos el catálogo con los items que hemos quitado
                cat.modificar_prod(p, -(cant - no_quit));
                cout << "  " << no_quit << endl;
            }
        }
        
        else if (op == "distribuir") {
            cin >> p >> cant;
            cout << "distribuir " << p << " " << cant << endl;
            if (not cat.existe_prod(p)) 
                cout << "  " << "error" << endl;
            else {
                int uds = al.distribuir(p, cant);
                //Incrementamos el catálogo con los items que hemos colocado
                cat.modificar_prod(p, cant - uds);
                cout << "  " << uds << endl;
            }
        }
        else if (op == "compactar") {
            cin >> s;
            cout << "compactar " << s << endl;
            al.compactar(s);            
        }
        
        else if (op == "reorganizar") {
            cin >> s;
            cout << "reorganizar " << s << endl;
            al.reorganizar(s);
        }
        
        else if (op == "redimensionar") {
            cin >> s >> f >> c;
            cout << "redimensionar " << s << " " << f << " " << c << endl;
            al.redimensionar(s, f, c);
        }
        
        else if (op == "inventario") {
            cout << "inventario" << endl;
            cat.inventario();
        }
        
        else if (op == "escribir") {
            cin >> s;
            cout << "escribir " << s << endl;
            al.escribir(s);
        }
        
        else if (op == "consultar_pos") {
            cin >> s >> f >> c;
            cout << "consultar_pos " << s << " " << f << " " << c << endl;
            al.consultar_pos(s, f, c);
        }
        
        else if (op == "consultar_prod") {
            cin >> p;
            cout << "consultar_prod " << p << endl;
            cat.consultar_prod(p);
        }
        cin >> op;
    }
    cout << "fin" << endl;
    return 0;
}
