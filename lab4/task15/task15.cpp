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

void PrintArray(int** array, int N, int M) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << std::setw(5)<< array[i][j] << " ";
        }
        std::cout << "\n";
    }

}

int main() {

    int number = Input(), a = Input(), i = 0, j = 1, counter = 2, square = 2;
    int** array = new int*[number];
    for (int i = 0; i < number; i++)
    {
        array[i] = new int[number];
    }

    array[0][0] = 1;

    while (square < number + 1)
    {
        while (i < square)
        {
            array[i][j] = counter;
            counter++;
            i++;
        }
        --i;
        while (j > 0)
        {
            --j;
            array[i][j] = counter;
            counter++;
        }
        square++;
        j = square - 1;
        i = 0;
    }
    PrintArray(array, number, number);

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            if (a == array[i][j]) {
                std::cout << "i: " << i << " j: " << j;
                break;
            }
        }
    }
    for (int i = 0; i < number; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}