//Author: Tyler Bieker
//CS260 Project 3
//Date: 05/13/2016
//Sources:

#include "hashtable.h"

hashTable::hashTable(){
  capacity = DEFAULT_CAPACITY;
  initializeTable();
  return;
}

hashTable::hashTable(const hashTable& aTable){
  /*
  capacity = DEFAULT_CAPACITY;
  table = new node*[capacity];

  for(int i = 0; i < capacity; i++){
    if(aTable.table[i] == nullptr){
      table[i] = nullptr;
    }else{
      node * src;
      node * dest;

      table[i] = new node;
      table[i]->data = aTable.table[i]->data;

      dest = table[i];
      src = aTable.table[i]->next;
      while(src){
        dest->next = new node;
        dest->data = src->data;
        src = src->next;
      }
      dest->next = nullptr;
    }
  }
  */
	*this = aTable;
	return;
}

const hashTable& hashTable::operator=(const hashTable& aTable){
	if(this == &aTable){
		return *this;
	}else{
		destroyTable();

		capacity = DEFAULT_CAPACITY;
		table = new node*[capacity];

		for(int i = 0; i < capacity; i++){
			if(aTable.table[i] == nullptr){
				table[i] = nullptr;
			}else{
				node * src;
				node * dest;

				table[i] = new node;
				table[i]->data = aTable.table[i]->data;

				dest = table[i];
				src = aTable.table[i]->next;
				while(src){
					dest->next = new node;
					dest->data = src->data;
					src = src->next;
				}
				dest->next = nullptr;
			}
		}
	}
    return *this;
}

hashTable::~hashTable(){
  destroyTable();
  return;
}

void hashTable::add(node * newNode){
  int key;
  char product[100];
  newNode->data.getProduct(product);
  key = keyGen(product);

  //first node of table[key]
  if(table[key] == nullptr){
    newNode->next = nullptr;
    table[key] = newNode;
    return;
  }
  else{
    node * curr;
    node * prev;
    prev = nullptr;
    curr = table[key];
    /********************************************************
    * Sort nodes alphabetically
    ********************************************************/

	//get names to compare
	char newName[100];
	newNode->data.getName(newName);
	char currentName[100];
	curr->data.getName(currentName);

    //create new head
    if(newName < currentName){
      newNode->next = table[key];
      table[key] = newNode;
      return;
    }else{
      while(curr != nullptr && currentName < newName){
        //advance to next node
		prev = curr;
        curr = curr->next;
		//get name of next node
		curr->data.getName(currentName);
        }
        //reached end of list, new node to tail
        if(curr == nullptr){
            prev->next = newNode;
            newNode->next = nullptr;
            return;
        }else{
            prev->next = newNode;
            newNode->next = curr;
            return;
        }
    }
  }
}

bool hashTable::remove(char * product){
  node * curr;
  node * prev;
  char aProduct[100];

  int key;
  key = keyGen(product);
  curr = table[key];
  prev = table[key];
  curr->data.getProduct(aProduct);
  if(aProduct == product){  //head of list removed
    table[key] = curr->next;
    delete curr;
    curr = nullptr;
    return true;
  }
  curr = curr->next;
  while(curr){
    curr->data.getProduct(aProduct);
    if(aProduct == product){
      prev->next = curr->next;
      delete curr;
      curr = nullptr;
      return true;
    }else{
      curr = curr->next;
      prev = prev->next;
    }
  }
  return false;
}

bool hashTable::retrieve(char * product, vendor& aVendor){
  int key;
  key = keyGen(product);
  char aProduct[100];

  node * curr;
  curr = table[key];
  while(curr){
    curr->data.getProduct(aProduct);
    if(aProduct == product){
      aVendor = curr->data;
      return true;  //return true if products match
    }
    curr = curr->next;
  }
  return false; //reached end of list and no match found
}

void hashTable::display(){
  for(int i = 0; i < capacity; i++){
    node * curr = table[i];
    while(curr){
      curr->data.print();
      std::cout << std::endl;
      curr = curr->next;
    }
  }
  return;
}

void hashTable::monitor(){
    //function to monitor the individual chains in hash file
  for(int i = 0; i < capacity; i++){
    int size = 0;
    node * curr;
    curr = table[i];
    while(curr){
      size++;
      curr = curr->next;
    }
    if(size){
        std::cout << "Chain: " << i << std::endl << "Nodes: " << size << std::endl << std::endl;
    }
  }
  return;
}

void hashTable::writeOut(char * fileName){
  std::ofstream out;

  out.open(fileName);
  if(!out){
    std::cout << "Failed to write to " << fileName << std::endl;
    exit(1);
  }

  node * curr;
  for(int i = 0; i < capacity; i++){
    curr = table[i];
    while(curr){
      out << curr->data;
      curr = curr->next;
    }
  }
  out.close();
  return;
}

/*
Private functions
*/

void hashTable::initializeTable(){
  table = new node*[capacity];
  for(int i = 0; i < capacity; i++){
    table[i] = nullptr;
  }
  return;
}

void hashTable::destroyTable(){
  node * head;
  node * curr;

  for(int i = 0; i < capacity; i++){
    head = table[i];
    curr = head;
    while(curr){
      head = curr->next;
      delete curr;
      curr = nullptr;
      curr = head;
    }
  }
  delete [] table;
  return;
}

int hashTable::keyGen(char * product){
    int key;
    //convert product to integer
	key = (int(product[0]) - 65);
    return key;
}
