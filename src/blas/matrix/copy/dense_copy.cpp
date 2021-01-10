#include "../../../../include/monolish_blas.hpp"
#include "../../../internal/monolish_internal.hpp"

namespace monolish {
namespace matrix {

// copy monolish Dense
template <typename T> void Dense<T>::operator=(const Dense<T> &mat) {
  Logger &logger = Logger::get_instance();
  logger.util_in(monolish_func);

  val.resize(mat.get_nnz());
  rowN = mat.get_row();
  colN = mat.get_col();
  nnz = mat.get_nnz();

  // gpu copy
  if (mat.get_device_mem_stat()) {
    send();
    internal::vcopy(get_nnz(), mat.val.data(), val.data(), true);
  }

  // cpu copy
  internal::vcopy(get_nnz(), mat.val.data(), val.data(), false);

  logger.util_out();
}

template void Dense<double>::operator=(const Dense<double> &mat);
template void Dense<float>::operator=(const Dense<float> &mat);

} // namespace matrix
} // namespace monolish
