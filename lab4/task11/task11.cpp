#include<iostream>
#define s size-1
int Input() {
    int x;

    while (true)
    {
        std::cin >> x;

        if (!std::cin.fail())
            return x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter correct value" << std::endl;
    }
}

int*** InputArray(int*** matrix, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                matrix[i][j][k] = Input();
            }
        }
    }

    return matrix;
}

int GetDiagonal(int*** array, int size,int i , int j ,int k) {
    int diagonalSum = 0;
    while (k >= 0)
    {
        diagonalSum += array[abs(i - (size - k))][abs(j - (size - k))][k];
        k--;

    }
    return diagonalSum;
}

int main() {
    std::cout << "Enter size of matrix: " << std::endl;
    int size = Input(), index;
    index = size;
    int*** array = new int** [size];

    for (int i = 0; i < size; i++)
    {
        array[i] = new int* [size];
        for (int j = 0; j < size; j++)
        {
            array[i][j] = new int[size];
        }
    }

    
    InputArray(array, size);

    std::cout << std::max(GetDiagonal(array, s, 0, 0, s), std::max(GetDiagonal(array, s, 0, s, s),
        std::max(GetDiagonal(array, s, s, 0, s), GetDiagonal(array, s, s, s, s)))) << " is max value of diagonal" << std::endl;


    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            delete[] array[i][j];
        }
        delete[] array[i];
    }
    delete[] array;
}