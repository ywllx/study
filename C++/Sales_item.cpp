class Sales_item {
public:
    Sales_item::avg_price() const 
    {
        if (units_sold)
            return revenue/units_sold;
        else:
            return 0;
    }

private:
    string isbn;
    unsigned units_sold;
    double revenue;
}

