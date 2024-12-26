// https://www.ibm.com/docs/en/i/7.5?topic=only-inline-member-functions-c

/*
Class definition itself contains only operation access to its representation
 */
class Complex {
    double re, im; // representation: two doubles
public:
    Complex(double re, double im) : re{re}, im{im} {}
    Complex(double re) : re{re}, im{0} {}
    Complex() : re{0}, im{0} {} // default constructor => prevent uninitialized variables

    // const => this function not modified the object being called
    double real() const { return re; }
    void real(double d) { re = d; }
    double imag() const { return im; }
    void imag(double d) { im = d; }

    // Function defined in class is inlined by default
    // inlined = without function calls in machine code => efficient
    Complex& operator+=(Complex z) {
        re += z.re;
        im += z.im;
        return *this;
    }

    Complex& operator-=(Complex z) {
        re -= z.re;
        im -= z.im;
        return *this;
    }

    // Complex& operator*=(Complex z); // define else-where
    // Complex& operator/=(Complex z);
};

// not inline by default, but not need direct access to representation so it's ok
Complex operator+(Complex a, Complex b) { return a+=b; }
Complex operator-(Complex a, Complex b) { return a-=b; }
Complex operator-(Complex a) { return {-a.real(), -a.imag()}; }
// Complex operator*(Complex a, Complex b) { return a*=b; }
// Complex operator/(Complex a, Complex b) { return a/=b; }

bool operator==(Complex a, Complex b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

bool operator!=(Complex a, Complex b) { return !(a ==b); }