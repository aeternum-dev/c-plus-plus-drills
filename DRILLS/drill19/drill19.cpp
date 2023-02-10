/*
    Use line below to compile:
    g++ drill19.cpp -o d19.out
*/

#include "../../GUI/std_lib_facilities.h"

template <typename T>
    struct S {
    private:
        T val;  
    public:
        //2
        S(T s) { val = s;} 
        void Print() {cout << val << endl;}
        void vectorPrint() {
            for (int i = 0; i < val.size(); ++i)
                cout << val[i] << ' ';
            cout << endl;
        }
    //6
    T& get();
    //9
    void set(const T& new_T);
    //10
    T& operator=(const T&);
    //11
    const T& get() const;
    //12.
    void read_val(T& v); 
    };


// 6
template<typename T> T& S<T>::get() {return val;};

// 9
template<typename T> void S<T>::set(const T& new_T) {val=new_T;};

//10
template<typename T> T& S<T>::operator=(const T& s) {val =s; return val;}

//11
template<typename T> const T& S<T>::get() const {return val;};

//12
template<typename T> void read_val(T& v) {cin>>v;}

//14
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v)
{
    os << "{ ";
    for (int i = 0; i<v.size(); ++i) {
        os << v[i];
        if (i<v.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v)
{
    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget(); 
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}

int main() {
    // 3
    S<int> myint(1961);
    S<char> mychar('a');
    S<double> mydouble(398601.2);
    S<string> mystring("Moon Landings");
    S<vector<int>> myvector(vector<int> {1969, 2025});

    // 4
    cout << "\nValues presented without the get()function\n";
    myint.Print();
    mychar.Print();
    mydouble.Print();
    mystring.Print();
    myvector.vectorPrint();


    // 8
    cout << "\nValues presented with the get()function\n";
    cout << myint.get() <<endl;
    cout << mychar.get() <<endl;
    cout << mydouble.get() <<endl;
    cout << mystring.get() <<endl;
    for (int i = 0; i < myvector.get().size(); ++i)
        cout << myvector.get()[i] << ' ';
    cout << endl;

    cout << "\nMiscellaneous\n";
    mychar.set('b');
    mychar.Print();

    //13
    int a; char b; double c; string d;
    cout << "\nTaking input(int,char,double,string)\n";
    read_val(a);
    S<int> sa(a);
    read_val(b);
    S<char> sb(b);
    read_val(c);
    S<double> sc(c);
    read_val(d);
    S<string> sd(d);
    
    cout << "\nPrinting new input\n";
    cout << sa.get() <<endl;
    cout << sb.get() <<endl;
    cout << sc.get() <<endl;
    cout << sd.get() <<endl;

    //14
    cout << "\nReading vector elements from cin...\n";
    cout << "Syntax: {val1, val2, val3, [valn]}\n";
    vector<int> e;
    read_val(e);
    S<vector<int>> se {e};
    cout << "S<vector<int>> cin read: " << se.get() << '\n';



    return 0;
}