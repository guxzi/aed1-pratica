
void troca (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bublesort(int* head, int tamanho){
    if (head == nullptr or tamanho <=0){
    return;
    }
    for (int i=0; i < tamanho -1; i++){
        int* ptr = head;
        for (int j=0; j < tamanho -1; j ++){
            if (*ptr > *(ptr + 1)){
                troca(ptr, ptr + 1);
            }
            ptr++;
        }

    } 
}

void selectionsort(int* head, int tamanho){
    if (head == nullptr or tamanho <= 0){
        return;
    }
    int* ptr = head;
    for (int i = 0; i < tamanho -1; i++){
        int* ptrmin = ptr;
        int* ptraux = ptr +1;

        
        for (int j = i + 1; j < tamanho; j++){
            if (*ptraux < *ptrmin){
                ptrmin = ptraux;
            }
            ptraux++;
        }
        if (ptrmin != ptr){
            troca(ptr, ptrmin);
        }
        ptr++;
    }


}

void insertsort(int* head, int tamanho){
    if (head == nullptr or tamanho <= 0){
        return;
    }
    
    for (int i = 1; i < tamanho; i++){
        int ptraux = *(head + i);
        int* ptr = head + i;

        while (ptr > head && *(ptr - 1) > ptraux){
            *ptr = *(ptr - 1);
            ptr--;
        }
        *ptr = ptraux;
    }
}

