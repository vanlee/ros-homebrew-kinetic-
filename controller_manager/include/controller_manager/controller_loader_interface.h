///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012, hiDOF, Inc
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//   * Neither the name of hiDOF, Inc. nor the names of its
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//////////////////////////////////////////////////////////////////////////////

#ifndef CONRTOLLER_MANAGER_CONTROLLER_LOADER_INTERFACE_H
#define CONRTOLLER_MANAGER_CONTROLLER_LOADER_INTERFACE_H

#include <vector>
#include <string>
#include <boost/shared_ptr.hpp>

namespace controller_interface
{
class ControllerBase;
}

namespace controller_manager
{

class ControllerLoaderInterface
{
public:
  ControllerLoaderInterface(const std::string& name) : name_(name) { }
  virtual boost::shared_ptr<controller_interface::ControllerBase> createInstance(const std::string& lookup_name) = 0;
  virtual std::vector<std::string> getDeclaredClasses() = 0;
  virtual void reload() = 0;
  const std::string& getName() { return name_; }
  virtual ~ControllerLoaderInterface() { }
private:
  const std::string name_;

};

}

#endif
