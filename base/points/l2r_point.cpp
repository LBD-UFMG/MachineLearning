#include "l2r_point.h"

#include <string>
#include <vector>

#include "base/point.h"

namespace base {
namespace points {

L2RPoint::~L2RPoint() {
}

double L2RPoint::GetFeatureValue(unsigned feature_id) const {
  return 0;
}

double L2RPoint::GetLabel() const {
  return 0;
}

std::string L2RPoint::ToString() const {
  return std::string();
}

void L2RPoint::Initialize(const std::string& source) {
}

}  // namespace points
}  // namespace base
