#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#define GRID_SIZE 4

int grid[GRID_SIZE][GRID_SIZE] = {0};

void place_num()
{
  int row = rand() % GRID_SIZE;
  int col = rand() % GRID_SIZE;
  int num = rand() % 2;
  if (grid[row][col] == 0)
  {
    if (num == 0)
    {
      grid[row][col] = 2;
    }
    else
    {
      grid[row][col] = 4;
    }
  }
  else
  {
    place_num();
  }
}

void print_grid()
{
  for (int i = 0; i < GRID_SIZE; i++)
  {
    for (int j = 0; j < GRID_SIZE; j++)
    {
      printf("%4d", grid[i][j]);
    }
    printf("\n");
  }
}

void process_cmd(char input)
{
  getchar();
  switch (input)
  {
  case 'W':
    printf("UP\n");
    break;
  case 'A':
    printf("LEFT\n");
    break;
  case 'S':
    printf("DOWN\n");
    break;
  case 'D':
    printf("RIGHT\n");
    break;
  default:
    break;
  }
}

void rotate_right()
{
  int gridCopy[GRID_SIZE][GRID_SIZE];
  memcpy(gridCopy, grid, sizeof(int) * GRID_SIZE * GRID_SIZE);
}

void rotate_left()
{
  int gridCopy[GRID_SIZE][GRID_SIZE];
  memcpy(gridCopy, grid, sizeof(int) * GRID_SIZE * GRID_SIZE);
}

void welcome()
{
  printf("Welcome to 2048!\nHow to Play: W=Up A=Left S=Down D=Right Q=Quit\n");
}

int main()
{
  srand(time(0));
  welcome();
  place_num();
  place_num();
  print_grid();
  char c;
  while ((c = getchar()) != 'Q')
  {
    process_cmd(c);
    place_num();
    print_grid();
  }
  return EXIT_SUCCESS;
}