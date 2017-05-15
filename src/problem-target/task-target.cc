// Copyright (c) 2016, Joseph Mirabel
// Authors: Joseph Mirabel (joseph.mirabel@laas.fr)
//
// This file is part of hpp-core.
// hpp-core is free software: you can redistribute it
// and/or modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation, either version
// 3 of the License, or (at your option) any later version.
//
// hpp-core is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty
// of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Lesser Public License for more details.  You should have
// received a copy of the GNU Lesser General Public License along with
// hpp-core. If not, see <http://www.gnu.org/licenses/>.

#include <hpp/core/problem-target/task-target.hh>

#include <stdexcept>

#include <hpp/util/debug.hh>

#include <hpp/core/node.hh>
#include <hpp/core/connected-component.hh>
#include <hpp/core/problem.hh>
#include <hpp/core/roadmap.hh>
#include <hpp/core/constraint-set.hh>
#include <hpp/core/config-validations.hh>
#include <hpp/core/configuration-shooter.hh>

#include "../astar.hh"

namespace hpp {
  namespace core {
    namespace problemTarget {
      namespace {
        HPP_DEFINE_REASON_FAILURE (REASON_PROJECTION_FAILED, "Projection failed");
        HPP_DEFINE_REASON_FAILURE (REASON_COLLISION, "Collision");
      }

      TaskTargetPtr_t TaskTarget::create (const ProblemPtr_t& problem)
      {
        TaskTarget* tt = new TaskTarget (problem);
        TaskTargetPtr_t shPtr (tt);
        tt->init (shPtr);
        return shPtr;
      }

      void TaskTarget::check (const RoadmapPtr_t&) const
      {
        if (!constraints_) {
          std::string msg ("No constraints: task not specified.");
          hppDout (error, msg);
          throw std::runtime_error (msg);
        }
      }

      bool TaskTarget::reached (const RoadmapPtr_t& roadmap) const
      {
        // TODO
        return false;
      }

      PathVectorPtr_t TaskTarget::computePath(const RoadmapPtr_t& roadmap) const
      {
        Astar astar (roadmap, problem_->distance ());
        return astar.solution ();
      }
    } // namespace problemTarget
  } // namespace core
} // namespace hpp
