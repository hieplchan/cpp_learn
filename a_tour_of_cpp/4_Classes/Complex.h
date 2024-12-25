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

    Complex& operator*=(Complex z); // define else-where
    Complex& operator/=(Complex z);
};