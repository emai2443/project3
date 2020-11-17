#ifndef FIELD_H
#define FIELD_H

/* imports */
#include <vector>

class Field
{
private:
  void _precompute();
  void _print_matrix();
  void _fill_vector_with_zeroes();
  void _print_precomputed_weights();

  int _rows;
  int _cols;
  std::vector<std::vector<int>> _matrix;
  std::vector<std::vector<int>> _precomputed_weights;

public:
  Field(std::vector<std::vector<int>> &matrix);
  Field(std::vector<std::vector<int>> &&matrix);
  int weight(int x1, int y1, int x2, int y2);
};

#endif