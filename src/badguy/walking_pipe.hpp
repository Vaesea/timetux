//  SuperTux
//  Copyright (C) 2006 Matthias Braun <matze@braunis.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_BADGUY_WALKINGPIPE_HPP
#define HEADER_SUPERTUX_BADGUY_WALKINGPIPE_HPP

#include "badguy/walking_badguy.hpp"

class WalkingPipe final : public WalkingBadguy
{
public:
  WalkingPipe(const ReaderMapping& reader);
  WalkingPipe(const Vector& pos, Direction d, const std::string& script);

  static std::string class_name() { return "walkingpipe]"; }
  virtual std::string get_class_name() const override { return class_name(); }
  static std::string display_name() { return _("Walking Pipe"); }
  virtual std::string get_display_name() const override { return display_name(); }
  virtual GameObjectClasses get_class_types() const override { return WalkingBadguy::get_class_types().add(typeid(WalkingPipe)); }

  virtual bool is_snipable() const override { return false; }
  virtual bool is_freezable() const override;
  virtual bool is_flammable() const override { return false; }

  GameObjectTypes get_types() const override;
  std::string get_default_sprite_name() const override;

protected:
  virtual bool collision_squished(MovingObject& object) override;

private:
  enum Type {
    NORMAL,
    BUMPKIN,
    BSOD
  };

private:
  WalkingPipe(const WalkingPipe&) = delete;
  WalkingPipe& operator=(const WalkingPipe&) = delete;
};

#endif

/* EOF */
