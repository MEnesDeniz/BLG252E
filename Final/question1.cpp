//Muhammed Enes Deniz
//070170450

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Warlord
{
private:
	int power;
	int magic;

public:
	Warlord(int, int);
	void Print() const;
	bool operator>(const Warlord &) const;
};

Warlord::Warlord(int power = 0, int magic = 0)
{
	if (power < 0) //cannot be negative
	{
		throw "A warlord cannot have negative power!\n";
	}
	
	if (magic <= 0) //cannot be nonpositive
	{
		throw "A warlord cannot be a non-magic wielder!\n";
	}

	this->magic = magic;
	this->power = power;
}

void Warlord::Print() const //Print out the
{
	cout << "Power: " << power << " "
		 << "Magic: " << magic << endl;
}

//Overload the operator> in order to make a comparison between the two Warlord object
bool Warlord::operator>(const Warlord &inobj) const
{
	int firstsum = power + magic;
	int secondsum = inobj.magic + inobj.power;
	return firstsum > secondsum;
}

//Comparison function has decleared as a template function so it will use any type.
//Simply it will use operator+ for this case in order to ensure sorting
template <class T>
bool Comparison(const T &l1, const T &l2)
{
	if (l1 > l2)
	{
		return true;
	}
	return false;
}
/* Write a comparison function which will return true if first parameter is bigger than the second */

/* Define an STL container (vector, list, etc.) here. Use typedef to name it as "Container" */
typedef vector<Warlord> Container;
typedef Container::iterator Iterator;

/* You should not change or remove the given code parts. Add necessary codes to get the same result with sample output */
int main()
{
	try
	{
		Warlord w1(1, 1);
		Warlord w2(2, 2);
		Warlord w3(2, 1);

		/* Initialize the "Container" and put the w1,w2, and w3 into container */
		Container lords;
		lords.push_back(w1);
		lords.push_back(w2);
		lords.push_back(w3);

		cout << "Unsorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++)
			(*i).Print();

		/* Sort Warlords in the container */
		sort(lords.begin(), lords.end(), Comparison<Warlord>);
		cout << endl
			 << "Sorted Warlords" << endl;
		for (Iterator i = lords.begin(); i != lords.end(); i++)
			(*i).Print();

		Warlord w4; /* by default warlords have zero power and zero magic*/
		w4.Print();
	}
	catch (const char *exceptionthrowned)
	{
		cout << exceptionthrowned << endl;
	}

	return 0;
}
