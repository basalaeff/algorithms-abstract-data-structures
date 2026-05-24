// Рекурсивная функция для вставки узла
template <typename T>
TreeNode<T>* BinarySearchTree<T>::insert(TreeNode<T>* node, T value) {
  if (!node) {
    return new TreeNode<T>(value);
  }

  if (value < node->data_) {
    node->left_ = insert(node->left_, value);
  } else {
    node->right_ = insert(node->right_, value);
  }

  return node;
}

// Публичный метод для вставки узла
template <typename T>
void BinarySearchTree<T>::insert(T value) {
  root_ = insert(root_, value);
}