//Kevin Le
//M547h365

#include<iostream>
#include<cstdlib>
#include<time.h>
#include"DynamicArray.h"
using namespace std;

//default constructor
DynArray::DynArray(){ 

   size = 10;

   data = new int[size];

}
// parametrized constructor
DynArray::DynArray(int size){

   this->size = size;

   this->data = new int[this->size];

}
//copy constructor
DynArray::DynArray(const DynArray &obj){ 

   size = obj.size;

   data = new int[size];

   for(int i = 0 ; i < size; i++){

       data[i] = obj.data[i];

   }
}
//operator
DynArray& DynArray::operator= (const DynArray &obj){

   if (this != &obj) {

data = new int[obj.size];

size = obj.size;

for (int i=0; i<size; i++) data[i] = obj.data[i];

}

return *this;

}

//insert function
void DynArray::insert(){ 
  
   for(int i = 0 ; i < this->size; i++){

       int d = rand()%100;

       this->data[i] = d;
   }
}
//print function
void DynArray::print(){ 

   for(int i = 0; i < this->size; i++){

       cout<<this->data[i]<<" ";
   }

   cout<<"\n";
}
//insertionsort function
void DynArray::sort(){ 

   int i,j,key;

   for(i = 1; i < size; i++){

       j = i-1;

       key = data[i];

       while(j >= 0 && data[j] > key){

           data[j+1] = data[j];

           j--;
       }

       data[j+1] = key;

   }
}
int main(){

   DynArray obj;

    //random number
   srand(time(0));

   obj.insert();

   cout<<"Default Constructor: \n";

   cout<<"Before Sorting: "<<" ";

   obj.print();

   cout<<"After Sorting: "<<" ";

   obj.sort();

   obj.print();

   DynArray obj1(20);

   obj1.insert();

   cout<<"Parametrized Constructor: \n";

   cout<<"Before Sorting: "<<" ";

   obj1.print();

   cout<<"After Sorting: "<<" ";

   obj1.sort();

   obj1.print();

   cout<<"Copy Constructor: \n";

   DynArray obj3 = obj;

   obj3.print();
}