# include "stack_vector.h"

int main ()
{
    Stack_t <string,  0> stack_str   ;
    Stack_t <int,     3> stack_int   ;
    Stack_t <double,  2> stack_double;
    Stack_t <float     > stack_float ;

    stack_str.Push ("test_str1");
    stack_str.Push ("test_str2");

    stack_int.Push (70);
    stack_int.Push (80);
    stack_int.Push (90);
    stack_int.Push (10);

    stack_double.Push (0.2);
    stack_double.Push (0.5);
    stack_double.Push (1/3);
    stack_double.Push (0.7);

    stack_float.Push (1.45);
    stack_float.Push (1.32);

    cout << "str = " << stack_str.Pop () << endl;
    cout << "str = " << stack_str.Pop () << endl;

    cout << "double = " << stack_double.Pop () << endl;
    cout << "double = " << stack_double.Pop () << endl;
    cout << "double = " << stack_double.Pop () << endl;

    cout << "int = " << stack_int.Pop () << endl;

    cout << "float = " << stack_float.Pop () << endl;

    stack_str.Dump ();

    stack_str.Dump ();

    stack_double.Dump ();

    stack_int.Dump ();

    stack_float.Dump ();

    return 0;
}

