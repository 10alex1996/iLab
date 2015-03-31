#include "cvector.h"


int main ()
{
    CVector <int    > array_1 (3);
    CVector <int> array_2    ;

    array_1.push_back(5 );
    array_1.push_back(10);

    array_2.push_back(15);
    array_2.push_back(20);

    array_1 += array_2;

    array_1.dump ();

    //cout << array [2] << endl;

    return 0;
}
