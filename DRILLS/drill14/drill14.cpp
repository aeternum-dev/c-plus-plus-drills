#include "../../GUI/std_lib_facilities.h"

/*1. Define a class B1 with a virtual function vf() and a non-virtual function f(). 
Define both of these functions within class B1. Implement each function 
to output its name (e.g., B1::vf()). Make the functions public. Make a B1
object and call each function.*/
class B1 {
	public:
		void f() {cout << "B1::f()" << endl;}
		virtual void vf() {cout << "B1::vf()" << endl;}
		/*5. Add a pure virtual function called pvf() to B1*/
		virtual void pvf() = 0;
};


/*2. Derive a class D1 from B1 and override vf(). Make a D1 object and call vf()
and f() for it.*/
class D1 : public B1 {
	public:
		//D1();
		void vf() override {cout << "D1::vf()"<<endl;}
		/*4. Now define a function called f() for D1 and repeat 1–3. Explain the results*/
		void f() {cout << "D1::F()" << endl;}
		void pvf() override {cout << "D1::pvf()" << endl; }
};

/* 6. Define a class D2 derived from D1 and override pvf() in D2. Make an 
object of class D2 and invoke f(), vf(), and pvf() for it.*/
class D2 : public D1 {
	public:
		void pvf() override {cout << "D2::pvf()" << endl; }
};

/* 7. Define a class B2 with a pure virtual function pvf(). Define a class D21
with a string data member and a member function that overrides pvf(); 
D21::pvf() should output the value of the string. Define a class D22 that 
is just like D21 except that its data member is an int. Define a function f()
that takes a B2& argument and calls pvf() for its argument. Call f() with a 
D21 and a D22.*/
class B2 {
	public:
		virtual void pvf() = 0;
	
};
class D21 : public B2 {
	public:
		string s;
		void pvf() override {cout  << s << endl;}
	
};
class D22 : public B2 {
	public:
		int i;
		void pvf() override {cout << i <<endl;}
		void f(B2& a) {a.pvf();}
	
};


int main() {

	/*B1 B1_object; //won't compile while an object of a class with pure virtual functions is present:/
	B1_object.f();
	B1_object.vf();
	cout << endl;*/

	D1 D1_object;
	D1_object.f();
	D1_object.vf();
	D1_object.pvf();
	cout << endl;

	/*3. Define a reference to B1 (a B1&) and initialize that to the D1 object you 
	just defined. Call vf() and f() for that reference.*/
	B1& myRef = D1_object;
	myRef.vf();
	myRef.f();
	cout << endl;

	//4
	D2 D2_object;
	D2_object.f();
	D2_object.vf();
	D2_object.pvf();

	//7
	D21 D21_object;
	D21_object.s = "D21 string";

	D22 D22_object;
	D22_object.i = 421;

	D22_object.f(D21_object);
	D22_object.f(D22_object);


	return 0;

}

