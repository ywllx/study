class Person {
public:
    Person(const string &nm, const string &add):
        name(nm), address(add)
    { 
    }
    
    string getName const ()
    {
        return name;
    }
    
    string getAddress const()
    {
        return address;
    }
    
    
private:
    string name;
    string address;


};
