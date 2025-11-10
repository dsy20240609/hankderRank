#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

class Box {
    public:  
    Box() {
        l=0;
        b=0;
        h=0;
    }
    Box(int l,int b,int h) {
        this->l=l;
        this->b=b;
        this->h=h;
    }
    Box(Box& box) {
        l=box.l;
        b=box.b;
        h=box.h;
    } // copy constuctor
    
    bool operator<(const Box&  other) {
        if(l<other.l) {
            return true;
        } else if (b< other.b && l==other.l) {
            return true;
        } else if (h< other.h && l== other.l && b == other.b) {
            return true;
        } else {
            return false;
        }
    }  
    friend ostream& operator<<(ostream &out, const Box& box) {
        out <<box.l << " " << box.b << " " << box.h;
        return out;
    } 
    
    int getLength() {return l;}
    int getBreadth() {return b;}
    int getHeight()  {return h;}
    long long CalculateVolume() {
        long temp1=l*b;
        long long res= temp1*h;
        return res;
    }
    
    private:
    
    int l;
    int b;
    int h;
};
// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}

//several places that it is easy to get wrong:
//ofstream ostream friend class as the operator overload <<
// for the constructor it is better to use initialization list


#include <iostream>
using namespace std;

class Box {
private:
    int length;
    int breadth;
    int height;

public:
    // 1️⃣ Default constructor
    Box() : length(0), breadth(0), height(0) {}

    // 2️⃣ Parameterized constructor
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {}

    // 3️⃣ Copy constructor
    Box(const Box& B) {
        length = B.length;
        breadth = B.breadth;
        height = B.height;
    }

    // 4️⃣ Getters
    int getLength() const { return length; }
    int getBreadth() const { return breadth; }
    int getHeight() const { return height; }

    // 5️⃣ Calculate volume (long long to avoid overflow)
    long long CalculateVolume() const {
        return 1LL * length * breadth * height;
    }

    // 6️⃣ Overload operator<
    bool operator<(const Box& B) const {
        if (length < B.length) return true;
        if (length == B.length && breadth < B.breadth) return true;
        if (length == B.length && breadth == B.breadth && height < B.height) return true;
        return false;
    }

    // 7️⃣ Overload operator<< (friend function)
    friend ostream& operator<<(ostream& out, const Box& B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

// ✅ Example usage
int main() {
    Box b1;                // default constructor
    Box b2(2, 3, 4);       // parameterized constructor
    Box b3(b2);            // copy constructor

    cout << "b2 length: " << b2.getLength() << endl;
    cout << "b2 breadth: " << b2.getBreadth() << endl;
    cout << "b2 height: " << b2.getHeight() << endl;
    cout << "b2 volume: " << b2.CalculateVolume() << endl;

    bool x = (b1 < b2);
    cout << "Is b1 < b2? " << (x ? "true" : "false") << endl;

    cout << "b2: " << b2 << endl;

    return 0;
}