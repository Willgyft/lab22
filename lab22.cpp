#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		friend ComplexNumber operator+(const ComplexNumber &c, const ComplexNumber &d){
            return ComplexNumber(c.real + d.real, c.imag + d.imag);
    }
        friend ComplexNumber operator-(const ComplexNumber &c, const ComplexNumber &d) {
            return ComplexNumber(c.real - d.real, c.imag - d.imag);
    }
        friend ComplexNumber operator*(const ComplexNumber &c, const ComplexNumber &d) {
            return ComplexNumber(c.real*d.real - c.imag*d.imag, c.real*d.imag + c.imag*d.real);
    }
        friend ComplexNumber operator/(const ComplexNumber &c, const ComplexNumber &d) {
            double a = d.real*d.real + d.imag*d.imag;
            return ComplexNumber((c.real*d.real + c.imag*d.imag)/a, (c.imag*d.real - c.real*d.imag)/a);
    }
        friend bool operator==(const ComplexNumber &c, const ComplexNumber &d) {
            return (c.real == d.real && c.imag == d.imag);
    }
        double abs();
        double angle();
    friend ostream& operator<<(ostream &os, const ComplexNumber &c);
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}
double ComplexNumber::abs(){
	return sqrt((real*real)+(imag*imag));
}
double ComplexNumber::angle(){
	return atan2(imag, real)*180 / M_PI;
}
ostream& operator<<(ostream &os, const ComplexNumber &c) {
    if (c.real == 0 && c.imag == 0) return os << "0";
    if (c.real == 0) return os << c.imag << "i";
    if (c.imag == 0) return os << c.real;
    return os << c.real << (c.imag > 0 ? "+" : "") << c.imag << "i";
}

int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





