Assignment 16

Pseudo Code

	Created the 3 functions: AddVectors(), SwitchRows() and MultiplyRows(). Also created a SetRowVector() function to better implement the SwitchRows function.
	
	void Matrix::SwitchRows(Matrix& m, unsigned row1, unsigned row2)
	{
		std::vector<double> temp = m.GetRowVector(row2);
		m.SetRowVector(m.GetRowVector(row1), row2);
		m.SetRowVector(temp, row1);
	}
	
	void Matrix::SetRowVector(std::vector<double> row, unsigned index)
	{
		if (index >= GetRowCount())
		{
			throw std::domain_error("Index out of range in GetRowVector()."); ///Throws an exception if the value being set is invalid.
		}
		_data[index] = row;
	}
	
	std::vector<double> Matrix::MultiplyRows(std::vector<double>& vec, int i)
	{
		std::vector<double> ret;
		for (unsigned a = 0; a < vec.size(); ++a)
		{
			ret.push_back(vec[a] * i); //push back the multiplied values for each row
		}
		return ret;
	}
	std::vector<double> Matrix::AddVectors(std::vector<double>& vec1, std::vector<double>& vec2)
	{
		std::vector<double> ret;
		for (unsigned i = 0; i < vec1.size(); ++i)
		{
			ret.push_back(vec1[i] + vec2[i]); //push back the added values for each row
		}
		return ret;
	}
	
	I was not able to finish the GJElimination() function.
	
	
Bonus
	I did not implement the bonus for this assignment.