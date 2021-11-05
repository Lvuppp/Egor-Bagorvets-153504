#include <iostream>

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

int main()
{
    const int K = 10;
    int array[K];
    int maxElementIndex = 0;
    int minElementIndex = 0;
    
    std::cout << "Enter an array of k elements separated by a space" << std::endl;

    for (int i = 0; i < K; i++)
    {        
        std::cout << "Enter " << i << " element: ";
        array[i] = Input();
        std::cout << std::endl;
    }

    for (int i = 1; i < K; i++)
    {
        if (array[maxElementIndex] < array[i])
            maxElementIndex = i;
        if (array[minElementIndex] > array[i])
            minElementIndex = i;
    }

    int temp = array[maxElementIndex];
    array[maxElementIndex] = array[minElementIndex];
    array[minElementIndex] = temp;

    for (int i = 0; i < K; i++)
    {
        std::cout << array[i] << " ";
    }

    return 0;
}
