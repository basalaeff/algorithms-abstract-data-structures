// Рекурсивная функция для удаления всех узлов
template <typename T>
void BinarySearchTree<T>::clear(TreeNode<T>* node) {
  if (!node) return;

  clear(node->left_);
  clear(node->right_);
  delete node;
}