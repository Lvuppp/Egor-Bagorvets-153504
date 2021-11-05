#include<iostream>

int Input() {
    int x;

    while (true)
    {
        std::cin >> x;

        if (!std::cin.fail() && x > 0)
            return x;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter correct value" << std::endl;
    }
}

int main() {
    std::cout << "Enter extension: " << std::endl;
    int N = Input(), sumSocket = 1;
    int* array = new int[N];
    
    for (int i = 0; i < N; i++)
    {
        std::cout << "\n" << i << " sockets in one extension: ";
        array[i]= Input();
    }
    for (int i = 0; i < N; i++)
    {
        sumSocket += array[i];
    }
    sumSocket -= N;
    
    std::cout << "Amount sockets " << sumSocket;

    delete[] array;
    return 0;
}