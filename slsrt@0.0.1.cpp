#include <iostream>
#include <sstream>

using namespace std;

bool input(float * &elements, unsigned int num)
{
    float *tmp_elements;
    string str;

    getline(cin, str);

    tmp_elements = new float [num];

    for (string str; getline(cin, str); ) {
        std::istringstream stream(str);
        for (unsigned int j = 0; j < num; ++j) {
            if(!(stream >> tmp_elements[j])) {
                stream.setstate(std::ios::failbit);
                return false;
            }
        }
        break;
    }
    elements = tmp_elements;
    return true;
}

void slcsort(float *elements, unsigned int num)
{
    int min;
    for (int i = 0; i < num - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < num; j++)
            if (elements[j] < elements[min])
                min = j;
        swap(elements[min], elements[i]);
    }
}

int main() {
    float *elements;
    unsigned int num;

    if(!(cin>>num))
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    if(!(input(elements,num)))
    {
        cout <<"An error has occured while reading input data.\n";
        return 0;
    }

    slcsort(elements, num);
    for (int i = 0; i < num; i++) cout << elements[i]<<' ';

    return 0;
}
