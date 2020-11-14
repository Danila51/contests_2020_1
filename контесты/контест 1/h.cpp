Node *mergeLists(Node *first_node, Node *second_node){
    Node *final_node;
    final_node = new Node;
    final_node->value = 0;
    final_node->next = nullptr;
    Node *ans = final_node;
    while(first_node != nullptr && second_node != nullptr){
        Node *new_node;
        new_node = new Node;
        new_node->next = nullptr;
        if(first_node->value < second_node->value){
            new_node->value = first_node->value;
            first_node = first_node->next;
        }
        else if(first_node->value > second_node->value){
            new_node->value = second_node->value;
            second_node = second_node->next;
        }
        else{
            new_node->value = second_node->value;
            second_node = second_node->next;
            first_node = first_node->next;
        }
        final_node->next = new_node;
        final_node = final_node->next;
    }
    while(first_node != nullptr){
        Node *new_node;
        new_node = new Node;
        new_node->next = nullptr;
        new_node->value = first_node->value;
        final_node->next = new_node;
        final_node = final_node->next;
        first_node = first_node->next;
    }
    while(second_node != nullptr){
        Node *new_node;
        new_node = new Node;
        new_node->next = nullptr;
        new_node->value = second_node->value;
        final_node->next = new_node;
        final_node = final_node->next;
        second_node = second_node->next;
    }
    return ans->next;
}
