/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2020, Locus Robotics
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ROBOT_NAV_VIZ_DEMOS_SPECTRUM_DISPLAY_H
#define ROBOT_NAV_VIZ_DEMOS_SPECTRUM_DISPLAY_H

#include <rviz/display.h>
#include <rviz/display_context.h>
#include <rviz/ogre_helpers/arrow.h>
#include <rviz/properties/enum_property.h>
#include <rviz/properties/color_property.h>
#include <rviz/properties/int_property.h>
#include <rviz/properties/float_property.h>
#include <vector>

namespace robot_nav_rviz_plugins
{
class SpectrumDisplay: public rviz::Display
{
Q_OBJECT
public:
  SpectrumDisplay();
  void reset() override;

protected:
  void onInitialize() override;

private Q_SLOTS:
  void updateSize();
  void updateColors();

private:
  enum struct SpectrumStyle {rgb, hsv, short_hsv};
  SpectrumStyle getSpectrumStyle() const { return static_cast<SpectrumStyle>(spectrum_property_->getOptionInt()); }

  std::vector<rviz::Arrow*> arrows_;

  rviz::EnumProperty* spectrum_property_;
  rviz::ColorProperty* color_a_property_;
  rviz::FloatProperty* alpha_a_property_;
  rviz::ColorProperty* color_b_property_;
  rviz::FloatProperty* alpha_b_property_;
  rviz::IntProperty* size_property_;
};
}  // namespace robot_nav_rviz_plugins

#endif  // ROBOT_NAV_VIZ_DEMOS_SPECTRUM_DISPLAY_H
