// Функция для печати узлов с двумя дочерними элементами
template <typename T>
void BinarySearchTree<T>::printTwoChildren() const {
  std::vector<T> result;
  collect(root_, result);
  if (result.empty()) {
    throw std::invalid_argument("no nodes with two children");
  }
  for (T v : result) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}