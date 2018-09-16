/** @file Almacen.hh
    @brief Especificación de la clase Almacen 
*/

#ifndef _ALMACEN_HH_
#define _ALMACEN_HH_

#include "Sala.hh"
#include "Catalogo.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

/** @class Almacen
    @brief Representa el conjunto de características y operaciones para la correcta representación de un almacén 

    El almacén es representado en forma de árbol binario, dónde cada nodo del árbol es una ID de sala. Esta ID esta relacionada con un vector de salas (posición de la sala en el vector = (ID sala en BinTree) - 1). Hay un catalogo que contiene todos los productos y sus cuantidades. Se pueden consultar elementos en el árbol (una vez inicializado ya no se pueden añadir mas nodos), consultar y modificar elementos del vector de sala y consultar, modificar y añadir elementos en el catalogo. */

class Almacen
{
    
private:
    
    /** @brief Árbol binario que contiene una ID de sala en cada nodo */    
    BinTree<int> id_sala;
    /** @brief Vector de Sala que contiene todas las salas */
    vector<Sala> val;
    
    //Inicialización
    
    /** @brief Inicializadora por defecto. 

        Se ejecuta automáticamente al declarar un almacén.
        \pre En la entrada hay la secuencia, en preorden, de los nodos del árbol.
        \post El resultado es un árbol inicializado.
    */
    static void initBinTree(BinTree<int>& a);
    
    
    //Distribución 
    
    /** @brief Inmersión de la función Distribuir por especificación.

        \pre El producto existe en el catálogo de almacén, la cantidad es correcta.
        \post Distribuye la cantidad del producto por todo el almacén y devuelve las unidades que no han podido ser distribuidas.
    */
    int i_distribuir(const string &p, int cant, const BinTree<int>& a);
    
    
public:
    
    //Constructoras
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar un almacén.
        \pre Cierto.
        \post El resultado es un almacén no inicializado.
    */  
    Almacen();

    
    /** @brief Creadora con inicialización. 

        Se ejecuta automáticamente al declarar un almacén con parámetros.
        \pre Cierto.
        \post El resultado es un almacén inicializado.
    */  
    Almacen(int n);
    
    //Modificadoras de almacén
    
    /** @brief Distribuir producto por el almacén (en preorden).

        \pre El producto existe en el catálogo de almacén, la cantidad es correcta (modifica el catálogo).
        \post Se distibuye producto y devuelve entero con unidades no distribuidas.
    */
    int distribuir(const string &p, int cant);
    
    
    //Modificadoras de sala
    
    /** @brief Poner producto en una sala seleccionada del almacén.

        \pre La sala y cantidad son correctas. El producto existe en el catálogo de almacén.
        \post Máximas unidades colocadas en la sala y se devuelve entero con unidades no colocadas.
    */
    int poner_items(int s, const string &p, int cant);
    
    
    /** @brief Quitar producto de una sala seleccionada del almacén.

        \pre La sala y cantidad son correctas. El producto existe en el catálogo de almacén.
        \post Máximas unidades quitadas en la sala y se devuelve entero con unidades que no se han podido quitar (porque no había tantas).
    */
    int quitar_items(int s, const string &p, int cant);
    
    
    /** @brief Compactar la estantería de la sala seleccionada del almacén.

        \pre La sala es correcta.
        \post Estantería compactada a izquierda y abajo, sin huecos entre productos y respetando el orden inicial.
    */
    void compactar(int s);
    
    
    /** @brief Reorganizar la estantería de la sala seleccionada del almacén.

        \pre La sala es correcta.
        \post Estantería reorganizada por orden alfabético, sin huecos entre productos.
    */
    void reorganizar(int s);
    
    
    /** @brief Redimensionar la estantería de la sala seleccionada del almacén.

        \pre La sala es correcta.
        \post Estantería compactada y redimensionada o error si no caben los productos en la nueva estantería.
    */
    void redimensionar(int s, int f, int c);
    
    
    // Consultoras de sala
    
    /** @brief Escribir el contenido de la sala seleccionada del almacén.

        \pre La sala es correcta.
        \post Escribir contenido de la sala: estantería de arriba a abajo y de izq. a der. (NULL si hueco vacío), el total de productos y el desglose de estos en cada producto y su cantidad correspondiente (por orden de identificador).
    */
    void escribir(int s) const;
    
    
    /** @brief Consultar posición de la estantería de la sala seleccionada del almacén.

        \pre La sala es correcta.
        \post Escribir el nombre del producto de la posición o NULL si la posición es vacía o incorrecta.
    */
    void consultar_pos(int s, int f, int c) const;
    

};
#endif
