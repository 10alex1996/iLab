enum
{
    EMPTY        = 100,
    FLOAT             ,
    VARIABLE          ,
    MATH_OPERAND      ,
    ROOT              ,
};

enum
{
    ADD = 0,
    SUB    ,
    MUL    ,
    DIV    ,
    SIN    ,
    COS    ,
    SQRT   ,
    POWER  ,
};

//typedef float X_t;

typedef float Math_operand_t;

typedef float Float_t;

typedef float Root_t;


const char math_operands [10][8] = {{"+"}, {"-"}, {"*"}, {"/"}, {"sin"}, {"cos"}, {"sqrt"}, {"power"}};


# include "shell_of_node.h"

# include "node_x.h"
# include "node_float.h"

#include <cmath>

# include "node_math_operand.h"
# include "node_root.h"
