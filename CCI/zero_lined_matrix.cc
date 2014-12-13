// Write an algorithm such that if an element in an MxN matrix is 0, its entire
// row and column are set to 0.

/*
  APPROACH 1:
  Use two binary integers with M and N digits where each bit represents whether
  a column or row should be all-zeros. This uses M+N bits, but since they're
  represented as integers, the space complexity is O(1).
  The time complexity is O(2MN), because two sweeps are required. One for
  finding 0s, the other for setting 0s.

  APPROACH 2:
  Find the first 0. Because that row and column are going to be filled later
  anyway, use them in the meantime to store all future 0-locations. Once
  finished with the initial sweep, go back and check the row and the column,
  filling in rows and columns independently along the way. Extra space is O(1),
  and time is O(MN + M + N).

  ANALYSIS:
  First approach is:
  T = O(MN)
  S = O(1)

  Second approach is:
  T = O(MN)
  S = O(1)

  The first approach is much more clear and readable than the second, minimizing
  the chance of mistakes.
*/

#include <iostream>
#include <vector>

void printSingleDigitMatrix(std::vector<std::vector<int>> matrix) {
  if ((matrix.size() == 0) || (matrix[0].size() == 0)) return;

  std::cout << std::endl;
  for (int r=0; r<matrix.size(); r++) {
    for (int c=0; c<matrix[0].size(); c++) {
      std::cout << matrix[r][c] << " ";
    }
    std::cout << std::endl;
  }
}


void zeroArrangementMatrix1(std::vector<std::vector<int>>& matrix) {
  if ((matrix.size() == 0) || (matrix[0].size() == 0)) return;

  int height = matrix.size();
  int width = matrix[0].size();
  
  int rows = 1 << height; // Example for 6 rows, 0b1000000, just
  int cols = 1 << width;  // ignore the 1 in (2**height)ths place.

  // If zero is found, flip the corresponding row and column bits
  // to indicate that both lines should be filled with zeros.
  for (int r=0; r<height; r++) {
    for (int c=0; c<width; c++) {
      if (matrix[r][c] == 0) {
	rows |= (1 << r);
	cols |= (1 << c);
      }
    }
  }

  // Example 0b1001101 & 0b1000 is 0b1000, not 0b0
  int i, j;
  // Fill rows with zeros...
  for (i=0; i<height; i++) {
    if (rows & (1<<i)) {
      // this row has a zero
      for (j=0; j<width; j++) {
	matrix[i][j] = 0;
      }
    }
  }

  // Fill columns with zeros...
  for (i=0; i<width; i++) {
    if (cols & (1<<i)) {
      // this column has a zero
      for (j=0; j<height; j++) {
	matrix[j][i] = 0;
      }
    }
  }  
}


void zeroArrangementMatrix2(std::vector<std::vector<int>>& matrix) {
  if ((matrix.size() == 0) || (matrix[0].size() == 0)) return;

  int height = matrix.size();
  int width = matrix[0].size();

  // Once the first 0 is found, we know that row/column are going to be filled,
  // and any data will be lost, so we can use that row to record the columns
  // that should be filled, and we can use to column to record the rows. 
  bool first_found = 0;
  int storage_row, storage_col;
  for (int r=0; r<height; r++) {
    for (int c=0; c<width; c++) {
      if (matrix[r][c] == 0) {
	if (!first_found) {
	  storage_row = r;
	  storage_col = c;
	  first_found = 1;
	} else if (first_found) {
	  // store column in storage_row
	  // store row in storage_column
	  matrix[storage_row][c] = 0;
	  matrix[r][storage_col] = 0;
	}
      }
    }
  }

  if (!first_found) return;

  // Look through storage_row and storage_column for zeros, and overwrite the
  // matrix columns and rows, respectively. Make sure to leave the location at
  // [storage_row][storage_col] for last, else you overwrite all the zeros we
  // placed.
  int i, j;
  for (i=0; i<width; i++) {
    if (i == storage_col) continue;
    if (matrix[storage_row][i] == 0) {
      for (j=0; j<height; j++) {
	matrix[j][i] = 0;
      }
    }
    matrix[storage_row][i] = 0;
  }

  for (i=0; i<height; i++) {
    if (i == storage_row) continue;
    if (matrix[i][storage_col] == 0) {
      for (j=0; j<width; j++) {
	matrix[i][j] = 0;
      }
    }
    matrix[i][storage_col] = 0;
  }
}


int main() {
  std::vector<std::vector<int>> m1 = {{1, 2, 3, 4},
				      {2, 4, 0, 8},
				      {1, 2, 3, 4},
				      {0, 4, 6, 8},
				      {1, 2, 3, 0},
				      {2, 4, 0, 8}};
				      
  printSingleDigitMatrix(m1);
  zeroArrangementMatrix1(m1);
  printSingleDigitMatrix(m1);

  std::vector<std::vector<int>> m2 = {{1, 2, 3, 4},
				      {2, 4, 0, 8},
				      {1, 2, 3, 4},
				      {0, 4, 6, 8},
				      {1, 2, 3, 0},
				      {2, 4, 0, 8}};  

  zeroArrangementMatrix2(m2);
  printSingleDigitMatrix(m2);

}
