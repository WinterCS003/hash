#ifndef HASH_H
#define HASH_H

struct unique{
    std::string data;
    unique* next;

    unique(): data(""), next(nullptr){};
    unique(std::string d): data(d), next(nullptr){};
};

class uniqueWords{
  private:
    unique* head;
    unique* tail;
    int count;
    
  public:
  /******************************
   ** CONSTRUCTOR & DESTRUCTOR **
   ******************************/
    uniqueWords();

    ~uniqueWords();
    
  /***************
   ** ACCESSORS **
   ***************/
    bool contains(std::string word) const; // IN - word to check
    
    unique* Head() const { return head; }; 
    
    int size() const { return count; };
  
    /**************
     ** MUTATORS **
     **************/
    void append(std::string word); // IN - word to insert

    void readFile(std::string file); // IN - file to read
};

/****************************************************************
 * Hash Class
 *   This class represents a list of all unique words stored as 
 *   strings in a linked list.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/
  
/***********************************************************
* Hash()
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
* ~Hash();
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
 * unique* Head() const;
 *
 *   Accessor; This method will return a pointer to the head
 *             node of the list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: head - pointer to head of node
 ***************************************************************/
 
 
/****************************************************************
 * int size() const;
 *
 *   Accessor; This method will return the number of unique words
 *             in the list.
 * --------------------------------------------------------------
 *   Parameters: none
 * --------------------------------------------------------------
 *   Return: count - number of unique words in list 
 ***************************************************************/

 /**************
  ** MUTATORS **
  **************/

/****************************************************************
 * void append(std::string word);
 *
 *   Mutator; This function will add the given word to the end 
 *            of the list if it is not already in the list.
 * --------------------------------------------------------------
 *   Parameters: word (std::string) // IN - word to add
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

/****************************************************************
 * void readFile(std::string file);
 *
 *   Mutator; This function will read from the given file
 *            and stores all unique words found
 *            in the file.
 * --------------------------------------------------------------
 *   Parameters: file(std::string) // IN - file to read
 * --------------------------------------------------------------
 *   Return: none
 ***************************************************************/

#endif // HASH_H
