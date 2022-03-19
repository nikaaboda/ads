#include <iostream>

using namespace std;

class Complex {
	private:
		double re, im;
	public:
		Complex(double re, double im) {
			this->re = re;
			this->im = im;
		}
		Complex& operator=(const Complex o) {
			this->re = o.re;
			this->im = o.im;
			return *this;
		}
        int operator==(const Complex o) {
        if(	this->re == o.re &&
			this->im == o.im)
            return 1;
        else
			return 0;
		}
		Complex operator+(const Complex o) {
			return Complex(this->re + o.re, this->im + o.im);
		}
		friend ostream& operator<<(ostream &o, Complex c) {
			o << c.re << "+" << c.im << "i" << endl;
			return o;
		}
};

template <class T>
int array_search(T arr[], int size, T elem)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == elem)
            return i;
    }
    return -1;
}

int main()
{
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c(1, 5);
    Complex d(8, 9);
    Complex toseek(1, 5);

    int arr1[5] = { 4, 3, 5, 6, 8 };
    double arr2[5] = { 4.12, 3.12, 5.12, 6.12, 8.12 };
    Complex arr3[4] =  { a, b, c, d };

    int res1 = array_search(arr1, 5, 6);
    int res2 = array_search(arr2, 5, 6.12);
    int res3 = array_search(arr3, 4, toseek);
    
    cout << res1 << endl << res2 << endl << res3 << endl;
    return 0;
}