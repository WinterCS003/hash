/******************************************************************
 * AUTHOR   : Jaemok C. Lee
 * ASSIGNMENT #8 : Hashing Shakespeare
 * CLASS    : CS 008 Data Structures
 * SECTION  : 6:30p - 8:35
 * DUE DATE : 05/14/2021
 ******************************************************************/
#include <iostream>
#include <fstream>
#include <ctime>

#include "HashTable.h"
#include "Hash.h"

/************************************************************
*
* Hashing Shakespeare
*___________________________________________________________
* This program stores the hashes of all words found in 
* Shakespeare's plays. Collisions are handled with 
* three methods: linear probing, quadratic probing, and 
* chaining. The method that produces the least number of
* collisions is found and returned.
*___________________________________________________________
* INPUTS:
*   none
*
* OUTPUTS:
*   report of number of collisions for each table, and the
*   best table.
*************************************************************/

int main() {
  srand(time(NULL)); 
  // Stores number of collisions from Linear, Quadratic, 
  // and Chaining for 5 different tables.
  int results[5][4];
  uniqueWords shakespeare;
  shakespeare.readFile("will.txt");


  HashTable test1(50000, shakespeare);
  results[0][0] = test1.size();
  results[0][1] = test1.linCollisions();
  results[0][2] = test1.quadCollisions();
  results[0][3] = test1.chainCollisions();

  HashTable test2(80000, shakespeare);
  results[1][0] = test2.size();
  results[1][1] = test2.linCollisions();
  results[1][2] = test2.quadCollisions();
  results[1][3] = test2.chainCollisions();
  
  HashTable test3(60000, shakespeare);
  results[2][0] = test3.size();
  results[2][1] = test3.linCollisions();
  results[2][2] = test3.quadCollisions();
  results[2][3] = test3.chainCollisions();
  
  HashTable test4(67850, shakespeare);
  results[3][0] = test4.size();
  results[3][1] = test4.linCollisions();
  results[3][2] = test4.quadCollisions();
  results[3][3] = test4.chainCollisions();
  
  HashTable test5(78240, shakespeare);
  results[4][0] = test5.size();
  results[4][1] = test5.linCollisions();
  results[4][2] = test5.quadCollisions();
  results[4][3] = test5.chainCollisions();
  
  // Print results
  std::cout << "Table Size\t\tLinear\t\tQuadratic\t\tChaining\n" 
            << "----------\t\t------\t\t---------\t\t-------\n";
  for(int i = 0; i < 5; i++){
    std::cout << results[i][0] << "\t\t" << results[i][1] << "\t\t" << results[i][2] << "\t\t" << results[i][3] << std::endl;
  }
  std::cout << std::endl;

  int minSize = 0;
  int index = 1;
  for(int i = 0; i < 5; i++){
    int minColl = results[0][1];
    for(int j = 1; j < 4; j++){
      if(results[i][j] < minColl){
        minColl = results[i][j];
        minSize = i;
        index = j;
      }
    }
  }

  std::cout << "Best Combination is: " << std::endl;
  std::cout << "\tTable size: " << results[minSize][0] << std::endl;
  std::cout << "\tCollision handling: ";
  switch(index){
    case 1:
      std::cout << "Linear Probing" << std::endl;
      break;
    case 2:
      std::cout << "Quadratic Probing" << std::endl;
      break;
    case 3:
      std::cout << "Chaining" << std::endl;
  }
  
  std::cout << "Hasing function used: " << std::endl;

}
