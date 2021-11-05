#include<iostream>

void Verify()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter correct value" << std::endl;
}

int Input() {
    int x;
    std::cin >> x;
    while (true)
    {
        std::cin >> x;
        if (!std::cin.fail())
            break;
       Verify();
    }
    return x;
}
char InputSign() {
    char x;
    while (true)
    {
        std::cin >> x;
        if (!std::cin.fail() && (x == '.' || x == '*'))
            break;
        Verify();
    }
    return x;
}
void PrintArray(char** array, int N, int M) {

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

}
char SeekMine(char** array, int columnSize, int lineSize, int columnSizeEnd,int lineSizeEnd) {
    int counter = 0;
    for (int k = columnSize; k < columnSizeEnd; k++)
    {
        for (int l = lineSize; l < lineSizeEnd; l++)
        {
            if(array[k][l] == '*')
                counter++;
        }
    }
    if(counter > 0)
        return counter + 48;
    else
        return '.';
}

int main() {
    int N = Input(), M = Input();

    char** array = (char**)malloc(N*sizeof(char**));

    for (int i = 0; i < N; i++)
    {
        array[i] = (char*)malloc(M * sizeof(char*));
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            array[i][j] = InputSign();
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(array[i][j] == '*')
                continue;

            if((i == N - 1 && j == M - 1) || (i == 0 && j == 0) || (i == 0 && j == M - 1) || (i == N - 1 && j == 0))
                array[i][j] = SeekMine(array, std::min(i, abs(i - 1)), std::min(j, abs(j - 1)), std::max(abs(i - 1), i) + 1, std::max(j, abs(j - 1)) + 1);
            else if((i == N - 1 || i == 0) && j != 0 && j != M - 1)
                array[i][j] = SeekMine(array, std::min(i, abs(i - 1)), j - 1, std::max(abs(i - 1), i) + 1, j + 2);
            else if((j == 0 || j == M - 1) && i != 0 && i != N - 1)
                array[i][j] = SeekMine(array, i - 1, std::min(j, abs(j - 1)), i + 2, std::max(abs(j - 1), j) + 1);
            else
                array[i][j] = SeekMine(array, i - 1, j - 1, i + 2, j + 2);
        }
    }

    PrintArray(array, N, M);

    for (int i = 0; i < N; i++)
    {
        free(array[i]);
    }
        
    free(array);
    return 0;
}