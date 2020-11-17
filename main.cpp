/* imports */
#include <vector>

/*  header files */
#include "Field.hpp"

int main()
{
  std::vector<std::vector<int>> matrix;

  for (int i = 0; i < 6; i++)
  {
    std::vector<int> row;
    for (int j = 0; j < 6; j++)
    {
      row.push_back(j + 1);
    }
    matrix.push_back(row);
  }

  Field field(matrix);
  field.weight(1, 5, 1, 1);
}