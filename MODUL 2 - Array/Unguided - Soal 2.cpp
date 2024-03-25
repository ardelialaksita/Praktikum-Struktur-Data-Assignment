#include <iostream>
using namespace std;

int main()
{
  int rows, columns, cubes;

  // input ukuran array 3 dimensi oleh user
  cout << "Masukkan dimensi pertama array: ";
  cin >> rows;
  cout << "Masukkan dimensi kedua array: ";
  cin >> columns;
  cout << "Masukkan dimensi ketiga array: ";
  cin >> cubes;

  // deklarasi array
  int arr[rows][columns][cubes];

  // inisialisasi dan input elemen array tiga dimensi
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // output elemen array yang telah diinput
  cout << "\nArray elements: \n";
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;

  // tampilan array
  for (int x = 0; x < rows; x++)
  {
    for (int y = 0; y < columns; y++)
    {
      for (int z = 0; z < cubes; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}