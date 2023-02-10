#include<iostream>
#include <map>
#include<string>
#include<vector>

using namespace std;

//map      -      self-balancing binary search tree (typically red-black tree)
//unordered_map - hash table
template<typename T, typename V>
	void print(const map<T,V> m) 
		{for (const auto& p: m) cout << p.first << ' '<< p.second << endl;}

// 5. Write a function that reads value pairs from cin and places them in msi.
void read_map(map<string, int>& m, int p){
	string s;
	int i = 0;
	while(m.size() < p){
		cin >> s >> i;
		m[s] = i;
	}
}


int main() {
	// 1. Define a map<string,int> called msi
	map<string, int> msi; //key, value
	// 2. Insert ten (name,value) pairs into it, e.g., msi["lecture"]=21.
	msi["zh"] = 21;
	msi["y"] = 42;
	msi["z"] = 356;
	msi["g"] = 31;
	msi["a"] = 56;
	msi["m"] = 88;
	msi["e"] = 50;
	msi["r"] = 3;
	msi["programmer"] = 420;
	msi["u"] = 37;

	// 3. Output the (name,value) pairs to cout in some format of your choice.
	print(msi);

	// 4. Erase the (name,value) pairs from msi.
	msi.erase("u");	//deleting 1 element
	cout << "After erasing 1 element: " << endl;
	print(msi);
	
	msi.erase(msi.begin(), msi.end());	//deleting all the content from the map
	cout << "After erasing everything: " << endl;
	print(msi);
	
	// 6. Read ten pairs from input and enter them into msi.
	cout << "How many element pairs would you like?" << endl;
	int e;
	cin >> e;
	read_map(msi, e);

	// 7. Write the elements of msi to cout.
	cout << "msi after being filled from cin:" << endl;
	print(msi);

	// 8. Output the sum of the (integer) values in msi.
	int sum = 0;
	for (const auto& p: msi) sum = sum + p.second;	
	cout << "The sum of the integer values in msi: " << sum << endl;

	// 9. Define a map<int,string> called mis.
	map<int, string> mis;
	// 10. Enter the values from msi into mis; that is, if msi has an element
	//(" lecture",21), mis should have an element (21,"lecture").
	for(const auto& a : msi){
		mis[a.second] = a.first;
	}
	
	// 11. Output the elements of mis to cout.
	cout << "mis map: " << endl;
	print(mis);

}