#include <iostream>
#include <string>

class Sales_data
{
	friend Sales_data add(const Sales_data &, const Sales_data &);
	friend std::ostream & print(std::ostream &, const Sales_data &);
	friend std::istream & read(std::istream &, Sales_data &);

	public:

	Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s) {}
	Sales_data(const std::string &s, unsigned n, double p) :
		bookNo(s), units_sold(n), revenue(p * n) {}
	Sales_data(std::istream &);


	std::string isbn() const {return bookNo;};
	Sales_data & combine(const Sales_data &);

	private:
	double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream & print(std::ostream &, const Sales_data &);
std::istream & read(std:: istream &, Sales_data &);

Sales_data::Sales_data(std::istream &is)
{
	read(is, *this);
}

double Sales_data::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	return 0;
}
Sales_data & Sales_data::combine(const Sales_data &rhs) 
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;

	return  *this;
}

std::ostream & print(std::ostream & os, const Sales_data &item)
{
	os << item.isbn() << " " << item.units_sold << " "
		<< item.revenue << " " << item.avg_price();
}

std::istream & read(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price * item.units_sold;
	return is;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs)
{
	Sales_data  sum = lhs;
	sum.combine(rhs);

	return sum;
}


int main()
{

	return 0;
} 
