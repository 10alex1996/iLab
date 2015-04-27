# include "node.h"


# define ASSERT                                         \
if (!_root)                                             \
{                                                       \
    std::cout << "_root = NULL" << std::endl;           \
                                                        \
    assert (_root);                                     \
}                                                       \
else if (!_cur_node)                                    \
{                                                       \
    std::cout << "_cur_node = NULL" << std::endl;       \
                                                        \
    assert (_cur_node);                                 \
}                                                       \


void Dump        (shell_of_node_t * cur_node, int level = 0);
void delete_tree (shell_of_node_t * root                   );


struct tree_t 
{
    public :

    tree_t  (                      );
    tree_t  (shell_of_node_t * node);
        
    ~tree_t ();
    
        
    void dump ();
    
    void add (shell_of_node_t * node);
    
    shell_of_node_t * ret_shell      ();
    shell_of_node_t * ret_root_shell ();
    
    void up    ();
    void left  ();
    void right ();
    
    private :
    
    shell_of_node_t * _cur_node;
    shell_of_node_t * _root    ;
};


tree_t :: tree_t ()
{
    _cur_node = (shell_of_node_t *) (new node_root_t);
    
    _root = _cur_node;
}


tree_t :: tree_t (shell_of_node_t * node) : 

          _cur_node (node),
          _root     (node)
{
    /*std::cout << "constructor with parametrs" << std::endl;

    std::cout << "_cur_node   =" << _cur_node           << std::endl;
    std::cout << "left_node   =" << _cur_node->left  () << std::endl;
    std::cout << "right_node  =" << _cur_node->right () << std::endl;
    
    std::cout << std::endl;*/
}


tree_t :: ~tree_t ()
{
    delete_tree (_root);
}


void tree_t :: add (shell_of_node_t * node)
{
    ASSERT;

    assert (node);

    /*std::cout << "before add" << std::endl;

    std::cout << "_cur_node   =" << _cur_node           << std::endl;
    std::cout << "left_node   =" << _cur_node->left  () << std::endl;
    std::cout << "right_node  =" << _cur_node->right () << std::endl;
    
    std::cout << std::endl;*/

    _cur_node->add (node);
    
    /*std::cout << "after add" << std::endl;
    
    std::cout << "_cur_node   =" << _cur_node           << std::endl;
    std::cout << "left_node   =" << _cur_node->left  () << std::endl;
    std::cout << "right_node  =" << _cur_node->right () << std::endl;
    
    std::cout << std::endl;*/
    
    ASSERT;
}


void tree_t :: dump ()
{
    ASSERT;
    
    Dump (_root);
}

shell_of_node_t * tree_t :: ret_shell ()
{
    ASSERT;

    return _cur_node;
}


void tree_t :: up ()
{
    ASSERT;

    assert (_cur_node->up ());
    
    _cur_node = _cur_node->up ();
    
    ASSERT;
}


void tree_t :: left  ()
{
    ASSERT;

    assert (_cur_node->left ());

    _cur_node = _cur_node->left ();
    
    ASSERT;
}


void tree_t :: right ()
{
    ASSERT;

    assert (_cur_node->right ());

    _cur_node = _cur_node->right ();
    
    ASSERT;
}

//=============================================================================================================================================
//
//general tree function
//
//=============================================================================================================================================



void Dump (shell_of_node_t * cur_node, int level)
{
    /*std::cout << "cur_node   =" << cur_node           << std::endl;
    std::cout << "left_node  =" << cur_node->left  () << std::endl;
    std::cout << "right_node =" << cur_node->right () << std::endl;
    
    std::cout << std::endl;*/
    
    assert (cur_node);
    
    bool check_print = false;

    if (cur_node->right () != NULL)
    {
        Dump (cur_node->right (), level + 1);
    }
    
    for (int i = 0; i < level; i++)
        std::cout << "          ";
        
    std::cout << "--------->";
        
    ret_type ret_value = 0;
    
    try
    {
        ret_value = cur_node->execute ();
    }
    
    catch (int * arg)
    {
        //std::cout << *arg << std::endl;
        //std::cout << FLOAT << std::endl;
        //std::cout << ret_value << std::endl;
        
        if      (* arg == VARIABLE) std::cout << "x   "                << std::endl;
        else if (* arg == ROOT    ) std::cout << "root"                << std::endl;
        
        check_print = true;
    }
    
    catch (math_exception exc)
    {
        std::cout << math_operands [exc._math_operand] << " = " << exc._value << std::endl;
        
        check_print = true;
    }
    
    if (!check_print) std::cout << ret_value << std::endl;
    
    if (cur_node->left () != NULL)
    {
        Dump (cur_node->left (), level + 1);
    }
}


void delete_tree (shell_of_node_t * root)
{
    assert (root);

    if (root->left () != NULL) 
    {
        delete_tree (root->left ());
    }
    
    if (root->right () != NULL) 
    {
        delete_tree (root->right ());
    }
    
    delete root;
    
    root = NULL;
}

