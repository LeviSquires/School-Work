#pragma once

#include <vector>
#include <ostream>
#include <stdexcept>


class Matrix
{
public:
	Matrix(void);
	Matrix(unsigned rows, unsigned cols, double value);

	unsigned GetRowCount() const
	{
		return _data.size();
	}
	unsigned GetColumnCount() const
	{
		if(GetRowCount() == 0)
		{
			return 0;
		}
		//Assuming the class invariant hold
		return _data[0].size();
	}

	void SetValue(unsigned row, unsigned col, double value)
	{
		if(row >= GetRowCount() || col >= GetColumnCount())
		{
			throw std::domain_error("Out of range index on SetValue()");
		}

		_data[row][col] = value;
	}

	double GetValue(unsigned row, unsigned col) const
	{
		if(row >= GetRowCount() || col >= GetColumnCount())
		{
			throw std::domain_error("Out of range index on GetValue()");
		}
		return _data[row][col];
	}

	void AddRow();
	void AddRow(const std::vector<double>& vec);

	void AddColumn();
	void AddColumn(const std::vector<double>& vec);

	void RemoveColumn(unsigned index);
	void RemoveRow(unsigned index);


	std::vector<double> GetRowVector(unsigned index)const;
	std::vector<double> GetColumnVector(unsigned index)const;


	static double DotProduct(const std::vector<double>& v1, const std::vector<double>& v2);

	Matrix operator*(const Matrix& m)const;

private:
	
	std::vector<std::vector<double>> _data;
	friend std::ostream& operator<<(std::ostream&, const Matrix& m);

};

bool FuzzyEquals(double d1, double d2, int magnitude = -6);

std::ostream& operator<<(std::ostream&, const Matrix& m);
