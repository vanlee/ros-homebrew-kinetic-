///////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2012, hiDOF INC.
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

/*
 * Author: Wim Meeussen
 */

#ifndef HARDWARE_INTERFACE_JOINT_STATE_INTERFACE_H
#define HARDWARE_INTERFACE_JOINT_STATE_INTERFACE_H

#include "hardware_interface/hardware_interface.h"
#include <string>
#include <vector>

namespace hardware_interface{

class JointStateHandle
{
public:
  JointStateHandle(const std::string& name, const double* pos, const double* vel, const double* eff)
    : name_(name), pos_(pos), vel_(vel), eff_(eff)
  {}

  std::string getName() const {return name_;}
  double getPosition() const {return *pos_;}
  double getVelocity() const {return *vel_;}
  double getEffort()   const {return *eff_;}


private:
  std::string name_;
  const double* pos_;
  const double* vel_;
  const double* eff_;
};



class JointStateInterface: virtual public HardwareInterface
{
public:
  JointStateHandle getJointStateHandle(const std::string& name) const
  {
    const double* pos = getPosition(name);
    const double* vel = getVelocity(name);
    const double* eff = getEffort(name);

    if (!pos || !vel || !eff)
      throw HardwareInterfaceException( "Failed to construct JointStateHandle for joint [" + name + "]");

    return JointStateHandle(name, pos, vel, eff);
  }

  virtual std::vector<std::string> getJointNames() const = 0;

protected:
  virtual const double* getPosition(const std::string& name) const = 0;
  virtual const double* getVelocity(const std::string& name) const = 0;
  virtual const double* getEffort(const std::string& name) const = 0;

  JointStateInterface() {registerType(typeid(JointStateInterface).name());}
};

}

#endif
