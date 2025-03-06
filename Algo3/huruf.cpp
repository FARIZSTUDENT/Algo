#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    FILE *hiu;
    hiu = fopen("hiu.txt", "r");
    rename("hiu.txt", "bambang.txt");
    // char text[100];
    // while (fgets(text, 50, hiu) != NULL)
    // {
    //     cout << text << " " << endl;
    // }

    if (hiu == NULL)
    {
        cout << "File tidak ditemukan" << endl;
        exit(1);
    }
    
    // fprintf(hiu, "Nama : %s\n, Umur : %d\n", "Fariz", 19);
    fclose(hiu);
}
