// Given an image represented by an NxN matrix, where each pixel in the image is
// 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
// place?
#include <stdio.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define MAX 6

void rotateMatrix(int matrix[][6], int size=6) {
  int temp;
  for (int layer=0; layer<(size/2); layer++) {
    for (int i=layer; i<(size-layer-1); i++) {
      temp = matrix[layer][i];

      // left --> top
      matrix[layer][i] = matrix[size-1-i][layer];
      // bottom --> left
      matrix[size-1-i][layer] = matrix[size-1-layer][size-1-i]; 
      // right --> bottom
      matrix[size-1-layer][size-1-i] = matrix[i][size-1-layer];
      // top --> right
      matrix[i][size-1-layer] = temp;
    }
  }
}


void populateMatrix(int a[6][6]) {
  int initial_direction = UP , n = MAX , p = 1 ;
  int r ,c;
  int row_right  = 0 , column_down = n-1 , row_left = n-1 , column_up = 0 ;
 
  // Set all elements of the matrix to 0
  for(r = 0 ; r < MAX ; r++) {
    for(c = 0 ; c < MAX ; c++) a[r][c] = 0 ;
  }
 
  // Generate elements of the spiral matrix
  while(p != n*n+1) {
    if(initial_direction == UP) {
      // Move RIGHT
      r = row_right++ ;
      for(c = 0 ; c < n ; c++) {
	if(a[r][c] == 0)
	  a[r][c] = p++;
      }

      initial_direction = RIGHT ;
    } else if (initial_direction == RIGHT) {
      // Move down
      c = column_down-- ;
      for(r = 0 ; r < n ; r++) {
	if(a[r][c] == 0) a[r][c] = p++;
      }

      initial_direction = DOWN;
    }

    else if(initial_direction == DOWN) {
      // Move left
      r = row_left-- ;
      for(c = n-1 ; c >= 0 ; c--) {
	if(a[r][c] == 0) a[r][c] = p++;
      }
      
      initial_direction = LEFT ;
    } else if(initial_direction == LEFT) {
      // Move up
      c = column_up++;
      for(r = n-1 ; r >= 0 ; r--) {
	if(a[r][c] == 0) a[r][c] = p++;
      }

      initial_direction = UP ;
    }
  }
}

 


void printMatrix(int matrix[][6], int size=6) {
  printf("\n\n");
  for(int r=0 ; r<MAX ; r++) {
    for(int c=0 ; c<MAX ; c++) printf("%4d ", matrix[r][c]);
    printf("\n");
  }
}


int main() {
  int matrix[6][6];
  populateMatrix(matrix);

  printMatrix(matrix);
  for (int i=0; i<4; i++) {
    rotateMatrix(matrix);
    printMatrix(matrix);
  }  
}
