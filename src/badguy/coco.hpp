//  SuperTux
//  Copyright (C) 2008 Wolfgang Becker <uafr@gmx.de>
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

#ifndef HEADER_SUPERTUX_BADGUY_COCO_HPP
#define HEADER_SUPERTUX_BADGUY_COCO_HPP

#include "badguy/walking_badguy.hpp"

class Coco final : public WalkingBadguy
{
public:
  Coco(const ReaderMapping& reader);

  virtual void active_update(float dt_sec) override;
  virtual void collision_solid(const CollisionHit& hit) override;

  static std::string class_name() { return "coco"; }
  virtual std::string get_class_name() const override { return class_name(); }
  static std::string display_name() { return _("Coco"); }
  virtual std::string get_display_name() const override { return display_name(); }
  virtual GameObjectClasses get_class_types() const override { return WalkingBadguy::get_class_types().add(typeid(Coco)); }
  virtual bool is_snipable() const override { return true; }
  virtual bool is_freezable() const override { return true; }
  virtual bool is_flammable() const override { return true; }

  bool might_climb(int width, int height) const;

protected:
  virtual bool collision_squished(MovingObject& object) override;

private:
  bool m_jumping;

private:
  Coco(const Coco&) = delete;
  Coco operator=(const Coco&) = delete;
};

#endif

/* EOF */
