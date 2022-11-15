#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    srand(time(0));
    setlocale(LC_ALL, "ru_RU.UTF-8");
    system("chcp 65001");
    const int N = 100;
    short A[N], A2[N];
    int arr[N], arr_[N];
    int r, sort = 0, max, min, average;
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;

    cout << "Создан неотсортированный массив из 100 элементов: ";
    for (int i = 0; i < N; i++) {
        A[i] = rand() % 198 - 99;
        A2[i] = A[i];
        cout << A[i] << " ";
    }
    sort = 0;
    cout << endl << "Для продолжения нажмите enter";
    getchar();
    cout << endl;

    while (true) {

        cout << "          Меню\n" <<
            "1 - создать новый массив\n" <<
            "2 - отсортировать массив\n" <<
            "3 - найти максимальный и минимальный элемент массива\n" <<
            "4 - найти среднее значение max и min, кол-ао элементов, равных ему, и их индексы\n" <<
            "5 - найти кол-во элементов отсортированного массива, меньше введённого вами числа\n" <<
            "6 - найти кол-во элементов отсортированного массива, больше введённого вами числа\n" <<
            "7 - поменять местами элементы массива\n" <<
            "0 - выйти из программы\n";
        cout << "Ваш выбор: ";
        cin >> r;
        cin.sync();
        if (r == 0) break;
        switch (r) {
        case 1:
            cout << "Задание 1\n";


            for (int i = 0; i < N; ++i) {
                A[i] = rand() % 198 - 99;
                A2[i] = A[i];
                cout << A[i] << " ";
            }

            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;


        case 2:
            cout << "Задание 2\n";
            start = steady_clock::now();

            for (int i = 0; i < 100; i++) {
                for (int j = 0; j < 100 - i - 1; j++)
                    if (A[j] > A[j + 1])
                        swap(A[j], A[j + 1]);
            }
            for (int y = 0; y < 100; ++y)
                cout << A[y] << " ";

            cout << "\n";

            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);

            sort = 1;
            cout << endl << "Наносекунды: " << result.count() << endl << endl;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;

        case 3:

            cout << "Задание 3\n";
            start = steady_clock::now();
            min = A[0];
            max = A[N - 1];
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Минимальный элемент в отсортированном массиве: " << min << endl;
            cout << "Максимальный элемент в отсортированном массиве: " << max << endl;
            cout << "Время поиска: " << result.count() << endl << endl;

            max = -100;
            min = 100;
            start = steady_clock::now();

            for (int i = 0; i < N; ++i) {
                if (A2[i] > max)

                    max = A2[i];
                if (A2[i] < min)
                    min = A2[i];
            }
            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            cout << "Минимальный элемент в неотсортированном массиве: " << min << endl;
            cout << "Максимальный элемент в неотсортированном массиве: " << max << endl;
            cout << "Время поиска:" << result.count() << endl << endl;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;

            break;
        case 4:
            cout << "Задание 4\n";


            average = A[0] + A[N - 1];
            if (average % 2 != 0)
                average += 1;
            average /= 2;
            cout << "Среднее значение: " << average << endl;

            cout << "Индексы элементов, которые равны среднему значению: ";
            int k;
            k = 0;
            start = steady_clock::now();
            for (int i = 0; i < 100; ++i) {
                if (A[i] == average) {
                    k += 1;
                    cout << i << " ";
                }
            }
            end = steady_clock::now();
            cout << "Время поиска:" << result.count() << endl << endl;
            k = 0;
            cout << endl << "Неотсортированный массив" << endl;
            cout << "Индексы равных элементов: ";
            start = steady_clock::now();
            for (int i = 0; i < N; i++) {
                if (A[i] == average) {
                    cout << i << " ";
                    k++;
                }
            }
            end = steady_clock::now();
            cout << endl << "Кол-во равных элементов: " << k;
            cout << endl << "Время поиска (наносекунды): " << result.count();
            cout << endl << "Количество равных элементов: " << k;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;

        case 5:
            cout << "Задание 5\n";

            int a;
            cin >> a;
            k = 0;
            for (int i = 0; i < 100; ++i) {
                if (A[i] < a) {
                    k += 1;
                }
            }
            cout << "Количество элементов, которые меньше числа a: " << k << endl << endl;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            break;

        case 6:

            cout << "Задание 6\n";

            int b;
            cin >> b;
            k = 0;
            for (int i = 0; i < 100; ++i) {
                if (A[i] > b) {
                    k += 1;
                }
            }
            cout << "Количество элементов, которые меньше числа b: " << k << endl << endl;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl;
            break;

        case 7:
            cout << "Задание 8\n";

            int x, y, t;
            cin >> x >> y;
            start = steady_clock::now();
            swap(A[x], A[y]);

            end = steady_clock::now();
            result = duration_cast<nanoseconds>(end - start);
            for (int i = 0; i < 100; ++i) {
                cout << A[i] << " ";
            }
            cout << endl;
            cout << "Cкорость обмена: " << result.count() << endl << endl;
            cout << endl << "Для продолжения нажмите enter";
            getchar();
            cout << endl << endl;
            break;
        }
    }
    return 0;
}
