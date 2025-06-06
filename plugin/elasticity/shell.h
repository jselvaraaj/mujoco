// Copyright 2023 DeepMind Technologies Limited
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MUJOCO_PLUGIN_ELASTICITY_SHELL_H_
#define MUJOCO_PLUGIN_ELASTICITY_SHELL_H_

#include <optional>
#include <vector>

#include <mujoco/mjdata.h>
#include <mujoco/mjmodel.h>
#include <mujoco/mjtnum.h>
#include "elasticity.h"


namespace mujoco::plugin::elasticity {

struct StencilFlap {
  static constexpr int kNumVerts = 4;
  int vertices[kNumVerts];
};

class Shell {
 public:
  // Returns a new Shell instance or nullopt on failure.
  static std::optional<Shell> Create(const mjModel* m, mjData* d,
                                     int instance);
  Shell(Shell&&) = default;

  Shell& operator=(Shell&& other) = default;

  void Compute(const mjModel* m, mjData* d, int instance);

  static void RegisterPlugin();

  int i0;  // index of first body
  int f0;  // index of corresponding flex
  int nc;  // number of quads in the grid
  int nv;  // number of vertices (bodies) in the Shell

  // precomputed quantities
  std::vector<mjtNum> position;             // previous-step positions (nv x 3)

 private:
  Shell(const mjModel* m, mjData* d, int instance);
};

}  // namespace mujoco::plugin::elasticity

#endif  // MUJOCO_PLUGIN_ELASTICITY_SHELL_H_
