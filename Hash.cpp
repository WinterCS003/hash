#include <iostream>
#include <fstream>

#include "Hash.h"

/**********************************************************
 *
 * CONSTRUCTOR readFile 
 *_________________________________________________________
 * This constructor receives nothing and initializes 
 * attributes to nullptr and 0.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will null or zero-initialize attributes.
 ***********************************************************/
uniqueWords::uniqueWords(){
  head = tail = nullptr;
  count = 0;
}
    
/**********************************************************
 *
 * DESTRUCTOR ~uniqueWords
 *_________________________________________________________
 * This destructor receives nothing and deletes any
 * dynamically allocated memory
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will free all used memory.
 ***********************************************************/
uniqueWords::~uniqueWords(){ 
  for(unique* current = head; current != nullptr;){ 
    unique* temp = current; 
    current = current->next; 
    delete temp; 
  } 
}
    
/**********************************************************
 *
 * FUNCTION contains 
 *_________________________________________________________
 * This function receives a word and returns true if the
 * word is found in the list.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following must be defined:
 *     word(std::string) // IN - word to check
 *
 * POST-CONDITIONS
 *   This function will return true if the given word is
 *   found in the list. This ensures that the list only 
 *   contains unique words.
 ***********************************************************/
bool uniqueWords::contains(std::string word) // IN - word to check
const {
   for(unique* current = head; current != nullptr; current = current->next){
    if(current->data == word){
      return true;
    }
  }
  return false;
}
    
/**********************************************************
 *
 * FUNCTION append 
 *_________________________________________________________
 * This function adds the given word to the end of the
 * list if it does not already exist.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following must be defined:
 *      word(std::string) : // IN - word to insert
 *
 * POST-CONDITIONS
 *   This function will update the count and the list if the
 *   word is added.
 ***********************************************************/
void uniqueWords::append(std::string word) // IN - word to insert
{
  if(contains(word)){
    return;
  }
  if(count == 0){
    head = tail = new unique(word);
  } else{
    unique* temp = new unique(word);
    tail->next = temp;
    tail = temp;
  }
  count++;

  if(count % 10000 == 0){
    std::cout << count << " unique words counted so far\n";
  }
}

/**********************************************************
 *
 * FUNCTION readFile 
 *_________________________________________________________
 * This function receives nothing and reads from the 
 * file defined in the constructor. All words in the
 * file are hashed and stored in a dynamic array.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following must be defined:
 *     file(std::string) // IN - file to read from
 *
 * POST-CONDITIONS
 *   This function will generate and store the hashes of
 *   all the words found in the file.
 ***********************************************************/
void uniqueWords::readFile(std::string file) // IN - file to read from
{
  std::cout << "Finding unique words..." << std::endl;

  std::ifstream input(file);
  if(input.is_open())
  {
    char c;
    std::string line;
    std::string word;
    while(std::getline(input, line))
    {
      for(unsigned int i = 0; i < line.size(); i++){
        c = line[i];
        // store only letters
        if((c >= 65 && c <= 90 ) || (c >= 97 && c<= 122))
        {
          word += c;
        }
        // at the end of the word or the line, compute the hash 
        if((c == ' ' || i == line.size()-1) && word.size() > 0)
        {
          append(word);
          word = "";
        }
      }
    }
  }
  input.close();

  std::cout << "Total: " << count << " unique words counted\n\n";
}
