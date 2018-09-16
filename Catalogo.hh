/** @file Catalogo.hh
    @brief Especificación de la clase Catalogo 
*/

#ifndef _CATALOGO_HH_
#define _CATALOGO_HH_

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <string>
#include <map>
#endif
using namespace std;

/** @class Catalogo
    @brief Representa un catálogo, ya sea de almacén o de sala.
    
    Diccionario (map) con todos los productos (de un almacén o una estantería) y con sus corespondientes unidades, organizados por su ID (string).
    
    Dada la similitud y correspondencia entre el catálogo de almacén (el general) y el catálogo de salas (productos en X sala), esta clase se usará para representar ambos. Es por esto que hay ciertas operaciones creadas específicamente para encajar en una u otra definición.*/

class Catalogo
{
    
private:
    
    /** @brief Diccionario con los productos ordenados alfabéticamente y sus cantidades correspondientes */
    map < string, int > cat;
    
    
public:
    
    //Constructoras
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un catálogo.
        \pre Cierto.
        \post El resultado es un catálogo no inicializado.
    */  
    Catalogo();
    
    
    //Modificadoras
    
    /** @brief Introducir un nuevo producto al catálogo.
     * 
        \pre El producto no existe en el parámetro implícito.
        \post Producto dado de alta en el parámetro implícito con cero unidades.
    */
    void poner_prod(const string &p);
    
    
    /** @brief Quitar un producto del catálogo.
     * 
        \pre El producto a eliminar existe y tiene 0 uds en el parámetro implícito.
        \post Producto eliminado del parámetro implícito.
    */
    void quitar_prod(const string &p);
    
    
    /** @brief Modificar unidades de un producto del catálogo.
     * 
        \pre El producto a modificar existe en el parámetro implícito. Uds. del producto + cant >= 0.
        \post Producto modificado (Uds. producto = uds. original + cant) en el parámetro implícito.
    */
    void modificar_prod(const string &p, int cant);
    
    
    //Consultoras
    
    /** @brief Mostrar inventario.

        \pre Cierto
        \post Escribe productos del parámetro implícito y su cantidad (ordenado implícitamente por orden alfabético).
    */
    void inventario() const;
    
    
    /** @brief Consultar producto en el catálogo.

        \pre Cierto.
        \post Escribir la cantidad total del producto o error si no existe en el parámetro implícito.
    */
    void consultar_prod(const string &p) const;
    
    
    /** @brief Consultar si existe el producto en el catálogo.

        \pre Cierto.
        \post Cierto si el producto existe en el parámetro implícito.
    */
    bool existe_prod(const string &p) const;
    
    
    /** @brief Consultar si el producto tiene 0 unidades.

        \pre El producto existe en el parámetro implícito.
        \post Cierto si el producto del parámetro implícito tiene 0 unidades.
    */
    bool cero_uds_prod(const string &p) const;
    
    /** @brief Reorganizar sala por orden alfabético a partir de su catálogo.

        \pre Cierto.
        \post Devuelve una estantería de medida f y c, con todos los productos ordenados alfabéticamente y sin espacios entre ellos.
    */
    vector < vector <string> > reorganizar(int f, int c);
    
};
#endif
