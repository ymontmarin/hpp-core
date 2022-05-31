//
// Copyright (c) 2019 CNRS
// Authors: Florent Lamiraux
//

// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.

#include <hpp/core/collision-path-validation-report.hh>
#include <hpp/core/collision-validation.hh>
#include <hpp/core/config-validations.hh>
#include <hpp/core/path-validation/discretized.hh>
#include <hpp/core/path.hh>
#include <hpp/pinocchio/device.hh>
#include <hpp/util/debug.hh>

namespace hpp {
namespace core {
namespace pathValidation {
HPP_PREDEF_CLASS(NoValidation);
typedef shared_ptr<NoValidation> NoValidationPtr_t;
class NoValidation : public PathValidation {
 public:
  // Validate all paths
  virtual bool validate(const PathPtr_t& path, bool, PathPtr_t& validPart,
                        PathValidationReportPtr_t&) {
    validPart = path;
    return true;
  }
  static NoValidationPtr_t create(const DevicePtr_t&, const value_type&) {
    NoValidation* ptr = new NoValidation();
    NoValidationPtr_t shPtr(ptr);
    return shPtr;
  }

 protected:
  NoValidation() {}
};  // class NoValidation
}  // namespace pathValidation
}  // namespace core
}  // namespace hpp
