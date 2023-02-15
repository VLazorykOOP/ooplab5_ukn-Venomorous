#include <iostream>
#include <string>

using namespace std;

class Row
{
private:
    string row;

public:
    Row(string row)
    {
        this->row = row;
    }
    Row(const Row &row)
    {
        this->row = row.row;
        cout << "Copy constructor" << endl;
    }
    string getRow()
    {
        return row;
    }
    void setRow(string row)
    {
        this->row = row;
    }
    void print()
    {
        cout << "Row: " << row << endl;
    }
    ~Row()
    {
        cout << "Rows destructor" << endl;
    }
};

class NumberRow : public Row
{
public:
    NumberRow(string row) : Row(row)
    {
    }
    NumberRow(const NumberRow &numberRow) : Row(numberRow)
    {
        cout << "NumberRow copy constructor" << endl;
    }
    void print()
    {
        cout << "NumberRow: " << getRow() << endl;
    }
};

int main()
{
    Row row("Hello");
    row.print();

    Row row2(row);
    row2.print();

    NumberRow numberRow("123");
    numberRow.print();

    NumberRow numberRow2(numberRow);
    numberRow2.print();

    return 0;
}
