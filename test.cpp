#include <iostream>

int funct(char* data, int length)
{
    // if we have no character or 1 character return 1;
    if(length < 2)
        return 1;
    if(data[0] == '0')
        return 0;

    int arr[length + 1];
    arr[0] = 1;
    arr[1] = 1;
    // at this point we know the length is at least 2
    // the first character is already checked and for is not zero
    for (int i = 2; i <= length; i++)
    {
        // we always start with the zero
        arr[i] = 0;

        if(data[i-1] > '0')
            arr[i] = arr[i-1];
        if( (data[i-2] == '1' || data[i-2] == '2') && (data[i-1] < '7') )
            arr[i] += arr[i-2];
    }
    return arr[length];
    
}

int main(void)
{
char word[] = "123";
int result = funct(word, strlen(word));
std::cout<< "Result: "<< result << std::endl;

}