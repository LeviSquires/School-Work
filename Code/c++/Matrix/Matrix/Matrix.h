#pragma once

#include <vector>
#include <ostream>
#include <stdexcept>

class Matrix
{
public:
	Matrix();
	Matrix(unsigned rows, unsigned columns, double value);
	unsigned GetRowCount() const
	{
		return _data.size();
	}
	unsigned GetColumnCount() const
	{
		if (GetRowCount() == 0)
		{
			return 0;
		}
		//assumning the class invarient passes
		return _data[0].size();
	}
	void SetValue(unsigned row, unsigned column, double value)
	{
		if (row >= GetRowCount() || column >= GetColumnCount())
		{
			throw std::domain_error("Out of range index on SetValue().");
		}
		_data[row][column] = value;
	}

	double GetValue(unsigned row, unsigned column) const
	{
		if (row >= GetRowCount() || column >= GetColumnCount())
		{
			throw std::domain_error("Out of range index on GetValue().");
		}
		return _data[row][column];
	}

	void AddRow();
	void AddRow(const std::vector<double>& vec);
	
	void AddColumn();
	void AddColumn(const std::vector<double>& vec);

	void RemoveRow(unsigned index);
	
	void RemoveColumn(unsigned index);

	std::vector<double> GetRowVector(unsigned index) const;
	std::vector<double> GetColumnVector(unsigned index) const;

	static double DotProduct(const std::vector<double>& v1, const std::vector<double>& v2);

	Matrix operator*(const Matrix& m) const;

private :
	std::vector<std::vector<double>> _data;

	friend std::ostream& operator<<(std::ostream&, const Matrix& m);
};

std::ostream& operator<<(std::ostream&, const Matrix& m);

bool FuzzyEquals(double d1, double d2, int magnitude = -6);
