// Функция для печати узлов с двумя дочерними элементами
template <typename T>
void BinarySearchTree<T>::printTwoChildren() const {
  std::vector<T> result;
  collect(root_, result);
  for (T v : result) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}