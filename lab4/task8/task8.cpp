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
void PrintArray(int* array, int size) {
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Enter amount of number" << std::endl;

    int N = Input(), zeroNumbers = 0, minIndex = 0, maxIndex = 0, noneZeroIndex = 0;

    int* array = new int[N];

    for (int  i = 0; i < N; i++)
    {
        std::cout << "Enter " << i << " number" << std::endl;
        array[i] = Input();
    }

    for (int i = 0; i < N; i++)
    {
        if (array[i] < array[minIndex])
            minIndex = i;
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }
    
    PrintArray(array, N);

    int i = 0;

    while (i < N)
    {
        if (i > std::min(minIndex, maxIndex) && i < std::max(maxIndex, minIndex) && array[i] != array[minIndex] && array[i] != array[maxIndex])
        {
            array[i] = 0;
            zeroNumbers++;
        }
        else if (array[i] == 0)
        {
            zeroNumbers++;
        }
        i++;
    }

    if (zeroNumbers > N / 2) {
        int* noneZeroArray = new int[N - zeroNumbers];

        for (int i = 0; i < N; i++)
        {
            if (array[i] != 0)
            {
                noneZeroArray[noneZeroIndex] = array[i];
                noneZeroIndex++;
            }
        }
        PrintArray(noneZeroArray, N - zeroNumbers);
        
        delete[] noneZeroArray;;
    }
    else {
        PrintArray(array ,N);
    }

    delete[] array;

    return 0;
}