// Рекурсивная функция для сбора узлов с двумя дочерними элементами
template <typename T>
void BinarySearchTree<T>::collect(TreeNode<T>* node,
                                  std::vector<T>& out) const {
  if (!node) return;

  // обход левого поддерева
  collect(node->left_, out);

  // проверка двух детей
  if (node->left_ && node->right_) {
    out.push_back(node->data_);
  }

  // обход правого поддерева
  collect(node->right_, out);
}