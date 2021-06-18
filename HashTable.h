#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <cstdlib>

#include "Hash.h"

// function to use for hashing
#define HASH_FUNCTION(input) rand()%_size //input.size()%_size // Replace Me!

/***********************************************************
* struct node
*_________________________________________________________
* This node is used for chain probing. It manages a 
* a boolean to indicate if it holds a data value 
* and a pointer to the next node.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   A boolean and pointer to node are initialized.
***********************************************************/
struct node{
  bool _word;  // IN - indicates if data is being held
  node* _next; // IN - pointer to next node

  node(): _word(false), _next(nullptr){};
  node(bool word, node* next): _word(word), _next(next){};
};

/***********************************************************
* Class CompareMin
*_________________________________________________________
* This templated class implements a minimum value comparator. 
* There is only 1 function.
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Allows for comparison between 2 values, true is 
*   returned if the value to the left is less than the other.
***********************************************************/
class HashTable{
  private:
    int _size;                // IN - size of tables
    int _linearCollisions;    // IN - counts number of collisions from 
                              //      linear probing
    int _quadraticCollisions; // IN - counts number of collisions for
                              //      quadratic probing
    int _chainingCollisions;  // IN - counts number of collisions for
                              //      chain probing
    bool* _table;             // IN - table for linear and quadratic
                              //      probing
    node** _chainTable;       // IN - 2D array for table with chain
                              //      probing
    /**************
     ** MUTATORS **
     **************/
    void clearTable();

    void linearProbing(uniqueWords& u);    // IN - reference to list of unique words
    void quadraticProbing(uniqueWords& u); // IN - reference to list of unique words
    void chainProbing(uniqueWords& u);     // IN - reference to list of unique words
    
  public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
    HashTable();
    HashTable(int size,        // IN - size of table to create
              uniqueWords& u); // IN - list of unique words
    ~HashTable();
  
  /***************
   ** ACCESSORS **
   ***************/
    int linCollisions() const { return _linearCollisions; }; 
    int quadCollisions() const { return _quadraticCollisions; };
    int chainCollisions() const { return _chainingCollisions; };
    int size() const { return _size; };
    int hashFunction(std::string input){
      unsigned int hash = 5381;
      for(int i = 0; i < input.size(); i++){
        hash = ((hash << 5) + hash) + (int)input[i];
      }

      return hash;
    }
};


/****************************************************************
 * HashTable Class
 *   This class represents a hash table that stores all words of
 *   in Shakespeare's plays into a table. Three different 
 *   techniques are used to handle collisions: linear, quadratic,
 *   and chaining. The number of collisions for each method
 *   are calculated and output to the console.
 ***************************************************************/


/*****************
 ** CONSTRUCTOR **
 *****************/

/***********************************************************
* HashTable()
*_________________________________________________________
* Constructor; initializes variable data
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   Initializes all values to zero or none.   
***********************************************************/

/***********************************************************
* HashTable(int size, uniqueWords& u);
*_________________________________________________________
* Constructor; initializes variable data
*_________________________________________________________
* PRE-CONDITIONS
*   The following variables must be declared:
*     size (int):         // IN - size of table to create
*     u (uniqueWords&):   // IN - reference to list of unique words
*
* POST-CONDITIONS
*   Creates a table with the given size and uses the list
*   to add words onto the table. Linear, quadratic 
*   and chain probing are used to calculate the number of
*   collisions caused when storing the words.
***********************************************************/


/****************
 ** DESTRUCTOR **
 ****************/

/***********************************************************
* ~HashTable();
*_________________________________________________________
* Destructor; frees any dynamically allocated memory
*_________________________________________________________
* PRE-CONDITIONS
*   none
*
* POST-CONDITIONS
*   frees any dynamically allocated memory 
***********************************************************/


/***************
 ** ACCESSORS **
 ***************/

/****************************************************************
 * int linCollisions() const;
 *
 *   Accessor; This method will return the number of collisions
 *             caused by using linear probing.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _linearCollisions - number of collisions 
 ***************************************************************/

/****************************************************************
 * int quadCollisions() const;
 *
 *   Accessor; This method will return the number of collisions
 *             caused by using quadratic probing.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _quadraticCollisions - number of collisions 
 ***************************************************************/
   
/****************************************************************
 * int chainCollisions() const;
 *
 *   Accessor; This method will return the number of collisions
 *             caused by using chaining 
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _chainingCollisions - number of collisions 
 ***************************************************************/

/****************************************************************
 * int size () const;
 *
 *   Accessor; This method will return the size of the table.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: _size - size of table
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/
    
/****************************************************************
 * void clearTable();
 *
 *   Mutator; This function will delete all data from table
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
    
/****************************************************************
 * void linearProbing(uniqueWords& u);
 *
 *   Mutator; This function will store all hashes into the table
 *            using linear probing.
 * --------------------------------------------------------------
 *   Parameters: u // IN - reference to list of unique words
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

    
/****************************************************************
 * void quadraticProbing(uniqueWords& u);
 *
 *   Mutator; This function will store all hashes into the table
 *            using quadratic probing.
 * --------------------------------------------------------------
 *   Parameters: u // IN - reference to list of unique words
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/
    
/****************************************************************
 * void chainProbing(uniqueWords& u);
 *
 *   Mutator; This function will store all hashes into the table
 *            using chaining.
 * --------------------------------------------------------------
 *   Parameters: u // IN - reference to list of unique words
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

#endif // HASHTABLE_H
