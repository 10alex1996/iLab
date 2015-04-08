#include "cvector.h"


int main ()
{
    CVector <float> array_1 (3);
    CVector <float> array_2    ;

    array_1.push_back(5 );
    array_1.push_back(10);

    array_2.push_back(15);
    array_2.push_back(20);

    array_1 += array_2;

    array_1.dump ();

    cout << array_2 [1] << endl;

    return 0;
}
