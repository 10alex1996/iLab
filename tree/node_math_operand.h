//============================================================================================================================================
//
//structure to know information about math operand and about value
//
//============================================================================================================================================

struct math_exception
{
    math_exception () {}

//    math_exception (int math_operand, int value);

    void load (int math_operand, float value);

    int _math_operand;
    
    float _value;
};

void math_exception :: load (int math_operand, float value)
{
    _math_operand = math_operand;
    _value        = value       ;
}

//============================================================================================================================================

class node_math_operand_t : public shell_of_node_t//private shell_of_node_t
{
    public: 
    
        //node_math_operand_t ();
        
        node_math_operand_t (/*shell_of_node_t * parent,*/ Math_operand_t data);
        
        ~node_math_operand_t ();
        
        virtual ret_type execute ();

    private :
    
        Math_operand_t _data;
        
        int _node_type;
};



/*ode_math_operand_t  :: node_math_operand_t () : shell_of_node_t ()
{
    _node_type = MATH_OPERAND;
    
    /*std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "level      = " << level     << std::endl;
    std::cout << "_node_math_operand_type = " << _node_math_operand_type << std::endl;
    
    std::cout << std::endl;
}
*/


node_math_operand_t  :: node_math_operand_t (/*shell_of_node_t * parent,*/ Math_operand_t data) : 
                    
                    //shell_of_node_t (parent),
                    _data   (data  )
{
    _node_type = MATH_OPERAND;
    
    //parent->add (this);
    
    //shell_of_node_t * l = parent->left  ();
    
    /*std::cout << "l          = " << l                << std::endl;
    
    std::cout << "parent     = " << parent           << std::endl;
    std::cout << "parent->l  = " << parent->left  () << std::endl;
    std::cout << "parent->r  = " << parent->right () << std::endl;
    
    std::cout << "this       = " << this       << std::endl;
    std::cout << "_data      = " << _data      << std::endl;
    std::cout << "_level     = " << _level     << std::endl;
    std::cout << "_node_math_operand_type = " << _node_math_operand_type << std::endl;*/
    
}



node_math_operand_t  :: ~node_math_operand_t ()
{
}


/*ret_type node_math_operand_t  :: execute ()
{
    //std::cout << "math_op, type = " << _node_type << "math_op_type = " << MATH_OPERAND <<std::endl;

    if (! left ()) assert (0);
    
    int data = (int) _data;
    
    switch (data)
    {
        case SIN :
        {
            return sin (left ()->execute());
        }
        
        case COS :
        {
            return cos (left ()->execute());
        }
        
        case SQRT :
        {
            return sqrt (left ()->execute());
        }
        
        default : break;
    }
    
    if (! right ()) assert (0);

    switch (data)
    {
        case ADD :
        {
            return (left ()->execute() + right ()->execute());
        }
        
        case SUB :
        {
            return (left ()->execute() - right ()->execute());
        }
        
        case MUL :
        {
            return (left ()->execute() * right ()->execute());
        }
        
        case DIV :
        {
            return (left ()->execute() / right ()->execute());
        }
        
        case POWER :
        {
            return pow (left ()->execute(), right ()->execute());
        }
        
        default : break;
    }
}
*/


ret_type node_math_operand_t  :: execute ()
{
    //std::cout << "math_op, type = " << _node_type << "math_op_type = " << MATH_OPERAND <<std::endl;

    if (! left ()) assert (0);
    
    int data = (int) _data;
    
    math_exception exc;
    
    try
    
    {
        switch (data)
        {
            case SIN :
            {
                exc.load (SIN, sin (left ()->execute()));
                
                throw exc;
            }
            
            case COS :
            {
                exc.load (COS, cos (left ()->execute()));
                
                throw exc;
            }
            
            case SQRT :
            {
                exc.load (SQRT, sqrt (left ()->execute()));
                
                throw exc;
            }
            
            default : break;
        }
        
        if (! right ()) assert (0);

        switch (data)
        {
            case ADD :
            {
                exc.load (ADD, (left ()->execute() + right ()->execute()));
                
                throw exc;
            }
            
            case SUB :
            {
                exc.load (SUB, (left ()->execute() - right ()->execute()));
                
                throw exc;
            }
            
            case MUL :
            {
                exc.load (MUL, (left ()->execute() * right ()->execute()));
                
                throw exc;
            }
            
            case DIV :
            {
                exc.load (DIV, (left ()->execute() / right ()->execute()));
                
                throw exc;
            }
            
            case POWER :
            {
                exc.load (POWER, pow (left ()->execute(), right ()->execute()));
                
                throw exc;
            }
            
            default : break;
        }
    }
    
    catch (math_exception exc)
    {
        throw;
    }
}
