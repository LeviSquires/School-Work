#include "matrix.h"
#include <ostream>
#include <iomanip>
#include <cmath>

bool FuzzyEquals(double d1, double d2, int magnitude)
{
	double epsilon = pow(10, magnitude);
	double diff = abs(d1 - d2);
	return diff < epsilon;
}



std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
	if(m.GetRowCount() == 0)
	{
		os << "<empty>";
		return os;
	}
	for(unsigned row = 0; row < m.GetRowCount(); ++row)
	{
		os << "| ";
		for(unsigned col = 0; col < m._data[row].size(); ++col)
		{
			os << std::left << std::setw(12) << std::fixed << std::setprecision(6) << m._data[row][col];
		}
		os << "|" << std::endl;
	}
	return os;
}


Matrix::Matrix(void)
{
}

Matrix::Matrix(unsigned rows, unsigned cols, double value)
{
	if(rows == 0 || cols == 0)
	{
		return;
	}

	std::vector<double> vec(cols, value);
	for(unsigned i = 0; i < rows; ++i)
	{
		_data.push_back(vec);
	}
}


void Matrix::AddRow()
{
	if(GetRowCount() == 0)
	{
		return;
	}
	_data.push_back(std::vector<double>(GetColumnCount(), 0));
}


void Matrix::AddColumn()
{
	if(GetColumnCount() == 0)
	{
		return;
	}

	for(unsigned row = 0; row < GetRowCount(); ++row)
	{
		_data[row].push_back(0);
	}

}

void Matrix::AddColumn(const std::vector<double>& vec)
{
	if(GetColumnCount() == 0)
	{
		if(vec.size() == 0)
		{
			return;
		}
		_data = std::vector<std::vector<double>>(vec.size(), std::vector<double>());
	}
	if(GetRowCount() != vec.size())
	{
		throw std::domain_error("Row count mismatch in AddColumn().");
	}
	for(unsigned row = 0; row < GetRowCount(); ++row)
	{
		_data[row].push_back(vec[row]);
	}	

}



void Matrix::AddRow(const std::vector<double>& vec)
{
	if(GetRowCount() == 0)
	{
		if(vec.size() == 0)
		{
			return;
		}
		_data.push_back(vec);
		return;
	}
	if(GetColumnCount() != vec.size())
	{
		throw std::domain_error("Column count mismatch in AddRow().");
	}
	_data.push_back(vec);
}


void Matrix::RemoveColumn(unsigned index)
{
	if(index >= GetColumnCount())
	{
		throw std::domain_error("Index out of range in RemoveColumn().");
	}
	for(unsigned row = 0; row < GetRowCount(); ++row)
	{
		_data[row].erase(_data[row].begin() + index);
	}
}

void Matrix::RemoveRow(unsigned index)
{
	if(index >= GetRowCount())
	{
		throw std::domain_error("Index out of range in RemoveRow().");
	}
	_data.erase(_data.begin() + index);
}


std::vector<double> Matrix::GetRowVector(unsigned index)const
{
	if(index >= GetRowCount())
	{
		throw std::domain_error("Index out of range in GetRowVector().");
	}
	return _data[index];
}



std::vector<double> Matrix::GetColumnVector(unsigned index)const
{
	if(index >= GetColumnCount())
	{
		throw std::domain_error("Index out of range in GetColumnVector().");
	}
	std::vector<double> ret;
	for(unsigned row = 0; row < GetRowCount(); ++row)
	{
		ret.push_back(_data[row][index]);
	}
	return  ret;
}

double Matrix::DotProduct(const std::vector<double>& v1, const std::vector<double>& v2)
{
	if(v1.size() != v2.size())
	{
		throw std::domain_error("Vector size mismatch in DotProduct().");
	}
	double ret = 0;
	for(unsigned  i = 0; i < v1.size(); ++i)
	{
		ret += (v1[i] * v2[i]);
	}
	return ret;

}

Matrix Matrix::operator*(const Matrix& m)const
{
	if(GetColumnCount() != m.GetRowCount())
	{
		throw std::domain_error("Dimension Mismatch in Matrix Multiplication.");
	}
	Matrix ret(GetRowCount(), m.GetColumnCount(), 0);

	for(unsigned row = 0; row < ret.GetRowCount(); ++row)
	{
		for(unsigned col = 0; col < ret.GetColumnCount(); ++col)
		{
			double value = DotProduct(GetRowVector(row), m.GetColumnVector(col));
			if(FuzzyEquals(value, 0))
			{
				value = 0;
			}
			ret.SetValue(row, col, value); 
		}
	}
	return ret;
}

