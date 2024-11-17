void shift(int k) {
    // TODO: Add your code here
    int times = k % (int)mSize;
    if (times == 0) return;
    node* n;
    if (k < 0) {
        n = mHeader->prev;
        while (times++) n = n->prev;
    } else {
        n = mHeader->next;
        while (times--) n = n->next;
        n = n->prev;
    }
    // detact mHeader
    mHeader->prev->next = mHeader->next;
    mHeader->next->prev = mHeader->prev;
    // attach mHeader
    mHeader->prev = n;
    mHeader->next = n->next;
    // fix link
    mHeader->prev->next = mHeader;
    mHeader->next->prev = mHeader;
}