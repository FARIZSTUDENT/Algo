#include <iostream>

using namespace std;

int main()
{
    int angka = 123;
    FILE *hiu;
    hiu = fopen("data.bin", "w");
    fwrite(&angka, sizeof(int), 1, hiu);
    fclose(hiu);
}