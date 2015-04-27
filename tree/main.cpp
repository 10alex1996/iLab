# include "tree.h"

int main ()
{
    tree_t * root = new tree_t;
    
    root->add (new node_math_operand_t (POWER));
    
    root->left ();
    
    root->add (new node_float_t (50));
    root->add (new node_float_t (3));
    
    root->left ();
    
    root->add (new node_float_t (40));
    root->add (new node_x_t         );
    
    root->dump (); 
    
    //delete_tree (root->ret_root_shell ());
    
    delete root;
}
