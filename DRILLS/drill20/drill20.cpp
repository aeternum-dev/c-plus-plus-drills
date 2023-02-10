#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <exception>

using namespace std;


template<typename C>
void print(const C& c){
	for(auto& data : c){
		cout << data << ' ';
	}
	cout << endl;
}

template<typename C>
void inc(C& c, double n){
	for(auto& i : c){
		i += n;
	}
}

template<typename Iter1, typename Iter2>

 // 6 - requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 custom_copy(Iter1 f1, Iter1 e1, Iter2 f2) {
	for(Iter1 p = f1; p != e1; ++p ) 
	{
		*f2++=*p;
	}
	return f2;
}

	
int main() {
	try {
		constexpr int array_size = 10;
		//1 -  initial array
		int myarray[array_size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		
		//2 - define vector
		vector<int> myvector;
		for (int i = 0; i < array_size; i++)
		{
			myvector.push_back(myarray[i]) ;
		}

		//3 - define list
		list<int> mylist;
		for (int i = 0; i < array_size; i++) 
		{
			mylist.push_back(myarray[i]);
		}


		//4 - declaring copies of the original array, vector, list
		array<int, array_size> second_array;
		copy(begin(myarray), end(myarray), begin(second_array));
		vector<int> second_vector = myvector;
		list<int> second_list = mylist;

    	/*int *p1 = myarray;
 	    int *p2 = second_array;

 		for(int i=0 ; i<array_size ; i++)
        	*(p2+i) = *(p1+i);*/

		//testing if datastructures were filled up the rigth way

		cout << "myarray elements" << endl;
		print(myarray);

		cout << "myvector elements: " << endl;
		print(myvector);

		cout << "mylist elements: " << endl;
		print(mylist);

		cout << "second_array elements" << endl;
		print(second_array);	

		cout << "second_vector elements: " << endl;
		print(second_vector);

		cout << "second_list elements: " << endl;
		print(second_list);
		
		//5. Increase the value of each element in the array by 2; increase the value of 
		//each element in the vector by 3; increase the value of each element in the 
		//list by 5.
		for ( int i = 0; i< array_size; i++)
			myarray[i] = myarray[i] + 2;

		for ( int i = 0; i < myvector.size(); i++)
			myvector[i] = myvector[i] + 3;

		inc(mylist, 5); //changes elements of our list
		

		cout << "Data Structures with increased values" << endl;
		print(myarray);
		print(myvector);
		print(mylist);

		//7
		//copy the array into the vector and to copy the list into the array
		custom_copy(begin(myarray), end(myarray), begin(myvector));
		custom_copy(begin(mylist), end(mylist), begin(myarray));

		cout << "Data Structures after shuffling" << endl;
		print(myarray);
		print(myvector);
		print(mylist);
	
	// 8
	// if the vector contains the value 3 and print out its position if it does
	auto res_v = find(myvector.begin(), myvector.end(), 3);
	if (res_v != myvector.end())
		cout << "myvector contains 3 at position: " << distance(myvector.begin(), res_v) << endl;
		//distance: megadja az első és második paraméter közötti ugrások számát
	else
		cout << "myvector does not contain 3" << endl;
		
	//checks if the list contains the value 27 and print out its position if it does
	auto res_l = find(mylist.begin(), mylist.end(), 27);
	if (res_l != mylist.end())
		cout << "mylist contains 27 at position: " << distance(mylist.begin(), res_l) << endl;
	else
		cout << "mylist does not contain 27" << endl;


	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
	catch(...) {
		cerr << "Error" << endl;
	}
}