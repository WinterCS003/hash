#include <iostream>
#include <string>

#include "HashTable.h"

/**********************************************************
 *
 * CONSTRUCTOR HashTable
 *_________________________________________________________
 * This function null initializes the attributes
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will create a new HashTable object 
 *   with all null initialized attributes.
 ***********************************************************/
HashTable::HashTable(){
  _size = 0;
  _linearCollisions = 0;
  _quadraticCollisions = 0;
  _chainingCollisions = 0;
  _table = nullptr;
  _chainTable = nullptr;
}

/**********************************************************
 *
 * CONSTRUCTOR HashTable
 *_________________________________________________________
 * This function initializes attributes to the give values
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following must be defined:
 *     size (int):         // IN - size of table to create
 *     file (std::string): // IN - file to read words from
 *
 * POST-CONDITIONS
 *   This function will create a new HashTable object 
 *   with a table with given size and hashes taken from 
 *   words read from the file.
 ***********************************************************/
HashTable::HashTable(int size,         // IN - size of table 
                     uniqueWords& u) // IN - all unique words
{
  _size = size;
  _linearCollisions = 0;
  _quadraticCollisions = 0;
  _chainingCollisions = 0;
  
  _table = nullptr;
  _chainTable = nullptr;

  // create tables based on the number of hashes 
  _table = new bool[_size];
  _chainTable = new node*[_size];
  for(int i = 0; i < _size; i++){
    _chainTable[i] = new node(false, nullptr);
  }

  std::cout << "Beginning testing on table size: " << _size << std::endl;
  linearProbing(u);
  std::cout << "Linear Probing finished\n";
  quadraticProbing(u);
  std::cout << "Quadratic Probing finished\n";
  chainProbing(u);
  std::cout << "Chaining finished\n\n";
}


/**********************************************************
 *
 * DESTRUCTOR HashTable
 *_________________________________________________________
 * This function will delete all variables used by the 
 * program
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will free any dynamic memory used by the
 *   program.
 ***********************************************************/
HashTable::~HashTable(){
  delete [] _table; // delete table
  // delete all nodes of chaining table 
  for(int i = 0; i < _size; i++){
    for(node* current = _chainTable[i]; current != nullptr;){
      node* temp = current->_next;
      delete current;
      current = temp;
    }
  }
  delete [] _chainTable;
}

/**********************************************************
 *
 * FUNCTION clearTable 
 *_________________________________________________________
 * This function receives nothing and clears all values
 * in the table.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   All values in table are set to false to indicate empty.
 ***********************************************************/
void HashTable::clearTable(){
  for(int i = 0; i < _size; i++){
    _table[i] = false;
  }
}

/**********************************************************
 *
 * FUNCTION linearProbing
 *_________________________________________________________
 * This function receives nothing and adds all the hashes 
 * computed from the file to the table using linearProbing
 * to handle collisions 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will update the number of collisions that 
 *   occurred.
 ***********************************************************/
void HashTable::linearProbing(uniqueWords& u){
  clearTable();
  unsigned int index = 0;
  for(unique* current = u.Head(); current != nullptr; current = current->next){
    index = hashFunction(current->data) % _size;
    
    while(_table[index]){
      _linearCollisions++;
      index = (index + 1) % _size;
    }

    _table[index] = true;
  }
}

/**********************************************************
 *
 * FUNCTION quadraticProbing
 *_________________________________________________________
 * This function receives nothing and adds all the hashes 
 * computed from the file to the table using quadratic 
 * probing to handle collisions 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will update the number of collisions that 
 *   occurred.
 ***********************************************************/
void HashTable::quadraticProbing(uniqueWords& u){
  clearTable();
  int hash = 0;
  int index = 0;
  // iterate through all hashes from file 
  for(unique* current = u.Head(); current != nullptr; current = current->next){
    hash = hashFunction(current->data) % _size;
    for(int j = 0; ; j++){
      index = (hash + j*j)%_size;
      // if there are no new indices, resize aray 
      if(j != 0 && index == hash){
        std::cout << "Quad resize!" << std::endl;
        bool* temp = new bool[2*_size];
        for(int i = 0; i < _size; i++){
          temp[i] = _table[i];
        }
        delete [] _table;
        _table = temp;
      }
      if(!_table[index]){
        _table[index] = true;
        break;
      } else{
        _quadraticCollisions++;
      }
    }
  }
}

/**********************************************************
 *
 * FUNCTION chainProbing
 *_________________________________________________________
 * This function receives nothing and adds all the hashes 
 * computed from the file to the table using chaining to 
 * handle collisions 
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will update the number of collisions that 
 *   occurred.
 ***********************************************************/
void HashTable::chainProbing(uniqueWords& u){
  int hash = 0;
  node* current = nullptr;
  for(unique* curr = u.Head(); curr != nullptr; curr = curr->next){
    hash = hashFunction(curr->data) % _size;
    current = _chainTable[hash];
    if(!current->_word){
      current->_word = true;
    } else{
      _chainingCollisions++;
      while(current->_next != nullptr){
        current = current->_next;
        _chainingCollisions++;
      }
      current->_next = new node(true, nullptr);
    }
  }
}
