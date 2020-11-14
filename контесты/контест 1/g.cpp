int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    int* arr = new int[n_new];
    if (source != NULL){
        for (int i = 0; i < n_old; ++i)
            if(i < n_new) arr[i] =  source[i];
        delete [] source;
    }
    return arr;
}
