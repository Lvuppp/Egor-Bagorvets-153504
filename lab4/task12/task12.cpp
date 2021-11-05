#include <iostream>
int Input() {
    double x;

    while (true)
    {
        std::cin >> x;

        if (!std::cin.fail())
            return (int)x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter correct value" << std::endl;
    }
}

void PrintArray(int* array, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}
int main() {
    int size = Input(), counter = 0, updateSize = 1;
    int* array = new int[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = Input();
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] == (int)INFINITY)
                continue;

            if (array[i] == array[j])
                array[j] = (int)INFINITY;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if (array[i] == (int)INFINITY)
            continue;
        updateSize++;
    }

    int* updateArray = (int*)malloc(updateSize * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        if (array[i] == (int)INFINITY)
            continue;
        updateArray[counter] = array[i];
        counter++;
    }
    PrintArray(updateArray, updateSize-1);

    delete[] array;
    free(array); 
    return 0;
}