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

#include "badguy/walking_pipe.hpp"

#include "sprite/sprite.hpp"

WalkingPipe::WalkingPipe(const ReaderMapping& reader)
  : WalkingBadguy(reader, "images/creatures/walking_pipe/walking_pipe.sprite", "left", "right")
{
  parse_type(reader);

  walk_speed = 80;
}

WalkingPipe::WalkingPipe(const Vector& pos, Direction d, const std::string& script)
  : WalkingBadguy(pos, d, "images/creatures/walking_pipe/walking_pipe.sprite", "left", "right")
{
  walk_speed = 80;
  m_dead_script = script;
}

GameObjectTypes
WalkingPipe::get_types() const
{
  return {
    { "normal", _("Normal") },
    { "bumpkin", _("Bumpkin") },
    { "bsod", _("BSOD") }
  };
}

std::string
WalkingPipe::get_default_sprite_name() const
{
  switch (m_type)
  {
    case BUMPKIN:
      return "images/creatures/pumpkin/bumpkin.sprite";
    case BSOD:
      return "images/creatures/bsod/bsod.sprite";
    default:
      return m_default_sprite_name;
  }
}

bool
WalkingPipe::is_freezable() const
{
  return m_type == BUMPKIN || m_type == BSOD;
}

bool
WalkingPipe::collision_squished(MovingObject& object)
{
  if (m_frozen)
    return WalkingBadguy::collision_squished(object);

  set_action("squished", m_dir);
  kill_squished(object);
  return true;
}

/* EOF */
