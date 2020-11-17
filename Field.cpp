/* imports */
#include <iostream>

/* header files */
#include "Field.hpp"

Field::Field(std::vector<std::vector<int>> &matrix)
{
  const int num_of_rows = matrix.size();
  const int num_of_cols = matrix[0].size(); // TODO make exception for this just in case it's a matrix with 0 rows (see above)

  // if(num_of_rows === 0) throw exception

  this->_rows = num_of_rows;
  this->_cols = num_of_cols;
  this->_matrix = matrix;

  this->_fill_vector_with_zeroes();
  this->_precompute();

  this->_print_precomputed_weights();
  std::cout << "\n";
}

void Field::_precompute()
{
  for (int i = 0; i < this->_rows; i++)
  {
    for (int j = 0; j < this->_cols; j++)
    {
      if (i == 0 && j == 0)
      {
        int current_matrix_num = this->_matrix[i][j];
        this->_precomputed_weights[i][j] = current_matrix_num;
      }
      else if (i == 0)
      {
        int current_matrix_num = this->_matrix[i][j];
        int num_left = this->_precomputed_weights[i][j - 1];
        this->_precomputed_weights[i][j] = current_matrix_num + num_left;
      }
      else if (j == 0)
      {
        int current_matrix_num = this->_matrix[i][j];
        int num_top = this->_precomputed_weights[i - 1][j];
        this->_precomputed_weights[i][j] = current_matrix_num + num_top;
      }
      else
      {
        int current_matrix_num = this->_matrix[i][j];
        int num_top = this->_precomputed_weights[i - 1][j];
        int num_left = this->_precomputed_weights[i][j - 1];
        int num_top_left = this->_precomputed_weights[i - 1][j - 1];
        int current_node = current_matrix_num + num_top + num_left + num_top_left;
        this->_precomputed_weights[i][j] = current_matrix_num + num_left + num_top - num_top_left;
      }
    }
  }
}

void Field::_fill_vector_with_zeroes()
{
  for (int i = 0; i < this->_rows; i++)
  {
    std::vector<int> row;
    for (int j = 0; j < this->_cols; j++)
    {
      row.push_back(0);
    }
    this->_precomputed_weights.push_back(row);
  }
}

void Field::_print_matrix()
{
  for (int i = 0; i < this->_rows; i++)
  {
    for (int j = 0; j < this->_cols; j++)
    {
      std::cout << this->_matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
}

void Field::_print_precomputed_weights()
{
  for (int i = 0; i < this->_rows; i++)
  {
    for (int j = 0; j < this->_cols; j++)
    {
      std::cout << this->_precomputed_weights[i][j] << " ";
    }
    std::cout << '\n';
  }
}

Field::Field(std::vector<std::vector<int>> &&matrix)
{
  std::cout << 2;
}

int Field::weight(int x1, int y1, int x2, int y2)
{
  int top_left_x = std::min(x1, x2);
  int top_left_y = std::min(y1, y2);
  int bottom_right_x = std::max(x1, x2);
  int bottom_right_y = std::max(y1, y2);

  // take out everything from 0,0 to bottom left (bottom left = (top_left_x, bottom_right_y)
}

/*
  top left = (0,0) bottom right = (4,4);
  
      x
  0 1 2 3 4 
  0 1 2 3 4  y
  0 1 2 3 4 
  0 1 2 3 4 

*/