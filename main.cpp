#include <iostream>
#define SIZE 5

using namespace std;

int overload(int (&arr)[SIZE]) {
    int res=0;

    for (int num: arr) {
        if (num==0) res++;
        else if (num%2==0) res++;
    }

    return res;
}

int overload(string textLine) {
    int res=0;

    bool isFirst = true, findNext = false;

    for (char c: textLine) {
        
        if ((c=='a'||int(c)==-80)&&!findNext) {
            res++;
            findNext=true;
        }

        if (c==' ') findNext = false;
    }

    return res;
}

int main() {
    srand(time(NULL));
    int arr[SIZE]{};
    cout << "Массив: ";

    for (int i=0;i<SIZE;i++) {
        arr[i]=rand()%11-5; 
        cout << arr[i] << " ";
    }
    cout << endl << "Количество четных элементов массива: " << overload(arr) << endl;

    string textLine = "Слово еще арматура anniversary СЛОВО апельсин apple Апельсин";
    //cout << "Введите строку: "; getline(cin, textLine);

    cout << "Количество слов, начинающихся на \"a\": " << overload(textLine);

    return 0;
}