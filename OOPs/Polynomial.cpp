
class Polynomial {
    public:
        int *degCoeff;
        int capacity;
    
        Polynomial()
        {
            capacity = 1;
            degCoeff = new int [capacity];
            
            for(int i=0; i<capacity; i++)
                degCoeff[i] = 0;
        }
    
        // Default Constructor
        Polynomial(int capacity)
        {
            this->capacity = capacity;
            this->degCoeff = new int [capacity];
            
            for(int i=0; i<capacity; i++)
                degCoeff[i] = 0;
        }
    
        // Copy Constructor - As the default copy constructore makes shallow copy
        Polynomial(Polynomial const &P1)
        {
            degCoeff = new int [P1.capacity];
            for(int i=0; i<P1.capacity; i++)
                degCoeff[i] = P1.degCoeff[i];
            
            capacity = P1.capacity;                
        }
    
        void setCoefficient(int index, int value)
        {
            while (index >= capacity)
            {
                int *newArr = new int [2 * capacity];
                for(int i = 0; i < 2*capacity; i++)
                {
                    if( i < capacity )
                        newArr[i] = degCoeff[i];
                    else
                        newArr[i] = 0;
                }
                
                delete [] degCoeff;
                degCoeff = newArr;
                capacity *= 2;
            }
            
            degCoeff[index] = value;
        }
        
        // Overloading PLUS Operator
        Polynomial operator+(Polynomial const &P2)
        {
            int degree = max(capacity, P2.capacity);
            Polynomial pNew(degree);
            
            for(int i=0; i<degree; i++)
            {
                if( i < capacity && i < P2.capacity )
                    pNew.degCoeff[i] = this->degCoeff[i] + P2.degCoeff[i];
                else if( i < capacity )
                    pNew.degCoeff[i] = this->degCoeff[i];
                else
                    pNew.degCoeff[i] = P2.degCoeff[i];
            }
            
            return pNew;
        }
    
        // Overloading MINUS Operator
        Polynomial operator-(Polynomial const &P2)
        {
            int degree = max(capacity, P2.capacity);
            Polynomial pNew(degree);
            
            for(int i=0; i<degree; i++)
            {
                if( i < capacity && i < P2.capacity )
                    pNew.degCoeff[i] = this->degCoeff[i] - P2.degCoeff[i];
                else if( i < capacity )
                    pNew.degCoeff[i] = this->degCoeff[i];
                else
                    pNew.degCoeff[i] = P2.degCoeff[i] * (-1);
            }
            
            return pNew;
        }
    
        // Overloading MULTIPLY Operator
        Polynomial operator*(Polynomial const &P2)
        {
            int degree = capacity * P2.capacity;
            Polynomial pNew(degree);
            
            for(int i=0; i<capacity; i++)
            {
                for(int j=0; j<P2.capacity; j++)
                {
                    int value = i * j;
                    pNew.degCoeff[value] += degCoeff[i] * P2.degCoeff[j];
                }
            }
            
            return pNew;
        }
    
        // Overloading ASSIGNMENT Operator
        void operator=(Polynomial const &P2)
        {
            capacity = P2.capacity;
            
            for(int i=0; i<capacity; i++)
                degCoeff[i] = P2.degCoeff[i];
        }
        
        void print()
        {
            for(int i=0; i<capacity; i++)
            {
                if( degCoeff[i] != 0 )
                    cout<< degCoeff[i]<< "x"<< i<< " ";
            }
        }
};
