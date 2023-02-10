#include <stdio.h>

void unique_print(const char* p, const int x)
{
	printf("p is \"%s\" and x is %i\n",p,x);
}

int main(void) 
{

	//1
	printf("Hello World!\n");

	//2
	char* hello = "Hello";
	char* world = "World!";
	printf("%s %s\n",hello,world);

	//3
	unique_print("Jancsi",11);
	unique_print("Juliska",10);
	unique_print("Banya", 91);

}