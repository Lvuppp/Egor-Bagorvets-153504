#include<iostream>
#include<iomanip>

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

int** InputMatrix(int** matrix,int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix[i][j] = Input();
        }
    }

    return matrix;
}

void PrintMatrix(int** array, int size) {
    for (int i = 0; i < size; i++)
    {
        printf("\n");

        for (int j = 0; j < size; j++)
        {
            printf( "%d ", array[i][j]);
        }       
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Enter size of matrix N: " << std::endl;
    int size = Input();

    int** firstMatrix = (int**)malloc(size * sizeof(int*));
    int** secondMatrix = (int**)malloc(size * sizeof(int*));
    int** multipliedMatrix = (int**)calloc(size,size * sizeof(int*));

    for (int i = 0; i < size; i++)
    {
        firstMatrix[i] = (int*)malloc(size * sizeof(int*));
        secondMatrix[i] = (int*)malloc(size * sizeof(int*));
        multipliedMatrix[i] = (int*)calloc(size ,size * sizeof(int));
    }

    InputMatrix(firstMatrix,size);
    InputMatrix(secondMatrix,size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                multipliedMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
    PrintMatrix(multipliedMatrix,size);

    for (int i = 0; i < size; i++)
    {
        delete(int*)firstMatrix[i];
        delete(int*)secondMatrix[i];
        delete(int*)multipliedMatrix[i];
    }

    delete(int*)firstMatrix;
    delete(int*)secondMatrix;
    delete(int*)multipliedMatrix;

    return 0;
}