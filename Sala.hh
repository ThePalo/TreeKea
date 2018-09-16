/** @file Sala.hh
    @brief Especificación de la clase Sala 
*/

#ifndef _SALA_HH_
#define _SALA_HH_
#include "Catalogo.hh"

/** @class Sala
    @brief Representa el conjunto de características y operaciones para la correcta representación de una sala. 

    La sala contiene una estantería para guardar productos en ella (representados por una matriz de string de cada ID del producto). También hay un catálogo con los productos de la sala y su cantidad (clase Catalogo). Y un contador del total de productos de la sala. Se pueden consultar, eliminar i mover sus elementos (de tipo string). */


class Sala
{

private:
    
    /** @brief Contador del total de productos de la sala */
    int t_prod;
    /** @brief Catalogo específico para la sala (este catálogo no puede tener productos con 0 unidades ya que representa los productos que hay en el almacén)*/
    Catalogo cat;
    /** @brief Estantería de la sala */
    vector < vector<string> > est;
    
public:

    //Constructoras
    
    /** @brief Creadora por defecto. 

        Se ejecuta automáticamente al declarar una sala.
        \pre Cierto.
        \post El resultado es una sala no inicializada.
    */  
    Sala();
    
    /** @brief Creadora con inicialización. 

        Se ejecuta automáticamente al declarar una sala con parámetros.
        \pre Cierto.
        \post El resultado es una sala inicializada.
    */  
    Sala(int f, int c);
    
    
    //Modificadoras
    
    /** @brief Poner producto en una sala.

        \pre La cantidad es correcta y el producto existe en el catálogo del almacén.
        \post Máximas unidades colocadas en la sala y se devuelve entero con unidades no colocadas.
    */
    int poner_items(const string &p, int cant);
    
    
    /** @brief Quitar producto de una sala.

        \pre La cantidad es correcta y el producto existe en el catálogo del almacén.
        \post Máximas unidades quitadas en la sala y se devuelve entero con unidades que no se han podido quitar (porque no había tantas o porque el producto no está en esa sala).
    */
    int quitar_items(const string &p, int cant);
    
    
    /** @brief Compactar la estantería de la sala.

        \pre Cierto.
        \post Estantería compactada a izquierda y abajo, sin huecos entre productos y respetando el orden inicial de estos.
    */
    void compactar();
    
    
    /** @brief Reorganizar la estantería de la sala.

        \pre Cierto.
        \post Estantería reorganizada por orden alfabético, sin huecos entre productos.
    */
    void reorganizar();
    
    
    /** @brief Redimensionar la estantería de la sala.

        \pre Cierto.
        \post Estantería compactada y redimensionada o error si no caben los productos en la nueva estantería (error si f*c < t_prod).
    */
    void redimensionar(int f, int c);
    
    
    // Consultoras
    
    /** @brief Escribir el contenido de la sala.

        \pre Cierto.
        \post Escribir contenido estantería de arriba a abajo y de izq. a der. (NULL si hueco vacío), el total de productos y el desglose de estos en cada producto y su cantidad correspondiente (por orden de identificador).
    */
    void escribir() const;
    
    
    /** @brief Consultar posición de la estantería de la sala.

        \pre Cierto.
        \post Escribir el nombre del producto de la posición o NULL si la posición es vacía o incorrecta.
    */
    void consultar_pos(int f, int c) const;
    
};
#endif
