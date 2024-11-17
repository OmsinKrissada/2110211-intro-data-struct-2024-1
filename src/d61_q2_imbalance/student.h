// Your code here

int calcHeightBalance(node* n, std::pair<KeyT, int>& bp) {
    if (n == NULL) return -1;
    int left = calcHeightBalance(n->left, bp);
    int right = calcHeightBalance(n->right, bp);
    int height = std::max(left, right) + 1;
    int balance_abs = abs(left - right);
    if (balance_abs > bp.second || balance_abs == bp.second && mLess(n->data.first, bp.first)) {
        bp.first = n->data.first;
        bp.second = balance_abs;
    }
    return height;
}

KeyT getValueOfMostImbalanceNode() {
    // Your code here
    std::pair<KeyT, int> bp = std::make_pair(INT32_MAX, 0);
    calcHeightBalance(mRoot, bp);

    return bp.first;
}