#include <iostream>
#include <string>
#include <fstream> // maybe, maybe
#include <vector>
#include <algorithm>

template<typename T>
	T mySum(std::vector<T> v) {
		T tmp = 0.0;
		for(double i: v)
			tmp += i;
		return tmp;
	}
//using namespace std;

int main()
{
	//1. read from file to vd
	std::vector<double> vd; double tmp; std::vector<int> vi;
	std::ifstream infile("input.csv");

	while (infile >> tmp) 
		vd.push_back(tmp);

	//2. print that vector
	std::cout << "Elements of vd: " << std::endl;
	for (int i=0; i<vd.size(); i++)
		std::cout << vd[i] << ' ';
	std::cout << std::endl;

	//3. make int vector (vi) that copies vd's elements into itself 
	//remove the part right of the decimal
	for (int i = 0; i < vd.size(); ++i)
		vi.push_back((int)vd[i]); //pushes back a truncated vd[i] to vi

	//4. output vi and vd elements in pair 
	std::cout << "\nValue pairs:" << std::endl;
	for (int i = 0; i < vd.size(); ++i)	
		std::cout <<"Double value: "<< vd[i] <<" Integer value: "<< vi[i] << std::endl;

	//5. sum of elements in vd
	std::cout << "\nSum of vd's elements: " << mySum(vd) << std::endl;
	
	//6. output diffrence between two sums of the two vectors(vi,vd)
	std::cout << "\nDiffrence between two sums of the two vectors(vi,vd): ";	
	std::cout << mySum(vd)-mySum(vi) << std::endl;

	//7.std::reverse function (vd) than output vd
	reverse(vd.begin(), vd.end());

	std::cout << "\nElements of vd after reverse():" << std::endl;
	for (int i=0; i<vd.size(); i++)
		std::cout << vd[i] << ' ';
	std::cout << std::endl;

	//8. mean of vd, than output it 
	double mean = mySum(vd)/vd.size();
	std::cout << "\nThe mean of vd is " << mean << std::endl;

	// 9.create vd2 copy vd elements if(i<mean(vd))
	std::vector<double> vd2;
	for (int i=0; i<vd.size(); i++)
		if (vd[i] < mean)
			vd2.push_back(vd[i]);
	
	std::cout << "\nElements of vd2:" << std::endl;
	for (int i=0; i<vd2.size(); i++)
		std::cout << vd2[i] << ' ';
	std::cout << std::endl;

	// 10 sort vd than  output
	sort(vd.begin(), vd.end());

	std::cout << "\nElements of vd after sorting:" << std::endl;
	for (int i=0; i<vd.size(); i++)
		std::cout << vd[i] << ' ';
	std::cout << std::endl;

}
