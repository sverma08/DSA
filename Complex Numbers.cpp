class ComplexNumbers {
    // Complete this class
    private:
        int real;
        int imaginary;
    public:
        ComplexNumbers(int real, int imaginary)
        {
            this->real = real;
            this->imaginary = imaginary;
        }
        void plus(ComplexNumbers const & C)
        {
            real = real + C.real;
            imaginary = imaginary + C.imaginary;
        }
        // ComplexNumbers const & C: To save memory by not creating a copy of the original variable 
        // and keeping it constant to prevent it from being changed.
        void multiply(ComplexNumbers const & C)
        {
            int real = this->real;
            int imaginary = this->imaginary;
            
            this->real = real * (C.real) - imaginary * (C.imaginary);
            this->imaginary = real * (C.imaginary) + imaginary * (C.real);
        }
        void print()
        {
            if( imaginary > 0 )
                cout<< real<< " + i"<< imaginary<< endl;
            else
                cout<< real<< " - i"<< imaginary*(-1)<< endl;
        }
};
