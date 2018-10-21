#include<iostream>
using namespace std;
struct node
{
  T data;
  node<T>  * next;         
};

template<class T>
class Change{
    node<T>*top ;
public:
	Change(){
	top=NULL;
	}
void push(T  e){   
      node<T>* s= new node<T> ;
	  whlie(e<0){
		int i=e%2;
      s->data=i;
      s->next=top;
      top=s;
	  e=e/2-1;
	  }
	}
};
int main(){
	Change<int> c;
	c.push(16);
	return 0;
}