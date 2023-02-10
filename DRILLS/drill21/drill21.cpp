#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

struct Item 
{ 
	string name; 
	int iid; 
	double value;
	//Item(string n, int iid2 = 0, double v = 0.0) : name{n}, iid{iid2}, value{v} {}
};

struct Cmp_by_name {
 	bool operator()(const Item& a, const Item& b) const
	{ return a.name < b.name; }
};

struct Cmp_by_iid {
 	bool operator()(const Item& a, const Item& b) const
	{ return a.iid < b.iid; }
};

struct Cmp_by_value_desc {
 	bool operator()(const Item& a, const Item& b) const
	{ return a.value > b.value; }
};

class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

void print_item_vector(vector<Item> v) {
	for ( Item i : v)
		cout << i.name << '\t' << i.iid << '\t' << i.value << endl;
	cout << endl;
}

void print_item_list(list<Item> l) {
	for ( Item i : l)
		cout << i.name << '\t' << i.iid << '\t' << i.value << endl;
	cout << endl;
}


int main()
{
	//1. Read some floating-point values (at least 16 values) from a file
	//into a vector<double> called vd.
	ifstream infile("input.txt");
	string n; string tmp; int i; double v; Item item; vector <Item> vi;
	while(infile.good()){
		infile >> n;
		infile >> tmp;
		i = stoi(tmp);
		infile >> tmp;
		v = stod(tmp);
		item = {n, i, v};
		vi.emplace_back(item);
	}

	print_item_vector(vi);

	//2. Sort vi by name.
	cout << "Sort vi by name" << endl;
	
	sort(vi.begin(), vi.end(), Cmp_by_name());
	print_item_vector(vi);

	//3. Sort vi by iid.
	cout << "Sort vi by iid" << endl;
	
	sort(vi.begin(), vi.end(), Cmp_by_iid());
	print_item_vector(vi);

	//4. Sort vi by value; print it in order of decreasing value
	//(i.e., largest value first).
	cout << "Sort vi by value, desc" << endl;
	
	sort(vi.begin(), vi.end(), Cmp_by_value_desc());
	print_item_vector(vi);

	//5. Insert Item("horse shoe",99,12.34) and Item("Canon S400", 9988,499.95).
	cout << "Insert Item(\"horse shoe\",99,12.34) and Item(\"Canon S400\", 9988,499.95)." << endl;

	vi.push_back({"horse shoe",99,12.34});
	vi.push_back({"Canon S400", 9988,499.95});
	print_item_vector(vi);

 	//6. Remove (erase) two Items identified by name from vi.
	double armin_place = 0;
	double levi_place = 0; 
	int a = 0;
	for(const auto& i : vi){
		if(i.name == "Armin") {armin_place = a;}
		if(i.name == "Levi") {levi_place = a;}
		++a;
	}

	vi.erase(vi.begin()+armin_place);
	vi.erase(vi.begin()+levi_place);
	cout << "Remove (erase) two Items identified by name from vi." << endl;
	print_item_vector(vi);
	
	//7. Remove (erase) two Items identified by iid from vi.
	cout << endl;
	double fifty_place = 0;
	double three_place = 0; 
	int b = 0;	
	for(const auto& i : vi){
		if(i.iid == 50) {fifty_place = b;}
		if(i.iid == 3) {three_place = b;}
		++b;
	}

	vi.erase(vi.begin()+fifty_place);
	vi.erase(vi.begin()+three_place);
	cout << "Remove (erase) two Items identified by iid from vi." << endl;
	print_item_vector(vi);

 	//8. Repeat the exercise with a list<Item> rather than a vector<Item>
	
	ifstream infile2("input.txt");
	list<Item> li;
	while(infile2.good()){
		infile2 >> n;
		infile2 >> tmp;
		i = stoi(tmp);
		infile2 >> tmp;
		v = stod(tmp);
		item = {n, i, v};
		li.emplace_back(item);
	}
	cout << "List after readin" << endl;
	print_item_list(li);

	cout << "Sort vi by name (list)" << endl;
	
	li.sort(Cmp_by_name());
	print_item_list(li);

	cout << "Sort vi by iid (list)" << endl;
	
	li.sort(Cmp_by_iid());
	print_item_list(li);

	cout << "Sort vi by value, desc (list)" << endl;
	
	li.sort(Cmp_by_value_desc());
	print_item_list(li);

	li.insert(li.end(),{"Horse shoe",99,12.34});
	li.insert(li.end(),{"Canon S400",9988,499.95});
	cout << "Insert Item elements to the list." << endl;
	print_item_list(li);

	list<Item>::iterator li_it =
		find_if(li.begin(),li.end(),Find_by_name("Marco"));
	li.erase(li_it);
	li_it = find_if(li.begin(),li.end(),Find_by_name("Reiner"));
	li.erase(li_it);
	cout << "Remove (erase) two Items identified by name from vi.(list)" << endl;
	print_item_list(li);

	li_it = find_if(li.begin(),li.end(),Find_by_iid(4));
	li.erase(li_it);
	li_it = find_if(li.begin(),li.end(),Find_by_iid(5));
	li.erase(li_it);
	cout << "Remove (erase) two Items identified by iid from vi.(list)" << endl;
	print_item_list(li);
}